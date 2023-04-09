#ifndef HERO_H
#define HERO_H
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Hero
{
      sf::RenderWindow *window_;
      sf::Vector2f spawn_;
      sf::RectangleShape hero_;
public:
    Hero(sf::RenderWindow *w);
    sf::RectangleShape getHero();
    void work(const sf::ConvexShape &map,const std::string &name);
    void drawing();
    void parameters(const sf::Vector2f &start);
    void backToSpawn(const sf::Vector2f &spawn_hero);
};

#endif // HERO_H
