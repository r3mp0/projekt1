#include "Pomieszczenie.h"
#include "Symulacja.h"
#include "Grzejnik.h"
#include "PID.h"
#include "Dwustawny.h"

int main() {
    Pomieszczenie pokoj(5.0, 4.0, 3.0);
    Grzejnik grzejnik;

    PID pid(&pokoj, &grzejnik, 22.0, 30.0, 0.1, 0.5);
    Dwustawny dwustawny(&pokoj, &grzejnik, 22.0);

    Symulacja s(pokoj, grzejnik);

    s.ustawRegulator(&pid);

    s.przebieg(20, 1.0);
    s.zapisWynikow("wyniki.csv");

    return 0;
}