#include "poziom3.h"

Poziom3::Poziom3()
{
    this->name_="3";
    this->point_=20;
    for(auto i=0;i<2;i++)
    {
    this->  coordinates_.emplace_back(25.0+(1325.0*i), 340.0+(i*220));
    this->  coordinates_.emplace_back(270.0+(820.0*i), 340.0+(i*220));
    this->  coordinates_.emplace_back(270.0+(820.0*i), 115.0+(i*700));
    this->  coordinates_.emplace_back(520.0+(320.0*i), 115.0+(i*700));
    this->  coordinates_.emplace_back(520.0+(320.0*i), 340.0+(i*220));
    this->  coordinates_.emplace_back(840.0+(-320.0*i), 340.0+(i*220));

    this->  coordinates_.emplace_back(840.0+(-320.0*i), 115.0+(i*700));
    this->  coordinates_.emplace_back(1090.0+(-820.0*i), 115.0+(i*700));
    this->  coordinates_.emplace_back(1090.0+(-820.0*i), 340.0+(i*220));
    this->  coordinates_.emplace_back(1350.0+(-1325.0*i), 340.0+(i*220));
    }
    this->undercut_.emplace_back(0,0);
    this->undercut_.emplace_back(275, 550);
    this->  meta_.emplace_back(0.4, 0.4);//setcale
    this->  meta_.emplace_back(1240,340);//Pozycja
    this->  spawn_.emplace_back(0.4,0.4);
    this->  spawn_.emplace_back(25,340);

    this->  spawn_hero_.x  =  60;
    this->  spawn_hero_.y  =  430;

    // strzałki 66
    for (auto it=0;it<2;it++)
    {
        for(auto i =0;i<3;i++)
        {
            this->  balls_coordi_.emplace_back(390+(580*it),500+(60*i-(340*it)));
        }
        for(auto i =0;i<3;i++)
        {
            this->  balls_coordi_.emplace_back(370+(580*it),530+(60*i-(340*it)));
            this->  balls_coordi_.emplace_back(410+(580*it),530+(60*i-(340*it)));
        }
        for(auto i =0;i<2;i++)
        {
            this->  balls_coordi_.emplace_back(350+(580*it),560+(60*i-(340*it)));
            this->  balls_coordi_.emplace_back(430+(580*it),560+(60*i-(340*it)));
        }
        for(auto i =0;i<3;i++)
        {
            this->  balls_coordi_.emplace_back(330-(20*i)+(580*it),590+(30*i-(340*it)));
            this->  balls_coordi_.emplace_back(450+(20*i)+(580*it),590+(30*i-(340*it)));
        }
        this->  balls_coordi_.emplace_back(330+(580*it),650-(340*it));
        this->  balls_coordi_.emplace_back(450+(580*it),650-(340*it));

        for(auto i =0;i<4;i++)
        {
            this->  balls_coordi_.emplace_back(350+(580*it),680+(40*i-(340*it)));
            this->  balls_coordi_.emplace_back(390+(580*it),680+(40*i-(340*it)));
            this->  balls_coordi_.emplace_back(430+(580*it),680+(40*i-(340*it)));
        }
    }

    this->  balls_speed_.emplace_back(0,-6.5);
    this->  balls_num_ =balls_coordi_.size();
    this->coins_num_=5;
    this->coins_coordi_.emplace_back(620,400);
    this->coins_coordi_.emplace_back(754,400);
    this->coins_coordi_.emplace_back(620,500);
    this->coins_coordi_.emplace_back(754,500);
    this->coins_coordi_.emplace_back(687,450);
}
std::string Poziom3::getName()
{
    return name_;
}
int Poziom3:: getPoint()
{
    return point_;
}
int Poziom3::getBalls_num()
{
    return balls_num_;
}
int Poziom3:: getCoins_num()
{
    return coins_num_;
}
std::vector<sf::Vector2i>Poziom3:: getUndercut()
{
    return undercut_;
}
std::vector<sf::Vector2f>Poziom3::getBalls_coordi()
{
    return balls_coordi_;
}
std::vector<sf::Vector2f>Poziom3::getBalls_speed()
{
    return balls_speed_;
}
std::vector<sf::Vector2f>Poziom3::getCoordinates()
{
    return coordinates_;
}
std::vector<sf::Vector2f>Poziom3::getMeta()
{
    return meta_;
}
std::vector<sf::Vector2f>Poziom3::getSpawn()
{
    return spawn_;
}
sf::Vector2f Poziom3::getSpawn_hero()
{
    return spawn_hero_;
}
std::vector<sf::Vector2f> Poziom3:: getCoins_coordi()
{
    return coins_coordi_;
}
