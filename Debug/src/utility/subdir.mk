################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/utility/Geometry.cpp 

OBJS += \
./src/utility/Geometry.o 

CPP_DEPS += \
./src/utility/Geometry.d 


# Each subdirectory must supply rules for building sources it contributes
src/utility/%.o: ../src/utility/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/opt/boost -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


