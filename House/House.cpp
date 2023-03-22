//
// Created by Florian ALBORA on 19/03/2023.
//

#include "House.h"
#include "../Zoo/Zoo.h"
#include "../Random/Random.h"

using namespace std;


House::House(string type)
        : m_type(type){
    if (m_type=="Tigre"){
        m_buyPrice = 2000;
        m_sellPrice = 500;
        m_size = 2;
    } else if (m_type=="Eagle"){
        m_buyPrice = 2000;
        m_sellPrice = 500;
        m_size = 4;
    } else {
        m_buyPrice = 300;
        m_sellPrice = 50;
        m_size = 10;
    }

}

int House::getPrice() {
    return m_buyPrice;
}

string House::getType() {
    return m_type;
}

int House::getSellPrice() {
    return m_sellPrice;
}

int House::getSize() {
    return m_size;
}

void House::addAnimal(IAnimal *animal) {
    house.push_back(animal);
}

int House::getLen() {
    return house.size();
}

void House::feedAnimals(Zoo &zoo) {
    for ( auto *animal : house){
        animal->feed(zoo);
    }
}

int House::getShowableAnimalsNbr() {
    int showable = 0;
    for (IAnimal *animal : house){
        if (!animal->getPregnatSatus() && !animal->getSick()){
            showable ++;
        }
    }
    return showable;
}

void House::showAnimals(Time *date) {
    for (int i = 0; i < house.size(); i++) {
        cout << "Tiger n°" << i << endl;
        cout << "Name: " << house[i]->getName() << endl;
        cout << "Gender: " << house[i]->getGender() << endl;
        cout << "Age: " << house[i]->getAge(*date).getYear() << " years "
             << house[i]->getAge(*date).getMonth() << " months "
             << house[i]->getAge(*date).getDay() << " days \n" << endl;
    }
}

void House::sellAnimal(int animalIndex, Time *date, Zoo &zoo) {
    zoo.setMoney(house[animalIndex]->getSellPrice(*date));
    delete house[animalIndex];
    house.erase(house.begin() + animalIndex);
}

void House::checkAnimalAges(Time *date) {
    for (auto *animal : house){
        if (animal->getAge(*date).getYear()>25){
            removeAnimal(animal); // the tiger dies
        }
    }
}

void House::removeAnimal(IAnimal *animal) {
    for (auto it = house.begin(); it != house.end(); ++it) {
        if (*it == animal) {
            house.erase(it);
            delete animal; // deallocate memory for the removed animal
            break;
        }
    }
}

vector<IAnimal *> House::getHouse() {
    return house;
}

void House::checkGestation(Time *date) {
    for (auto *tiger : house){
        if (!tiger->getGender() && tiger->getPregnatSatus()){
            tiger->gestation(date, *this);
        }
    }
}

void House::fire() {
    for (auto *animal : house){
        removeAnimal(animal);
    }
}

void House::animalTheft(){
    // set a random animal
    auto *probability = new Random();
    int randomAnimal = probability->randomInt(house.size());
    cout << house[randomAnimal]->getName() << " has been stolen!!!" << endl;
    removeAnimal(house[randomAnimal]);
}

void House::beSick() {
    for (auto *animal : house){
        animal->beSick();
    }
}

void House::checkSick() {
    for (auto *animal : house){
        animal->checkSick();

        if (animal->getSick()){
            // 10% probability of dying
            auto *probability = new Random();
            if (probability->probability(10)){
                removeAnimal(animal);
                cout << animal->getName() << " died because of the disease :( " << endl;
            }
        }
    }
}

void House::addNewEagle(Time *date) {
    srand(time(nullptr));
    int randomNum = rand() % 2;
    bool gender = (randomNum == 1);
    Eagle *eagle = new Eagle("", gender);
    eagle->setNAme(eagle->askName(gender));
    eagle->setBirthDate(0, date->getYear(), date->getMonth(), date->getDay());
    addAnimal(eagle);
}

House::~House() {
    cout << "Goodbye " << getType() << " house" << getSellPrice() << endl;
}
