IMAGE_FSTYPES_append = " balenaos-img"

DEPENDS += " imx-boot-owasys "

BALENA_IMAGE_BOOTLOADER_owa5x = " u-boot-owasys "

BALENA_BOOT_PARTITION_FILES = " \
    ${KERNEL_IMAGETYPE}${KERNEL_INITRAMFS}-${MACHINE}.bin:/Image.gz \
    imx8mp-owa5x.dtb:/imx8mp-owa5x.dtb \
    ${MACHINE}-flash.bin:/${MACHINE}-flash.bin \
"

IMAGE_CMD_balenaos-img_append () {
    dd if=${DEPLOY_DIR_IMAGE}/${MACHINE}-flash.bin of=${BALENA_RAW_IMG} conv=notrunc seek=32 bs=1K
}

#IMAGE_ROOTFS_SIZE = "970000"
#IMAGE_OVERHEAD_FACTOR = "1.0"
#IMAGE_ROOTFS_EXTRA_SPACE = "752"
#IMAGE_ROOTFS_MAXSIZE = "970752"

IMAGE_INSTALL_append = " pmsrvsystemd pmsrv kernel-modules "
                    
deltask do_packagedata