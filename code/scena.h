#ifndef SCENA_H
#define SCENA_H
#include "menu.h"
#include "panel.h"
#include "poziomabstra.h"
#include "poziom1.h"
#include "poziom2.h"
#include "poziom3.h"
#include "poziom4.h"
#include "poziom5.h"
#include "hero.h"
#include "generator.h"
#include "balls.h"
#include "coins.h"
#include "audio.h"


class Scena
{
private:
    sf::RenderWindow window_;
    Hero hero_;
    Balls balls_;
    Menu menu_;
    Poziom1 poziom1_;
    Poziom2 poziom2_;
    Poziom3 poziom3_;
    Poziom4 poziom4_;
    Poziom5 poziom5_;
    Panel panel_;
    Generator generator_;
    Coins coins_;
    Audio audio_;
    int status_;
    int status_poziom_;
    int warunek_;
    int check_end_;//sprawdzz warunek zakończenia poziomu
    int balls_warun_;
    void drawing_();
    void poziom_();
    void warunki_();
public:
    Scena(int X, int Y);

    void loop();

};

#endif // SCENA_H
