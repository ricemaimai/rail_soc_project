################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/SeigoSakaki/SimplicityStudio/SDKs/gecko_sdk/platform/radio/rail_lib/plugin/rail_util_pti/sl_rail_util_pti.c 

OBJS += \
./gecko_sdk_4.4.5/platform/radio/rail_lib/plugin/rail_util_pti/sl_rail_util_pti.o 

C_DEPS += \
./gecko_sdk_4.4.5/platform/radio/rail_lib/plugin/rail_util_pti/sl_rail_util_pti.d 


# Each subdirectory must supply rules for building sources it contributes
gecko_sdk_4.4.5/platform/radio/rail_lib/plugin/rail_util_pti/sl_rail_util_pti.o: C:/Users/SeigoSakaki/SimplicityStudio/SDKs/gecko_sdk/platform/radio/rail_lib/plugin/rail_util_pti/sl_rail_util_pti.c gecko_sdk_4.4.5/platform/radio/rail_lib/plugin/rail_util_pti/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m33 -mthumb -std=c99 '-DEFR32FG23B010F512IM40=1' '-DSL_COMPONENT_CATALOG_PRESENT=1' '-DSL_RAIL_LIB_MULTIPROTOCOL_SUPPORT=0' '-DSL_RAIL_UTIL_PA_CONFIG_HEADER=<sl_rail_util_pa_config.h>' -I"C:\Users\SeigoSakaki\SimplicityStudio\v5_workspace\rail_soc_project\autogen" -I"C:\Users\SeigoSakaki\SimplicityStudio\v5_workspace\rail_soc_project\config" -I"C:\Users\SeigoSakaki\SimplicityStudio\v5_workspace\rail_soc_project\config\rail" -I"C:\Users\SeigoSakaki\SimplicityStudio\v5_workspace\rail_soc_project" -I"C:/Users/SeigoSakaki/SimplicityStudio/SDKs/gecko_sdk//platform/Device/SiliconLabs/EFR32FG23/Include" -I"C:/Users/SeigoSakaki/SimplicityStudio/SDKs/gecko_sdk//platform/common/inc" -I"C:/Users/SeigoSakaki/SimplicityStudio/SDKs/gecko_sdk//platform/CMSIS/Core/Include" -I"C:/Users/SeigoSakaki/SimplicityStudio/SDKs/gecko_sdk//platform/service/device_init/inc" -I"C:/Users/SeigoSakaki/SimplicityStudio/SDKs/gecko_sdk//platform/emdrv/dmadrv/inc" -I"C:/Users/SeigoSakaki/SimplicityStudio/SDKs/gecko_sdk//platform/emdrv/common/inc" -I"C:/Users/SeigoSakaki/SimplicityStudio/SDKs/gecko_sdk//platform/emlib/inc" -I"C:/Users/SeigoSakaki/SimplicityStudio/SDKs/gecko_sdk//platform/emlib/init/gpio_simple" -I"C:/Users/SeigoSakaki/SimplicityStudio/SDKs/gecko_sdk//platform/emdrv/gpiointerrupt/inc" -I"C:/Users/SeigoSakaki/SimplicityStudio/SDKs/gecko_sdk//platform/service/iostream/inc" -I"C:/Users/SeigoSakaki/SimplicityStudio/SDKs/gecko_sdk//platform/service/mpu/inc" -I"C:/Users/SeigoSakaki/SimplicityStudio/SDKs/gecko_sdk//platform/peripheral/inc" -I"C:/Users/SeigoSakaki/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/common" -I"C:/Users/SeigoSakaki/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/protocol/ble" -I"C:/Users/SeigoSakaki/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/protocol/ieee802154" -I"C:/Users/SeigoSakaki/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/protocol/wmbus" -I"C:/Users/SeigoSakaki/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/protocol/zwave" -I"C:/Users/SeigoSakaki/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/chip/efr32/efr32xg2x" -I"C:/Users/SeigoSakaki/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/protocol/sidewalk" -I"C:/Users/SeigoSakaki/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/plugin/rail_util_callbacks" -I"C:/Users/SeigoSakaki/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/plugin/pa-conversions" -I"C:/Users/SeigoSakaki/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/plugin/pa-conversions/efr32xg23" -I"C:/Users/SeigoSakaki/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/plugin/rail_util_protocol" -I"C:/Users/SeigoSakaki/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/plugin/rail_util_pti" -I"C:/Users/SeigoSakaki/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/plugin/rail_util_rssi" -I"C:/Users/SeigoSakaki/SimplicityStudio/SDKs/gecko_sdk//platform/common/toolchain/inc" -I"C:/Users/SeigoSakaki/SimplicityStudio/SDKs/gecko_sdk//platform/service/system/inc" -I"C:/Users/SeigoSakaki/SimplicityStudio/SDKs/gecko_sdk//platform/service/sleeptimer/inc" -I"C:/Users/SeigoSakaki/SimplicityStudio/SDKs/gecko_sdk//platform/emdrv/uartdrv/inc" -I"C:/Users/SeigoSakaki/SimplicityStudio/SDKs/gecko_sdk//platform/service/udelay/inc" -Og -Wall -Wextra -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mcmse --specs=nano.specs -c -fmessage-length=0 -MMD -MP -MF"gecko_sdk_4.4.5/platform/radio/rail_lib/plugin/rail_util_pti/sl_rail_util_pti.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


