################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/CLCD_KHALED/CLCD_program.c 

OBJS += \
./HAL/CLCD_KHALED/CLCD_program.o 

C_DEPS += \
./HAL/CLCD_KHALED/CLCD_program.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/CLCD_KHALED/%.o: ../HAL/CLCD_KHALED/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


