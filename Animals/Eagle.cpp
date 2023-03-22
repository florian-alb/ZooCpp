//
// Created by Florian ALBORA on 19/03/2023.
//

#include <iostream>
#include "Eagle.h"
#include "../Zoo/Zoo.h"
#include "../Random/Random.h"

using namespace std;

Eagle::Eagle(string name, bool gender) : IAnimal(name, gender) {};

int Eagle::getPrice(int age) {
    switch (age) {
        case 1:
            return 1000;
        case 2:
            return 4000;
        case 3:
            return 2000;
    }
    return 1;
}

void Eagle::setBirthDate(int age, int year, int month, int day) {
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

int Eagle::getSellPrice(Time date) {
    int age = getAge(date).getYear();

    if (age < 4) {
        return 500;
    } else if (age < 14) {
        return 2000;
    } else {
        return 400;
    }
}

int Eagle::daysBeforeHunger() {
    return 10;
}

void Eagle::checkHunger(int daysSinceHunger) {
    if (daysSinceHunger >= daysBeforeHunger()) {
        setHunger(true);
    }
}

void Eagle::feed(Zoo &zoo) {
    int daysSinceHunger = 0;
    if (!getGender()) {
        if (getPregnatSatus()) {
            if (zoo.getMeat() >= 0.6) {
                zoo.setMeat(-0.6);
                setHunger(false);
                daysSinceHunger = 0;
                cout << "Meat : " << zoo.getMeat() << "kg" << endl;
            } else {
                checkHunger(daysSinceHunger++);
            }
        } else {
            if (zoo.getMeat() >= 0.3) {
                zoo.setMeat(-0.3);
                setHunger(false);
                daysSinceHunger = 0;
                cout << "Meat : " << zoo.getMeat() << "kg" << endl;
            } else {
                checkHunger(daysSinceHunger++);
            }
        }
    } else {
        if (zoo.getMeat() >= 0.25) {
            zoo.setMeat(-0.25);
            setHunger(false);
            daysSinceHunger = 0;
            cout << "Meat : " << zoo.getMeat() << "kg" << endl;
        } else {
            checkHunger(daysSinceHunger++);
        }
    }
}

void Eagle::setLastPregnancyDate(const Time *date) {
    cout << "" << endl;
}

bool Eagle::canBePregnant(Time *date) {
    return false;
    // TODO : reproduction aigles;
}

void Eagle::gestation(Time *date, House &house){
    cout << "" << endl;
    // TODO : gestation aigles
}

void Eagle::beSick() {
    // set probability
    auto *probability = new Random();
    // convert annual probability in monthly probability.
    if (probability->probability(10/12)){
        setSick(true);
        int duration = 15*probability->getUncertainty(0.8, 1.2);
        setDaysBeforeHealing(duration);
        cout << getName() << " is sick for " << duration << " days!" << endl;
    }
}

//void Eagle::removeAnimal() {
//    EagleHouse::getInstance()->removeAnimal(this);
//}

Eagle::~Eagle() = default;


