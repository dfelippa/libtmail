################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/tlib/md5.cpp \
../src/tlib/tlibdata.cpp \
../src/tlib/tlibos.cpp \
../src/tlib/tlibptr.cpp \
../src/tlib/tlibstr.cpp \
../src/tlib/tlibtime.cpp 

OBJS += \
./src/tlib/md5.o \
./src/tlib/tlibdata.o \
./src/tlib/tlibos.o \
./src/tlib/tlibptr.o \
./src/tlib/tlibstr.o \
./src/tlib/tlibtime.o 

CPP_DEPS += \
./src/tlib/md5.d \
./src/tlib/tlibdata.d \
./src/tlib/tlibos.d \
./src/tlib/tlibptr.d \
./src/tlib/tlibstr.d \
./src/tlib/tlibtime.d 


# Each subdirectory must supply rules for building sources it contributes
src/tlib/%.o: ../src/tlib/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O3 -Wall -c -fmessage-length=0 `pkg-config --cflags glib-2.0` `pkg-config --cflags sigc++-2.0` -fPIC -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


