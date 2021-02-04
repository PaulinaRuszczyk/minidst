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
#include <sstream>
#include "obiekty.h"
#include <stdlib.h>
#include "postac.h"
#include "obiekty.h"
class przeciwnik
{

public:
 friend class postac;
    // virtual ~przeciwnik();
    int k=0;
    int ile_zabitych=0;
    int ile_bije;
    std::vector <int> ile_zycia;
    bool zabiera_psychike;
    int ile_psychiki;
    int predkosc;
    std::vector <sf::Text> tekst;
    sf::Texture tekstura;
    std::vector <sf::Sprite> duszek;
    //sf::Sprite duszek;
    std::vector <sf::Sprite> elementy;
    std::vector <sf::RectangleShape> prostokat_zycia;
    std::vector <sf::RectangleShape> prostokat_calego_zycia;
    sf::Sprite podstawowy_duszek;
    std::vector <bool> pojawil_sie;
    int pomocnicza=0;
    int pomocnicza1=0;
    sf::Font font;
    double kat;
    // std::vector <obiekty> pajeczy_gruczol;
    przeciwnik(std::string nazwa_pliku, int pr, int bije, int ile_wytrzyma, obiekty kokon);
    void atak(int i, int x, int y, postac &bohater, sf::RenderWindow &okno);
    void atak_bohatera(sf::Event e, sf::RenderWindow *okno, postac &bohater, int x, int y);
    bool czy_zyje(int i);
    void rysuj(sf::RenderWindow &okno,obiekty kokon, postac &bohater, swiat s, int x, int y,  int ile_wytrzyma );
};

#endif // PRZECIWNIK_H
