/*
  MecanumWheel.cpp - source code of the library definying the basic
  movements of the Mecanum Omni Direction Wheel Robot Car
  by osoyoo (https://osoyoo.com/?p=43404).
  Created by M. Bonfanti, Feb 11, 2023.
*/

#include "Arduino.h"
#include "MecanumWheel.h"

/*
  Functions are named according to the following rules:
  XX is a code that defines the wheel position:
    fl -> front left   fr -> front right
    rl -> rear left    rr -> rear right
    
  Pin numbers are stored in an array in the following order:
    0  | pin_rr_speed
    1  | pin_rr_dir1
    2  | pin_rr_dir2
    3  | pin_rl_speed
    4  | pin_rl_dir1
    5  | pin_rl_dir2
    6  | pin_fr_speed
    7  | pin_fr_dir1
    8  | pin_fr_dir2
    9  | pin_fl_speed
    10 | pin_fl_dir1
    11 | pin_fl_dir2
*/

MecanumWheel::MecanumWheel( int pins[12] )
{
    // store the definitions of the pin numbers
    for (byte i = 0; i < 12; i = i + 1) {
        _pins[i] = pins[i];
    }

    // initialize the pins
    for (byte i = 0; i < 12; i = i + 1) {
        pinMode(pins[i], OUTPUT);
    }

    // set initial speed to 0 for all the wheels
    analogWrite(_pins[0], 0);  
    analogWrite(_pins[3], 0);  
    analogWrite(_pins[6], 0);  
    analogWrite(_pins[9], 0);  
}

// *******************************************************
// INDEPENDENT MOVEMENTS OF THE WHEELS (private functions)
// *******************************************************

// REAR RIGHT WHEEL - PINS 0, 1, 2

void MecanumWheel::rr_fwd(int speed)
{
    digitalWrite(_pins[1], HIGH);
    digitalWrite(_pins[2], LOW);
    analogWrite(_pins[0], speed);  
}

void MecanumWheel::rr_bck(int speed)
{
    digitalWrite(_pins[1], LOW);
    digitalWrite(_pins[2], HIGH);
    analogWrite(_pins[0], speed);  
}

// REAR LEFT WHEEL - PINS 3, 4, 5

void MecanumWheel::rl_fwd(int speed)
{
    digitalWrite(_pins[4], HIGH);
    digitalWrite(_pins[5], LOW);
    analogWrite(_pins[3], speed);  
}

void MecanumWheel::rl_bck(int speed)
{
    digitalWrite(_pins[4], LOW);
    digitalWrite(_pins[5], HIGH);
    analogWrite(_pins[3], speed);  
}

// FRONT RIGHT WHEEL - PINS 6, 7, 8

void MecanumWheel::fr_fwd(int speed)
{
    digitalWrite(_pins[7], HIGH);
    digitalWrite(_pins[8], LOW);
    analogWrite(_pins[6], speed);  
}

void MecanumWheel::fr_bck(int speed)
{
    digitalWrite(_pins[7], LOW);
    digitalWrite(_pins[8], HIGH);
    analogWrite(_pins[6], speed);  
}

// FRONT LEFT WHEEL - PINS 9, 10, 11

void MecanumWheel::fl_fwd(int speed)
{
    digitalWrite(_pins[10], HIGH);
    digitalWrite(_pins[11], LOW);
    analogWrite(_pins[9], speed);  
}

void MecanumWheel::fl_bck(int speed)
{
    digitalWrite(_pins[10], LOW);
    digitalWrite(_pins[11], HIGH);
    analogWrite(_pins[9], speed);  
}

// *******************************************************
//       MOVEMENTS OF THE CAR (public functions)
// *******************************************************

void MecanumWheel::stop()
{
    analogWrite(_pins[0], 0);  
    analogWrite(_pins[3], 0);  
    analogWrite(_pins[6], 0);  
    analogWrite(_pins[9], 0);  
}

void MecanumWheel::go_forward(int speed, unsigned time)
{
    rl_fwd(speed);
    rr_fwd(speed);
    fr_fwd(speed);
    fl_fwd(speed); 
    delay(time);
    stop();
}

void MecanumWheel::go_backward(int speed, unsigned time)
{
    rl_bck(speed);
    rr_bck(speed);
    fr_bck(speed);
    fl_bck(speed);
    delay(time);
    stop();
}

void MecanumWheel::turn_left(int speed, unsigned time)
{
    rl_bck(0);
    rr_fwd(speed);
    fr_fwd(speed);
    fl_bck(0);
    delay(time);
    stop();
}

void MecanumWheel::turn_right(int speed, unsigned time)
{
    rl_fwd(speed);
    rr_fwd(0);
    fr_fwd(0);
    fl_fwd(speed);
    delay(time);
    stop();
}

void MecanumWheel::turn_left_back(int speed, unsigned time)
{
    rl_fwd(0);
    rr_bck(speed);
    fr_bck(speed);
    fl_fwd(0);
    delay(time);
    stop();
}

void MecanumWheel::turn_right_back(int speed, unsigned time)
{
    rl_bck(speed);
    rr_fwd(0);
    fr_fwd(0);
    fl_bck(speed);
    delay(time);
    stop();
}

void MecanumWheel::rotate_clockwise(int speed, unsigned time)
{
    rl_fwd(speed);
    rr_bck(speed);
    fr_bck(speed);
    fl_fwd(speed);
    delay(time);
    stop();
}

void MecanumWheel::rotate_countclockwise(int speed, unsigned time)
{
    rl_bck(speed);
    rr_fwd(speed);
    fr_fwd(speed);
    fl_bck(speed);
    delay(time);
    stop();
}

void MecanumWheel::shift_right(int speed_fl_fwd, int speed_rl_bck, int speed_rr_fwd, int speed_fr_bck, unsigned time)
{
    fl_fwd(speed_fl_fwd); 
    rl_bck(speed_rl_bck); 
    rr_fwd(speed_rr_fwd);
    fr_bck(speed_fr_bck);
    delay(time);
    stop();
}

void MecanumWheel::shift_left(int speed_fl_bck, int speed_rl_fwd, int speed_rr_bck, int speed_fr_fwd, unsigned time)
{
    fl_bck(speed_fl_bck);
    rl_fwd(speed_rl_fwd);
    rr_bck(speed_rr_bck);
    fr_fwd(speed_fr_fwd);
    delay(time);
    stop();
}


