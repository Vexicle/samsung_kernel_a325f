#!/bin/bash

rm $(pwd)/arch/arm64/boot/zImage -s

export CROSS_COMPILE=$(pwd)/toolchain/aarch64-linux-android-4.9/bin/aarch64-linux-androidkernel-
export CC=$(pwd)/toolchain/proton-clang-20210522/bin/clang
export CLANG_TRIPLE=$(pwd)toolchain/proton-clang-20210522/bin/aarch64-linux-gnu-
export ARCH=arm64
export ANDROID_MAJOR_VERSION=r

export KCFLAGS=-w
export CONFIG_SECTION_MISMATCH_WARN_ONLY=y

make -C $(pwd) O=$(pwd)/out KCFLAGS=-w CONFIG_SECTION_MISMATCH_WARN_ONLY=y a32_defconfig -j16
make -C $(pwd) O=$(pwd)/out KCFLAGS=-w CONFIG_SECTION_MISMATCH_WARN_ONLY=y -j16

cp out/arch/arm64/boot/Image $(pwd)/arch/arm64/boot/Image
cp $(pwd)/arch/arm64/boot/Image $(pwd)/arch/arm64/boot/zImage 
