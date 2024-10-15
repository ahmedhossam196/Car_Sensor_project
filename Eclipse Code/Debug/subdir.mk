################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Buzzer.c \
../GPIO.c \
../ICU.c \
../LCD.c \
../LED.c \
../Ultrasonic.c \
../main.c 

OBJS += \
./Buzzer.o \
./GPIO.o \
./ICU.o \
./LCD.o \
./LED.o \
./Ultrasonic.o \
./main.o 

C_DEPS += \
./Buzzer.d \
./GPIO.d \
./ICU.d \
./LCD.d \
./LED.d \
./Ultrasonic.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


