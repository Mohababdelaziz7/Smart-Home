################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../CLCD_2/HAL/SSD/SSD_program.c 

OBJS += \
./CLCD_2/HAL/SSD/SSD_program.o 

C_DEPS += \
./CLCD_2/HAL/SSD/SSD_program.d 


# Each subdirectory must supply rules for building sources it contributes
CLCD_2/HAL/SSD/%.o: ../CLCD_2/HAL/SSD/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


