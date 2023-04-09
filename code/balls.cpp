#include "balls.h"
#include <iostream>

Balls::Balls(sf::RenderWindow *w):window_(w)
{    

}
void Balls::drawing()
{
    for(auto &s : balls_) {
        window_->draw(*s);
    }
}
void Balls:: parameters(const std::vector<sf::Vector2f> &balls_coordi, const int &balls_num,const std::vector<sf::Vector2f>&balls_speed
                        ,const std::string &name)
{
   for(auto i=0;i<balls_coordi.size();i++)
   {
       auto circle=std::make_unique<sf::CircleShape>();
       circle->setRadius(20);
       circle->setFillColor(sf::Color(0,0,205));
       circle->setOrigin(circle->getRadius(),circle->getRadius());
       circle->setPosition(balls_coordi[i].x,balls_coordi[i].y);
       balls_.emplace_back(move(circle));
       speed_x_=balls_speed[0].x;
       speed_y_=balls_speed[0].y;
   }
   if(name=="2"||name=="4")
   {
       R_.clear();
       r_.clear();
       for(auto i=1;i<3;i++)
       {
           R_.emplace_back(balls_[0]->getPosition().y-balls_[i]->getPosition().y);
           r_.emplace_back(balls_[0]->getPosition().y-balls_[i+2]->getPosition().y);
       }
   }
   if(name=="5")
   {
       R_.clear();
       r_.clear();
       for(auto i=1;i<3;i++)
       {
           R_.emplace_back(balls_[0]->getPosition().y-balls_[i]->getPosition().y);
           r_.emplace_back(balls_[0]->getPosition().y-balls_[i+4]->getPosition().y);
           speed_x2_=-4;
           speed_y2_=2;
           speed_x3_=8;
       }
   }
}
void Balls:: work(const sf::ConvexShape &map,const int &balls_num,const std::string &name)
{
    if(name=="1")
    {
        for(auto i=0;i<balls_num;i=i+2)
        {
            if (balls_[i]->getPosition().y-balls_[i]->getRadius()<= map.getPoint(0).y)
            {
                speed_y_ =std::abs( speed_y_);
            }
            else if (balls_[i]->getPosition().y+balls_[i]->getRadius()>= map.getPoint(3).y)
            {
                speed_y_ = -std::abs(speed_y_);
            }
            balls_[i]->move(speed_x_,speed_y_);
        }
        for(auto i=1;i<balls_num-1;i=i+2)
        {
            speed_y2_=-speed_y_;
            if (balls_[i]->getPosition().y-balls_[i]->getRadius()<= map.getPoint(0).y)
            {
                speed_y2_ =std::abs( speed_y2_);
            }
            else if (balls_[i]->getPosition().y+balls_[i]->getRadius()>= map.getPoint(3).y)
            {
                speed_y2_ = -std::abs(speed_y2_);
            }
            balls_[i]->move(speed_x_,speed_y2_);
        }
    }
    else if(name=="2")
    {
        //ruch po okręgu, ciężkie to było do zrozumienia i zrobienia ;/
        for(auto it=0;it<3;it++)
        {
            for(auto i=1;i<3;i++)//Pierwsze górne belki/szurikeny
            {
                if(ballsAngle1 < 360){
                    ballsAngle1 += 0.6;
                }else{
                    ballsAngle1 = 0;
                }
                //new_G_Pi_X nowy,górny,pionowy,x
                float new_G_Pi_X = balls_[(5*it)]->getPosition().x+(R_[i-1]*cos((ballsAngle1-30) * _PI / 180.0));
                float new_G_Pi_Y = balls_[(5*it)]->getPosition().y+(R_[i-1]*sin((ballsAngle1-30)* _PI / 180.0));
                float new_D_Pi_X = balls_[(5*it)]->getPosition().x+(r_[i-1]*cos(ballsAngle1 * _PI / 180.0));
                float new_D_Pi_Y = balls_[(5*it)]->getPosition().y+(r_[i-1]*sin(ballsAngle1 * _PI / 180.0));
                balls_[i+(5*it)]->setPosition({new_G_Pi_X, new_G_Pi_Y});
                balls_[i+2+(5*it)]->setPosition({new_D_Pi_X, new_D_Pi_Y});
            }
            for(auto i=1;i<3;i++)//drugie wiatraki
            {
                if(ballsAngle2 < 360){
                    ballsAngle2 +=0.3;
                }else{
                    ballsAngle2 = 0;
                }//Po znaczy poziomy
                float new_G_Pi_X = balls_[15+(9*it)]->getPosition().x+(R_[i-1]*sin((ballsAngle2) * _PI / 180.0));
                float new_G_Pi_Y = balls_[15+(9*it)]->getPosition().y+(R_[i-1]*cos((ballsAngle2)* _PI / 180.0));
                float new_G_Po_X = balls_[15+(9*it)]->getPosition().x+(R_[i-1]*sin((ballsAngle2+90)* _PI / 180.0));
                float new_G_Po_Y = balls_[15+(9*it)]->getPosition().y+(R_[i-1]*cos((ballsAngle2+90)* _PI / 180.0));
                float new_D_Pi_X = balls_[15+(9*it)]->getPosition().x+(r_[i-1]*sin(ballsAngle2 * _PI / 180.0));
                float new_D_Pi_Y = balls_[15+(9*it)]->getPosition().y+(r_[i-1]*cos(ballsAngle2 * _PI / 180.0));
                float new_D_Po_X = balls_[15+(9*it)]->getPosition().x+(r_[i-1]*sin((ballsAngle2+90) * _PI / 180.0));
                float new_D_Po_Y = balls_[15+(9*it)]->getPosition().y+(r_[i-1]*cos((ballsAngle2+90)* _PI / 180.0));
                balls_[i+15+(9*it)]->setPosition({new_G_Pi_X, new_G_Pi_Y});
                balls_[i+15+2+(9*it)]->setPosition({new_G_Po_X, new_G_Po_Y});
                balls_[i+4+15+(9*it)]->setPosition({new_D_Pi_X, new_D_Pi_Y});
                balls_[i+4+15+2+(9*it)]->setPosition({new_D_Po_X, new_D_Po_Y});
            }
        }
    }
    else if(name=="3")
    {
        for(auto i=0;i<balls_num;i++)//66
        {
            balls_[i]->move(speed_x_,speed_y_);
            if (balls_[i]->getPosition().y-balls_[i]->getRadius()<= map.getPoint(2).y)
            {
                   balls_[i]->setPosition(balls_[i]->getPosition().x,map.getPoint(12).y);
            }
        }
    }
    else if(name=="4")
    {
        for(auto i=1;i<3;i++)//pierwsze wiatrak
        {
            if(ballsAngle2 < 360){
                ballsAngle2 += 0.3;
            }else{
                ballsAngle2 = 0;
            }//Po znaczy poziomy
            float new_G_Pi_X = balls_[0]->getPosition().x+(R_[i-1]*sin((ballsAngle2-45) * _PI / 180.0));
            float new_G_Pi_Y = balls_[0]->getPosition().y+(R_[i-1]*sin((ballsAngle2)* _PI / 180.0));
            float new_G_Po_X = balls_[0]->getPosition().x+(R_[i-1]*sin((ballsAngle2+45)* _PI / 180.0));
            float new_G_Po_Y = balls_[0]->getPosition().y+(R_[i-1]*sin((ballsAngle2+90)* _PI / 180.0));
            balls_[i]->setPosition({new_G_Pi_X, new_G_Pi_Y});
            balls_[i+2]->setPosition({new_G_Po_X, new_G_Po_Y});
        }
        for(auto i=11;i<13;i++)//trzecie wiatrak
        {
            if(ballsAngle2 < 360){
                ballsAngle2 += 0.2;
            }else{
                ballsAngle2 = 0;
            }//Po znaczy poziomy
            float new_G_Pi_X = balls_[10]->getPosition().x+((-1)*R_[i-11]*sin((ballsAngle2-45) * _PI / 180.0));
            float new_G_Pi_Y = balls_[10]->getPosition().y+(R_[i-11]*sin((ballsAngle2)* _PI / 180.0));
            float new_G_Po_X = balls_[10]->getPosition().x+(R_[i-11]*sin((ballsAngle2+45)* _PI / 180.0));
            float new_G_Po_Y = balls_[10]->getPosition().y+(R_[i-11]*sin((ballsAngle2+90)* _PI / 180.0));
            balls_[i]->setPosition({new_G_Pi_X, new_G_Pi_Y});
            balls_[i+2]->setPosition({new_G_Po_X, new_G_Po_Y});
        }
        for(auto i=6;i<8;i++)//drugi wiatrak
        {
            if(ballsAngle2 < 360){
                ballsAngle2 += 0.3;
            }else{
                ballsAngle2 = 0;
            }//Po znaczy poziomy
            float new_G_Pi_X = balls_[5]->getPosition().x+(R_[i-6]*sin((ballsAngle2-45) * _PI / 180.0));
            float new_G_Pi_Y = balls_[5]->getPosition().y+(R_[i-6]*cos((ballsAngle2)* _PI / 180.0));
            float new_G_Po_X = balls_[5]->getPosition().x+(R_[i-6]*sin((ballsAngle2+45)* _PI / 180.0));
            float new_G_Po_Y = balls_[5]->getPosition().y+(R_[i-6]*sin((ballsAngle2+90)* _PI / 180.0));
            balls_[i]->setPosition({new_G_Pi_X, new_G_Pi_Y});
            balls_[i+2]->setPosition({new_G_Po_X, new_G_Po_Y});


        }
        if (balls_[15]->getPosition().x-balls_[16]->getRadius()<= map.getPoint(0).x)
        {
            speed_x_ =std::abs( speed_x_);
        }
        else if (balls_[15]->getPosition().x+balls_[15]->getRadius()>= map.getPoint(1).x)
        {
            speed_x_ = -std::abs(speed_x_);
        }
        balls_[15]->move(speed_x_,0);
        speed_x2_=-speed_x_;
        if (balls_[16]->getPosition().x-balls_[16]->getRadius()<= map.getPoint(3).x)
        {
            speed_x2_ =std::abs( speed_x2_);
        }
        else if (balls_[16]->getPosition().x+balls_[16]->getRadius()>= map.getPoint(5).x)
        {
            speed_x2_ = -std::abs(speed_x2_);
        }
        balls_[16]->move(speed_x2_,0);
    }
    else if(name=="5")
    {
        for(auto it=0;it<2;it++)
        {
            for(auto i=1;i<3;i++)
            {
                if(ballsAngle2 < 360){
                    ballsAngle2 += 1.3;
                }else{
                    ballsAngle2 = 0;
                }//Po znaczy poziomy
                float new_G_Pi_X = balls_[0+(it*9)]->getPosition().x+(R_[i-1]*sin((ballsAngle2) * _PI / 180.0));
                float new_G_Pi_Y = balls_[0+(it*9)]->getPosition().y+(R_[i-1]*cos((ballsAngle2)* _PI / 180.0));
                float new_G_Po_X = balls_[0+(it*9)]->getPosition().x+(R_[i-1]*sin((ballsAngle2+90)* _PI / 180.0));
                float new_G_Po_Y = balls_[0+(it*9)]->getPosition().y+(R_[i-1]*cos((ballsAngle2+90)* _PI / 180.0));
                float new_D_Pi_X = balls_[0+(it*9)]->getPosition().x+(r_[i-1]*cos(ballsAngle2 * _PI / 180.0));
                float new_D_Pi_Y = balls_[0+(it*9)]->getPosition().y+(r_[i-1]*sin(ballsAngle2 * _PI / 180.0));
                float new_D_Po_X = balls_[0+(it*9)]->getPosition().x+(r_[i-1]*cos((ballsAngle2+90) * _PI / 180.0));
                float new_D_Po_Y = balls_[0+(it*9)]->getPosition().y+(r_[i-1]*sin((ballsAngle2+90)* _PI / 180.0));
                balls_[i+(it*9)]->setPosition({new_G_Pi_X, new_G_Pi_Y});
                balls_[i+2+(it*9)]->setPosition({new_G_Po_X, new_G_Po_Y});
                balls_[i+4+(it*9)]->setPosition({new_D_Pi_X, new_D_Pi_Y});
                balls_[i+6+(it*9)]->setPosition({new_D_Po_X, new_D_Po_Y});

            }
        }
        for(auto i=0;i<2;i++)
        {
            if(balls_[0+(i*9)]->getPosition().y>=655)
            {
                balls_[0+(i*9)]->move(speed_x_,0);
            }
            if(balls_[0+(i*9)]->getPosition().x>=1230)
            {
                balls_[0+(i*9)]->move(0,-speed_y_);
            }
            if(balls_[0+(i*9)]->getPosition().y<=295)
            {
                balls_[0+(i*9)]->move(-speed_x_,0);
            }
            if(balls_[0+(i*9)]->getPosition().x<=270)
            {
                balls_[0+(i*9)]->move(0,speed_y_);
            }
        }
        for(auto i=18;i<22;i=i+3)
        {
            if (balls_[i]->getPosition().x-balls_[i]->getRadius()<= map.getPoint(0).x+110)
            {
                speed_x2_ =std::abs( speed_x2_);
            }
            else if (balls_[i]->getPosition().x+balls_[i]->getRadius()>= map.getPoint(1).x)
            {
                speed_x2_ = -std::abs(speed_x2_);
            }
            balls_[i]->move(speed_x2_,0);

        }
        for(auto i=19;i<21;i++)
        {
            if (balls_[i]->getPosition().x-balls_[i]->getRadius()<= map.getPoint(0).x+80)
            {
                speed_x3_ =std::abs( speed_x3_);
            }
            else if (balls_[i]->getPosition().x+balls_[i]->getRadius()>= map.getPoint(1).x)
            {
                speed_x3_ = -std::abs(speed_x3_);
            }
            balls_[i]->move(speed_x3_,0);
        }
        if (balls_[22]->getPosition().x-balls_[22]->getRadius()<=1150)
        {
            speed_y2_ =std::abs( speed_y2_);//dlatego speed_y2_ ponieważ zostało więc go wykorzystuje
        }
        else if (balls_[22]->getPosition().x+balls_[22]->getRadius()>= map.getPoint(1).x)
        {
            speed_y2_ = -std::abs(speed_y2_);
        }
        balls_[22]->move(speed_y2_,0);



    }
}
