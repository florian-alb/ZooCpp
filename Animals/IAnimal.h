//
// Created by Florian ALBORA on 19/03/2023.
//

#ifndef ZOOREWORK_IANIMAL_H
#define ZOOREWORK_IANIMAL_H

#include <iostream>
#include "../Time/Time.h"

using namespace std;

class House;

class Zoo;

class IAnimal {
    string m_name;
    bool m_gender;
    bool m_hungry;
    bool m_pregnant;
    bool m_sick;
    int m_daysBeforeHealing;

protected:
    Time m_birthDate;

public:
    IAnimal(string name, bool gender);

    virtual int getPrice(int age) = 0;

    virtual int getSellPrice(Time date) = 0;

    virtual int daysBeforeHunger() = 0;

    virtual void feed(Zoo &zoo) = 0;

    virtual void beSick() = 0;

    void checkSick();

    // getters
    bool getGender();

    Time getBirthDate();

    Time getAge(Time date);

    bool getPregnatSatus();

    int getDaysBeforeHealing();

    bool getSick();

    void setHunger(bool feed);

    void setSick(bool sick);

    void setDaysBeforeHealing(int days);

    bool getHungry();

    virtual string askName(bool gender)=0;

    void setNAme(string name);

    string getName();

    void setPregnant(bool status);

    virtual void setLastPregnancyDate(const Time *date) = 0;

    virtual bool canBePregnant(Time *date) = 0;

    virtual void gestation(Time *time, House &house) = 0;

    virtual IAnimal* getPartner()=0;

    virtual void setPartner(IAnimal *eagle)=0;

    virtual ~IAnimal();
};


#endif //ZOOREWORK_IANIMAL_H
