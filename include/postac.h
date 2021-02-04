#ifndef POSTAC_H
#define POSTAC_H
#include <sstream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Main.hpp>
#include <iostream>
#include <string>
//#include "przeciwnik.h"
#include "obiekty.h"
class postac : public sf::RectangleShape
{
public:
    friend class przeciwnik;
private:
    sf::Texture tekstura;
    sf::Vector2i ramka[4];
    sf::RectangleShape *rec;
    sf::Vector2f wektorek;
public:
    int wielkosc_x;
    int wielkosc_y;
    sf::Sprite duszek;
    sf::RectangleShape prostokat_zycia;
    sf::RectangleShape prostokat_calego_zycia;
    sf::Text tekst;
    bool czy_zyje();
    sf::Font font;
    void pojawienie_postaci(std::string plik_z_postacia, int x, int y, int ile_bije, int ile_zycia);
    void ruch_duszka (sf::Event e, sf::RenderWindow *okno);
    int predkosc;
    sf::Sprite bohater;
public:
        postac();
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

