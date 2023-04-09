#ifndef POZIOM5_H
#define POZIOM5_H
#include "poziomabstra.h"

class Poziom5: public PoziomAbstra
{
public:
    Poziom5();
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

#endif // POZIOM5_H
