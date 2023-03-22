#include "Chicken.h"
#include "../Zoo/Zoo.h"
#include "../Random/Random.h"

using namespace std;

Chicken::Chicken(string name, bool gender)
        : IAnimal(name, gender) {};

void Chicken::setBirthDate(int age, int year, int month, int day) {
    if (age == 1) {
        if (month <= 6) {
            year -= 1;
            month += 12;
        }
        this->m_birthDate.setYear(year);
        this->m_birthDate.setMonth(month - 6);
        this->m_birthDate.setDay(day);
    } else {
        this->m_birthDate.setYear(year);
        this->m_birthDate.setMonth(month);
        this->m_birthDate.setDay(day);
    }
}

int Chicken::getPrice(int gender) {
    if (gender == 1) {
        return 100;
    }
    return 20;
}

int Chicken::getSellPrice(Time date) {
    bool gender = getGender();
    if (gender) {
        return 20;
    }
    return 10;
}

void Chicken::eggSpawning(Time *date) {
    eggs.push_back(date);
}

int Chicken::daysBeforeHunger() {
    if (getGender()) {
        return 2;
    }
    return 1;
}

void Chicken::checkHunger(int daysSinceHunger) {
    if (daysSinceHunger >= daysBeforeHunger()) {
        setHunger(true);
    }
}

void Chicken::feed(Zoo &zoo) {
    int daysSinceHunger = 0;
    if (!getGender()) {
        if (getPregnatSatus()) {
            if (zoo.getSeeds() >= 0.3) {
                zoo.setSeeds(-0.3);
                setHunger(false);
                daysSinceHunger = 0;
                cout << "Seeds : " << zoo.getSeeds() << "kg" << endl;
            } else {
                checkHunger(daysSinceHunger++);
            }
        } else {
            if (zoo.getSeeds() >= 0.15) {
                zoo.setSeeds(-0.15);
                setHunger(false);
                daysSinceHunger = 0;
                cout << "Seeds : " << zoo.getSeeds() << "kg" << endl;
            } else {
                checkHunger(daysSinceHunger++);
            }
        }
    } else {
        if (zoo.getSeeds() >= 0.18) {
            zoo.setSeeds(-0.18);
            setHunger(false);
            daysSinceHunger = 0;
            cout << "Seeds : " << zoo.getSeeds() << "kg" << endl;
        } else {
            checkHunger(daysSinceHunger++);
        }
    }
}

void Chicken::setLastPregnancyDate(const Time *date) {
    cout << "" << endl;
}

bool Chicken::canBePregnant(Time *date) {
    return false;
    // TODO : reproduction poules;
}

void Chicken::gestation(Time *date, House &house){
    cout << "" << endl;
    // TODO : gestation poules
}

void Chicken::beSick() {
    // set probability
    auto *probability = new Random();
    // convert annual probability in monthly probability.
    if (probability->probability(5/12)){
        setSick(true);
        int duration = 15*probability->getUncertainty(0.8, 1.2);
        setDaysBeforeHealing(duration);
        cout << getName() << " is sick for " << duration << " days!" << endl;
    }
}

IAnimal* Chicken::getPartner(){
    return nullptr;
}

void Chicken::setPartner(IAnimal *eagle) {
    // nothing here
}

Chicken::~Chicken() = default;
