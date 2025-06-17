#include "Symulacja.h"
#include <fstream>
#include <iostream>

using namespace std;

Symulacja::Symulacja(Pomieszczenie& p, Grzejnik& g)
    : pokoj(&p), grzejnik(&g), regulator(nullptr)
{
    czasy.push_back(0.0f);
    temperatury.push_back(p.getTemperatura());
    moceGrzejnika.push_back(grzejnik->pobierzMoc());
}

void Symulacja::ustawRegulator(Regulator* reg)
{
    regulator = reg;
}

void Symulacja::iteracja(float dt)
{
    if (regulator != nullptr)
    {
        float moc = regulator->steruj(dt);

        // Zak³adamy, ¿e PID zwraca moc w watach, wiêc normalizujemy j¹:
        moc /= grzejnik->pobierzMocMaksymalna();

        // Przycinamy moc do [0..1]
        if (moc < 0.0f) moc = 0.0f;
        if (moc > 1.0f) moc = 1.0f;

        grzejnik->ustawMoc(moc);
    }
    else
    {
        grzejnik->ustawMoc(0.0f);
    }

    float cieplo = grzejnik->emitujCieplo(dt);
    pokoj->dodajCieplo(cieplo);
    pokoj->aktualizuj(dt);
}

void Symulacja::przebieg(int liczbaIteracji, float dt)
{
    for (int i = 1; i <= liczbaIteracji; ++i)
    {
        iteracja(dt);
        czasy.push_back(i * dt);
        temperatury.push_back(pokoj->getTemperatura());
        moceGrzejnika.push_back(grzejnik->pobierzMoc());
        cout << "Iteracja " << i << ": czas = " << i * dt << " s, temperatura = " << pokoj->getTemperatura() << " C\n";
    }
}

void Symulacja::zapisWynikow(const char* nazwaPliku) const
{
    ofstream plik(nazwaPliku);
    locale pol("pl_PL.UTF-8");
    plik.imbue(pol);

    plik << "Iteracja;Czas [s];Temperatura [st C];Moc grzejnika [0-1]\n";

    for (size_t i = 0; i < czasy.size(); ++i)
    {
        plik << i << ";" << czasy[i] << ";" << temperatury[i] << ";" << moceGrzejnika[i] << "\n";
    }
}
