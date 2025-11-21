#ifndef _KMSG_PERSISTENT_H
#define _KMSG_PERSISTENT_H

#include <linux/types.h>

void write_kmsg_to_file(const char *buf, size_t len);
void flush_kmsg_buffer(void);

#endif /* _KMSG_PERSISTENT_H */
