/*
  MecanumWheel.h - header file of the library definying the basic
  movements of the Mecanum Omni Direction Wheel Robot Car
  by osoyoo (https://osoyoo.com/?p=43404).
  Created by M. Bonfanti, Feb 11, 2023.
*/
#ifndef MecanumWheel_h
#define MecanumWheel_h

#include "Arduino.h"

class MecanumWheel
{
    public:
        MecanumWheel(int pins[12]);
        void stop();
        void go_forward(int speed, unsigned time);
        void go_backward(int speed, unsigned time);
        void turn_left(int speed, unsigned time);
        void turn_right(int speed, unsigned time);
        void turn_left_back(int speed, unsigned time);
        void turn_right_back(int speed, unsigned time);
        void rotate_clockwise(int speed, unsigned time);
        void rotate_countclockwise(int speed, unsigned time);
        void shift_right(int speed_fl_fwd, int speed_rl_bck, int speed_rr_fwd, int speed_fr_bck, unsigned time);
        void shift_left(int speed_fl_bck, int speed_rl_fwd, int speed_rr_bck, int speed_fr_fwd, unsigned time);
    private:
        int _pins[12];
        void rr_fwd(int speed);
        void rr_bck(int speed);
        void rl_fwd(int speed);
        void rl_bck(int speed);
        void fr_fwd(int speed);
        void fr_bck(int speed);
        void fl_fwd(int speed);
        void fl_bck(int speed);
};

#endif



