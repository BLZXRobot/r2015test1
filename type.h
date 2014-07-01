// =========================================
/* type.h
 * 
 * My own typedefs
 *
 */
// =========================================
#include <API.h>

#ifndef TYPE_H
#define TYPE_H

// =========================================
#define MOTOR_PORT_NUM 10
#define ANALOG_PORT_NUM 12
#define DIGITAL_PORT_NUM 8

unsigned char motor_value[MOTOR_PORT_NUM];
unsigned int analog_input[ANALOG_PORT_NUM]; 
unsigned int digital_input[DIGITAL_PORT_NUM];

void readAllAnalogInput(){
var i;
for (i = 0; i < ANALOG_PORT_NUM; i++){
analog_input[i] = GetAnalogInput(i+1);
}
}

void readAllDigitalInput(){
var i;
for (i = 0; i < DIGITAL_PORT_NUM; i++){
digital_input[i] = GetDigitalInput(i+1);
}
}

void setAllMotor(){
var i;
for (i = 0; i < motor_value; i++){
SetMotor(i+1, motor_value[i]);
}
}

typedef struct motor {



} motor;

// =========================================

#endif
