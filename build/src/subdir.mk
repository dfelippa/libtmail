################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/address.cpp \
../src/code.cpp \
../src/content.cpp \
../src/header.cpp \
../src/mail.cpp \
../src/pop3.cpp \
../src/protocol.cpp \
../src/smtp.cpp 

OBJS += \
./src/address.o \
./src/code.o \
./src/content.o \
./src/header.o \
./src/mail.o \
./src/pop3.o \
./src/protocol.o \
./src/smtp.o 

CPP_DEPS += \
./src/address.d \
./src/code.d \
./src/content.d \
./src/header.d \
./src/mail.d \
./src/pop3.d \
./src/protocol.d \
./src/smtp.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/include/sigc++-2.0 -I/usr/lib/sigc++-2.0/include -O2 -Wall -c -fmessage-length=0 `pkg-config --cflags glib-2.0` `pkg-config --cflags sigc++-2.0` -fPIC -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


