#ifndef POSTAC_H
#define POSTAC_H


class postac
{
    public:
        postac();
        virtual ~postac();
        int szybkosc_chodzenia;
        int sila;
        int obrona;
        int zycie;
        int mozg;
        int glodek;
        atak();
        oberwanie();
        chwyt_obiektu();
        budowanie();
    protected:

    private:
        glodnienie();
        glupienie();
};

#endif // POSTAC_H
