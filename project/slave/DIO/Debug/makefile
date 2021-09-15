################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include CLCD_2/MCAL/UART/subdir.mk
-include CLCD_2/MCAL/TIM1/subdir.mk
-include CLCD_2/MCAL/TIM0/subdir.mk
-include CLCD_2/MCAL/SPI/subdir.mk
-include CLCD_2/MCAL/GIE/subdir.mk
-include CLCD_2/MCAL/EXTI/subdir.mk
-include CLCD_2/MCAL/DIO/subdir.mk
-include CLCD_2/MCAL/ADC/subdir.mk
-include CLCD_2/HAL/SW/subdir.mk
-include CLCD_2/HAL/SSD/subdir.mk
-include CLCD_2/HAL/LED/subdir.mk
-include CLCD_2/HAL/KBP/subdir.mk
-include CLCD_2/HAL/CLCD_Eng_Hesham/subdir.mk
-include CLCD_2/Debug/MCAL/UART/subdir.mk
-include CLCD_2/Debug/MCAL/TIM1/subdir.mk
-include CLCD_2/Debug/MCAL/TIM0/subdir.mk
-include CLCD_2/Debug/MCAL/SPI/subdir.mk
-include CLCD_2/Debug/MCAL/GIE/subdir.mk
-include CLCD_2/Debug/MCAL/EXTI/subdir.mk
-include CLCD_2/Debug/MCAL/DIO/subdir.mk
-include CLCD_2/Debug/MCAL/ADC/subdir.mk
-include CLCD_2/Debug/HAL/SW/subdir.mk
-include CLCD_2/Debug/HAL/SSD/subdir.mk
-include CLCD_2/Debug/HAL/LED/subdir.mk
-include CLCD_2/Debug/HAL/KBP/subdir.mk
-include CLCD_2/Debug/HAL/CLCD_Eng_Hesham/subdir.mk
-include CLCD_2/Debug/APP/subdir.mk
-include CLCD_2/APP/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
My_First.lss \

FLASH_IMAGE += \
My_First.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: My_First.elf secondary-outputs

# Tool invocations
My_First.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,My_First.map -mmcu=atmega32 -o "My_First.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

My_First.lss: My_First.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S My_First.elf  >"My_First.lss"
	@echo 'Finished building: $@'
	@echo ' '

My_First.hex: My_First.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex My_First.elf  "My_First.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: My_First.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 My_First.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) My_First.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
