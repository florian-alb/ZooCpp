//
// Created by Florian ALBORA on 19/03/2023.
//

#ifndef ZOOREWORK_HOUSE_H
#define ZOOREWORK_HOUSE_H

#include <iostream>
#include <vector>
#include "../Animals/IAnimal.h"

using namespace std;

class Tiger;

class Eagle;

class Chicken;

class House {
    vector<IAnimal *> house;

    string m_type;
    int m_buyPrice;
    int m_sellPrice;
    int m_size;


public:
    House(string type);

    int getPrice();

    string getType();

    int getSellPrice();

    int getSize();

    void addAnimal(IAnimal *tiger);

    //void addAnimal(IAnimal *animal) = 0;
    int getLen();

    void feedAnimals(Zoo &zoo);

    int getShowableAnimalsNbr();

    void showAnimals(Time *date);

    void sellAnimal(int animalIndex, Time *date, Zoo &zoo);

    void checkAnimalAges(Time *date);

    void removeAnimal(IAnimal *animal);

    vector<IAnimal *> getHouse();

    void checkGestation(Time *date);

    void beSick();

    void checkSick();

    void addNewEagle(Time *date);

    void fire();

    void animalTheft();

    ~House();
};


#endif //ZOOREWORK_HOUSE_H
