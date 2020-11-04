#ifndef POSTAC_H
#define POSTAC_H
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Main.hpp>
#include <iostream>
class postac : public sf::RectangleShape
{
private:
    sf::Texture tekstura;
    sf::Vector2i ramka[4];
        void ktora_ramka();
        int wielkosc_x;
        int wielkosc_y;
        sf::RectangleShape rec;
        sf::Vector2f wektorek;

        void wyciecie_ramki()
        {
            this->wektorek.x=50.0;
            this->wektorek.y=50;
            this->rec.setSize(wektorek);
            this->tekstura.loadFromFile("wendy.png",rec);
            this->ramka[0]=sf::Vector2i(0,0);
            this->ramka[1]=sf::Vector2i(1*this->wielkosc_y,0);
            this->ramka[2]=sf::Vector2i(2*this->wielkosc_y,0);
            //this->ramka[3]=sf::Vector2i(3*this->wielkosc_y,0);
        }
    int predkosc;
    sf::Sprite bohater;
public:
        postac(std::string nazwa_pliku, int x, int y, sf::Vector2f rozmiar, sf::RenderWindow &okno)
        {
            //this->setSize(rozmiar);
            bohater.setScale(x,y);
            //this->wielkosc_x=x;
            bohater.setPosition(sf::Vector2f(10,10));
            //this->wielkosc_y=y;
            sf::Texture tex;
            this->wyciecie_ramki();
            if(!tex.loadFromFile(nazwa_pliku))
               std::cout<<"problem";

            //this->setTexture(tex, true);
            bohater.setTexture(tex);
            okno.draw(bohater);
            this->aktualizuj();

        }
        void aktualizuj()
        {
            sf::Vector2f ruch(0,0);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            {
               this->ramka[0]=sf::Vector2i(0,0);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            {
               // ruch.x+=predkosc*deltaTime;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            {
              //  ruch.y -=predkosc*deltaTime;

            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            {
               // ruch.y +=predkosc*deltaTime;

            }

        }
        virtual ~postac();
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
        void poruszanie(sf::RenderWindow& w);
        void pojawienie(sf::RenderWindow& w)
        {
             sf::CircleShape kolo;
    kolo.setFillColor(sf::Color::Blue);
    //kolo.setPosition(100,100);
    kolo.setRadius(55);
    w.draw(kolo);
        }

        sf::Vector2f pozycja ( ) { return body.getPosition();}
    protected:

    private:
        glodnienie();
        glupienie();
        sf::RectangleShape body;
};

#endif // POSTAC_H
