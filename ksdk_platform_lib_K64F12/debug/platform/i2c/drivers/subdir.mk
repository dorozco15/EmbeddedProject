################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Freescale/KSDK_1.3.0/platform/drivers/src/i2c/fsl_i2c_common.c \
C:/Freescale/KSDK_1.3.0/platform/drivers/src/i2c/fsl_i2c_shared_function.c 

OBJS += \
./platform/i2c/drivers/fsl_i2c_common.o \
./platform/i2c/drivers/fsl_i2c_shared_function.o 

C_DEPS += \
./platform/i2c/drivers/fsl_i2c_common.d \
./platform/i2c/drivers/fsl_i2c_shared_function.d 


# Each subdirectory must supply rules for building sources it contributes
platform/i2c/drivers/fsl_i2c_common.o: C:/Freescale/KSDK_1.3.0/platform/drivers/src/i2c/fsl_i2c_common.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall  -g -DDEBUG -DCPU_MK64FN1M0VMD12 -I../../../../../platform/CMSIS/Include -I../../../../../platform/devices -I../../../../../platform/devices/MK64F12/include -I../../../../../platform/devices/MK64F12/startup -I../../../../../platform/utilities/inc -I../../../../../platform/hal/inc -I../../../../../platform/drivers/inc -I../../../../../platform/system/inc -I../../../../../platform/osa/inc -std=gnu99 -fno-common  -ffreestanding  -fno-builtin  -mapcs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

platform/i2c/drivers/fsl_i2c_shared_function.o: C:/Freescale/KSDK_1.3.0/platform/drivers/src/i2c/fsl_i2c_shared_function.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall  -g -DDEBUG -DCPU_MK64FN1M0VMD12 -I../../../../../platform/CMSIS/Include -I../../../../../platform/devices -I../../../../../platform/devices/MK64F12/include -I../../../../../platform/devices/MK64F12/startup -I../../../../../platform/utilities/inc -I../../../../../platform/hal/inc -I../../../../../platform/drivers/inc -I../../../../../platform/system/inc -I../../../../../platform/osa/inc -std=gnu99 -fno-common  -ffreestanding  -fno-builtin  -mapcs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


