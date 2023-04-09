#ifndef POZIOM1_H
#define POZIOM1_H
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <memory>
#include "poziomabstra.h"

class Poziom1 : public PoziomAbstra
{
public:
    Poziom1();
    //void setName(std::string value);
    //to musi tak być bo inaczej klasa z której dziedzicze musiałaby mieć wartości public ;(
    std::string getName();
    int getCoins_num();//liczna monet
    int getPoint();//ile współrzędnych ma mapa
    int getBalls_num();//liczba kólek
    std::vector<sf::Vector2i>getUndercut();//podcięcie tekstury
    std::vector<sf::Vector2f>getBalls_coordi();//współrzędne kulek
    std::vector<sf::Vector2f>getBalls_speed();
    std::vector<sf::Vector2f>getCoordinates();//współrzędne mapy
    std::vector<sf::Vector2f>getMeta();//różne dane mety
    std::vector<sf::Vector2f>getSpawn();//różne dane mety
    sf::Vector2f getSpawn_hero();//miejsce kwadratu
    std::vector<sf::Vector2f>getCoins_coordi();//współrzędne monet
};
#endif // POZIOM1_H
