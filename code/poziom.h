#ifndef POZIOM_H
#define POZIOM_H
#include "poziomabstra.h"


class Poziom: public PoziomAbstra
{
private:
    //void rysuj(sf::RenderTarget &window_);
    Hero hero_;
    Balls balls_;
    Panel panel_;
    Generator generator_;
    Coins coins_;
    int status_poziom_;
    int warunek_;
    int check_end_;

public:
    Poziom(sf::RenderWindow *w);
    void rysuj(sf::RenderTarget &window_);
    void DanePoziom1();
    void DanePoziom2();
    void ParametersPoziom();
    void CreatPoziom();
    void poziom_();
    void warunki_();
};

#endif // POZIOM_H
