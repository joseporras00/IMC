################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../imc/MultilayerPerceptron.cpp 

OBJS += \
./imc/MultilayerPerceptron.o 

CPP_DEPS += \
./imc/MultilayerPerceptron.d 


# Each subdirectory must supply rules for building sources it contributes
imc/%.o: ../imc/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


