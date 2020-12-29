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
    friend obiekty(std::string,int, int , int , int ,swiat &);
        sf::VertexArray wektor;
   public:
        sf::Texture tekstura;
        sf::Vector2i rozmiar_mapy;

    bool zaladuj(const std::string& nazwa_pliku, sf::Vector2u rozmiar, const int* kafelek, unsigned int szerokosc, unsigned int wysokosc)
    {

        if (!tekstura.loadFromFile(nazwa_pliku))
            return false;
        wektor.setPrimitiveType(sf::Quads);
        wektor.resize(szerokosc * wysokosc * 4);
        for (unsigned int i = 0; i < szerokosc; ++i)
            for (unsigned int j = 0; j < wysokosc; ++j)
            {
                int ktory = kafelek[i + j * szerokosc];
                int tu = ktory % (tekstura.getSize().x / rozmiar.x);
                int tv = ktory / (tekstura.getSize().x / rozmiar.x);
                sf::Vertex* aktualny = &wektor[(i + j * szerokosc) * 4];
                aktualny[0].position = sf::Vector2f(i * rozmiar.x, j * rozmiar.y);
                aktualny[1].position = sf::Vector2f((i + 1) * rozmiar.x, j * rozmiar.y);
                aktualny[2].position = sf::Vector2f((i + 1) * rozmiar.x, (j + 1) * rozmiar.y);
                aktualny[3].position = sf::Vector2f(i * rozmiar.x, (j + 1) * rozmiar.y);
                aktualny[0].texCoords = sf::Vector2f(tu * rozmiar.x, tv * rozmiar.y);
                aktualny[1].texCoords = sf::Vector2f((tu + 1) * rozmiar.x, tv * rozmiar.y);
                aktualny[2].texCoords = sf::Vector2f((tu + 1) * rozmiar.x, (tv + 1) * rozmiar.y);
                aktualny[3].texCoords = sf::Vector2f(tu * rozmiar.x, (tv + 1) * rozmiar.y);
            }
        rozmiar_mapy.x=rozmiar.x*szerokosc;
        rozmiar_mapy.y=rozmiar.y*wysokosc;
        return true;
    }

private:

    virtual void draw(sf::RenderTarget& centrum, sf::RenderStates stan) const
    {
        stan.transform *= getTransform();
        stan.texture = &tekstura;
        centrum.draw(wektor, stan);
    }
public:
};
#endif // SWIAT_H

