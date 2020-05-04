#ifndef JEDZENIE_H
#define JEDZENIE_H


class jedzenie
{
    public:
        jedzenie();
        virtual ~jedzenie();
    protected:

    private:
        int zaspokajanie_glodku;
        int ilosc_psychiki;
        int ilosc_zdrowia;
        int trwalosc;
        int maks_w_plecaczku;
};

#endif // JEDZENIE_H
