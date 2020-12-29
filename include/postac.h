#ifndef POSTAC_H
#define POSTAC_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Main.hpp>
#include <iostream>
#include <string>
#include "obiekty.h"
#include "postac.h"
class postac : public sf::RectangleShape
{
public:
    friend class przeciwnik;
private:

    sf::Texture tekstura;
    sf::Vector2i ramka[4];
        void ktora_ramka();

        sf::RectangleShape *rec;
        sf::Vector2f wektorek;
public:
        int wielkosc_x;
        int wielkosc_y;
        sf::Sprite duszek;

        void pojawienie_postaci(std::string plik_z_postacia, int x, int y)
        {

            wielkosc_x=x;
            wielkosc_y=y;
            if(!this->tekstura.loadFromFile(plik_z_postacia))
            {
               std::cout<<"problem";
            }
            //this->duszek.setPosition(50,250);
            duszek.setTexture(tekstura);
            duszek.setTextureRect(sf::IntRect(0,0,wielkosc_x,wielkosc_y));

        }
        void ruch_duszka (sf::Event e, sf::RenderWindow *okno)
        {
            while(okno->pollEvent(e))
            {
            if(e.type==sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                okno->close();
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            {
                duszek.setTextureRect(sf::IntRect(0,0,241,300));

            }
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            {
                duszek.setTextureRect(sf::IntRect(241,0,241,333));
            }
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            {
                duszek.setTextureRect(sf::IntRect(0,0,241,333));

            }
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            {
                duszek.setTextureRect(sf::IntRect(482,0,241,333));

            }

            okno->draw(duszek);

            }
        }
    int predkosc;
    sf::Sprite bohater;
public:
        postac(std::string nazwa_pliku, int x, int y, sf::Vector2f rozmiar, sf::RenderWindow &okno)
        {


        }
       // virtual ~postac();
        // jaki kawa³ek wyci¹æ
        int wyciecie_x=100;
        int wyciecie_y=100;
        int krok=5;
        int kierunek;

        int szybkosc_chodzenia;
        int sila;
        int obrona;
        int zycie;
        int mozg;
        int glodek;
        void atak();
        void oberwanie();
        void chwyt_obiektu();
        void budowanie();
        sf::Vector2f pozycja ( ) { return body.getPosition();}
    protected:

    private:
        glodnienie();
        glupienie();
        sf::RectangleShape body;
};

#endif // POSTAC_H
