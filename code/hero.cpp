#include "hero.h"

Hero::Hero(sf::RenderWindow *w):window_(w)
{
    hero_.setSize(sf::Vector2f(40.0, 40.0));
    hero_.setFillColor(sf::Color::Red);
}
sf::RectangleShape Hero:: getHero()
{
    return hero_;
}
void  Hero:: backToSpawn(const sf::Vector2f &spawn_hero)
{
    hero_.setPosition(spawn_hero.x,spawn_hero.y);
}
void Hero:: work(const sf::ConvexShape &map,const std::string &name)//ruch bohatera na danych mapach z granicami
{

    sf::FloatRect hero_bounds = hero_.getGlobalBounds();
    if(name=="1")
    {
        if(hero_bounds.top<= map.getPoint(0).y) {this->hero_.move(0,0);}
        else{if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {this->hero_.move(0,-4);}}
        if (hero_bounds.top+hero_bounds.height >= map.getPoint(3).y) {this->hero_.move(0,0);}
        else{if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {this->hero_.move(0,4);}}
        if (hero_bounds.left<=map.getPoint(0).x) {this->hero_.move(0,0);}
        else{if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {this->hero_.move(-4,0);}}
        if (hero_bounds.left+hero_bounds.width >=map.getPoint(1).x) {this->hero_.move(0,0);}
        else{if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {this->hero_.move(4,0);}}

    }
    if(name=="2")
    {
        if(hero_bounds.top+hero_bounds.height <= map.getPoint(6).y||hero_bounds.top>= map.getPoint(5).y)//lewa strona
        {
            if (hero_bounds.left<=map.getPoint(0).x) {this->hero_.move(0,0);}
            else{if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {this->hero_.move(-4,0);}}
            if (hero_bounds.left+hero_bounds.width >=map.getPoint(1).x) {this->hero_.move(0,0);}
            else{if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {this->hero_.move(4,0);}}
        }
        else //prawa strona, pionowa
        {
            if (hero_bounds.left<=map.getPoint(6).x+9) {this->hero_.move(0,0);}
            else{if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {this->hero_.move(-4,0);}}
            if (hero_bounds.left+hero_bounds.width >=map.getPoint(2).x) {this->hero_.move(0,0);}
            else{if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {this->hero_.move(4,0);}}
        }
        if(hero_bounds.left<=map.getPoint(6).x&&hero_bounds.top+hero_bounds.height<=map.getPoint(6).y)//górny
        {
            if(hero_bounds.top<= map.getPoint(0).y){this->hero_.move(0,0);}
            else{if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {this->hero_.move(0,-4);}}
            if (hero_bounds.top+hero_bounds.height >= map.getPoint(7).y-9) {this->hero_.move(0,0);}
            else{if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {this->hero_.move(0,4);}}
        }
        else if (hero_bounds.left <=map.getPoint(5).x&&hero_bounds.top>=map.getPoint(5).y)//dolny
        {
            if(hero_bounds.top<= map.getPoint(5).y+9) {this->hero_.move(0,0);}
            else{if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {this->hero_.move(0,-4);}}
            if (hero_bounds.top+hero_bounds.height >= map.getPoint(3).y) {this->hero_.move(0,0);}
            else{if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {this->hero_.move(0,4);}}
        }
        else //prawa strona, pionowa
        {
            if(hero_bounds.top<= map.getPoint(1).y) {this->hero_.move(0,0);}
            else{if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {this->hero_.move(0,-4);}}
            if (hero_bounds.top+hero_bounds.height >= map.getPoint(2).y) {this->hero_.move(0,0);}
            else{if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {this->hero_.move(0,4);}}
        }
    }
    if(name=="3")
    {
        if(hero_bounds.top<= map.getPoint(0).y) {this->hero_.move(0,0);}
        else{if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {this->hero_.move(0,-4);}}
        if (hero_bounds.top+hero_bounds.height >= map.getPoint(19).y) {this->hero_.move(0,0);}
        else{if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {this->hero_.move(0,4);}}
        if (hero_bounds.left<=map.getPoint(0).x) {this->hero_.move(0,0);}
        else{if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {this->hero_.move(-4,0);}}
        if (hero_bounds.left+hero_bounds.width >=map.getPoint(9).x) {this->hero_.move(0,0);}
        else{if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {this->hero_.move(4,0);}}
    }
     if(name=="4")
     {
         if(hero_bounds.top+hero_bounds.height < map.getPoint(2).y)
         {

             if (hero_bounds.left<=map.getPoint(0).x) {this->hero_.move(0,0);}
             else{if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {this->hero_.move(-4,0);}}
             if (hero_bounds.left+hero_bounds.width >=map.getPoint(2).x-1) {this->hero_.move(0,0);}
             else{if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {this->hero_.move(4,0);}}
         }
         else if(hero_bounds.top+hero_bounds.height >= map.getPoint(2).y)
         {
             if (hero_bounds.left<=map.getPoint(0).x) {this->hero_.move(0,0);}
             else{if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {this->hero_.move(-4,0);}}
             if (hero_bounds.left+hero_bounds.width >=map.getPoint(5).x-1) {this->hero_.move(0,0);}
             else{if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {this->hero_.move(4,0);}}
         }
         if(hero_bounds.left+hero_bounds.width <=map.getPoint(2).x||hero_bounds.left+hero_bounds.width >=map.getPoint(3).x)
         {
             if(hero_bounds.top<= map.getPoint(0).y) {this->hero_.move(0,0);}
             else{if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {this->hero_.move(0,-4);}}
             if (hero_bounds.top+hero_bounds.height >= map.getPoint(7).y) {this->hero_.move(0,0);}
             else{if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {this->hero_.move(0,4);}}
         }
         else if (hero_bounds.left+hero_bounds.width >=map.getPoint(2).x)
         {
             if(hero_bounds.top<= map.getPoint(2).y) {this->hero_.move(0,0);}
             else{if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {this->hero_.move(0,-4);}}
             if (hero_bounds.top+hero_bounds.height >= map.getPoint(7).y) {this->hero_.move(0,0);}
             else{if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {this->hero_.move(0,4);}}
         }
     }
     if(name=="5")
     {
         if(hero_bounds.top<= map.getPoint(0).y) {this->hero_.move(0,0);}
         else{if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {this->hero_.move(0,-4);}}
         if (hero_bounds.top+hero_bounds.height >= map.getPoint(3).y) {this->hero_.move(0,0);}
         else{if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {this->hero_.move(0,4);}}
         if (hero_bounds.left<=map.getPoint(0).x) {this->hero_.move(0,0);}
         else{if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {this->hero_.move(-4,0);}}
         if (hero_bounds.left+hero_bounds.width >=map.getPoint(1).x) {this->hero_.move(0,0);}
         else{if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {this->hero_.move(4,0);}}

     }

}

void Hero::drawing()
{
    window_->draw(hero_);
}
void Hero:: parameters(const sf::Vector2f &start)
{
    hero_.setPosition(start);
}
