################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../source/Practica_2.c \
../source/mtb.c \
../source/semihost_hardfault.c 

OBJS += \
./source/Practica_2.o \
./source/mtb.o \
./source/semihost_hardfault.o 

C_DEPS += \
./source/Practica_2.d \
./source/mtb.d \
./source/semihost_hardfault.d 


# Each subdirectory must supply rules for building sources it contributes
source/%.o: ../source/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DPRINTF_FLOAT_ENABLE=0 -D__USE_CMSIS -DCR_INTEGER_PRINTF -DSDK_DEBUGCONSOLE=0 -D__MCUXPRESSO -DDEBUG -DCPU_MKL25Z128VLK4 -DCPU_MKL25Z128VLK4_cm0plus -I"C:\Users\Misael\Documents\MCUXpressoIDE_10.1.1_606\workspace\Try1\Practica_2\board" -I"C:\Users\Misael\Documents\MCUXpressoIDE_10.1.1_606\workspace\Try1\Practica_2\source" -I"C:\Users\Misael\Documents\MCUXpressoIDE_10.1.1_606\workspace\Try1\Practica_2" -I"C:\Users\Misael\Documents\MCUXpressoIDE_10.1.1_606\workspace\Try1\Practica_2\drivers" -I"C:\Users\Misael\Documents\MCUXpressoIDE_10.1.1_606\workspace\Try1\Practica_2\utilities" -I"C:\Users\Misael\Documents\MCUXpressoIDE_10.1.1_606\workspace\Try1\Practica_2\startup" -I"C:\Users\Misael\Documents\MCUXpressoIDE_10.1.1_606\workspace\Try1\Practica_2\CMSIS" -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m0plus -mthumb -D__REDLIB__ -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


