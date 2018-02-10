#!/bin/bash
cd kernel
make ARCH=arm64 distclean
rm -rf ../out
