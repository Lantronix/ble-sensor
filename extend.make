# -----------------------------------------------------------------------------------
# DESCRIPTION:
# <module name>_LIBRARIES defines libraries used by this module.
# <module_name_INCLUDE_PATHS defines include paths used by this module.
# <module_name>_FORCED_FLASH_SECTIONS defines code sections to be placed in FLASH.
# <module_name>_FORCED_RAM_SECTIONS defines code sections to be placed in RAM.
#
# ALERT:
# Files added to these variables should maintain the alphabetical order.
# -----------------------------------------------------------------------------------

bleSensor_LIBRARIES := $(MY_DIR)/libraries/ltrx_bt_essential.a \
  $(MY_DIR)/libraries/bluetooth_low_energy.ThreadX.NetX.ARM_CR4.release.a

bleSensor_INCLUDE_PATHS := \
  $(LANTRONIX_DIRECTORY)/includes/system/bcm943907/bluetooth \

bleSensor_FORCED_FLASH_SECTIONS := *.html.o(.rodata*) *.js.gz.o(.rodata*) *_embedded_files.o(.rodata.*)

bleSensor_FORCED_RAM_SECTIONS := *(.rodata) *(.rodata.*)

bleSensor_LDFLAGS := -nostdlib
