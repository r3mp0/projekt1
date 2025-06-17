#pragma once
#include "Pomieszczenie.h"
#include "Grzejnik.h"

class Regulator
{
protected:
    Pomieszczenie* pokoj;
    Grzejnik* grzejnik;
    float tempZadana;

public:
    Regulator(Pomieszczenie* p, Grzejnik* g, float tZad)
        : pokoj(p), grzejnik(g), tempZadana(tZad) {
    }

    virtual ~Regulator() {}

    virtual float steruj(float dt) = 0; // metoda czysto wirtualna
};
