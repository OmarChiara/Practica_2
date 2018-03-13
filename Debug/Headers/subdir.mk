################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Headers/BCD.c \
../Headers/Debounce.c \
../Headers/GPIO.c \
../Headers/LED_INDICATOR.c \
../Headers/Mode.c \
../Headers/adc.c 

OBJS += \
./Headers/BCD.o \
./Headers/Debounce.o \
./Headers/GPIO.o \
./Headers/LED_INDICATOR.o \
./Headers/Mode.o \
./Headers/adc.o 

C_DEPS += \
./Headers/BCD.d \
./Headers/Debounce.d \
./Headers/GPIO.d \
./Headers/LED_INDICATOR.d \
./Headers/Mode.d \
./Headers/adc.d 


# Each subdirectory must supply rules for building sources it contributes
Headers/%.o: ../Headers/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DPRINTF_FLOAT_ENABLE=0 -D__USE_CMSIS -DCR_INTEGER_PRINTF -DSDK_DEBUGCONSOLE=0 -D__MCUXPRESSO -DDEBUG -DCPU_MKL25Z128VLK4 -DCPU_MKL25Z128VLK4_cm0plus -I"C:\Users\RicardoEmilio\git\Practica_2\board" -I"C:\Users\RicardoEmilio\git\Practica_2\source" -I"C:\Users\RicardoEmilio\git\Practica_2" -I"C:\Users\RicardoEmilio\git\Practica_2\Headers" -I"C:\Users\RicardoEmilio\git\Practica_2\drivers" -I"C:\Users\RicardoEmilio\git\Practica_2\utilities" -I"C:\Users\RicardoEmilio\git\Practica_2\startup" -I"C:\Users\RicardoEmilio\git\Practica_2\CMSIS" -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m0plus -mthumb -D__REDLIB__ -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


