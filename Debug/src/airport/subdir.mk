################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/airport/Edge.cpp \
../src/airport/Graph.cpp \
../src/airport/GraphElementsMaps.cpp \
../src/airport/Path.cpp \
../src/airport/Planner.cpp \
../src/airport/Road.cpp \
../src/airport/Roads.cpp \
../src/airport/Section.cpp \
../src/airport/Step.cpp \
../src/airport/Vertex.cpp 

OBJS += \
./src/airport/Edge.o \
./src/airport/Graph.o \
./src/airport/GraphElementsMaps.o \
./src/airport/Path.o \
./src/airport/Planner.o \
./src/airport/Road.o \
./src/airport/Roads.o \
./src/airport/Section.o \
./src/airport/Step.o \
./src/airport/Vertex.o 

CPP_DEPS += \
./src/airport/Edge.d \
./src/airport/Graph.d \
./src/airport/GraphElementsMaps.d \
./src/airport/Path.d \
./src/airport/Planner.d \
./src/airport/Road.d \
./src/airport/Roads.d \
./src/airport/Section.d \
./src/airport/Step.d \
./src/airport/Vertex.d 


# Each subdirectory must supply rules for building sources it contributes
src/airport/%.o: ../src/airport/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/opt/boost -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


