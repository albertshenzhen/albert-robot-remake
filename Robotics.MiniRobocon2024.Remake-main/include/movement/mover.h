#pragma once

#include <Arduino.h>
class Mover {
private:
    int _A1;
    int _A2;
    int _PWM;
    int _v_PWM;
public:
    Mover(const int A1, const int A2, const int PWM);
    Mover(const int A1, const int A2, const int PWM,int v_PWM);
    void sets(int v_PWM);
    void move(int v_PWM);
};