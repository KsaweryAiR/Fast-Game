#include "generator.h"

Generator::Generator(sf::RenderWindow *w):window_(w)
{
 name_="ja";
}
sf::ConvexShape Generator:: getMap()
{
 return map_;
}
sf::Sprite Generator:: getMeta_end()
{
    return meta_end_;
}
sf::Vector2f Generator:: getSpawn_hero()
{
    return spawn_hero_;
}
void Generator:: create(const int point, const std::vector<sf::Vector2f> &coordinates, const std::vector<sf::Vector2f> &meta,const std::vector<sf::Vector2f> &spawn
                        ,const std::vector<sf::Vector2i> &undercut, const sf::Vector2f &spawn_hero_new,const std::string &name)
{
    map_.setPointCount(point);
    spawn_hero_=spawn_hero_new;

    for(int i=0;i<point;i++)
    {
     map_.setPoint(i, coordinates[i]);
    }

    map_.setOutlineColor(sf::Color::Black);
    map_.setFillColor(sf::Color::White);
    map_.setOutlineThickness(9);

    elements_[0].setScale(meta[0]);
    //elements_[1].setTextureRect(sf::IntRect(0, 0, 275, 1250));
    elements_[0].setTextureRect(sf::IntRect(undercut[0], undercut[1]));
    elements_[0].setPosition(meta[1]);

    elements_[1].setScale(spawn[0]);
   elements_[1].setTextureRect(sf::IntRect(undercut[0], undercut[1]));
  // elements_[2].setTextureRect(sf::IntRect(0, 0, 275, 690));
    elements_[1].setPosition(spawn[1]);
    start= elements_[1].getOrigin();
    meta_end_=elements_[0];

    if(name=="1")
    {
        tapeta=tapety_[0];
    }
    else if(name=="2")
    {
        tapeta=tapety_[1];
    }
    else if(name=="3")
    {
        tapeta=tapety_[2];
    }
    else if(name=="4")
    {
        tapeta=tapety_[3];
    }
    else if(name=="5")
    {
        tapeta=tapety_[4];
        elements_[2].setPosition(365,385);
        name_=name;
    }
}
void Generator:: drawing()
{
    window_->draw(tapeta);
    window_->draw(map_);
    window_->draw(elements_[0]);
    window_->draw(elements_[1]);
    if(name_=="5")
    {
        window_->draw(elements_[2]);
    }
}
