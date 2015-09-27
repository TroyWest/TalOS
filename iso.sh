#!/bin/sh
set -e
. ./build.sh

mkdir -p isodir
mkdir -p isodir/boot
mkdir -p isodir/boot/grub

cp sysroot/boot/talos.kernel isodir/boot/talos.kernel
cat > isodir/boot/grub/grub.cfg << EOF
menuentry "talos" {
	multiboot /boot/talos.kernel
}
EOF
grub2-mkrescue -o talos.iso isodir
