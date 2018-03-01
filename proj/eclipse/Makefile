PROJECT_NAME := mbed_template

BOARD := BOARD_NRF6310
DEVICESERIES := nrf51
DEVICE_VARIANT := xxaa

#softdevices s110,s210 or empty
SOFTDEVICE:=s110

USE_MBED_API=true
USE_MBED_BLE=true
USE_MBED_RTOS=false

NRFJPROG_PATH=/Volumes/DataHDD/work/tools/nRF5x-Command-Line-Tools_9_3_1_OSX/nrfjprog

MBED_API_PATH=/Volumes/DataHDD/work/microcontroller/mbed-api
SDK_PATH=/Volumes/DataHDD/work/tools/nRF51_SDK_7_2_0/

OPTFLAGS= -g3 -O0

# application source

INC_PATHS += $(call allincludes,./../../src)
#C_SOURCE_FILES += $(call allsourcefiles,./../../src,*.c)
CPP_SOURCE_FILES += $(call allsourcefiles,./../../src,*.cpp)


CFLAGS := -DDEBUG_NRF_USER -Wno-unused-function


#MBED API
ifeq ($(USE_MBED_API),true)
CFLAGS += -D__CORTEX_M0
# -DTARGET_MCU_NRF51_16K -DTARGET_MCU_NRF51822 
#CFLAGS += -DTARGET_NRF51822_MKIT -DTARGET_LIKE_MBED -DTARGET_CORTEX_M 
CFLAGS += -DARM_MATH_CM0 
#-DMBED_BUILD_TIMESTAMP="1466981483" -DTARGET_NRF51822
#CFLAGS += -fomit-frame-pointer 
#-DTOOLCHAIN_GCC 
#-DTOOLCHAIN_GCC_ARM
CFLAGS += -DTARGET_MCU_NRF51822 -DTARGET_MCU_NORDIC_32K #for rtos use
CFLAGS += -DTARGET_MCU_NRF51_32K_S110 #-DSDK_CONN_PARAMS_MODULE_ENABLE -DDEVICE_LOWPOWERTIMER#for ble

#-DTOOLCHAIN_ARM_STD -DTOOLCHAIN_ARM
#CFLAGS += -D__MBED__="1" -DTARGET_NORDIC -DTARGET_MCU_NRF51 -DTARGET_MCU_NORDIC_16K -DTARGET_M0 
#CFLAGS += -DTARGET_MCU_NRF51_16K_S130 -DTARGET_LIKE_CORTEX_M0 -D__ASSERT_MSG

INC_PATHS += $(call allincludes,$(MBED_API_PATH)/hal)
C_SOURCE_FILES += $(call sourcefiles,$(MBED_API_PATH)/hal/targets/hal/TARGET_NORDIC/TARGET_MCU_NRF51822/,*.c)
C_SOURCE_FILES += $(call sourcefiles,$(MBED_API_PATH)/hal/targets/cmsis/TARGET_NORDIC/TARGET_MCU_NRF51822/,*.c)
C_SOURCE_FILES += $(call sourcefiles,$(MBED_API_PATH)/hal/common/,*.c)
CPP_SOURCE_FILES += $(call sourcefiles,$(MBED_API_PATH)/hal/common/,*.cpp)


#BLE
ifeq ($(USE_MBED_BLE),true)
INC_PATHS += -I$(MBED_API_PATH)/BLE_API
INC_PATHS += -I$(MBED_API_PATH)/BLE_API/ble/
INC_PATHS += -I$(MBED_API_PATH)/BLE_API/ble_nrf51/
INC_PATHS += -I$(MBED_API_PATH)/BLE_API/ble_nrf51/btle/
#INC_PATHS += -I$(MBED_API_PATH)/BLE_API/nrf51_sdk_new/ble/peer_manager/
#INC_PATHS += -I$(MBED_API_PATH)/BLE_API/nrf51_sdk_new/ble/common/
#INC_PATHS += -I$(MBED_API_PATH)/BLE_API/nrf51_sdk_new/libraries/util/
#INC_PATHS += -I$(MBED_API_PATH)/BLE_API/nrf51_sdk_new/libraries/fds/
#INC_PATHS += -I$(MBED_API_PATH)/BLE_API/nrf51_sdk_new/libraries/fstorage/

