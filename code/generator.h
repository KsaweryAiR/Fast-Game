#ifndef GENERATOR_H
#define GENERATOR_H
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <memory>
#include "poziomtextury.h"


class Generator : public PoziomTextury
{
    sf::Sprite tapeta;
    sf::RenderWindow *window_;
    sf::ConvexShape map_;
    sf::Vector2f start;
    sf::Sprite meta_end_;
    sf::Vector2f spawn_hero_;
    std::string name_;
public:
    //muszą być public bo przekazują elementy dalej i mogą być modyfikowane przez inne klasy i użytownika
    Generator(sf::RenderWindow *w);
    void create(const int point, const std::vector<sf::Vector2f> &coordinates , const std::vector<sf::Vector2f> &meta,const std::vector<sf::Vector2f> &spawn
                ,const std::vector<sf::Vector2i> &undercut, const sf::Vector2f &spawn_hero_new,const std::string &name);
    sf::ConvexShape getMap();
    sf::Sprite getMeta_end();
    void drawing();
    sf::Vector2f getSpawn_hero();
};

#endif // GENERATOR_H
