#ifndef PANEL_H
#define PANEL_H
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <memory>

class Panel
{
    std::vector<std::unique_ptr<sf::Texture>> textury_;
    sf::RenderWindow *window_;
    sf::Font font;
    sf::Text text_[3];
    sf::Text textEnd_[4];
    int death_=0;
    int coins_=0;
    std::vector<sf::Sprite> elements_;
    std::vector<sf::Sprite> end_;
public:
    Panel(sf::RenderWindow *w);
    void drawing();
    void death(const int &death);
    void Poziom_num(const std::string &name);
    void coins(const int &coins);
    void work();
    sf::Sprite GetElementIkon();
    void check();
    void check2();
    void TheEnd();
};

#endif // PANEL_H
