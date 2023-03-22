//
// Created by Florian ALBORA on 22/03/2023.
//

#include "Egg.h"

Egg::Egg(Time date, int covertime) :
        m_date(date), m_covertime(covertime) {}

int Egg::getCovertime() {
    return m_covertime;
}

Time Egg::getEggDate() {
    return m_date;
}