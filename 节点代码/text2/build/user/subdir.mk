#
# Auto-Generated file. Do not edit!
#

# Add inputs and outputs from these tool invocations to the build variables
C_SRCS += \
../user/gpio.c \
../user/BH1750.c \
../user/LED.c \
../user/buzzer.c \
../user/SHT30.c \
../user/MQ_2.c \
../user/ESP8266_01s.c

OBJS += \
./user/gpio.o \
./user/BH1750.o \
./user/LED.o \
./user/buzzer.o \
./user/SHT30.o \
./user/MQ_2.o \
./user/ESP8266_01s.o

C_DEPS += \
./user/gpio.d \
./user/BH1750.d \
./user/LED.d \
./user/buzzer.d \
./user/SHT30.d \
./user/MQ_2.d \
./user/ESP8266_01s.d

# Each subdirectory must supply rules for building sources it contributes
user/%.o: ../user/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: LoongArch32 ELF C Compiler'
	D:/LoongIDE/la32-tool/bin/loongarch32-newlib-elf-gcc.exe -mabi=ilp32s -march=loongarch32 -G0 -DLS1C102 -DBSP_USE_RTC -std=gnu99 -ffunction-sections -fdata-sections -msoft-float -fsched-pressure  -O2 -fno-builtin -g -Wall -c -fmessage-length=0 -pipe -I"../" -I"../include" -I"../include" -I"../drivers/include" -I"../drivers/private/ls1c102" -I"../drivers/public" -I"../system" -I"../src/rtc" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

