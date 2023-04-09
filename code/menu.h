#ifndef MENU_H
#define MENU_H
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <memory>

class Menu : public sf::RectangleShape
{
    sf::Font font;
    sf::Text text_[2];
    std::vector<std::unique_ptr<sf::Texture>> textury_;
    std::vector<sf::Sprite> elements_;
    sf::RenderWindow *window_;
    std::vector<sf::RectangleShape> rectangles_;
public:
    Menu(sf::RenderWindow *w);
    void drawing();
    void loop();
    void check(const int &wybor);
    void check2(const int &wybor);
    std::vector<sf::RectangleShape> getRectangles();
    };

#endif // MENU_H
