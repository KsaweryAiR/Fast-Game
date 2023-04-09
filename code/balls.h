#ifndef BALLS_H
#define BALLS_H
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <math.h>
#include <vector>
#define _PI 3.14159265

class Balls
{
private:
    float speed_y_;
    float speed_y2_;
    float speed_x_;
    float speed_x2_;
    float speed_x3_;
    float ballsAngle1=0;
    float ballsAngle2=0;
    sf::RenderWindow *window_;
    std::vector<float> R_;//odległość dalsza kulki od środka
    std::vector<float> r_;//odległość bliższa

public:

    Balls(sf::RenderWindow *w);
    std::vector<std::unique_ptr <sf::CircleShape>>balls_;
    void drawing();
    void work(const sf::ConvexShape &map,const int &balls_num,const std::string &name);
    void parameters(const std::vector<sf::Vector2f> &balls_coordi, const int &balls_num,const std::vector<sf::Vector2f>&balls_speed
                    ,const std::string &name);
};

#endif // BALLS_H
