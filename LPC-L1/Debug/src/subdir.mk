################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/INFO2_LIB.c \
../src/cr_startup_lpc175x_6x.c \
../src/crp.c \
../src/inicializar.c \
../src/mEST.c 

OBJS += \
./src/INFO2_LIB.o \
./src/cr_startup_lpc175x_6x.o \
./src/crp.o \
./src/inicializar.o \
./src/mEST.o 

C_DEPS += \
./src/INFO2_LIB.d \
./src/cr_startup_lpc175x_6x.d \
./src/crp.d \
./src/inicializar.d \
./src/mEST.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DDEBUG -D__CODE_RED -DCORE_M3 -D__LPC17XX__ -D__REDLIB__ -I"/home/ezequiel/LPCXpresso/workspace/LPC-L1/inc" -include"/home/ezequiel/LPCXpresso/workspace/LPC-L1/inc/abc_base.h" -include"/home/ezequiel/LPCXpresso/workspace/LPC-L1/inc/abc_io_map.h" -include"/home/ezequiel/LPCXpresso/workspace/LPC-L1/inc/abc_timer.h" -include"/home/ezequiel/LPCXpresso/workspace/LPC-L1/inc/lpc_types.h" -include"/home/ezequiel/LPCXpresso/workspace/LPC-L1/inc/registros.h" -include"/home/ezequiel/LPCXpresso/workspace/LPC-L1/inc/xyz_base.h" -include"/home/ezequiel/LPCXpresso/workspace/LPC-L1/inc/xyz_io.h" -include"/home/ezequiel/LPCXpresso/workspace/LPC-L1/inc/xyz_timer.h" -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m3 -mthumb -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


