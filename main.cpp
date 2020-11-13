#include "postac.h"
#include "swiat.h"
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
	cout<<"JI";
    postac kolko("wendy.png",5,5,sf::Vector2f(50,50),w);
    kolko.pojawienie_postaci("wendy.png");
    sf::View widok(sf::Vector2f(500,500),sf::Vector2f(1000,1000));
    int macierz[] =
    {
        0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0,
        1, 1, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 3,
        0, 1, 0, 0, 2, 0, 3, 3, 3, 0, 1, 1, 1, 0, 0, 0,
        0, 1, 1, 0, 3, 3, 3, 0, 0, 0, 1, 1, 1, 2, 0, 0,
        0, 0, 1, 0, 3, 0, 2, 2, 0, 0, 1, 1, 1, 1, 2, 0,
        2, 0, 1, 0, 3, 0, 2, 2, 2, 0, 1, 1, 1, 1, 1, 1,
        0, 0, 1, 0, 3, 2, 2, 2, 0, 0, 0, 0, 1, 1, 1, 1,
    };
    swiat stworzony_swiat;
    sf::Event e;
    sf::Vector2f kupa;
    if(!stworzony_swiat.zaladuj("Turfs1.png",sf::Vector2u(100,100),macierz,20,20))
            return 0;
    while(w.isOpen())
    {
        kupa=widok.getCenter();
        kolko.duszek.setPosition(sf::Vector2f(kupa.x/2,kupa.y/2));
        w.clear();
        //w.draw(kolko);
        w.draw((stworzony_swiat));

       // postac kolko("wendy.png",100,100,sf::Vector2f(50,50),w);
        //kolko.pojawienie(w);
        //w.draw(kolo);
       // w.draw(kolko);
       // w.display();
        w.setView(widok);
        //widok.setCenter(kolko.pozycja());
        while(w.pollEvent(e))
        {
            //kolko.ruch_duszka(e,w);
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
                        kolko.duszek.setTextureRect(sf::IntRect(0,0,241,333));
                        if(widok.getCenter().x>500)
                        widok.move(-5,0);
                        break;
                    }
                    case sf::Keyboard::Escape:
                        w.close();
                        break;
                    case (sf::Keyboard::D):
                        kolko.duszek.setTextureRect(sf::IntRect(241,0,241,333));
                         if(widok.getCenter().x<1500)
                        widok.move(5,0);
                        break;
                    case (sf::Keyboard::S):
                        kolko.duszek.setTextureRect(sf::IntRect(0,0,241,333));
                        if(widok.getCenter().y<1500)
                            widok.move(0,5);
                        break;
                    case (sf::Keyboard::W):
                        kolko.duszek.setTextureRect(sf::IntRect(482,0,241,333));
                        if(widok.getCenter().y>500)
                            widok.move(0,-5);
                        break;
                    case (sf::Keyboard::Q):
                        widok.rotate(90);
                        break;
                    case (sf::Keyboard::E):
                        widok.rotate(-90);
                        break;
                    }
                    break;
                case sf::Event::Resized:
                    {
                    sf::FloatRect widoczne_pole(0,0, e.size.width,e.size.height);
                    widok=sf::View(widoczne_pole);
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


        }
        w.draw(kolko.duszek);
        w.display();

    }
return 0;
}
