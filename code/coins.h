#ifndef COINS_H
#define COINS_H
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "poziomtextury.h"

class Coins :public PoziomTextury
{
    int rotate_;
    std::unique_ptr<sf::Texture>moneta =std::make_unique<sf::Texture>();
    sf::RenderWindow *window_;
public:
    Coins(sf::RenderWindow *w);
    std::vector<std::unique_ptr <sf::CircleShape>>coins;
    void drawing();
    void work();
    void parameters(const std::vector<sf::Vector2f> &coins_coordi, const int &coins_num);
};

#endif // COINS_H
