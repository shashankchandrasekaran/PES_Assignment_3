################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../source/BLINKINGLIGHTS.c \
../source/DELAY.c \
../source/LED_ON_OFF.c \
../source/STARTUP_INF.c \
../source/TSI.c \
../source/mtb.c \
../source/semihost_hardfault.c 

C_DEPS += \
./source/BLINKINGLIGHTS.d \
./source/DELAY.d \
./source/LED_ON_OFF.d \
./source/STARTUP_INF.d \
./source/TSI.d \
./source/mtb.d \
./source/semihost_hardfault.d 

OBJS += \
./source/BLINKINGLIGHTS.o \
./source/DELAY.o \
./source/LED_ON_OFF.o \
./source/STARTUP_INF.o \
./source/TSI.o \
./source/mtb.o \
./source/semihost_hardfault.o 


# Each subdirectory must supply rules for building sources it contributes
source/%.o: ../source/%.c source/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DCPU_MKL25Z128VLK4 -DCPU_MKL25Z128VLK4_cm0plus -DFSL_RTOS_BM -DSDK_OS_BAREMETAL -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -D__MCUXPRESSO -D__USE_CMSIS -DNDEBUG -D__REDLIB__ -DSDK_DEBUGCONSOLE=0 -I"C:\Users\Shashank C\Documents\MCUXpressoIDE_11.6.0_8187\workspace\PES_Assignment_3\board" -I"C:\Users\Shashank C\Documents\MCUXpressoIDE_11.6.0_8187\workspace\PES_Assignment_3\source" -I"C:\Users\Shashank C\Documents\MCUXpressoIDE_11.6.0_8187\workspace\PES_Assignment_3" -I"C:\Users\Shashank C\Documents\MCUXpressoIDE_11.6.0_8187\workspace\PES_Assignment_3\drivers" -I"C:\Users\Shashank C\Documents\MCUXpressoIDE_11.6.0_8187\workspace\PES_Assignment_3\CMSIS" -I"C:\Users\Shashank C\Documents\MCUXpressoIDE_11.6.0_8187\workspace\PES_Assignment_3\utilities" -I"C:\Users\Shashank C\Documents\MCUXpressoIDE_11.6.0_8187\workspace\PES_Assignment_3\startup" -O0 -fno-common -g -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m0plus -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-source

clean-source:
	-$(RM) ./source/BLINKINGLIGHTS.d ./source/BLINKINGLIGHTS.o ./source/DELAY.d ./source/DELAY.o ./source/LED_ON_OFF.d ./source/LED_ON_OFF.o ./source/STARTUP_INF.d ./source/STARTUP_INF.o ./source/TSI.d ./source/TSI.o ./source/mtb.d ./source/mtb.o ./source/semihost_hardfault.d ./source/semihost_hardfault.o

.PHONY: clean-source

