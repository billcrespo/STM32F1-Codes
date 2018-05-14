################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include startup/subdir.mk
-include src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: Timer\ Externo.elf

dependents:
	-cd C:/Users/Bill/workspace/stm32f103c8t6_hal_lib/Debug && $(MAKE) clean all

# Tool invocations
Timer\ Externo.elf: $(OBJS) $(USER_OBJS) C:/Users/Bill/workspace/stm32f103c8t6_hal_lib/Debug/libstm32f103c8t6_hal_lib.a C:\Users\Bill\workspace\Timer\ Externo\LinkerScript.ld
	@echo 'Building target: $@'
	@echo 'Invoking: MCU GCC Linker'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -mfloat-abi=soft -L"C:\Users\Bill\workspace\stm32f103c8t6_hal_lib\Debug" -T"C:\Users\Bill\workspace\Timer Externo\LinkerScript.ld" -Wl,-Map=output.map -Wl,--gc-sections -o "Timer Externo.elf" @"objects.list" $(USER_OBJS) $(LIBS) -lm
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

post-build:
	-@echo 'Generating binary and Printing size information:'
	arm-none-eabi-objcopy -O binary "Timer Externo.elf" "Timer Externo.bin"
	arm-none-eabi-size "Timer Externo.elf"
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY: post-build
C:/Users/Bill/workspace/stm32f103c8t6_hal_lib/Debug/libstm32f103c8t6_hal_lib.a:

-include ../makefile.targets