CPP_SOURCE_FILES += $(MBED_API_PATH)/BLE_API/source/BLE.cpp
CPP_SOURCE_FILES += $(MBED_API_PATH)/BLE_API/ble_nrf51/nRF5xn.cpp
CPP_SOURCE_FILES += $(MBED_API_PATH)/BLE_API/ble_nrf51/btle/btle.cpp
CPP_SOURCE_FILES += $(MBED_API_PATH)/BLE_API/ble_nrf51/nRF5xGap.cpp
CPP_SOURCE_FILES += $(MBED_API_PATH)/BLE_API/ble_nrf51/btle/btle_gap.cpp
CPP_SOURCE_FILES += $(MBED_API_PATH)/BLE_API/ble_nrf51/btle/nRF5xGattServer.cpp
CPP_SOURCE_FILES += $(MBED_API_PATH)/BLE_API/ble_nrf51/btle/custom/custom_helper.cpp
CPP_SOURCE_FILES += $(MBED_API_PATH)/BLE_API/ble_nrf51/btle/btle_security.cpp

CPP_SOURCE_FILES += $(MBED_API_PATH)/BLE_API/source/GapScanningParams.cpp
CPP_SOURCE_FILES += $(MBED_API_PATH)/BLE_API/source/services/UARTService.cpp

#C_SOURCE_FILES += $(MBED_API_PATH)/BLE_API/nrf51_sdk_new/ble/peer_manager/id_manager.c
#C_SOURCE_FILES += $(MBED_API_PATH)/BLE_API/nrf51_sdk_new/ble/peer_manager/peer_database.c
#C_SOURCE_FILES += $(MBED_API_PATH)/BLE_API/nrf51_sdk_new/ble/common/ble_conn_state.c
#C_SOURCE_FILES += $(MBED_API_PATH)/BLE_API/nrf51_sdk_new/ble/peer_manager/peer_data_storage.c
#C_SOURCE_FILES += $(MBED_API_PATH)/BLE_API/nrf51_sdk_new/ble/peer_manager/pm_buffer.c
#C_SOURCE_FILES += $(MBED_API_PATH)/BLE_API/nrf51_sdk_new/libraries/fds/fds.c

#PUCK
ifeq ($(USE_MBED_PUCK),true)
INC_PATHS += -I$(MBED_API_PATH)/puck/
endif
endif

#RTOS
ifeq ($(USE_MBED_RTOS),true)
CFLAGS += -DTOOLCHAIN_GCC

INC_PATHS += -I"$(MBED_API_PATH)/rtos/rtos" -I"$(MBED_API_PATH)/rtos/rtx/TARGET_CORTEX_M"
C_SOURCE_FILES += $(call sourcefiles,$(MBED_API_PATH)/rtos/rtos/,*.c)
CPP_SOURCE_FILES += $(call sourcefiles,$(MBED_API_PATH)/rtos/rtos/,*.cpp)
C_SOURCE_FILES += $(call sourcefiles,$(MBED_API_PATH)/rtos/rtx/TARGET_CORTEX_M,*.c)

#ASM_SOURCE_FILES += $(MBED_API_PATH)/rtos/rtx/TARGET_CORTEX_M/TARGET_M0/TOOLCHAIN_GCC/HAL_CM0.s
#ASM_SOURCE_FILES += $(MBED_API_PATH)/rtos/rtx/TARGET_CORTEX_M/TARGET_M0/TOOLCHAIN_GCC/SVC_Table.s
endif
endif

#NRF SDK
INC_PATHS += $(call allincludes,$(SDK_PATH)/components/drivers_nrf/hal)
INC_PATHS += -I$(SDK_PATH)/components/softdevice/s110/headers
INC_PATHS += $(call allincludes,$(SDK_PATH)/components/libraries/util)
INC_PATHS += -I$(SDK_PATH)/components/toolchain/gcc
INC_PATHS += -I$(SDK_PATH)/components/toolchain

