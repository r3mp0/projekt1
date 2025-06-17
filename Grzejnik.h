#pragma once

class Grzejnik
{
private:
    float mocMaksymalna;
    float mocAktualna;

public:
    Grzejnik(float mocMax = 1000.0) : mocMaksymalna(mocMax), mocAktualna(0.0) {}
    void ustawMoc(float nowaMoc);
    float pobierzMoc();
    float emitujCieplo(float dt);
    float pobierzMocMaksymalna();
};