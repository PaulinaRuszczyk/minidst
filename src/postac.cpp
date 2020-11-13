#ifndef postac_cpp
#define postac_cpp
#include "postac.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
/*postac::postac()
{
    //ctor
}
*/
/*postac::~postac()
{
    //dtor
}*/
void pojawienie(sf::RenderWindow& w)
{
    sf::CircleShape kolo;
    kolo.setFillColor(sf::Color::Blue);
    kolo.setPosition(100,100);
    kolo.setRadius(55);
    w.draw(kolo);

}
void poruszanie(sf::RenderWindow& w, sf::Event& event)
{
       //wycinanie nowych ramek i imitacja ruchu w miejscu



}
#endif // postac_cpp