#BLE
INC_PATHS += $(call allincludes,$(SDK_PATH)/components/drivers_nrf/pstorage)
INC_PATHS += -I$(SDK_PATH)/components/ble/device_manager/config
INC_PATHS += -I$(SDK_PATH)/components/libraries/trace
INC_PATHS += -I$(SDK_PATH)/components/ble/ble_radio_notification
INC_PATHS += -I$(SDK_PATH)/components/ble/common
INC_PATHS += -I$(SDK_PATH)/components/softdevice/common/softdevice_handler
INC_PATHS += -I$(SDK_PATH)/components/libraries/scheduler
INC_PATHS += -I$(SDK_PATH)/components/drivers_nrf/ble_flash
INC_PATHS += -I$(SDK_PATH)/components/ble/device_manager
#INC_PATHS += -I$(SDK_PATH)/components/libraries/timer#ble SDK_CONN_PARAMS_MODULE_ENABLE

C_SOURCE_FILES += $(SDK_PATH)/components/drivers_nrf/pstorage/pstorage.c
C_SOURCE_FILES += $(SDK_PATH)/components/ble/device_manager/device_manager_peripheral.c
C_SOURCE_FILES += $(SDK_PATH)/components/libraries/util/app_error.c
C_SOURCE_FILES += $(SDK_PATH)/components/softdevice/common/softdevice_handler/softdevice_handler.c
C_SOURCE_FILES += $(SDK_PATH)/components/libraries/scheduler/app_scheduler.c
C_SOURCE_FILES += $(SDK_PATH)/components/ble/ble_radio_notification/ble_radio_notification.c
#C_SOURCE_FILES += $(SDK_PATH)/components/ble/common/ble_conn_params.c#ble SDK_CONN_PARAMS_MODULE_ENABLE
#C_SOURCE_FILES += $(SDK_PATH)/components/libraries/timer/app_timer.c#ble SDK_CONN_PARAMS_MODULE_ENABLE


#INC_PATHS += $(call allincludes,$(MBED_API_PATH)/BLE_API/nrf51_sdk)
#INC_PATHS += $(call allincludes,$(SDK_PATH)/components)


#INC_PATHS += $(call allincludes,$(SDK_PATH)/components/drivers_nrf/pstorage)
#INC_PATHS += $(call allincludes,$(SDK_PATH)/components/drivers_nrf/ble_flash)
#INC_PATHS += $(call allincludes,$(SDK_PATH)/components/drivers_nrf/sdio)
#INC_PATHS += $(call allincludes,$(SDK_PATH)/components/ble)

#NRFSD
#INC_PATHS += $(call allincludes,$(SDK_PATH)/components/softdevice/common)


#C_SOURCE_FILES += $(call allsourcefiles,$(MBED_API_PATH)/BLE_API/nrf51_sdk,*.c)
#C_SOURCE_FILES += $(call allsourcefiles,$(SDK_PATH)/components/drivers_nrf,*.c)
C_SOURCE_FILES += $(SDK_PATH)/components/toolchain/system_nrf51.c


#assembly files common to all targets
ASM_SOURCE_FILES += $(SDK_PATH)/components/toolchain/gcc/gcc_startup_$(DEVICESERIES).s

# Krix autodetect 
rwildcard=$(foreach d,$(wildcard $1*),$(call rwildcard,$d/,$2)  $(wildcard $d/$2))

alldirs=$(patsubst %/,%,$(sort $(dir $(call rwildcard,$1,*/))))

allincludes=$(patsubst %,-I"%",$(call alldirs,$1))

#allsourcefiles=$(foreach dir,$(call alldirs,$(patsubst %/,%,$1)),$(subst $(dir)/,,$(wildcard $(dir)/$2)))
allsourcefiles=$(foreach dir,$(call alldirs,$(patsubst %/,%,$1)),$(wildcard $(dir)/$2))

#sourcefiles=$(foreach dir,$(patsubst %/,%,$1),$(subst $(dir)/,,$(wildcard $(dir)/$2)))
sourcefiles=$(foreach dir,$(patsubst %/,%,$1),$(wildcard $(dir)/$2))

OBJECT_DIRECTORY = _build

MAKEFILE_NAME := $(MAKEFILE_LIST)
MAKEFILE_DIR := $(dir $(MAKEFILE_NAME) ) 

SOFTDEVICE_FILE=$(SDK_PATH)/SD/$(SOFTDEVICE).hex

