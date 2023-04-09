#include "poziom.h"

Poziom::Poziom(sf::RenderWindow *w):hero_(w),panel_(w),balls_(w),generator_(w),coins_(w)
{
    check_end_=0;
    warunek_=1;
    status_poziom_=1;
}
void Poziom::rysuj(sf::RenderTarget &window_)
{
    generator_.drawing();panel_.drawing();coins_.drawing();hero_.drawing();balls_.drawing();
}
void Poziom::DanePoziom1()
{
    this->name_="1";
    this->point_=4;
    this->  coordinates_.emplace_back(100.0, 200.0);
    this->  coordinates_.emplace_back(1300.0, 200.0);
    this->  coordinates_.emplace_back (1300.0, 700.0);
    this->  coordinates_.emplace_back(100.0, 700.0);

    this->undercut_.emplace_back(0,0);
    this->undercut_.emplace_back(275, 1250);
    this->  meta_.emplace_back(0.4, 0.4);//setcale
    this->  meta_.emplace_back(1190,200);//Pozycja
    this->  spawn_.emplace_back(0.4,0.4);
    this->  spawn_.emplace_back(100,200);
    this->  spawn_hero_.x  =  135;
    this->  spawn_hero_.y  =  430;


    this->  balls_coordi_.emplace_back(400,450);
    this->  balls_coordi_.emplace_back(500,450);
    this->  balls_coordi_.emplace_back(600,450);
    this->  balls_coordi_.emplace_back(700,450);
    this->  balls_coordi_.emplace_back(800,450);
    this->  balls_coordi_.emplace_back(900,450);
    this->  balls_coordi_.emplace_back(1000,450);
    this->  balls_speed_.emplace_back(0,-10);

    this->  balls_num_ =balls_coordi_.size();

    this->coins_num_=3;
    this->coins_coordi_.emplace_back(500,300);
    this->coins_coordi_.emplace_back(700,500);
    this->coins_coordi_.emplace_back(1000,600);
}
void Poziom:: DanePoziom2()
{
    this->name_="2";
    this->point_=8;

    this->  coordinates_.emplace_back(50.0, 170.0);
    this->  coordinates_.emplace_back(1300.0, 170.0);
    this->  coordinates_.emplace_back (1300.0, 750.0);
    this->  coordinates_.emplace_back(50.0, 750.0);
    this->  coordinates_.emplace_back(50.0, 465.0);
    this->  coordinates_.emplace_back(1050.0, 465.0);
    this->  coordinates_.emplace_back(1050.0, 455.0);
    this->  coordinates_.emplace_back(50.0, 455.0);

    this->undercut_.emplace_back(0,0);
    this->undercut_.emplace_back(275, 690);
    this->  meta_.emplace_back(0.4, 0.4);//setcale
    this->  meta_.emplace_back(50,474);//Pozycja
    this->  spawn_.emplace_back(0.4,0.4);
    this->  spawn_.emplace_back(50,170);

    this->  spawn_hero_.x  =  90;
    this->  spawn_hero_.y  =  280;

    for(auto i=0;i<3;i++)
    {
    this->  balls_coordi_.emplace_back(380+(i*300),312);//środkowa kula
    //kule dalsze
    this->  balls_coordi_.emplace_back(380+(i*300),212);
    this->  balls_coordi_.emplace_back(380+(i*300),412);
    //kule blizsze
    this->  balls_coordi_.emplace_back(380+(i*300),262);
    this->  balls_coordi_.emplace_back(380+(i*300),362);
    }

    for(auto i=0;i<3;i++)
    {
    this->  balls_coordi_.emplace_back(380+(i*300),607);//środkowa kula
    //kule dalsze
    this->  balls_coordi_.emplace_back(380+(i*300),507);
    this->  balls_coordi_.emplace_back(380+(i*300),707);
    this->  balls_coordi_.emplace_back(280+(i*300),607);
    this->  balls_coordi_.emplace_back(480+(i*300),607);
    //kule blizsze
    this->  balls_coordi_.emplace_back(380+(i*300),557);
    this->  balls_coordi_.emplace_back(380+(i*300),657);
    this->  balls_coordi_.emplace_back(330+(i*300),607);
    this->  balls_coordi_.emplace_back(430+(i*300),607);
    }

    this->  balls_speed_.emplace_back(0,0);

    this->  balls_num_ =balls_coordi_.size();

    this->coins_num_=4;
    this->coins_coordi_.emplace_back(500,380);
    this->coins_coordi_.emplace_back(900,225);
    this->coins_coordi_.emplace_back(950,700);
    this->coins_coordi_.emplace_back(300,550);
}
void Poziom::CreatPoziom()
{
    DanePoziom1();
    if(status_poziom_==1)
    {
    DanePoziom1();
    }
    else if (status_poziom_==2)
    {
    DanePoziom2();
    }
    if(warunek_==1)
    {
       ParametersPoziom();
        warunek_=0;
    }
    generator_.create(point_,coordinates_,meta_,spawn_,undercut_,spawn_hero_);//tworzenie mapy
    hero_.work(generator_.map,name_);//granice mapy
    balls_.work(generator_.map, balls_num_,name_);//granice i paramtry kulek
    warunki_();
}
void Poziom:: ParametersPoziom()
{
    //DanePoziom1();
    panel_.Poziom_num(name_);
    hero_.parameters(spawn_hero_);
    balls_.parameters(balls_coordi_, balls_num_,balls_speed_,name_);
    coins_.parameters(coins_coordi_, coins_num_);
}
void Poziom::warunki_()
{
     //DanePoziom1();
    //zbieranie monet
    for(auto it=coins_.coins.begin();it!=coins_.coins.end();) //zderzenia z obiektami
    {
        if(hero_.hero.getGlobalBounds().intersects((*it)->getGlobalBounds()))//sprawdza zderzenia hero z moneta
        {
            it=coins_.coins.erase(it);//usuwam obiekt i zwracam iterator
            panel_.coins(1);
            check_end_++;
        }
        else
        {
            it++;//to musi byc tu
        }
    }
    //warunek i przejście do następnego poziomu
    if(check_end_==coins_num_)
    {
        if(hero_.hero.getGlobalBounds().intersects((generator_.meta_end).getGlobalBounds()))//zderzenia hero i kulki
        {
            status_poziom_++;
            check_end_=0;
            balls_.balls.erase(balls_.balls.begin(),balls_.balls.end());//usuwam stare kulki zeby zrobić miejsce dla nowych
            warunek_=1;
        }
    }
    //zderzenia z kulkami
            for(auto it=balls_.balls.begin();it!=balls_.balls.end();it++) //zderzenia z obiektami
            {
                if(hero_.hero.getGlobalBounds().intersects((*it)->getGlobalBounds()))//sprawdza zderzenia hero z kulka
                {
                    hero_.hero.setPosition(generator_.spawn_hero.x,generator_.spawn_hero.y);
                    panel_.death(1);
                }
            }
}
