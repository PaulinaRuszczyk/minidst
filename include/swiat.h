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
/*class swiat : public sf::Drawable, public sf::Transformable
{
    public:
        sf::Texture tekstura;
        sf::VertexArray wektor;
        bool zaladuj (std::string& nazwa_pliku, sf::Vector2u rozmiar_pliku, int* plik, unsigned int szerokosc, unsigned int wysokosc)
        {
            if(!tekstura.loadFromFile(nazwa_pliku))
                return false;
            wektor.setPrimitiveType(sf::Quads);
            wektor.resize(wysokosc*szerokosc*4);
            for(unsigned int i=0; i<szerokosc;i++)
            {
                for(unsigned int j=0; j<wysokosc;j++)
                {
                    int ktory=plik[i+j*szerokosc];
                    int tu=ktory%(tekstura.getSize().x / rozmiar_pliku.x);
                    int tv = ktory/(tekstura.getSize().x / rozmiar_pliku.x);
                    sf::Vertex* wskaznik = &wektor[(i+j*szerokosc)*4];
                    wskaznik[0].position = sf::Vector2f(i*rozmiar_pliku.x, j*rozmiar_pliku.y);
                    wskaznik[1].position = sf::Vector2f((i+1)*rozmiar_pliku.x, j*rozmiar_pliku.y);
                    wskaznik[2].position = sf::Vector2f((i+1)*rozmiar_pliku.x, (j+1)*rozmiar_pliku.y);
                    wskaznik[3].position = sf::Vector2f(i*rozmiar_pliku.x, (j+1)*rozmiar_pliku.y);
                    wskaznik[0].texCoords = sf::Vector2f(tu*rozmiar_pliku.x, tv*rozmiar_pliku.y);
                    wskaznik[1].texCoords = sf::Vector2f((tu+1)*rozmiar_pliku.x, tv*rozmiar_pliku.y);
                    wskaznik[2].texCoords = sf::Vector2f((tu+1)*rozmiar_pliku.x, (tv+1)*rozmiar_pliku.y);
                    wskaznik[3].texCoords = sf::Vector2f(tu*rozmiar_pliku.x, (tv+1)*rozmiar_pliku.y);

                }
            }
            return true;
        }
        virtual void rysowanie(sf::RenderTarget& centrum, sf::RenderStates stan)
        {
            stan.transform *= getTransform();
            stan.texture =&tekstura;
            centrum.draw(wektor,stan);
        }

        ruch (sf::View widok, sf::Event wydarzenie, sf::RenderWindow okno)
        {

            // Do maina sf::View widok(sf::FloatRect(200,200,200,200));
            widok.setCenter(sf::Vector2f(200,200));

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
               widok.move(-100,0);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
                widok.move(100,0);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
                widok.move(0,-100);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
                widok.move(0,100);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
                widok.rotate(90);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
                widok.rotate(-90);
            if (sf::Mouse::VerticalWheel>0)
                widok.zoom(0.25);
            if (sf::Mouse::VerticalWheel<0)
                widok.zoom(1.25);
            if (wydarzenie.type==sf::Event::Resized)
            {
                sf::FloatRect  widoczne_pole(0,0, wydarzenie.size.width,wydarzenie.size.height);
                okno.setView(sf::View(widoczne_pole));
            }
        }
        virtual ~swiat();
        bool istnieje=false;
        protected:




};*/
class swiat : public sf::Drawable, public sf::Transformable
{
        sf::VertexArray wektor;
        sf::Texture tekstura;
public:

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
