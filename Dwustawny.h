#pragma once
#include "Regulator.h"

class Dwustawny : public Regulator
{
public:
    Dwustawny(Pomieszczenie* p, Grzejnik* g, float tZad)
        : Regulator(p, g, tZad) {
    }

    float steruj(float dT)
    {
        if (pokoj->getTemperatura() < tempZadana)
            return 1.0f;  // moc maksymalna, czyli 100%
        else
            return 0.0f;  // wy³¹czony
    }
};
