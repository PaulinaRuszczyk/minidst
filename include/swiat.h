#ifndef SWIAT_H
#define SWIAT_H


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
class swiat : public sf::Drawable, public sf::Transformable
{
friend class obiekty;
friend class przeciwnik;
friend obiekty(std::string,int, int , int , int ,swiat &);
    sf::VertexArray wektor;
public:
    sf::Texture tekstura;
    sf::Vector2i rozmiar_mapy;
    bool zaladuj(const std::string& nazwa_pliku, sf::Vector2u rozmiar, const int* kafelek, unsigned int szerokosc, unsigned int wysokosc);
private:
    virtual void draw(sf::RenderTarget& centrum, sf::RenderStates stan);
};
#endif // SWIAT_H

