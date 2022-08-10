IMAGE_FSTYPES_append = " balenaos-img"

DEPENDS += " imx-boot-owasys "

BALENA_IMAGE_BOOTLOADER_owa5x = " u-boot-owasys "

BALENA_BOOT_PARTITION_FILES = " \
    ${KERNEL_IMAGETYPE}-${MACHINE}.bin:/Image.gz \
    imx8mp-owa5x.dtb:/imx8mp-owa5x.dtb \
    ${MACHINE}-flash.bin:/${MACHINE}-flash.bin \
"

IMAGE_CMD_balenaos-img_append () {
    dd if=${DEPLOY_DIR_IMAGE}/${MACHINE}-flash.bin of=${BALENA_RAW_IMG} conv=notrunc seek=32 bs=1K
}

deltask do_packagedata

IMAGE_INSTALL_append = " pmsrvsystemd pmsrv kernel-modules "
                    
