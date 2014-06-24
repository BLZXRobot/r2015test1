#include "extern.h"


void test()
{
    SetMotor(2, 127);
    SetMotor(3, -127);
    SetMotor(6, 127);
    SetMotor(7, -127);
    Wait(1000);
}

void main_process()
{
    DefineRobotMotors(2, 1, 3, 2, 7, 6, 0, 0, 0, 0);
    while(1) // main loop(joystick)
    {
        Arcade4(1, 3, 1, 2, 3, 6, 7, 1, 1, 1, 1);
        JoystickDigitalToMotorAndLimit(1, 5, 1, 127, 0, 2, -127, 0, 8);
        JoystickDigitalToMotorAndLimit(1, 5, 1, -127, 0, 2, 127, 0, 9);
        JoystickDigitalToMotorAndLimit(1, 6, 1, -127, 0, 2, 127, 0, 4);
        JoystickDigitalToMotorAndLimit(1, 7, 1, -127, 0, 2, 127, 0, 5);
    }
}
