#include "poziom4.h"

Poziom4::Poziom4()
{
    this->name_="4";
    this->point_=8;


   this->  coordinates_.emplace_back(85,170);
   this->  coordinates_.emplace_back(320,170);
   this->  coordinates_.emplace_back(320,480);
   this->  coordinates_.emplace_back(1100,480);
   this->  coordinates_.emplace_back(1100,170);
   this->  coordinates_.emplace_back(1335,170);
   this->  coordinates_.emplace_back(1335,750);
   this->  coordinates_.emplace_back(85,750);





    this->undercut_.emplace_back(0,0);
    this->undercut_.emplace_back(565, 275);
    this->  meta_.emplace_back(0.4, 0.4);//setcale
    this->  meta_.emplace_back(1109,170);//Pozycja
    this->  spawn_.emplace_back(0.4,0.4);
    this->  spawn_.emplace_back(85,170);

    this->  spawn_hero_.x  =  175;
    this->  spawn_hero_.y  =  200;

    for(auto i=0;i<3;i++)//wiatraki
    {
    this->  balls_coordi_.emplace_back(280+(i*430),622);//środkowa kula /0
    //kule dalsze
    this->  balls_coordi_.emplace_back(380+(i*300),522);//1
    this->  balls_coordi_.emplace_back(380+(i*300),722);//2
    this->  balls_coordi_.emplace_back(280+(i*300),622);//3
    this->  balls_coordi_.emplace_back(480+(i*300),622);//4
    }
    this->  balls_coordi_.emplace_back(150,400);
    this->  balls_coordi_.emplace_back(1310,400);

    this->  balls_speed_.emplace_back(5,-6.5);
    this->  balls_num_ =balls_coordi_.size();
    this->coins_num_=6;
    this->coins_coordi_.emplace_back(200,450);
    this->coins_coordi_.emplace_back(1220,450);
    this->coins_coordi_.emplace_back(150,700);
    this->coins_coordi_.emplace_back(1270,700);
    this->coins_coordi_.emplace_back(500,650);
    this->coins_coordi_.emplace_back(950,650);
}
std::string Poziom4::getName()
{
    return name_;
}
int Poziom4:: getPoint()
{
    return point_;
}
int Poziom4::getBalls_num()
{
    return balls_num_;
}
int Poziom4:: getCoins_num()
{
    return coins_num_;
}
std::vector<sf::Vector2i>Poziom4:: getUndercut()
{
    return undercut_;
}
std::vector<sf::Vector2f>Poziom4::getBalls_coordi()
{
    return balls_coordi_;
}
std::vector<sf::Vector2f>Poziom4::getBalls_speed()
{
    return balls_speed_;
}
std::vector<sf::Vector2f>Poziom4::getCoordinates()
{
    return coordinates_;
}
std::vector<sf::Vector2f>Poziom4::getMeta()
{
    return meta_;
}
std::vector<sf::Vector2f>Poziom4::getSpawn()
{
    return spawn_;
}
sf::Vector2f Poziom4::getSpawn_hero()
{
    return spawn_hero_;
}
std::vector<sf::Vector2f> Poziom4:: getCoins_coordi()
{
    return coins_coordi_;
}
