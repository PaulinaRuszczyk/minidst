#ifndef POSTAC_H
#define POSTAC_H
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class postac : public sf::RectangleShape
{
private:
    sf::Vector2i ramka[4];
        void ktora_ramka();
        int wielkosc_x;
        int wielkosc_y;
        void wyciecie_ramki()
        {
            this->ramka[0]=sf::Vector2i(0,0);
            this->ramka[1]=sf::Vector2i(0,1*this->wielkosc_y);
            this->ramka[2]=sf::Vector2i(0,2*this->wielkosc_y);
            this->ramka[3]=sf::Vector2i(0,3*this->wielkosc_y);
        }
    int predkosc;

public:
        postac()
        {
            this->wyciecie_ramki();
        }
        postac(std::string nazwa_pliku, int x, int y, sf::Vector2f rozmiar)
        {
            this->setSize(rozmiar);
            this->wielkosc_x=x;
            this->wielkosc_y=y;
            sf::Texture *tex = new sf::Texture;
            this->wyciecie_ramki();
            tex->loadFromFile(nazwa_pliku);
            this->setTexture(tex, true);
            this->aktualizuj();
        }
        void aktualizuj()
        {
            sf::Vector2f ruch(0,0);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            {
               // ruch.x -=predkosc*deltaTime;

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
