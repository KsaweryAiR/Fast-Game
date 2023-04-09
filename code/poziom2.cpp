#include "poziom2.h"

Poziom2::Poziom2()
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

    for(auto i=0;i<3;i++)//bumerang
    {
    this->  balls_coordi_.emplace_back(380+(i*300),312);//środkowa kula
    //kule dalsze
    this->  balls_coordi_.emplace_back(380+(i*300),212);
    this->  balls_coordi_.emplace_back(380+(i*300),412);
    //kule blizsze
    this->  balls_coordi_.emplace_back(380+(i*300),262);
    this->  balls_coordi_.emplace_back(380+(i*300),362);
    }

    for(auto i=0;i<3;i++)//wiatraki
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
std::string Poziom2::getName()
{
    return name_;
}
int Poziom2:: getPoint()
{
    return point_;
}
int Poziom2::getBalls_num()
{
    return balls_num_;
}
int Poziom2:: getCoins_num()
{
    return coins_num_;
}
std::vector<sf::Vector2i>Poziom2:: getUndercut()
{
    return undercut_;
}
std::vector<sf::Vector2f>Poziom2::getBalls_coordi()
{
    return balls_coordi_;
}
std::vector<sf::Vector2f>Poziom2::getBalls_speed()
{
    return balls_speed_;
}
std::vector<sf::Vector2f>Poziom2::getCoordinates()
{
    return coordinates_;
}
std::vector<sf::Vector2f>Poziom2::getMeta()
{
    return meta_;
}
std::vector<sf::Vector2f>Poziom2::getSpawn()
{
    return spawn_;
}
sf::Vector2f Poziom2::getSpawn_hero()
{
    return spawn_hero_;
}
std::vector<sf::Vector2f> Poziom2:: getCoins_coordi()
{
    return coins_coordi_;
}
