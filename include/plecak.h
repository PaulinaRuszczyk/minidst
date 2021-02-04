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
    void stworz(sf::RenderWindow &okno);
    void rysuj(sf::RenderWindow &okno);
    void uaktualnij_pozycje(sf::RenderWindow &okno, int i, int j);
    virtual ~plecak();

    protected:

    private:

};

#endif // PLECAK_H
