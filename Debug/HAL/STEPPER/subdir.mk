################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/STEPPER/STEPPER_PROGRAM.c 

OBJS += \
./HAL/STEPPER/STEPPER_PROGRAM.o 

C_DEPS += \
./HAL/STEPPER/STEPPER_PROGRAM.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/STEPPER/%.o: ../HAL/STEPPER/%.c HAL/STEPPER/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


