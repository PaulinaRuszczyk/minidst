#ifndef PRZECIWNIK_H
#define PRZECIWNIK_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Main.hpp>
#include <iostream>
#include <string>
#include <cmath>
#include "obiekty.h"
#include "postac.h"
class przeciwnik
{
    public:

       // virtual ~przeciwnik();
        int ile_bije;
        int ile_zycia;
        bool zabiera_psychike;
        int ile_psychiki;
        sf::Texture tekstura;
        sf::Sprite duszek;
        przeciwnik(std::string nazwa_pliku)
        {
            if(!tekstura.loadFromFile(nazwa_pliku))
                std::cout<<"Brak pliku o nazwie "<<nazwa_pliku;
            duszek.setTexture(tekstura);

        }
        void rysuj(sf::RenderWindow &okno,obiekty kokon, postac bohater)
        {
            for(int i=0; i<kokon.duszek.size(); i++)
            {
                if(bohater.getPosition().x-kokon.duszek[i].getPosition().x<okno.getSize().x/2 && bohater.getPosition().x-kokon.duszek[i].getPosition().x>-okno.getSize().x/2 )
                {
                    std::cout<<"k";
                }
            }
        }
    protected:

    private:
};

#endif // PRZECIWNIK_H
