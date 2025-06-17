#pragma once
#include "Regulator.h"

class PID : public Regulator
{
private:
    float Kp, Ki, Kd;
    float uchybPoprzedni;
    float uchybCalka;

public:
    PID(Pomieszczenie* p, Grzejnik* g, float tZadana, float kp, float ki, float kd)
        : Regulator(p, g, tZadana), Kp(kp), Ki(ki), Kd(kd), uchybPoprzedni(0.0f), uchybCalka(0.0f) {
    }

    float steruj(float dT);
};
