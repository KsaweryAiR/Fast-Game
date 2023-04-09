#include "poziomtextury.h"

PoziomTextury::PoziomTextury()
{
    //tła
    auto poziom1 =std::make_unique<sf::Texture>();
    if (!poziom1->loadFromFile("poziom1.png")) {
        throw("Could not load texture");
    }
    textury_.emplace_back(std::move(poziom1));
    sf::Sprite sprite_poziom1;
    sprite_poziom1.setTexture(**(textury_.end()-1));
    tapety_.emplace_back(sprite_poziom1);

    auto poziom2 =std::make_unique<sf::Texture>();
    if (!poziom2->loadFromFile("poziom2.png")) {
        throw("Could not load texture");
    }
    textury_.emplace_back(std::move(poziom2));
    sf::Sprite sprite_poziom2;
    sprite_poziom2.setTexture(**(textury_.end()-1));
    tapety_.emplace_back(sprite_poziom2);

    auto poziom3 =std::make_unique<sf::Texture>();
    if (!poziom3->loadFromFile("poziom3.png")) {
        throw("Could not load texture");
    }
    textury_.emplace_back(std::move(poziom3));
    sf::Sprite sprite_poziom3;
    sprite_poziom3.setTexture(**(textury_.end()-1));
    tapety_.emplace_back(sprite_poziom3);

    auto poziom4 =std::make_unique<sf::Texture>();
    if (!poziom4->loadFromFile("poziom4.png")) {
        throw("Could not load texture");
    }
    textury_.emplace_back(std::move(poziom4));
    sf::Sprite sprite_poziom4;
    sprite_poziom4.setTexture(**(textury_.end()-1));
    tapety_.emplace_back(sprite_poziom4);

    auto poziom5 =std::make_unique<sf::Texture>();
    if (!poziom5->loadFromFile("poziom5.png")) {
        throw("Could not load texture");
    }
    textury_.emplace_back(std::move(poziom5));
    sf::Sprite sprite_poziom5;
    sprite_poziom5.setTexture(**(textury_.end()-1));
    tapety_.emplace_back(sprite_poziom5);

    //inne textury
    auto meta =std::make_unique<sf::Texture>();
    if (!meta->loadFromFile("meta.png")) {
        throw("Could not load texture");
    }
    meta->setRepeated(true);
    textury_.emplace_back(std::move(meta));
    sf::Sprite sprite_meta;
    sprite_meta.setTexture(**(textury_.end()-1));
    elements_.emplace_back(sprite_meta);

    auto spawn =std::make_unique<sf::Texture>();
    if (!spawn->loadFromFile("spawn.png")) {
        throw("Could not load texture");
    }
    spawn->setRepeated(true);
    textury_.emplace_back(std::move(spawn));
    sf::Sprite sprite_spawn;
    sprite_spawn.setTexture(**(textury_.end()-1));
    elements_.emplace_back(sprite_spawn);

    auto deska =std::make_unique<sf::Texture>();//środek w ostatnim elemencie.
    if (!deska->loadFromFile("deska.png")) {
        throw("Could not load texture");
    }
    textury_.emplace_back(std::move(deska));
    sf::Sprite sprite_deska;
    sprite_deska.setTexture(**(textury_.end()-1));
    elements_.emplace_back(sprite_deska);

}
