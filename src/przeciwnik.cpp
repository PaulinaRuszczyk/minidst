#include "przeciwnik.h"

przeciwnik::przeciwnik(std::string nazwa_pliku, int pr, int bije, int ile_wytrzyma, obiekty kokon)
{
    pojawil_sie.resize(kokon.ilosc_wszystkich);
    std::fill(pojawil_sie.begin(), pojawil_sie.end(), false);
    ile_zycia.resize(kokon.ilosc_wszystkich);
    std::fill(ile_zycia.begin(), ile_zycia.end(), ile_wytrzyma);
    tekst.resize(kokon.ilosc_wszystkich);
    prostokat_zycia.resize(kokon.ilosc_wszystkich);
    prostokat_calego_zycia.resize(kokon.ilosc_wszystkich);
    if(font.loadFromFile("font.ttf"))
        std::cout<<"przypa³";
    for(int i=0; i<tekst.size(); i++)
    {
        tekst[i].setFont(font);
        tekst[i].setStyle(sf::Text::Bold);
        tekst[i].setColor(sf::Color::Red);
        tekst[i].setCharacterSize(50);
        this->prostokat_calego_zycia[i].setOutlineColor(sf::Color::Red);
        this->prostokat_calego_zycia[i].setSize(sf::Vector2f(50,15));
        this->prostokat_zycia[i].setFillColor(sf::Color::Red);
        this->prostokat_zycia[i].setSize(sf::Vector2f(50,15));
    }
    this->predkosc=pr;
    if(!tekstura.loadFromFile(nazwa_pliku))
        std::cout<<"Brak pliku o nazwie "<<nazwa_pliku;
    this->ile_bije=bije;
    podstawowy_duszek.setTexture(tekstura);
    podstawowy_duszek.setPosition(sf::Vector2f(0,0));
    duszek.resize(kokon.duszek.size());
    std::fill(duszek.begin(), duszek.end(), podstawowy_duszek);
}
void przeciwnik::atak(int i, int x, int y, postac &bohater, sf::RenderWindow &okno)
{
    if(sqrt((x-duszek[i].getPosition().x)*(x-duszek[i].getPosition().x)+(y-duszek[i].getPosition().y)*(y-duszek[i].getPosition().y))<100 && pojawil_sie[i]==true && pomocnicza%100==0 )
    {
        bohater.zycie=bohater.zycie-this->ile_bije;
    }
    pomocnicza++;
}
void przeciwnik::atak_bohatera(sf::Event e, sf::RenderWindow *okno, postac &bohater, int x, int y)
{
    for(int i=0; i<ile_zycia.size(); i++)
    {
        if(czy_zyje(i) && sqrt((x-duszek[i].getPosition().x)*(x-duszek[i].getPosition().x)+(y-duszek[i].getPosition().y)*(y-duszek[i].getPosition().y))<300 && sf::Keyboard::isKeyPressed(sf::Keyboard::F))// && pomocnicza1%20==0 )
        {
            std::cout<<i<<"   "<<ile_zycia[i]<<std::endl;
            ile_zycia[i]-=bohater.sila;
            break;
        }
    }
}
bool przeciwnik::czy_zyje(int i)
{
    if(ile_zycia[i]>0)
        return true;
    else
    {
        return false;
    }
}
void przeciwnik::rysuj(sf::RenderWindow &okno,obiekty kokon, postac &bohater, swiat s, int x, int y,  int ile_wytrzyma )
{
    for(int i=0; i<kokon.duszek.size(); i++)
    {
        if(!czy_zyje(i) && pojawil_sie[i])
        {
            //pajeczy_gruczol.push_back()
            //pajeczy_gruczol[i].duch.setPosition(this->duszek[i].getPosition().x, this->duszek[i].getPosition().y);
            // okno.draw(pajeczy_gruczol[i].duch);
            pojawil_sie[i]=false;
            ile_zabitych++;
        }
        if(sqrt((x-kokon.duszek[i].getPosition().x)*(x-kokon.duszek[i].getPosition().x)+(y-kokon.duszek[i].getPosition().y)*(y-kokon.duszek[i].getPosition().y))<100 )
        {
            if(!(pojawil_sie[i]))
            {
                ile_zycia[i]=ile_wytrzyma;
                prostokat_calego_zycia[i].setPosition(duszek[i].getPosition().x,duszek[i].getPosition().y+50);
                prostokat_zycia[i].setSize(sf::Vector2f(prostokat_calego_zycia[i].getSize().x*ile_zycia[i]/50,15));
                prostokat_zycia[i].setPosition(prostokat_calego_zycia[i].getPosition().x,prostokat_calego_zycia[i].getPosition().y+50);
                std::stringstream ss;
                ss << ile_zycia[i];
                std::string str = ss.str();
                tekst[i].setString(str);
                // std::cout<<ile_zycia[i];
                duszek[i].setPosition(sf::Vector2f(kokon.duszek[i].getPosition().x-20,kokon.duszek[i].getPosition().y-20));
                tekst[i].setPosition(sf::Vector2f(duszek[i].getPosition().x, duszek[i].getPosition().y+50));
                pojawil_sie[i]=true;
                okno.draw(duszek[i]);
                okno.draw(tekst[i]);
            }
        }
        if(!pojawil_sie.empty() && pojawil_sie[i] &&!duszek.empty())
        {
            std::stringstream ss;
            ss << ile_zycia[i];
            std::string str = ss.str();
            tekst[i].setString(str);
            double odleglosc=sqrt((x-duszek[i].getPosition().x)*(x-duszek[i].getPosition().x)+(y-duszek[i].getPosition().y)*(y-duszek[i].getPosition().y));
            kat=atan2((x-duszek[i].getPosition().x),(y-duszek[i].getPosition().y));
            duszek[i].setPosition(duszek[i].getPosition().x+sin(kat)*predkosc,duszek[i].getPosition().y+cos(kat)*predkosc);
            tekst[i].setPosition(sf::Vector2f(duszek[i].getPosition().x, duszek[i].getPosition().y));
            prostokat_calego_zycia[i].setPosition(duszek[i].getPosition().x,duszek[i].getPosition().y);
            prostokat_zycia[i].setSize(sf::Vector2f(prostokat_calego_zycia[i].getSize().x*ile_zycia[i]/50,15));
            prostokat_zycia[i].setPosition(prostokat_calego_zycia[i].getPosition().x,prostokat_calego_zycia[i].getPosition().y);
            atak(i, x, y, bohater, okno);
            okno.draw(duszek[i]);
            okno.draw(tekst[i]);
            okno.draw(prostokat_calego_zycia[i]);
            okno.draw(prostokat_zycia[i]);
        }
    }
}
przeciwnik::~przeciwnik()
{
    //dtor
}
