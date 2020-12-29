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
        obiekty(std::string nazwa_pliku,int numer_biomu, int liczba_przedmiotow, int wielkosc_x, int wielkosc_y, swiat s, int wielkoscx, int wielkoscy,const int *kafelki, int wielkosc_macierzy)
        {
            bool ok=true;
            srand(time(NULL));
                if(!tekstura.loadFromFile(nazwa_pliku))
                    std::cout<<"DUPA";
                int polozenie_x, polozenie_y;
                int pom1, pom2;
                for(int i=0; i<liczba_przedmiotow; i++)
                {
                     do{
                        polozenie_x=rand()%s.rozmiar_mapy.x;
                        polozenie_y=rand()%s.rozmiar_mapy.y;
                        pom1=polozenie_x/wielkoscx;
                        pom2=polozenie_y/wielkoscy;
                    }while(kafelki[pom1+wielkosc_macierzy*pom2]!=numer_biomu);
                    this->duch.setPosition(sf::Vector2f(polozenie_x,polozenie_y-wielkosc_y));
                    this->duch.setTexture(tekstura);
                    //this->duch.setTextureRect(sf::IntRect(0, 0, wielkosc_x, wielkosc_y));
                    duszek.push_back(duch);
                }
        }
        void rysowanie ( sf::RenderWindow &okno)
        {
            for(int i=0; i<duszek.size();i++)
            {
                okno.draw(duszek[i]);
            }
        }
        //virtual ~obiekty();

    protected:

    private:
};

#endif // OBIEKTY_H
