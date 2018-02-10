#!/bin/bash
cd kernel
make ARCH=arm64 O=../out merge_kirin970_defconfig
make ARCH=arm64 O=../out menuconfig
make ARCH=arm64 O=../out -j8
