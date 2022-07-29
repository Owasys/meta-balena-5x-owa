# Requirements from https://github.com/balena-os/meta-balena/blob/master/contributing-device-support.md#recipes-bsp
UBOOT_KCONFIG_SUPPORT = "1"

inherit resin-u-boot

do_compile[nostamp] = "1"

