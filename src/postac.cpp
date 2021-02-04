#include "postac.h"

postac::postac()
{
    //ctor
}
bool postac::czy_zyje()
{
    if(zycie>0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void postac::pojawienie_postaci(std::string plik_z_postacia, int x, int y, int ile_bije, int ile_zycia)
{
    if(font.loadFromFile("font.ttf"))
        std::cout<<":<";
    zycie=ile_zycia;
    tekst.setFont(font);
    std::stringstream ss;
    ss << zycie;
    std::string str = ss.str();
    tekst.setString(str);
    tekst.setCharacterSize(50);
    tekst.setFillColor(sf::Color::Red);
    tekst.setStyle(sf::Text::Bold);
    sila=ile_bije;
    wielkosc_x=x;
    wielkosc_y=y;
    if(!this->tekstura.loadFromFile(plik_z_postacia))
    {
        std::cout<<"problem";
    }
    duszek.setTexture(tekstura);
    duszek.setTextureRect(sf::IntRect(0,0,wielkosc_x,wielkosc_y));
    this->prostokat_calego_zycia.setOutlineColor(sf::Color::Red);
    this->prostokat_calego_zycia.setSize(sf::Vector2f(x,15));
    this->prostokat_calego_zycia.setPosition(duszek.getPosition().x,duszek.getPosition().y+50);
    this->prostokat_zycia.setFillColor(sf::Color::Red);
    this->prostokat_zycia.setSize(sf::Vector2f(x,15));
    this->prostokat_zycia.setPosition(prostokat_calego_zycia.getPosition().x,prostokat_calego_zycia.getPosition().y+50);
}
 void postac::ruch_duszka (sf::Event e, sf::RenderWindow *okno)
{
    while(okno->pollEvent(e))
    {
        if(e.type==sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            okno->close();
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            duszek.setTextureRect(sf::IntRect(0,0,241,300));
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            duszek.setTextureRect(sf::IntRect(241,0,241,333));
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            duszek.setTextureRect(sf::IntRect(0,0,241,333));
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            duszek.setTextureRect(sf::IntRect(482,0,241,333));
        }
    }
}
