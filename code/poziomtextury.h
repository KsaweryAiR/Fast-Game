#ifndef POZIOMTEXTURY_H
#define POZIOMTEXTURY_H
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <memory>


class PoziomTextury
{
public:
    PoziomTextury();
protected:
    std::vector<std::unique_ptr<sf::Texture>> textury_;
    std::vector<sf::Sprite> elements_;
    std::vector<sf::Sprite> tapety_;
};

#endif // POZIOMTEXTURY_H
