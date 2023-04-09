#include "scena.h"
#include "menu.h"
#include "generator.h"
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <memory>

Scena::Scena(int X, int Y): window_(sf::VideoMode(X, Y), "FAST"), menu_(&window_),hero_(&window_),panel_(&window_)
  ,balls_(&window_),generator_(&window_),coins_(&window_)
{
    // create the window
    window_.setFramerateLimit(60);
    //menu_= create();
    balls_warun_=0;
    check_end_=0;
    warunek_=1;
    status_=0;
    status_poziom_=1;
    audio_.Playmusic();
}

void Scena::drawing_()//RYSOWANIE
{
    window_.clear(sf::Color::Black);
    switch(status_)
    {
    case 0: menu_.drawing();
        break;
    case 1: generator_.drawing();coins_.drawing();hero_.drawing();balls_.drawing();panel_.drawing();
        break;
    case 2: panel_.TheEnd();
        break;
    }

    window_.display();
}
void Scena:: loop()//PĘTLA
{
    while (window_.isOpen()) {
        sf::Event event;
        while (window_.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window_.close();
        }
        sf::Vector2f mouse_position = window_.mapPixelToCoords(sf::Mouse::getPosition(window_));//MENU GŁÓWNE
        if(status_==0)
        {
            for( auto i=0;i<menu_.getRectangles().size();i++)//menu początkowe
            {
                sf::FloatRect rectangle_bounds = menu_.getRectangles()[i].getGlobalBounds();
                if(mouse_position.x >rectangle_bounds.left && mouse_position.x<rectangle_bounds.left+rectangle_bounds.width
                        &&mouse_position.y >rectangle_bounds.top && mouse_position.y<rectangle_bounds.top+rectangle_bounds.height)
                {
                    menu_.check(i);
                    if (event.type == sf::Event::MouseButtonPressed) {
                        if(event.mouseButton.button == sf::Mouse::Left) {
                            switch(i)
                            {
                            case 0:status_=1;//Graj!!
                                break;
                            case 1: std::cout<<3<<std::endl;window_.close();//wyjdz
                                break;
                            }
                        }
                    }
                }
                else
                {
                    menu_.check2(i);
                }

            }
        }
        else if(status_==1)
        {

            this->poziom_();
            sf::FloatRect rectangle_bounds = panel_.GetElementIkon().getGlobalBounds();//to jest ikona na pasku
            if(mouse_position.x >rectangle_bounds.left && mouse_position.x<rectangle_bounds.left+rectangle_bounds.width
                    &&mouse_position.y >rectangle_bounds.top && mouse_position.y<rectangle_bounds.top+rectangle_bounds.height)
            {
                panel_.check();  //zmiana koloru po najechaniu
                if (event.type == sf::Event::MouseButtonPressed) {
                    if(event.mouseButton.button == sf::Mouse::Left) {
                        status_=0;//powrót do menu po klinknieciu
                    }
                }
            }
            else
            {
                panel_.check2();//kolor bialy
            }
        }
        else if(status_==2)
        {
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            {
                  window_.close();
            }
        }
        this->drawing_();
    }
}
void Scena::poziom_()
{
    panel_.work();
    if(status_poziom_==1)//poziom1
    {
        if(warunek_==1)
        {
            panel_.Poziom_num(poziom1_.getName());
            hero_.parameters(poziom1_.getSpawn_hero());
            balls_.parameters(poziom1_.getBalls_coordi(), poziom1_.getBalls_num(),poziom1_.getBalls_speed(),poziom1_.getName());
            coins_.parameters(poziom1_.getCoins_coordi(), poziom1_.getCoins_num());
            warunek_=0;
            balls_warun_=poziom1_.getCoins_num();
        }
        generator_.create(poziom1_.getPoint(),poziom1_.getCoordinates(),poziom1_.getMeta(),poziom1_.getSpawn(),poziom1_.getUndercut(),poziom1_.getSpawn_hero(),poziom1_.getName());//tworzenie mapy
        hero_.work(generator_.getMap(),poziom1_.getName());//granice mapy
        balls_.work(generator_.getMap(), poziom1_.getBalls_num(),poziom1_.getName());//granice i paramtry kulek
        coins_.work();
    }
    else if(status_poziom_==2)
    {
        if(warunek_==1)
        {
            panel_.Poziom_num(poziom2_.getName());
            hero_.parameters(poziom2_.getSpawn_hero());
            balls_.parameters(poziom2_.getBalls_coordi(), poziom2_.getBalls_num(),poziom2_.getBalls_speed(),poziom2_.getName());
            coins_.parameters(poziom2_.getCoins_coordi(), poziom2_.getCoins_num());
            warunek_=0;
            balls_warun_=poziom2_.getCoins_num();
        }
        generator_.create(poziom2_.getPoint(),poziom2_.getCoordinates(),poziom2_.getMeta(),poziom2_.getSpawn(),poziom2_.getUndercut(),poziom2_.getSpawn_hero(),poziom2_.getName());//tworzenie mapy
        hero_.work(generator_.getMap(),poziom2_.getName());//granice mapy
        balls_.work(generator_.getMap(), poziom2_.getBalls_num(),poziom2_.getName());//granice i paramtry kulek
        coins_.work();
    }
    else if(status_poziom_==3)
    {
        if(warunek_==1)
        {
            panel_.Poziom_num(poziom3_.getName());
            hero_.parameters(poziom3_.getSpawn_hero());
            balls_.parameters(poziom3_.getBalls_coordi(), poziom3_.getBalls_num(),poziom3_.getBalls_speed(),poziom3_.getName());
            coins_.parameters(poziom3_.getCoins_coordi(), poziom3_.getCoins_num());
            warunek_=0;
            balls_warun_=poziom3_.getCoins_num();
        }
        generator_.create(poziom3_.getPoint(),poziom3_.getCoordinates(),poziom3_.getMeta(),poziom3_.getSpawn(),poziom3_.getUndercut(),poziom3_.getSpawn_hero(),poziom3_.getName());//tworzenie mapy
        hero_.work(generator_.getMap(),poziom3_.getName());//granice mapy
        balls_.work(generator_.getMap(), poziom3_.getBalls_num(),poziom3_.getName());//granice i paramtry kulek
        coins_.work();
    }
    else if(status_poziom_==4)
    {
        if(warunek_==1)
        {
            panel_.Poziom_num(poziom4_.getName());
            hero_.parameters(poziom4_.getSpawn_hero());
            balls_.parameters(poziom4_.getBalls_coordi(), poziom4_.getBalls_num(),poziom4_.getBalls_speed(),poziom4_.getName());
            coins_.parameters(poziom4_.getCoins_coordi(), poziom4_.getCoins_num());
            warunek_=0;
            balls_warun_=poziom4_.getCoins_num();
        }
        generator_.create(poziom4_.getPoint(),poziom4_.getCoordinates(),poziom4_.getMeta(),poziom4_.getSpawn(),poziom4_.getUndercut(),poziom4_.getSpawn_hero(),poziom4_.getName());//tworzenie mapy
        hero_.work(generator_.getMap(),poziom4_.getName());//granice mapy
        balls_.work(generator_.getMap(), poziom4_.getBalls_num(),poziom4_.getName());//granice i paramtry kulek
        coins_.work();
    }
    else if(status_poziom_==5)
    {
        if(warunek_==1)
        {
            panel_.Poziom_num(poziom5_.getName());
            hero_.parameters(poziom5_.getSpawn_hero());
            balls_.parameters(poziom5_.getBalls_coordi(), poziom5_.getBalls_num(),poziom5_.getBalls_speed(),poziom5_.getName());
            coins_.parameters(poziom5_.getCoins_coordi(), poziom5_.getCoins_num());
            warunek_=0;
            balls_warun_=poziom5_.getCoins_num();
        }
        generator_.create(poziom5_.getPoint(),poziom5_.getCoordinates(),poziom5_.getMeta(),poziom5_.getSpawn(),poziom5_.getUndercut(),poziom5_.getSpawn_hero(),poziom5_.getName());//tworzenie mapy
        hero_.work(generator_.getMap(),poziom5_.getName());//granice mapy
        balls_.work(generator_.getMap(), poziom5_.getBalls_num(),poziom5_.getName());//granice i paramtry kulek
        coins_.work();
    }
    this->warunki_();
}
void Scena::warunki_()
{
    //zbieranie monet
    for(auto it=coins_.coins.begin();it!=coins_.coins.end();) //zderzenia z obiektami
    {
        if(hero_.getHero().getGlobalBounds().intersects((*it)->getGlobalBounds()))//sprawdza zderzenia hero z moneta
        {
            it=coins_.coins.erase(it);//usuwam obiekt i zwracam iterator
            panel_.coins(1);
            check_end_++;
            audio_.playcoin();
        }
        else
        {
            it++;//to musi byc tu
        }
    }

    //zderzenia z kulkami
    for(auto it=balls_.balls_.begin();it!=balls_.balls_.end();it++) //zderzenia z obiektami
    {
        if(hero_.getHero().getGlobalBounds().intersects((*it)->getGlobalBounds()))//sprawdza zderzenia hero z kulka
        {
            hero_.backToSpawn(generator_.getSpawn_hero());
            panel_.death(1);
            audio_.playkill();
        }
    }
    //warunek i przejście do następnego poziomu

    if(check_end_==balls_warun_)
    {
        if(hero_.getHero().getGlobalBounds().intersects((generator_.getMeta_end()).getGlobalBounds()))//zderzenia hero i kulki
        {
            status_poziom_++;
            check_end_=0;
            balls_.balls_.erase(balls_.balls_.begin(),balls_.balls_.end());//usuwam stare kulki zeby zrobić miejsce dla nowych
            warunek_=1;
            if(status_poziom_==6)
            {
                status_=2;

            }

        }
    }
}
