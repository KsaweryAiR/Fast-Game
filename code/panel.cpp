#include "panel.h"
#include "string"

Panel::Panel(sf::RenderWindow *w):window_(w)
{
    auto panel =std::make_unique<sf::Texture>();
    if (!panel->loadFromFile("panel.png")) {
        throw("Could not load texture");
    }
    textury_.emplace_back(std::move(panel));
    sf::Sprite sprite_panel;
    sprite_panel.setTexture(**(textury_.end()-1));
    elements_.emplace_back(sprite_panel);

    auto ikona =std::make_unique<sf::Texture>();
    if (!ikona->loadFromFile("ikona.png")) {
        throw("Could not load texture");
    }
    textury_.emplace_back(std::move(ikona));
    sf::Sprite sprite_ikona;
    sprite_ikona.setPosition(1200,10);
    sprite_ikona.setTexture(**(textury_.end()-1));
    elements_.emplace_back(sprite_ikona);

    auto poziomend =std::make_unique<sf::Texture>();
    if (!poziomend->loadFromFile("poziomend.png")) {
        throw("Could not load texture");
    }
    textury_.emplace_back(std::move(poziomend));
    sf::Sprite sprite_poiomend;
    sprite_poiomend.setTexture(**(textury_.end()-1));
    end_.emplace_back(sprite_poiomend);

    if (!font.loadFromFile("ARLRDBD.ttf"))
    {
        // handle error
    }
    for(int i=0;i<3;i++)
    {
        text_[i].setFont(font);
        text_[i].setCharacterSize(60);
    }
        text_[0].setPosition(sf::Vector2f(230,22));
        text_[0].setFillColor(sf::Color::Black);
        text_[1].setPosition(sf::Vector2f(670,22));
        text_[1].setFillColor(sf::Color::Red);
        text_[2].setPosition(sf::Vector2f(980,22));
        text_[2].setFillColor(sf::Color(197,179,88));

        for(int i=0;i<4;i++)
        {
            textEnd_[i].setFont(font);
            textEnd_[i].setFillColor(sf::Color::White);
            textEnd_[i].setOutlineColor(sf::Color::Black);
        }

        textEnd_[0].setCharacterSize(150);
        textEnd_[0].setPosition(sf::Vector2f(180,200));
        textEnd_[0].setOutlineThickness(5);
        textEnd_[0].setString("GRATULACJE");

        textEnd_[1].setCharacterSize(80);
        textEnd_[1].setPosition(sf::Vector2f(180,400));
        textEnd_[1].setOutlineThickness(5);
        textEnd_[1].setString("TWOJ WYNIK TO:");

        textEnd_[2].setFillColor(sf::Color::Red);

        textEnd_[2].setCharacterSize(80);
        textEnd_[2].setPosition(sf::Vector2f(900,400));
        textEnd_[2].setOutlineThickness(5);


        textEnd_[3].setCharacterSize(60);
        textEnd_[3].setPosition(sf::Vector2f(180,600));
        textEnd_[3].setOutlineThickness(5);
        textEnd_[3].setString("Nacisnij Escape aby zakonczyc gre");


}
sf::Sprite Panel:: GetElementIkon()
{
    return elements_[1];
}
void Panel::drawing()
{
     for(auto &s : elements_)
     {
         window_->draw(s);
     }
     for (int i=0;i<3;i++)
     {
        window_->draw(text_[i]);
     }
}
void Panel::death(const int &death)
{
    death_=death_+death;
    text_[1].setString(std::to_string(death_));
    textEnd_[2].setString(std::to_string(death_));//zbiera dane do koncowego etapu
}
void Panel::coins(const int &coins)
{
    coins_=coins_+coins;
    text_[2].setString(std::to_string(coins_));
}
void Panel::Poziom_num(const std::string &name)
{
   text_[0].setString(name);
}
void Panel:: work()
{
    text_[1].setString(std::to_string(death_));
    text_[2].setString(std::to_string(coins_));
}
void Panel:: check ()
{
    elements_[1].setColor(sf::Color(255,255,0));
}
void Panel:: check2 ()
{
    elements_[1].setColor(sf::Color(255,255,255));
}
void Panel::TheEnd()//metoda z ekranem koncowym
{
    window_->draw(end_[0]);
    for (int i=0;i<4;i++)
    {
       window_->draw(textEnd_[i]);
    }
}