TEMPLATE_PATH = $(SDK_PATH)/components/toolchain/gcc
ifeq ($(OS),Windows_NT)
include $(TEMPLATE_PATH)/Makefile.windows
else
include $(TEMPLATE_PATH)/Makefile.posix
endif


ifneq ($(SOFTDEVICE),)
	CFLAGS 	+= -DSOFTDEVICE_PRESENT -DBLE_STACK_SUPPORT_REQD -D`echo $(SOFTDEVICE)  | tr a-z A-Z`
	ASMFLAGS+= -DSOFTDEVICE_PRESENT -DBLE_STACK_SUPPORT_REQD -D`echo $(SOFTDEVICE)  | tr a-z A-Z`
endif
SOFTDEVICE_FILE=$(SDK_PATH)/SD/$(SOFTDEVICE).hex
ifeq ($(LINKER_SCRIPT),)
	LINKER_SCRIPT = $(SDK_PATH)/components/toolchain/gcc/gcc_$(DEVICESERIES)_$(SOFTDEVICE)_$(DEVICE_VARIANT).ld
endif

OUTPUT_FILENAME := $(PROJECT_NAME)_$(DEVICESERIES)_$(SOFTDEVICE)_$(DEVICE_VARIANT)

MK := mkdir
RM := rm -rf

#echo suspend
ifeq ("$(VERBOSE)","1")
NO_ECHO := 
else
NO_ECHO := @
endif

# Toolchain commands
CC       		:= "$(GNU_INSTALL_ROOT)/bin/$(GNU_PREFIX)-gcc"
CP       		:= "$(GNU_INSTALL_ROOT)/bin/$(GNU_PREFIX)-g++"
AS       		:= "$(GNU_INSTALL_ROOT)/bin/$(GNU_PREFIX)-as"
AR       		:= "$(GNU_INSTALL_ROOT)/bin/$(GNU_PREFIX)-ar" -r
LD       		:= "$(GNU_INSTALL_ROOT)/bin/$(GNU_PREFIX)-ld"
NM       		:= "$(GNU_INSTALL_ROOT)/bin/$(GNU_PREFIX)-nm"
OBJDUMP  		:= "$(GNU_INSTALL_ROOT)/bin/$(GNU_PREFIX)-objdump"
OBJCOPY  		:= "$(GNU_INSTALL_ROOT)/bin/$(GNU_PREFIX)-objcopy"
SIZE    		:= "$(GNU_INSTALL_ROOT)/bin/$(GNU_PREFIX)-size"

#function for removing duplicates in a list
remduplicates = $(strip $(if $1,$(firstword $1) $(call remduplicates,$(filter-out $(firstword $1),$1))))

LISTING_DIRECTORY = $(OBJECT_DIRECTORY)
OUTPUT_BINARY_DIRECTORY = $(OBJECT_DIRECTORY)

# Sorting removes duplicates
BUILD_DIRECTORIES := $(sort $(OBJECT_DIRECTORY) $(OUTPUT_BINARY_DIRECTORY) $(LISTING_DIRECTORY) )

#flags common to all targets
CFLAGS += -D`echo $(DEVICESERIES)  | tr a-z A-Z`
CFLAGS += -D$(BOARD)
CFLAGS += -mcpu=cortex-m0
CFLAGS += -mthumb -mabi=aapcs
CFLAGS += -Wall -Werror $(OPTFLAGS)
CFLAGS += -mfloat-abi=soft
# keep every function in separate section. This will allow linker to dump unused functions
CFLAGS += -ffunction-sections -fdata-sections -fno-strict-aliasing
CFLAGS += -flto -fno-builtin

# keep every function in separate section. This will allow linker to dump unused functions
LDFLAGS += -Xlinker -Map=$(LISTING_DIRECTORY)/$(OUTPUT_FILENAME).map
LDFLAGS += -mthumb -mabi=aapcs -L $(TEMPLATE_PATH) -T$(LINKER_SCRIPT)
LDFLAGS += -mcpu=cortex-m0
# let linker to dump unused sections
LDFLAGS +=  $(OPTFLAGS)
#-Wl,--gc-sections this strips the static initializer from classes
# use newlib in nano version
LDFLAGS += --specs=nano.specs -lc -lnosys

