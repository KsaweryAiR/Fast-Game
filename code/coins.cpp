#include "coins.h"

Coins::Coins(sf::RenderWindow *w):window_(w)
{
    if (!moneta->loadFromFile("moneta.png")) {
        throw("Could not load texture");
    }
    this->rotate_=1;
}
void Coins:: drawing()
{
    for(auto &s : coins) {

        window_->draw(*s);
    }
}
void Coins:: parameters(const std::vector<sf::Vector2f> &coins_coordi, const int &coins_num)
{

    for(auto i=0;i<coins_num;i++)
    {
        auto circle=std::make_unique<sf::CircleShape>();
        circle->setRadius(40);
        circle->setTexture(&*moneta);
        circle->setOrigin(circle->getRadius(),circle->getRadius());
        circle->setPosition(coins_coordi[i].x,coins_coordi[i].y);
        circle->setOutlineColor(sf::Color(197,179,88));
        circle->setOutlineThickness(2);
        coins.emplace_back(move(circle));
    }

}
void Coins:: work()
{
    for(auto &s : coins) {
        s->rotate(rotate_);
    }
}

