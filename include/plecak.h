#ifndef PLECAK_H
#define PLECAK_H

#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Main.hpp>

class plecak
{
    public:
        sf::Sprite duszek;
        sf::Texture tekstura;
        bool zajete[4];
            sf::RectangleShape tlo;
            sf::RectangleShape pola_na_rzeczy[8];


        void stworz(sf::RenderWindow &okno)
        {

            this->tlo.setFillColor(sf::Color::Red);
            this->tlo.setSize(sf::Vector2f(500,80));
            this->tlo.setPosition(okno.getSize().x,okno.getSize().y-50);
            for(int i=0; i<8;i++)
            {
            this->pola_na_rzeczy[i].setFillColor(sf::Color::White);
            this->pola_na_rzeczy[i].setSize(sf::Vector2f(50,50));
            this->pola_na_rzeczy[i].setPosition(tlo.getPosition().x+10+60*i,tlo.getPosition().y+10);
            }

        }
        void rysuj(sf::RenderWindow &okno)
        {

            okno.draw(this->tlo);
            for(int i=0; i<8;i++)
            {
                okno.draw(this->pola_na_rzeczy[i]);
            }

        }
        void uaktualnij_pozycje(sf::RenderWindow &okno, int i, int j)
        {

            this->tlo.setPosition(okno.getSize().x/3+i,okno.getSize().y-50+j);
            for(int i=0; i<8;i++)
            {
            this->pola_na_rzeczy[i].setPosition(tlo.getPosition().x+10+60*i,tlo.getPosition().y+10);
            }

        }
        //virtual ~plecak();

    protected:

    private:

};

#endif // PLECAK_H
