//
// Created by Florian ALBORA on 19/03/2023.
//

#ifndef ZOOREWORK_TIGER_H
#define ZOOREWORK_TIGER_H


#include <iostream>
#include "IAnimal.h"
#include "../Time/Time.h"

using namespace std;

class Tiger : public IAnimal {
    Time managementTime = Time(0, 3, 0);
    Time m_lastPregnancyDate = Time(0, 0, 0);

public:
    Tiger(string name, bool gender);

    void setBirthDate(int age, int year, int month, int day);

    int getPrice(int age) override;

    int getSellPrice(Time date) override;

    int daysBeforeHunger() override;

    void checkHunger(int daysSinceHunger);

    void feed(Zoo &zoo) override;

    void setLastPregnancyDate(const Time *date) override;

    bool canBePregnant(Time *date) override;

    void gestation(Time *date, House &house) override;

    string askName(bool gender);

    void beSick() override;

    IAnimal *getPartner() override;

    void setPartner(IAnimal *eagle) override;

    ~Tiger() override;

};


#endif //ZOOREWORK_TIGER_H
