#ifndef POZIOMABSTRA_H
#define POZIOMABSTRA_H
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class PoziomAbstra
{
protected:
    std::string name_;
    int point_;//ile współrzędnych ma mapa
    int balls_num_;//liczba kólek
    int coins_num_;//liczna monet
    std::vector<sf::Vector2i>undercut_;//podcięcie textury spawn i meta
    std::vector<sf::Vector2f>balls_coordi_;//współrzędne kulek
    std::vector<sf::Vector2f>balls_speed_;
    std::vector<sf::Vector2f>coordinates_;//współrzędne mapy
    std::vector<sf::Vector2f>meta_;//różne dane mety
    std::vector<sf::Vector2f>spawn_;//różne dane mety
    sf::Vector2f spawn_hero_;//miejsce kwadratu
    std::vector<sf::Vector2f> coins_coordi_;//współrzędne monet
public:
    PoziomAbstra();

};

#endif // POZIOMABSTRA_H
