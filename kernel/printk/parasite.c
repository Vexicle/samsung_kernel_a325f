//debug parasite
//PLEASE bro just compile

#include <linux/fs.h>
#include <linux/slab.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/err.h>
#include "parasite.h"

#define KMSG_BUFFER_SIZE (256*1024) // 256 KB

static char *kmsg_buffer;
static size_t buffer_pos = 0;
static struct file *kmsg_file = NULL;

static int ensure_file_open(void)
{
    if (kmsg_file)
        return 0;

    kmsg_file = filp_open("/data/kmsg.log",
                          O_WRONLY | O_CREAT | O_APPEND, 0644);
    if (IS_ERR(kmsg_file)) {
        kmsg_file = NULL;
        return -1;
    }
    return 0;
}

void write_kmsg_to_file(const char *buf, size_t len)
{
    loff_t pos = 0;

    if (!buf || len == 0)
        return;

    // Allocate buffer if first time
    if (!kmsg_buffer) {
        kmsg_buffer = kzalloc(KMSG_BUFFER_SIZE, GFP_KERNEL);
        buffer_pos = 0;
    }

    // Buffer until filesystem available
    if (!kmsg_file) {
        size_t copy_len = len;
        if (buffer_pos + copy_len > KMSG_BUFFER_SIZE)
            copy_len = KMSG_BUFFER_SIZE - buffer_pos;
        memcpy(kmsg_buffer + buffer_pos, buf, copy_len);
        buffer_pos += copy_len;
        return;
    }

    kernel_write(kmsg_file, buf, len, &pos);
}

void flush_kmsg_buffer(void)
{
    loff_t pos = 0;

    if (!kmsg_buffer || buffer_pos == 0)
        return;

    if (ensure_file_open() == 0) {
        kernel_write(kmsg_file, kmsg_buffer, buffer_pos, &pos);
        buffer_pos = 0;
    }
}

// Optional: cleanup on module unload
void cleanup_kmsg(void)
{
    flush_kmsg_buffer();
    if (kmsg_file) {
        filp_close(kmsg_file, NULL);
        kmsg_file = NULL;
    }
    kfree(kmsg_buffer);
    kmsg_buffer = NULL;
    buffer_pos = 0;
}