# Assembler flags
ASMFLAGS += -x assembler-with-cpp
ASMFLAGS += -D`echo $(DEVICESERIES)  | tr a-z A-Z`
ASMFLAGS += -D$(BOARD) $(OPTFLAGS) -D__CORTEX_M0 
#default target - first one defined
default: debug

debug: build_target erase flash_softdevice flash
	
build_target:
	$(NO_ECHO)$(MAKE) -f $(MAKEFILE_NAME) -C $(MAKEFILE_DIR) -e build
	
#building all targets
all:
#	$(NO_ECHO)$(MAKE) -f $(MAKEFILE_NAME) -C $(MAKEFILE_DIR) -e cleanobj
	$(NO_ECHO)$(MAKE) -f $(MAKEFILE_NAME) -C $(MAKEFILE_DIR) -e build

#target for printing all targets
help:
	@echo following targets are available:
	@echo 	nrf51422_xxac_s110


C_SOURCE_FILE_NAMES = $(notdir $(C_SOURCE_FILES))
CPP_SOURCE_FILENAMES= $(notdir $(CPP_SOURCE_FILES) )

C_PATHS = $(sort $(dir $(CPP_SOURCE_FILES) ) )
C_PATHS += $(sort $(dir $(C_SOURCE_FILES) ) )

C_OBJECTS = $(addprefix $(OBJECT_DIRECTORY)/, $(C_SOURCE_FILE_NAMES:.c=.o) )
CPP_OBJECTS = $(addprefix $(OBJECT_DIRECTORY)/, $(CPP_SOURCE_FILENAMES:.cpp=.o) )

ASM_SOURCE_FILE_NAMES = $(notdir $(ASM_SOURCE_FILES))
ASM_PATHS = $(sort $(dir $(ASM_SOURCE_FILES) ))
ASM_OBJECTS = $(addprefix $(OBJECT_DIRECTORY)/, $(ASM_SOURCE_FILE_NAMES:.s=.o) )

vpath %.cpp $(C_PATHS)
vpath %.c $(C_PATHS)
vpath %.s $(ASM_PATHS)

OBJECTS = $(CPP_OBJECTS) $(C_OBJECTS) $(ASM_OBJECTS)

build: $(BUILD_DIRECTORIES) $(OBJECTS)
	@echo Linking target: $(OUTPUT_FILENAME).out
	$(NO_ECHO)$(CP) $(LDFLAGS) $(OBJECTS) $(LIBS) -o $(OUTPUT_BINARY_DIRECTORY)/$(OUTPUT_FILENAME).out
	$(NO_ECHO)$(MAKE) -f $(MAKEFILE_NAME) -C $(MAKEFILE_DIR) -e finalize

## Create build directories
$(BUILD_DIRECTORIES):
	echo $(MAKEFILE_NAME)
	$(MK) $@

## Create objects from CPP source files
$(OBJECT_DIRECTORY)/%.o: %.cpp
	@echo Compiling file: $(notdir $<)
	$(NO_ECHO)$(CP) $(CFLAGS) $(INC_PATHS) -c -o $@ $<
	
# Create objects from C SRC files
$(OBJECT_DIRECTORY)/%.o: %.c
	@echo Compiling file: $(notdir $<)
	$(NO_ECHO)$(CC) $(CFLAGS) --std=gnu99 $(INC_PATHS) -c -o $@ $<

# Assemble files
$(OBJECT_DIRECTORY)/%.o: %.s
	@echo Compiling file: $(notdir $<)
	$(NO_ECHO)$(CC) $(ASMFLAGS) $(INC_PATHS) -c -o $@ $<


# Link
$(OUTPUT_BINARY_DIRECTORY)/$(OUTPUT_FILENAME).out: $(BUILD_DIRECTORIES) $(OBJECTS)
	@echo Linking target: $(OUTPUT_FILENAME).out
	$(NO_ECHO)$(CP) $(LDFLAGS) $(OBJECTS) $(LIBS) -o $(OUTPUT_BINARY_DIRECTORY)/$(OUTPUT_FILENAME).out


