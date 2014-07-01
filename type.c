// type.c : implementation file
#include "type.h"

void readAllAnalogInput(){
int i;
for (i = 0; i < ANALOG_PORT_NUM; i++){
analog_input[i] = GetAnalogInput(i+1);
}
}

void readAllDigitalInput(){
int i;
for (i = 0; i < DIGITAL_PORT_NUM; i++){
digital_input[i] = GetDigitalInput(i+1);
}
}

void setAllMotor(){
int i;
for (i = 0; i < MOTOR_PORT_NUM; i++){
SetMotor(i+1, motor_value[i]);
}
}

void syncBeforeLoop(){
readAllAnalogInput();
readAllDigitalInput();
}

void syncAfterLoop(){
setAllMotor();
}
