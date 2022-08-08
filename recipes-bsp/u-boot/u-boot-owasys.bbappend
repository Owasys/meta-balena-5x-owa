# Requirements from https://github.com/balena-os/meta-balena/blob/master/contributing-device-support.md#recipes-bsp
UBOOT_KCONFIG_SUPPORT="1"
BALENA_UBOOT_DEVICE_TYPES="usb mmc"
inherit resin-u-boot

FILESEXTRAPATHS_prepend := "${THISDIR}/files:"

# resin-u-boot class patch is rebased
SRC_URI_remove = " file://resin-specific-env-integration-kconfig.patch"
SRC_URI_append = " file://0001-Include-resin-env.patch"

SRC_URI_append_owa5x = " file://0002-Set-balena-bootcmd.patch \
                         file://0003-Changed-bootcmd-so-it-loads-the-kernel-from-the-root.patch \
                         file://0004-Removed-grammar-error.patch \
                         file://0005-Removed-strange-symbol-introduced-when-creating-patc.patch \
                         file://0006-Modified-bootargs-to-manually-boot-balenaOS.patch \
                         file://0007-Added-run-mmcargs-at-boot-command-so-needed-variable.patch \
                         "

do_configure[nostamp] = "1"
do_compile[nostamp] = "1"