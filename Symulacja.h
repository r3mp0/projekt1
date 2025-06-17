#pragma once
#include <vector>
#include "Pomieszczenie.h"
#include "Grzejnik.h"
#include "Regulator.h"
using namespace std;

class Symulacja
{
private:
    Pomieszczenie* pokoj;
    Grzejnik* grzejnik;
    Regulator* regulator;
    vector<float> czasy;
    vector<float> temperatury;
    vector<float> moceGrzejnika;
  

public:
    Symulacja(Pomieszczenie& p, Grzejnik& g);
    void ustawRegulator(Regulator* reg);
    void iteracja(float dt);
    void przebieg(int liczbaIteracji, float dt);
    void zapisWynikow(const char* nazwaPliku) const;
};
