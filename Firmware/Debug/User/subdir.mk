################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../User/control_loop.c \
../User/lcd_hd44780_i2c.c \
../User/thermocouple.c \
../User/ui.c \
../User/user_main.c 

OBJS += \
./User/control_loop.o \
./User/lcd_hd44780_i2c.o \
./User/thermocouple.o \
./User/ui.o \
./User/user_main.o 

C_DEPS += \
./User/control_loop.d \
./User/lcd_hd44780_i2c.d \
./User/thermocouple.d \
./User/ui.d \
./User/user_main.d 


# Each subdirectory must supply rules for building sources it contributes
User/%.o User/%.su User/%.cyclo: ../User/%.c User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L011xx -DUSE_FULL_LL_DRIVER -c -I../Core/Inc -I../User -I../Drivers/STM32L0xx_HAL_Driver/Inc -I../Drivers/STM32L0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L0xx/Include -I../Drivers/CMSIS/Include -Og -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-User

clean-User:
	-$(RM) ./User/control_loop.cyclo ./User/control_loop.d ./User/control_loop.o ./User/control_loop.su ./User/lcd_hd44780_i2c.cyclo ./User/lcd_hd44780_i2c.d ./User/lcd_hd44780_i2c.o ./User/lcd_hd44780_i2c.su ./User/thermocouple.cyclo ./User/thermocouple.d ./User/thermocouple.o ./User/thermocouple.su ./User/ui.cyclo ./User/ui.d ./User/ui.o ./User/ui.su ./User/user_main.cyclo ./User/user_main.d ./User/user_main.o ./User/user_main.su

.PHONY: clean-User

