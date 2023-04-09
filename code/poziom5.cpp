#include "poziom5.h"

Poziom5::Poziom5()
{
    this->name_="5";
    this->point_=4;


    this->  coordinates_.emplace_back(50.0, 175.0);
    this->  coordinates_.emplace_back(1350.0, 175.0);
    this->  coordinates_.emplace_back (1350.0, 775.0);
    this->  coordinates_.emplace_back(50.0, 775.0);


    this->undercut_.emplace_back(0,0);
    this->undercut_.emplace_back(275, 275);
    this->  meta_.emplace_back(0.4, 0.4);//setcale
    this->  meta_.emplace_back(50,665);//Pozycja
    this->  spawn_.emplace_back(0.4,0.4);
    this->  spawn_.emplace_back(50,175);

    this->  spawn_hero_.x  =  80;
    this->  spawn_hero_.y  =  210;

    for(auto i=0;i<2;i++)//wiatraki
    {
    this->  balls_coordi_.emplace_back(380+(i*750),667-(i*390));//środkowa kula
    //kule dalsze
    this->  balls_coordi_.emplace_back(380+(i*750),587-(i*390));
    this->  balls_coordi_.emplace_back(380+(i*750),747-(i*390));
    this->  balls_coordi_.emplace_back(280+(i*750),667-(i*390));
    this->  balls_coordi_.emplace_back(480+(i*750),667-(i*390));
    //kule blizsze
    this->  balls_coordi_.emplace_back(380+(i*750),627-(i*390));
    this->  balls_coordi_.emplace_back(380+(i*750),707-(i*390));
    this->  balls_coordi_.emplace_back(330+(i*750),667-(i*390));
    this->  balls_coordi_.emplace_back(430+(i*750),667-(i*390));
    }

    this->  balls_coordi_.emplace_back(400,230);
    this->  balls_coordi_.emplace_back(800,325);
    this->  balls_coordi_.emplace_back(800,630);
    this->  balls_coordi_.emplace_back(400,725);
    this->  balls_coordi_.emplace_back(1250,470);

    for(auto it=0;it<2;it++)
    {
        for(auto i=0;i<20;i++)
        {
            this->  balls_coordi_.emplace_back(370+(i*40),555-(it*165));
        }
    }

    for(auto it=0;it<2;it++)
    {
        for(auto i=0;i<3;i++)
        {
            this->  balls_coordi_.emplace_back(370+(it*760),433+(i*40));
        }
    }
    for(auto it=0;it<2;it++)
    {
        for(auto i=0;i<2;i++)
        {
            this->  balls_coordi_.emplace_back(70+(i*40),312+(it*320));
        }
    }
    for(auto i=0;i<7;i++)
    {
        this->  balls_coordi_.emplace_back(110,352+(i*40));
    }






    this->  balls_speed_.emplace_back(4,4);
    this->  balls_num_ =balls_coordi_.size();
    this->coins_num_=7;
    this->coins_coordi_.emplace_back(430,250);
    this->coins_coordi_.emplace_back(1220,250);
    this->coins_coordi_.emplace_back(430,700);
    this->coins_coordi_.emplace_back(1220,700);
    this->coins_coordi_.emplace_back(1240,475);
    this->coins_coordi_.emplace_back(200,475);
    this->coins_coordi_.emplace_back(950,650);
}
std::string Poziom5::getName()
{
    return name_;
}
int Poziom5:: getPoint()
{
    return point_;
}
int Poziom5::getBalls_num()
{
    return balls_num_;
}
int Poziom5:: getCoins_num()
{
    return coins_num_;
}
std::vector<sf::Vector2i>Poziom5:: getUndercut()
{
    return undercut_;
}
std::vector<sf::Vector2f>Poziom5::getBalls_coordi()
{
    return balls_coordi_;
}
std::vector<sf::Vector2f>Poziom5::getBalls_speed()
{
    return balls_speed_;
}
std::vector<sf::Vector2f>Poziom5::getCoordinates()
{
    return coordinates_;
}
std::vector<sf::Vector2f>Poziom5::getMeta()
{
    return meta_;
}
std::vector<sf::Vector2f>Poziom5::getSpawn()
{
    return spawn_;
}
sf::Vector2f Poziom5::getSpawn_hero()
{
    return spawn_hero_;
}
std::vector<sf::Vector2f> Poziom5:: getCoins_coordi()
{
    return coins_coordi_;
}

