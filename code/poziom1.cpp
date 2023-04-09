#include "poziom1.h"

Poziom1::Poziom1()
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
//void Poziom1:: setName(std::string value)
//{
//    this->name=value;
//}
std::string Poziom1::getName()
{
    return name_;
}
int Poziom1:: getPoint()
{
    return point_;
}
int Poziom1::getBalls_num()
{
    return balls_num_;
}
int Poziom1:: getCoins_num()
{
    return coins_num_;
}
std::vector<sf::Vector2i>Poziom1:: getUndercut()
{
    return undercut_;
}
std::vector<sf::Vector2f>Poziom1::getBalls_coordi()
{
    return balls_coordi_;
}
std::vector<sf::Vector2f>Poziom1::getBalls_speed()
{
    return balls_speed_;
}
std::vector<sf::Vector2f>Poziom1::getCoordinates()
{
    return coordinates_;
}
std::vector<sf::Vector2f>Poziom1::getMeta()
{
    return meta_;
}
std::vector<sf::Vector2f>Poziom1::getSpawn()
{
    return spawn_;
}
sf::Vector2f Poziom1::getSpawn_hero()
{
    return spawn_hero_;
}
std::vector<sf::Vector2f> Poziom1:: getCoins_coordi()
{
    return coins_coordi_;
}
