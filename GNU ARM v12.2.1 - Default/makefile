################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include gecko_sdk_4.4.5/platform/service/system/src/subdir.mk
-include gecko_sdk_4.4.5/platform/service/sleeptimer/src/subdir.mk
-include gecko_sdk_4.4.5/platform/service/mpu/src/subdir.mk
-include gecko_sdk_4.4.5/platform/service/iostream/src/subdir.mk
-include gecko_sdk_4.4.5/platform/service/device_init/src/subdir.mk
-include gecko_sdk_4.4.5/platform/radio/rail_lib/plugin/rail_util_rssi/subdir.mk
-include gecko_sdk_4.4.5/platform/radio/rail_lib/plugin/rail_util_pti/subdir.mk
-include gecko_sdk_4.4.5/platform/radio/rail_lib/plugin/rail_util_protocol/subdir.mk
-include gecko_sdk_4.4.5/platform/radio/rail_lib/plugin/pa-conversions/subdir.mk
-include gecko_sdk_4.4.5/platform/peripheral/src/subdir.mk
-include gecko_sdk_4.4.5/platform/emlib/src/subdir.mk
-include gecko_sdk_4.4.5/platform/emdrv/uartdrv/src/subdir.mk
-include gecko_sdk_4.4.5/platform/emdrv/gpiointerrupt/src/subdir.mk
-include gecko_sdk_4.4.5/platform/emdrv/dmadrv/src/subdir.mk
-include gecko_sdk_4.4.5/platform/common/toolchain/src/subdir.mk
-include gecko_sdk_4.4.5/platform/common/src/subdir.mk
-include gecko_sdk_4.4.5/platform/Device/SiliconLabs/EFR32FG23/Source/subdir.mk
-include autogen/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := rail_soc_project
BUILD_ARTIFACT_EXTENSION := axf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: main-build

# Main-build Target
main-build: rail_soc_project.axf

