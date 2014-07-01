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

void syncBeforeLoop();
void syncAfterLoop();



typedef struct motor {



} motor;

// =========================================

#endif

