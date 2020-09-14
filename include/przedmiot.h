#ifndef PRZEDMIOT_H
#define PRZEDMIOT_H
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <iostream>

class przedmiot
{
    friend class swiat;
    public:
        przedmiot();
        virtual ~przedmiot();
        int maks_w_plecaczku;
        int x;
        int y;
        int miejsce_odstepu;
    protected:

    private:
};

#endif // PRZEDMIOT_H
