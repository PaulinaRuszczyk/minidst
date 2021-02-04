#ifndef OBIEKTY_H
#define OBIEKTY_H
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include "swiat.h"
#include "postac.h"
//#include "przeciwnik.h"
class obiekty
{


    public:
    friend class przeciwnik;

    sf::Sprite duch;
    sf::Texture tekstura;
    std::vector <sf::Sprite> duszek;
    int ilosc_wszystkich;
    obiekty(std::string nazwa_pliku,int numer_biomu, int liczba_przedmiotow, int wielkosc_x, int wielkosc_y, swiat s, int wielkoscx, int wielkoscy,const int *kafelki, int wielkosc_macierzy);
    obiekty(std::string nazwa_pliku);
    void rysowanie ( sf::RenderWindow &okno);
    virtual ~obiekty();

    protected:

    private:
};

#endif // OBIEKTY_H
