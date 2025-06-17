#include "Grzejnik.h"

void Grzejnik::ustawMoc(float nowaMoc)
{
    if (nowaMoc < 0.0) nowaMoc = 0.0;
    if (nowaMoc > 1.0) nowaMoc = 1.0;
    mocAktualna = nowaMoc;
}


float Grzejnik::pobierzMoc()
{ 
    return mocAktualna; 
}

float Grzejnik::emitujCieplo(float dt)
{ 
    return mocMaksymalna * mocAktualna * dt; 
}

float Grzejnik::pobierzMocMaksymalna()
{ 
    return mocMaksymalna; 
}