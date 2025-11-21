#!/bin/bash

export CROSS_COMPILE=$(pwd)/../aarch64-linux-android-4.9/bin/aarch64-linux-androidkernel-
export CC=$(pwd)/../clang-r383902/bin/clang
export CLANG_TRIPLE=aarch64-linux-gnu-
export ARCH=arm64
export ANDROID_MAJOR_VERSION=r

export KCFLAGS=-w
export CONFIG_SECTION_MISMATCH_WARN_ONLY=y

make -C $(pwd) O=$(pwd)/out KCFLAGS=-w CONFIG_SECTION_MISMATCH_WARN_ONLY=y -o2 -j12 a32_defconfig
make -C $(pwd) O=$(pwd)/out KCFLAGS=-w CONFIG_SECTION_MISMATCH_WARN_ONLY=y -o2 -lto -j12

cp out/arch/arm64/boot/Image /home/vexicle/a32-sneakykernel/zImage
