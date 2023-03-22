//
// Created by Florian ALBORA on 19/03/2023.
//

#include <cstdlib>
#include <ctime>
#include "Tiger.h"
#include "../Zoo/Zoo.h"
#include "../Random/Random.h"

using namespace std;

Tiger::Tiger(string name, bool gender) : IAnimal(name, gender) {};

void Tiger::setBirthDate(int age, int year, int month, int day) {
    switch (age) {
        case 1:
            if (month <= 6) {
                year -= 1;
                month += 12;
            }
            this->m_birthDate.setYear(year);
            this->m_birthDate.setMonth(month - 6);
            this->m_birthDate.setDay(day);
            break;
        case 2:
            this->m_birthDate.setYear(year - 4);
            this->m_birthDate.setMonth(month);
            this->m_birthDate.setDay(day);
            break;
        case 3:
            this->m_birthDate.setYear(year - 14);
            this->m_birthDate.setMonth(month);
            this->m_birthDate.setDay(day);
            break;
        default:
            this->m_birthDate.setYear(year);
            this->m_birthDate.setMonth(month);
            this->m_birthDate.setDay(day);
            break;
    }
}

int Tiger::getPrice(int age) {
    switch (age) {
        case 1:
            return 3000;
        case 2:
            return 120000;
        case 3:
            return 60000;
    }
    return 0;
}

int Tiger::getSellPrice(Time date) {
    int age = getAge(date).getYear();
    if (age < 4) {
        return 1500;
    } else if (age < 14) {
        return 60000;
    } else {
        return 10000;
    }
}

void Tiger::setLastPregnancyDate(const Time *date) {
    m_lastPregnancyDate = *date;
}

bool Tiger::canBePregnant(Time *date) {
    if (!getPregnatSatus() && !getGender() && getAge(*date).getYear() >= 4 &&
        date->monthsBetweenDates(m_lastPregnancyDate) >= 20) {
        return true;
    }
    return false;
}

void Tiger::gestation(Time *currentDate, House &house) {
    if (getPregnatSatus()) {
        if (getHungry()) {
            setPregnant(false); // perte des foetus.
            return;
        }
        if (currentDate->monthsBetweenDates(m_lastPregnancyDate) >= 3) {
            srand(time(nullptr));
            int randomNum = rand() % 2;
            bool gender = (randomNum == 1);
            Tiger *tiger1 = new Tiger(askName(gender), gender);
            tiger1->setBirthDate(0, currentDate->getYear(), currentDate->getMonth(), currentDate->getDay());
            house.addAnimal(tiger1);

            randomNum = rand() % 2;
            gender = (randomNum == 1);
            Tiger *tiger2 = new Tiger(askName(gender), gender);
            tiger2->setBirthDate(0, currentDate->getYear(), currentDate->getMonth(), currentDate->getDay());
            house.addAnimal(tiger2);

            // perte de 1 foetus sur les 3 :
//            randomNum = rand() % 2;
//            gender = (randomNum == 1);
//            Tiger *tiger3 = new Tiger(askName(gender), gender);
//            tiger3->setBirthDate(0, currentDate->getYear(), currentDate->getMonth(), currentDate->getDay());
//            house.addAnimal(tiger3);
        }
    }
}

string Tiger::askName(bool gender) {
    string tGender;
    string tigerName;
    if (gender) {
        tGender = "male";
    } else {
        tGender = "female";
    }
    cout << "A new tiger is born! It's a " << tGender << " what shall we call it? " << endl;
    cin >> tigerName;
    return tigerName;
}

// feed
int Tiger::daysBeforeHunger() {
    return 2;
}

void Tiger::checkHunger(int daysSinceHunger) {
    if (daysSinceHunger >= daysBeforeHunger()) {
        setHunger(true);
    }
}

void Tiger::feed(Zoo &zoo) {
    int daysSinceHunger = 0;
    if (!getGender()) {
        if (getPregnatSatus()) {
            if (zoo.getMeat() >= 20) {
                zoo.setMeat(-20);
                setHunger(false);
                daysSinceHunger = 0;
                cout << "Meat : " << zoo.getMeat() << "kg" << endl;
            } else {
                checkHunger(daysSinceHunger++);
            }
        } else {
            if (zoo.getMeat() >= 10) {
                zoo.setMeat(-10);
                setHunger(false);
                daysSinceHunger = 0;
                cout << "Meat : " << zoo.getMeat() << "kg" << endl;
            } else {
                checkHunger(daysSinceHunger++);
            }
        }
    } else {
        if (zoo.getMeat() >= 12) {
            zoo.setMeat(-12);
            setHunger(false);
            daysSinceHunger = 0;
            cout << "Meat : " << zoo.getMeat() << "kg" << endl;
        } else {
            checkHunger(daysSinceHunger++);
        }
    }
}

void Tiger::beSick() {
    // set probability
    auto *probability = new Random();
    // convert annual probability in monthly probability.
    if (probability->probability(30/12)){
        setSick(true);
        int duration = 15*probability->getUncertainty(0.8, 1.2);
        setDaysBeforeHealing(duration);
        cout << getName() << " is sick for " << duration << " days!" << endl;
    }
}

IAnimal* Tiger::getPartner(){
    return nullptr;
}

void Tiger::setPartner(IAnimal *eagle) {
    // nothing here
}

//void Tiger::removeAnimal() {
//    TigerHouse::getInstance()->removeAnimal(this);
//}

Tiger::~Tiger() = default;