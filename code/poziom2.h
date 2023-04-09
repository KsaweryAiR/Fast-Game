#ifndef POZIOM2_H
#define POZIOM2_H
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <memory>
#include "poziomabstra.h"

class Poziom2: public PoziomAbstra
{
public:
    Poziom2();
    std::string getName();
    int getCoins_num();//liczna monet
    int getPoint();//ile współrzędnych ma mapa
    int getBalls_num();//liczba kólek
    std::vector<sf::Vector2i>getUndercut();
    std::vector<sf::Vector2f>getBalls_coordi();//współrzędne kulek
    std::vector<sf::Vector2f>getBalls_speed();
    std::vector<sf::Vector2f>getCoordinates();//współrzędne mapy
    std::vector<sf::Vector2f>getMeta();//różne dane mety
    std::vector<sf::Vector2f>getSpawn();//różne dane mety
    sf::Vector2f getSpawn_hero();//miejsce kwadratu
    std::vector<sf::Vector2f>getCoins_coordi();//współrzędne monet
};

#endif // POZIOM2_H