## Create binary .bin file from the .out file
$(OUTPUT_BINARY_DIRECTORY)/$(OUTPUT_FILENAME).bin: $(OUTPUT_BINARY_DIRECTORY)/$(OUTPUT_FILENAME).out
	@echo Preparing: $(OUTPUT_FILENAME).bin
	$(NO_ECHO)$(OBJCOPY) -O binary $(OUTPUT_BINARY_DIRECTORY)/$(OUTPUT_FILENAME).out $(OUTPUT_BINARY_DIRECTORY)/$(OUTPUT_FILENAME).bin

## Create binary .hex file from the .out file
$(OUTPUT_BINARY_DIRECTORY)/$(OUTPUT_FILENAME).hex: $(OUTPUT_BINARY_DIRECTORY)/$(OUTPUT_FILENAME).out
	@echo Preparing: $(OUTPUT_FILENAME).hex
	$(NO_ECHO)$(OBJCOPY) -O ihex $(OUTPUT_BINARY_DIRECTORY)/$(OUTPUT_FILENAME).out $(OUTPUT_BINARY_DIRECTORY)/$(OUTPUT_FILENAME).hex

finalize: genbin genhex echosize

genbin:
	@echo Preparing: $(OUTPUT_FILENAME).bin
	$(NO_ECHO)$(OBJCOPY) -O binary $(OUTPUT_BINARY_DIRECTORY)/$(OUTPUT_FILENAME).out $(OUTPUT_BINARY_DIRECTORY)/$(OUTPUT_FILENAME).bin

## Create binary .hex file from the .out file
genhex: 
	@echo Preparing: $(OUTPUT_FILENAME).hex
	$(NO_ECHO)$(OBJCOPY) -O ihex $(OUTPUT_BINARY_DIRECTORY)/$(OUTPUT_FILENAME).out $(OUTPUT_BINARY_DIRECTORY)/$(OUTPUT_FILENAME).hex

echosize:
	-@echo ""
	$(NO_ECHO)$(SIZE) $(OUTPUT_BINARY_DIRECTORY)/$(OUTPUT_FILENAME).out
	-@echo ""

clean:
	$(RM) $(BUILD_DIRECTORIES)

cleanobj:
	$(RM) $(BUILD_DIRECTORIES)/*.o

flash:
	@echo Flashing: $(OUTPUT_BINARY_DIRECTORY)/$(OUTPUT_FILENAME).hex
#	$(NRFJPROG_PATH)/../mergehex/mergehex -m $(SOFTDEVICE_FILE) $(OUTPUT_BINARY_DIRECTORY)/nrf51422_xxac_s110.hex -o $(OUTPUT_BINARY_DIRECTORY)/sd_nrf51422_xxac_s110.hex
	$(NRFJPROG_PATH)/nrfjprog --reset --program $(OUTPUT_BINARY_DIRECTORY)/$(OUTPUT_FILENAME).hex
	#/Applications/SEGGER/JLink/JLinkExe -device nrf51822 -if swd -speed 1000 >/dev/null 2>&1  & echo $$! >tmp.pid
	
## Flash softdevice
flash_softdevice: 
	@echo Flashing: s110_softdevice.hex
	$(NRFJPROG_PATH)/nrfjprog --reset --program $(SOFTDEVICE_FILE)

erase:
	$(NRFJPROG_PATH)/nrfjprog -e
	
jlink_connect:
	/Applications/SEGGER/JLink/JLinkExe -device nrf51822 -if swd -speed 1000 >/dev/null 2>&1  & echo $$! >tmp.pid
	
jlink_kill:
	kill $(shell cat tmp.pid)
	$(shell rm tmp.pid)

reset:
	$(NRFJPROG_PATH)/nrfjprog --reset

echostuff:
	@echo INC_PATHS: [$(sort $(INC_PATHS))]
	@echo CPP_SOURCE_FILES: [$(CPP_SOURCE_FILES)]
	@echo CPP_SOURCE_FILENAMES: [$(CPP_SOURCE_FILENAMES)]
	@echo C_SOURCE_FILES: [$(C_SOURCE_FILES)]
	@echo C_SOURCE_FILENAMES: [$(C_SOURCE_FILE_NAMES)]
	@echo C_SOURCE_PATHS: [ $(sort $(C_PATHS))]
	@echo CFLAGS: [$(CFLAGS)]
	