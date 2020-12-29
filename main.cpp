#include "postac.h"
#include "swiat.h"
#include "obiekty.h"
#include "plecak.h"
#include "przeciwnik.h"
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Main.hpp>
using namespace std;


int main() {

    sf::RenderWindow w(sf::VideoMode(1000, 800),"HI");
    w.setActive(true);
    w.setFramerateLimit(100);
    postac kolko("wendy.png",5,5,sf::Vector2f(50,50),w);
    kolko.pojawienie_postaci("wendy.png",241,333);
    plecak ekwipunek;
    ekwipunek.stworz(w);
    sf::View widok(sf::Vector2f(500,500),sf::Vector2f(1000,1000));
    int macierz[] =
    {
        4, 4, 4, 4, 4, 0, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
        4, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 2, 0, 0, 0, 4,
        4, 1, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 4,
        4, 1, 0, 0, 2, 0, 3, 3, 3, 0, 1, 1, 1, 0, 0, 4,
        4, 1, 1, 0, 3, 3, 3, 0, 0, 0, 1, 1, 1, 2, 0, 4,
        4, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 2, 0, 0, 0, 4,
        4, 1, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 4,
        4, 1, 0, 0, 2, 0, 3, 3, 3, 0, 1, 1, 1, 0, 0, 4,
        4, 1, 1, 0, 3, 3, 3, 0, 0, 0, 1, 1, 1, 2, 0, 4,
        4, 0, 1, 0, 3, 0, 2, 2, 0, 0, 1, 1, 1, 1, 2, 4,
        4, 0, 1, 0, 3, 0, 2, 2, 2, 0, 1, 1, 1, 1, 1, 4,
        4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
    };
    swiat stworzony_swiat;
    sf::Event e;
    sf::Vector2u wielkosc_okna;
    int i=0;
    int j=0;
        wielkosc_okna=w.getSize();
    if(!stworzony_swiat.zaladuj("Turfs.png",sf::Vector2u(510,512),macierz,16,12))
            return 0;
    obiekty drzewo("drzewo.png",3,50,238,386,stworzony_swiat,510,512,macierz,16);

    obiekty siano("siano.png",1,50,76,111,stworzony_swiat,510,512,macierz,16);

    obiekty pajecze_gniazdo("kokon_pajakow.png",0,5,326,275,stworzony_swiat,510,512,macierz,16);
    obiekty kamienie("kamienie.png",2,50,150,107,stworzony_swiat,510,512,macierz,16);
    obiekty patyki("patyki.png",0,50,118,156,stworzony_swiat,510,512,macierz,16);
    sf::Vector2i au=stworzony_swiat.rozmiar_mapy;
    sf::Vector2u o=w.getSize();
    przeciwnik pajak("pajak.png");
   // std::cout<<o.x<<"         "<<o.y<<endl<<au.x<<"                 "<<au.y<<endl;
    while(w.isOpen())
    {

        w.clear();
        //w.draw(kolko);
        w.draw(stworzony_swiat);
        w.setView(widok);
        kolko.duszek.setPosition(sf::Vector2f(wielkosc_okna.x/2+i,wielkosc_okna.y/2+j));

        while(w.pollEvent(e))
        {
           // std::cout<<endl<<kolko.duszek.getPosition().x<<"          "<<kolko.duszek.getPosition().y<<endl;
            //kolko.duszek.setPosition(sf::Vector2f(wielkosc_okna.x/2+i,wielkosc_okna.y/2+j));
            kolko.ruch_duszka(e,&w);
            switch(e.type)
            {
                case sf::Event::Closed:
                    w.close();
                    break;
                case sf::Event::KeyPressed:
                    switch(e.key.code)
                    {
                    case (sf::Keyboard::A):
                    {
                        if(widok.getCenter().x>510)
                        {
                            widok.move(-10,0);
                            i-=10;
                        }
                        break;
                    }
                    case sf::Keyboard::Escape:
                        w.close();
                        break;
                    case (sf::Keyboard::D):
                         if(widok.getCenter().x<stworzony_swiat.rozmiar_mapy.x-kolko.wielkosc_x-510)
                         {
                             widok.move(10,0);
                             i+=10;
                         }

                        break;
                    case (sf::Keyboard::S):
                        if(widok.getCenter().y<stworzony_swiat.rozmiar_mapy.y-kolko.wielkosc_y-512)
                        {
                            widok.move(0,10);
                            j+=10;
                        }

                        break;
                    case (sf::Keyboard::W):
                        if(widok.getCenter().y>612)
                        {
                            widok.move(0,-10);
                            j-=10;
                        }
                        break;
                   /* case (sf::Keyboard::Q):
                        widok.rotate(90);
                        kolko.duszek.rotate(90);
                        break;
                    case (sf::Keyboard::E):
                        widok.rotate(-90);
                        kolko.duszek.rotate(-90);
                        break;*/
                    }
                    break;
                case sf::Event::Resized:
                    {
                    sf::FloatRect widoczne_pole(500,500, e.size.width,e.size.height);
                    widok=sf::View(widoczne_pole);
                    wielkosc_okna=w.getSize();
                    break;
                    }
                case sf::Event::MouseWheelScrolled:
                   {

                    if(e.mouseWheel.x>0)
                        widok.zoom(0.75);
                    else
                        widok.zoom(1.25);
                    break;
                   }

            }

        pajak.rysuj(w,pajecze_gniazdo,kolko);
        }
            ekwipunek.uaktualnij_pozycje(w,i,j);
        drzewo.rysowanie(w);
        siano.rysowanie(w);
        patyki.rysowanie(w);
        kamienie.rysowanie(w);
        pajecze_gniazdo.rysowanie(w);
        ekwipunek.rysuj(w);
        w.draw(kolko.duszek);
        w.display();

    }
return 0;
}
