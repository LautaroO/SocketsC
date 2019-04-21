################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../IniciarServer/LevantarServer.c 

OBJS += \
./IniciarServer/LevantarServer.o 

C_DEPS += \
./IniciarServer/LevantarServer.d 


# Each subdirectory must supply rules for building sources it contributes
IniciarServer/%.o: ../IniciarServer/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


