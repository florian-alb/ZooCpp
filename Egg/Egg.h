//
// Created by Florian ALBORA on 22/03/2023.
//

#ifndef ZOOREWORK_EGG_H
#define ZOOREWORK_EGG_H

#include "../Time/Time.h"

class Egg {
    Time m_date;
    int m_covertime;
public:
    Egg(Time date, int covertime);

    Time getEggDate();

    int getCovertime();

};

#endif //ZOOREWORK_EGG_H
