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

    //aktualne polozenie
    int x=500;
    int y=400;
    sf::RenderWindow w(sf::VideoMode(1000, 800),"HI");
    w.setActive(true);
    w.setFramerateLimit(100);
    postac wendy();
    postac willow ();
    postac worm ();
    postac bohater();
    wendy.pojawienie_postaci("wendy.png",241,333,5, 150);
    willow.pojawienie_postaci("Willow1.png",241,333,5, 150);
    worm.pojawienie_postaci("Worm.png",241,333,5, 150);
    sf::Text tekst3;
    sf::Font font;
    if(font.loadFromFile("font.ttf"))
        std::cout<<":<";
    tekst3.setFont(font);
    tekst3.setCharacterSize(50);
    tekst3.setFillColor(sf::Color::Red);
    tekst3.setStyle(sf::Text::Bold);
    plecak ekwipunek;
    ekwipunek.stworz(w);
    sf::View widok(sf::Vector2f(500,500),sf::Vector2f(1000,1000));
    sf::View widok_pocz;
    widok_pocz=widok;
    int macierz[] =
    {
        4, 4, 4, 4, 4, 0, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
        4, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 2, 1, 1, 1, 4,
        4, 0, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 4,
        4, 0, 0, 0, 2, 0, 3, 3, 3, 2, 1, 1, 1, 2, 2, 4,
        4, 1, 1, 0, 3, 3, 3, 0, 2, 2, 1, 1, 1, 2, 2, 4,
        4, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 4,
        4, 1, 0, 0, 0, 0, 0, 1, 3, 3, 3, 3, 3, 3, 3, 4,
        4, 1, 0, 0, 2, 0, 3, 3, 3, 3, 1, 1, 1, 1, 1, 4,
        4, 1, 1, 0, 3, 3, 3, 2, 2, 2, 1, 1, 1, 2, 1, 4,
        4, 0, 1, 0, 3, 0, 2, 2, 2, 3, 1, 1, 1, 1, 2, 4,
        4, 0, 1, 0, 3, 0, 2, 2, 2, 2, 1, 1, 1, 1, 1, 4,
        4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
    };
    swiat stworzony_swiat;
    sf::Event e;
    sf::Vector2u wielkosc_okna;
    int i=0;
    int j=0;
    if(!stworzony_swiat.zaladuj("Turfs.png",sf::Vector2u(510,512),macierz,16,12))
            return 0;
    obiekty drzewo("drzewo.png",3,50,238,386,stworzony_swiat,510,512,macierz,16);

    obiekty siano("siano.png",1,50,76,111,stworzony_swiat,510,512,macierz,16);

    obiekty pajecze_gniazdo("kokon_pajakow.png",0,5,326,275,stworzony_swiat,510,512,macierz,16);
    obiekty kamienie("kamienie.png",2,50,150,107,stworzony_swiat,510,512,macierz,16);
    obiekty patyki("patyki.png",0,50,118,156,stworzony_swiat,510,512,macierz,16);
    sf::Vector2i au=stworzony_swiat.rozmiar_mapy;
    sf::Vector2u o=w.getSize();
    przeciwnik pajak("pajak.png",1, 10,50,pajecze_gniazdo);
   // std::cout<<o.x<<"         "<<o.y<<endl<<au.x<<"                 "<<au.y<<endl;
    bool wybrana_postac=false;
    //
    sf::Text tekst;
    tekst.setFont(font);
    tekst.setString("Wybierz postac, ktora chcesz grac:");
    tekst.setCharacterSize(50);
    tekst.setFillColor(sf::Color::Red);
    tekst.setStyle(sf::Text::Bold);

    sf::Text tekst2, tekst1, tekst_przycisku1, tekst_przycisku2;
    tekst2.setFont(font);
    tekst2.setString("Przegrales. Zdobyte punkty:" );
    tekst2.setCharacterSize(50);
    tekst2.setFillColor(sf::Color::Red);
    tekst2.setStyle(sf::Text::Bold);
    tekst2.setPosition(0,0);

    tekst1.setFont(font);
    tekst1.setCharacterSize(100);
    tekst1.setFillColor(sf::Color::Red);
    tekst1.setStyle(sf::Text::Bold);
    tekst1.setPosition(100,100);

    tekst_przycisku1.setFont(font);
    tekst_przycisku1.setString("Zagraj jeszcze raz");
    tekst_przycisku1.setCharacterSize(50);
    tekst_przycisku1.setFillColor(sf::Color::White);
    tekst_przycisku1.setStyle(sf::Text::Bold);
    tekst_przycisku1.setPosition(100,500);

    tekst_przycisku2.setFont(font);
    tekst_przycisku2.setString("Wyjdz");
    tekst_przycisku2.setCharacterSize(50);
    tekst_przycisku2.setFillColor(sf::Color::White);
    tekst_przycisku2.setStyle(sf::Text::Bold);
    tekst_przycisku2.setPosition(650,500);

    sf::RectangleShape przycisk, przycisk1, przycisk2;

    przycisk1.setFillColor(sf::Color::Red);
    przycisk1.setSize(sf::Vector2f(400,80));
    przycisk1.setPosition(100,500);

    przycisk2.setFillColor(sf::Color::Red);
    przycisk2.setSize(sf::Vector2f(150,80));
    przycisk2.setPosition(650,500);

    przycisk.setFillColor(sf::Color::Red);
    przycisk.setSize(sf::Vector2f(150,80));
    przycisk.setPosition(300,500);

    sf::Text tekst_przycisku;
    tekst_przycisku.setFont(font);
    tekst_przycisku.setString("GRAJ!");
    tekst_przycisku.setCharacterSize(50);
    tekst_przycisku.setFillColor(sf::Color::White);
    tekst_przycisku.setStyle(sf::Text::Bold);
    tekst_przycisku.setPosition(300,500);
    int mouseX, mouseY;
    sf::RectangleShape zaznaczenie;

    zaznaczenie.setFillColor(sf::Color::Red);
    int wybor;
    while(w.isOpen())
    {
        if(!wybrana_postac)
        {
            x=500;
            y=400;
            pajak.ile_zabitych=0;
            w.setView(widok_pocz);
            wielkosc_okna=w.getSize();
            tekst.setPosition(0,0);

            wendy.duszek.setPosition(0,100);
            willow.duszek.setPosition(250,100);
            worm.duszek.setPosition(500,100);
            w.clear(sf::Color::Black);


            while(w.pollEvent(e))
            {
                switch(e.type)
                {
                    case sf::Event::Closed:
                        w.close();
                        break;
                    case sf::Event::MouseButtonPressed:
                        if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
                        {
                            mouseX=sf::Mouse::getPosition(w).x;
                            mouseY=sf::Mouse::getPosition(w).y;
                            std::cout<<przycisk.getPosition().x<<"|"<<mouseX<<"|"<<przycisk.getPosition().x+przycisk.getSize().x<<" "<<przycisk.getPosition().y<<"|"<<mouseY<<"|"<<przycisk.getPosition().y+przycisk.getSize().y<<" "<<wybrana_postac<<std::endl;
                           // std::cout<<w.getPosition().x<<" "<<w.getPosition().y<<std::endl;
                            if(mouseX>wendy.duszek.getPosition().x && mouseX<wendy.duszek.getPosition().x+250 && mouseY>wendy.duszek.getPosition().y-30 && mouseY<wendy.duszek.getPosition().y+250)
                            {
                                zaznaczenie.setSize(sf::Vector2f(250,350));
                                zaznaczenie.setPosition(wendy.duszek.getPosition().x, wendy.duszek.getPosition().y);
                                wybor=1;
                            }
                            else if(mouseX>willow.duszek.getPosition().x && mouseX<willow.duszek.getPosition().x+250 && mouseY>willow.duszek.getPosition().y-30 && mouseY<willow.duszek.getPosition().y+250)
                            {
                                zaznaczenie.setSize(sf::Vector2f(250,350));
                                zaznaczenie.setPosition(willow.duszek.getPosition().x, willow.duszek.getPosition().y);
                                wybor=2;
                            }
                            else if(mouseX>worm.duszek.getPosition().x && mouseX<worm.duszek.getPosition().x+250 && mouseY>worm.duszek.getPosition().y-30 && mouseY<worm.duszek.getPosition().y+250)
                            {
                                zaznaczenie.setSize(sf::Vector2f(250,350));
                                zaznaczenie.setPosition(worm.duszek.getPosition().x, worm.duszek.getPosition().y);
                                wybor=3;
                            }

                            else if(mouseX>przycisk.getPosition().x && mouseX<przycisk.getPosition().x+przycisk.getSize().x && mouseY>przycisk.getPosition().y-140 && mouseY<przycisk.getPosition().y-40 )
                            {
                                if(wybor==1)
                                {
                                    bohater=wendy;
                                    wybrana_postac=true;
                                }
                                else if(wybor==2)
                                {
                                    bohater=willow;
                                    wybrana_postac=true;
                                }
                                else if (wybor==3)
                                {
                                    bohater=worm;
                                    wybrana_postac=true;
                                }

                            }
                        }
                }
            }
            w.draw(zaznaczenie);
            w.draw(przycisk);
            w.draw(wendy.duszek);
            w.draw(willow.duszek);
            w.draw(worm.duszek);
            w.draw(tekst);
            w.draw(tekst_przycisku);
            w.display();
        }
        else if(bohater.czy_zyje())
        {
        wielkosc_okna=w.getSize();

        w.clear();

        w.draw(stworzony_swiat);
        w.setView(widok);
        bohater.duszek.setPosition(sf::Vector2f(wielkosc_okna.x/2+i,wielkosc_okna.y/2+j));
        bohater.tekst.setPosition(sf::Vector2f(bohater.duszek.getPosition().x, bohater.duszek.getPosition().y));
        ekwipunek.uaktualnij_pozycje(w,i,j);
        std::stringstream ss;
        ss << pajak.ile_zabitych;
        std::string str = ss.str();
        tekst3.setString(str);

        tekst3.setPosition(0+i,0+j);
        while(w.pollEvent(e))
        {
            bohater.ruch_duszka(e,&w);
            pajak.atak_bohatera(e,&w,bohater,x, y);
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
                            widok.move(-30,0);
                            i-=30;
                            x-=30;
                        }
                        break;
                    }
                    case sf::Keyboard::Escape:
                        w.close();
                        break;
                    case (sf::Keyboard::D):
                         if(widok.getCenter().x<stworzony_swiat.rozmiar_mapy.x-bohater.wielkosc_x-510)
                         {
                             widok.move(30,0);
                             i+=30;
                             x+=30;
                         }
                        break;
                    case (sf::Keyboard::S):
                        if(widok.getCenter().y<stworzony_swiat.rozmiar_mapy.y-bohater.wielkosc_y-512)
                        {
                            widok.move(0,30);
                            j+=30;
                            y+=30;
                        }

                        break;
                    case (sf::Keyboard::W):
                        if(widok.getCenter().y>612)
                        {
                            widok.move(0,-30);
                            j-=30;
                            y-=30;
                        }
                        break;
                   /* case (sf::Keyboard::Q):
                        widok.rotate(90);
                        bohater.duszek.rotate(90);
                        break;
                    case (sf::Keyboard::E):
                        widok.rotate(-90);
                        bohater.duszek.rotate(-90);
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
        }
        pajak.rysuj(w,pajecze_gniazdo,bohater, stworzony_swiat, x, y,50);
        drzewo.rysowanie(w);
        siano.rysowanie(w);
        patyki.rysowanie(w);
        kamienie.rysowanie(w);
        pajecze_gniazdo.rysowanie(w);
        ekwipunek.rysuj(w);
        ////////////
        w.draw(bohater.duszek);
        std::stringstream ss1;
        ss1 << bohater.zycie;
        std::string str1 = ss1.str();
        bohater.tekst.setString(str1);

        bohater.prostokat_calego_zycia.setPosition(bohater.duszek.getPosition().x,bohater.duszek.getPosition().y);
        bohater.prostokat_zycia.setSize(sf::Vector2f(bohater.prostokat_calego_zycia.getSize().x*bohater.zycie/150,15));
        bohater.prostokat_zycia.setPosition(bohater.prostokat_calego_zycia.getPosition().x,bohater.prostokat_calego_zycia.getPosition().y);
        w.draw(bohater.prostokat_calego_zycia);
        //////////////////////

        w.draw(tekst3);
        w.draw(bohater.prostokat_zycia);
        w.draw(bohater.tekst);
        w.display();
        }
        else if(!bohater.czy_zyje())
        {
            std::fill(pajak.pojawil_sie.begin(), pajak.pojawil_sie.end(), false);
            w.setView(widok_pocz);
            wielkosc_okna=w.getSize();
            tekst2.setPosition(0,0);
            w.clear(sf::Color::Black);
            //Licznik zabitych paj¹ków
            std::stringstream ss;
            ss << pajak.ile_zabitych;
            std::string str = ss.str();
            tekst1.setString(str);
            widok=widok_pocz;
            i=0;
            j=0;
            while(w.pollEvent(e))
            {
                switch(e.type)
                {
                    case sf::Event::Closed:
                        w.close();
                        break;
                    case sf::Event::MouseButtonPressed:
                        if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
                        {
                            mouseX=sf::Mouse::getPosition(w).x;
                            mouseY=sf::Mouse::getPosition(w).y;
                            std::cout<<przycisk.getPosition().x<<"|"<<mouseX<<"|"<<przycisk.getPosition().x+przycisk.getSize().x<<" "<<przycisk.getPosition().y<<"|"<<mouseY<<"|"<<przycisk.getPosition().y+przycisk.getSize().y<<" "<<wybrana_postac<<std::endl;
                           // std::cout<<w.getPosition().x<<" "<<w.getPosition().y<<std::endl;
                            if(mouseX>przycisk1.getPosition().x && mouseX<przycisk1.getPosition().x+250 && mouseY>przycisk1.getPosition().y-140 && mouseY<przycisk1.getPosition().y+250)
                            {
                                wybrana_postac=false;
                            }
                            if(mouseX>przycisk2.getPosition().x && mouseX<przycisk2.getPosition().x+250 && mouseY>przycisk2.getPosition().y-140 && mouseY<przycisk2.getPosition().y+250)
                            {
                                w.close();
                            }
                        }
                }
            }
            w.draw(przycisk1);
            w.draw(przycisk2);
            w.draw(tekst2);
            w.draw(tekst1);
            w.draw(tekst_przycisku1);
            w.draw(tekst_przycisku2);
            w.display();
        }
    }
return 0;
}
