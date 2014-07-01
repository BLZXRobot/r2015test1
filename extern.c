#include "extern.h"

void test()
{
    SetMotor(2, 127);
    SetMotor(3, -127);
    SetMotor(6, 127);
    SetMotor(7, -127);
    Wait(1000);
}

void print_debug_inf_before_launch()
{
      Wait ( 500 ) ;
      PrintToScreen ( "\nVEX Debugger Utility\nby James Swineson\n\nStarting...\n" ) ;
    PrintToScreen("Now you can switch to graphic display.\n");
    ResetGD ( ) ;
}

void prepare_gd()
{
    PrintTextToGD ( 0 , 0 , 0 , "VEX Debugger Utility\n" ) ;
    PrintTextToGD ( 1 , 0 , 0 , "by James Swineson\n" ) ;
    PrintFrameToGD ( 1 , 1 , 6 , 20 , 0 ) ; // print frame
    PrintFrameToGD ( 8 , 1 , 11 , 31 , 0 ) ; // print frame
    PrintFrameToGD ( 14 , 1 , 17 , 51 , 0 ) ; // print frame
    PrintFrameToGD ( 19 , 1 , 21 , 52 , 0 ) ; // print frame
}

void print_gd_debug_inf()
{
      int i;
      int ja[4] = {0, 0, 0, 0}; // joystick analog 1-4
      unsigned char j5[2] = {0, 0}; // u, d
      unsigned char j6[2] = {0, 0}; // u, d
      unsigned char j7[4] = {0, 0, 0, 0}; // u, d, l, r
      unsigned char j8[4] = {0, 0, 0, 0}; // u, d, l, r
      int j_accelerometer[2] = {0, 0}; // x, y
      
      for(i = 0; i < 4; i++){ja[i] = GetJoystickAnalog( 1 , i+1 ) ;}
      j5[0] = GetJoystickDigital ( 1 , 5 , 2 ) ;
      j5[1] = GetJoystickDigital ( 1 , 5 , 1 ) ;
      j6[0] = GetJoystickDigital ( 1 , 6 , 2 ) ;
      j6[1] = GetJoystickDigital ( 1 , 6 , 1 ) ;
      j7[0] = GetJoystickDigital ( 1 , 7 , 2 ) ;
      j7[1] = GetJoystickDigital ( 1 , 7 , 1 ) ;
      j7[2] = GetJoystickDigital ( 1 , 7 , 3 ) ;
      j7[3] = GetJoystickDigital ( 1 , 7 , 4 ) ;
      j8[0] = GetJoystickDigital ( 1 , 8 , 2 ) ;
      j8[1] = GetJoystickDigital ( 1 , 8 , 1 ) ;
      j8[2] = GetJoystickDigital ( 1 , 8 , 3 ) ;
      j8[3] = GetJoystickDigital ( 1 , 8 , 4 ) ;
      j_accelerometer[0] = GetJoystickAccelerometer( 1 , 1 ) ;
      j_accelerometer[1] = GetJoystickAccelerometer( 1 , 2 ) ;
      PrintTextToGD ( 2 , 3 , 8388608 , "Channel 1 = %4d\n" , ja[0] ) ;
      PrintTextToGD ( 3 , 3 , 8388608 , "Channel 2 = %4d\n" , ja[1] ) ;
      PrintTextToGD ( 4 , 3 , 8388608 , "Channel 3 = %4d\n" , ja[2] ) ;
      PrintTextToGD ( 5 , 3 , 8388608 , "Channel 4 = %4d\n" , ja[3] ) ;
      PrintTextToGD ( 9 , 3 , 16384 , "Channel 5: Up = %d; Down = %d\n" , j5[0], j5[1] ) ;
      PrintTextToGD ( 10 , 3 , 16384 , "Channel 6: Up = %d; Down = %d\n" , j6[0], j6[1] ) ;
      PrintTextToGD ( 15 , 3 , 16744448 , "Channel 7: Up = %d; Down = %d; Left = %d; Right = %d\n" , j7[0], j7[1], j7[2], j7[3] ) ;
      PrintTextToGD ( 16 , 3 , 16744448 , "Channel 8: Up = %d; Down = %d; Left = %d; Right = %d\n" , j8[0], j8[1], j8[2], j8[3] ) ;
      PrintTextToGD ( 20 , 3 , 255 , "Gamepad Accelerometer: AxisX = %4d; AxisY = %4d\n" , j_accelerometer[0], j_accelerometer[1] ) ;


}

void main_process()
{
    print_debug_inf_before_launch();
    DefineRobotMotors(2, 1, 3, 2, 7, 6, 0, 0, 0, 0);
    StartTimer(6);
    while(1) // main loop(joystick)
    {
        PresetTimer(6, 0);
        prepare_gd();
        print_gd_debug_inf();
        Arcade4(1, 3, 1, 3, 2, 7, 6, 0, 0, 0, 0);
        JoystickDigitalToMotorAndLimit(1, 5, 1, 127, 0, 2, -127, 0, 8);
        JoystickDigitalToMotorAndLimit(1, 5, 1, -127, 0, 2, 127, 0, 9);
        JoystickDigitalToMotorAndLimit(1, 6, 1, -127, 0, 2, 127, 0, 4);
        JoystickDigitalToMotorAndLimit(1, 7, 1, -127, 0, 2, 127, 0, 5);
        PrintTextToGD ( 22 , 3 , 0 , "Loop time: %4d\n" , GetTimer(6) ) ;
    }
}

