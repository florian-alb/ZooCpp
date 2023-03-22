#include "IAnimal.h"

IAnimal::IAnimal(string name, bool gender)
        : m_name(name), m_gender(gender), m_hungry(false), m_pregnant(false), m_sick(false),
          m_birthDate(Time(0, 0, 0)), m_daysBeforeHealing(0) {
};

// getters
bool IAnimal::getGender() {
    return m_gender;
}

Time IAnimal::getBirthDate() {
    return m_birthDate;
}

Time IAnimal::getAge(Time date) {
    return Time(date.getYear() - m_birthDate.getYear(),
                date.getMonth() - m_birthDate.getMonth(),
                date.getDay() - m_birthDate.getDay());
}

int IAnimal::getDaysBeforeHealing() {
    return m_daysBeforeHealing;
}

void IAnimal::setPregnant(bool status){
    m_pregnant = status;
}

void IAnimal::setSick(bool sick) {
    m_sick = sick;
}

void IAnimal::setDaysBeforeHealing(int days) {
    m_daysBeforeHealing = days;
}

bool IAnimal::getPregnatSatus(){
    return m_pregnant;
}

bool IAnimal::getSick() {
    return m_sick;
}

void IAnimal::setHunger(bool feed) {
    m_hungry = feed;
    if (m_hungry){
        cout << getName() << " is hungry!!!"<< endl;
    }
}

bool IAnimal::getHungry() {
    return m_hungry;
}

void IAnimal::setNAme(string name) {
    m_name = name;
}

string IAnimal::getName() {
    return m_name;
}

void IAnimal::checkSick() {
    m_daysBeforeHealing --;

    if (m_sick && m_daysBeforeHealing==0){
        setSick(false);
        cout << getName() << " is healed!" << endl;
    }
}

IAnimal::~IAnimal() {
    cout << "Goodbye " << getName() << "!" << endl;
}