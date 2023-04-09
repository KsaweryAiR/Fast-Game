#include "menu.h"
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <memory>

Menu::Menu(sf::RenderWindow *w):window_(w)
{
    sf::Vector2f size(400.0, 90.0);
    int X = 1400;
    int Y=800;

    auto tapeta =std::make_unique<sf::Texture>();
    if (!tapeta->loadFromFile("tapeta1.png")) {
        throw("Could not load texture");
    }
    textury_.emplace_back(std::move(tapeta));

    sf::Sprite sprite_tapeta;
    sprite_tapeta.setTexture(**(textury_.end()-1));
    elements_.emplace_back(sprite_tapeta);

    if (!font.loadFromFile("ALGER.ttf"))
    {
        // handle error
    }
    for(int i=0;i<2;i++)
    {
        text_[i].setFont(font);
        text_[i].setFillColor(sf::Color::Black);
        text_[i].setPosition(sf::Vector2f(X / 2-100, Y / 2+100 +150*i));
        text_[i].setCharacterSize(70);
        rectangles_.emplace_back(sf::RectangleShape(size));
        rectangles_[i].setPosition(X / 2-200,  Y / 2 +100+150*i);
        rectangles_[i].setOutlineColor(sf::Color::Black);
        rectangles_[i].setOutlineThickness(5);
    }
    text_[0].setString("Graj!!!");
    text_[1].setString("Wyjdz");
}
std::vector<sf::RectangleShape>Menu:: getRectangles()
{
    return rectangles_;
}
void Menu:: check (const int &wybor)
{
    rectangles_[wybor].setFillColor(sf::Color(255,255,0));
}
void Menu:: check2 (const int &wybor)
{
    rectangles_[wybor].setFillColor(sf::Color(255,255,255));
}
void Menu::drawing()
{
     window_->draw(elements_[0]);
    for (int i=0;i<2;i++)
    {
       window_->draw(rectangles_[i]);
       window_->draw(text_[i]);

    }
}