# Tool invocations
rail_soc_project.axf: $(OBJS) $(USER_OBJS) makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Building target: $@'
	@echo 'Invoking: GNU ARM C Linker'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m33 -mthumb -T "C:\Users\ricem\SimplicityStudio\v5_workspace\rail_soc_project\autogen\linkerfile.ld" -Wl,--no-warn-rwx-segments -Xlinker --gc-sections -Xlinker -Map="rail_soc_project.map" -mfpu=fpv5-sp-d16 -mfloat-abi=hard --specs=nano.specs -o rail_soc_project.axf -Wl,--start-group "./app_init.o" "./app_process.o" "./main.o" "./autogen/rail_config.o" "./autogen/sl_device_init_clocks.o" "./autogen/sl_emlib_gpio_simple_init.o" "./autogen/sl_event_handler.o" "./autogen/sl_iostream_handles.o" "./autogen/sl_iostream_init_eusart_instances.o" "./autogen/sl_rail_util_callbacks.o" "./autogen/sl_rail_util_init.o" "./autogen/sl_uartdrv_init.o" "./gecko_sdk_4.4.5/platform/Device/SiliconLabs/EFR32FG23/Source/startup_efr32fg23.o" "./gecko_sdk_4.4.5/platform/Device/SiliconLabs/EFR32FG23/Source/system_efr32fg23.o" "./gecko_sdk_4.4.5/platform/common/src/sl_assert.o" "./gecko_sdk_4.4.5/platform/common/src/sl_slist.o" "./gecko_sdk_4.4.5/platform/common/src/sl_string.o" "./gecko_sdk_4.4.5/platform/common/src/sl_syscalls.o" "./gecko_sdk_4.4.5/platform/common/toolchain/src/sl_memory.o" "./gecko_sdk_4.4.5/platform/emdrv/dmadrv/src/dmadrv.o" "./gecko_sdk_4.4.5/platform/emdrv/gpiointerrupt/src/gpiointerrupt.o" "./gecko_sdk_4.4.5/platform/emdrv/uartdrv/src/uartdrv.o" "./gecko_sdk_4.4.5/platform/emlib/src/em_burtc.o" "./gecko_sdk_4.4.5/platform/emlib/src/em_cmu.o" "./gecko_sdk_4.4.5/platform/emlib/src/em_core.o" "./gecko_sdk_4.4.5/platform/emlib/src/em_emu.o" "./gecko_sdk_4.4.5/platform/emlib/src/em_eusart.o" "./gecko_sdk_4.4.5/platform/emlib/src/em_gpio.o" "./gecko_sdk_4.4.5/platform/emlib/src/em_ldma.o" "./gecko_sdk_4.4.5/platform/emlib/src/em_msc.o" "./gecko_sdk_4.4.5/platform/emlib/src/em_prs.o" "./gecko_sdk_4.4.5/platform/emlib/src/em_system.o" "./gecko_sdk_4.4.5/platform/emlib/src/em_timer.o" "./gecko_sdk_4.4.5/platform/emlib/src/em_usart.o" "./gecko_sdk_4.4.5/platform/peripheral/src/peripheral_sysrtc.o" "./gecko_sdk_4.4.5/platform/radio/rail_lib/plugin/pa-conversions/pa_conversions_efr32.o" "./gecko_sdk_4.4.5/platform/radio/rail_lib/plugin/pa-conversions/pa_curves_efr32.o" "./gecko_sdk_4.4.5/platform/radio/rail_lib/plugin/rail_util_protocol/sl_rail_util_protocol.o" "./gecko_sdk_4.4.5/platform/radio/rail_lib/plugin/rail_util_pti/sl_rail_util_pti.o" "./gecko_sdk_4.4.5/platform/radio/rail_lib/plugin/rail_util_rssi/sl_rail_util_rssi.o" "./gecko_sdk_4.4.5/platform/service/device_init/src/sl_device_init_dcdc_s2.o" "./gecko_sdk_4.4.5/platform/service/device_init/src/sl_device_init_emu_s2.o" "./gecko_sdk_4.4.5/platform/service/device_init/src/sl_device_init_hfxo_s2.o" "./gecko_sdk_4.4.5/platform/service/device_init/src/sl_device_init_nvic.o" "./gecko_sdk_4.4.5/platform/service/iostream/src/sl_iostream.o" "./gecko_sdk_4.4.5/platform/service/iostream/src/sl_iostream_eusart.o" "./gecko_sdk_4.4.5/platform/service/iostream/src/sl_iostream_retarget_stdio.o" "./gecko_sdk_4.4.5/platform/service/iostream/src/sl_iostream_uart.o" "./gecko_sdk_4.4.5/platform/service/iostream/src/sl_iostream_usart.o" "./gecko_sdk_4.4.5/platform/service/mpu/src/sl_mpu.o" "./gecko_sdk_4.4.5/platform/service/sleeptimer/src/sl_sleeptimer.o" "./gecko_sdk_4.4.5/platform/service/sleeptimer/src/sl_sleeptimer_hal_burtc.o" "./gecko_sdk_4.4.5/platform/service/sleeptimer/src/sl_sleeptimer_hal_sysrtc.o" "./gecko_sdk_4.4.5/platform/service/sleeptimer/src/sl_sleeptimer_hal_timer.o" "./gecko_sdk_4.4.5/platform/service/system/src/sl_system_init.o" "./gecko_sdk_4.4.5/platform/service/system/src/sl_system_process_action.o" "C:/Users/ricem/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/autogen/librail_release/librail_efr32xg23_gcc_release.a" -lgcc -lc -lm -lnosys -Wl,--end-group -Wl,--start-group -lgcc -lc -lnosys -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

	@echo 'Building out file: rail_soc_project.out'
	arm-none-eabi-objcopy "rail_soc_project.axf" "rail_soc_project.out"
	@echo ' '

	@echo 'Building hex file: rail_soc_project.hex'
	arm-none-eabi-objcopy -O ihex "rail_soc_project.axf" "rail_soc_project.hex"
	@echo ' '

	@echo 'Building bin file: rail_soc_project.bin'
	arm-none-eabi-objcopy -O binary "rail_soc_project.axf" "rail_soc_project.bin"
	@echo ' '

	@echo 'Building s37 file: rail_soc_project.s37'
	arm-none-eabi-objcopy -O srec "rail_soc_project.axf" "rail_soc_project.s37"
	@echo ' '

	@echo 'Running size tool'
	arm-none-eabi-size "rail_soc_project.axf" -A
	@echo ' '

# Other Targets
clean:
	-@$(foreach FILE, $(EXECUTABLES), $(shell $(RM) $(FILE)) )
	-@$(foreach FILE, $(OBJS), $(shell $(RM) $(FILE)) )
	-@$(foreach FILE, $(C_DEPS), $(shell $(RM) $(FILE)) )
	-$(RM) rail_soc_project.axf
	-@echo ' '

.PHONY: all clean dependents main-build

-include ../makefile.targets
