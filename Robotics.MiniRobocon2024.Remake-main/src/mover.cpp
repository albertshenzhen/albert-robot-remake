#include "movement/mover.h"

Mover::Mover(const int A1, const int A2, const int PWM) : _A1(A1), _A2(A2), _PWM(PWM){
    pinMode(_A1, OUTPUT);
    pinMode(_A2, OUTPUT);
    pinMode(_PWM, INPUT);
};

Mover::Mover(const int A1, const int A2, const int PWM, int v_PWM) : _A1(A1), _A2(A2), _PWM(PWM), _v_PWM(v_PWM){
    pinMode(_A1, OUTPUT);
    pinMode(_A2, OUTPUT);
    pinMode(_PWM, INPUT);
    v_PWM = _v_PWM;
};

void Mover::sets(int v_PWM){
    _v_PWM = v_PWM;
}

void Mover::move(int v_PWM){
    if (v_PWM > 0){
        _v_PWM = v_PWM;
        digitalWrite(_A1, HIGH);
        digitalWrite(_A2, LOW);
        analogWrite(_PWM, _v_PWM);
    }
    else if (v_PWM < 0){
        _v_PWM = -v_PWM;
        digitalWrite(_A1, LOW);
        digitalWrite(_A2, HIGH);
        analogWrite(_PWM, _v_PWM);
    }
    else if (v_PWM == 0)
    {
        digitalWrite(_A1, LOW);
        digitalWrite(_A2, LOW);
        analogWrite(_PWM, 0);
    }
}