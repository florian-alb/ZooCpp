//
// Created by Florian ALBORA on 19/03/2023.
//

#ifndef ZOOREWORK_ZOO_H
#define ZOOREWORK_ZOO_H

#include <vector>
#include "../Animals/Eagle.h"
#include "../Animals/Chicken.h"
#include "../House/House.h"
#include "../Food/Food.h"
#include "../Time/Time.h"

class Tiger;

class Zoo {
    string m_name;
    double m_money;
    float m_seeds;
    float m_meat;

    vector<House *> zooHouses;

public:
    Zoo(string name, int money);


    // getters:
    double getMoney();

    float getMeat();

    float getSeeds();

    int getHouseSize(int index);

    // setters:
    void setMoney(double money);

    void setMeat(float quantity);

    void setSeeds(float quantity);

    // buy functions:
    void buyFood(Food *food, int quantity);

    void buyAnimal(Tiger *animal, int age, Time date);

    void buyAnimal(Eagle *animal, int age, Time date);

    void buyAnimal(Chicken *animal, bool gender, Time date);

    void buyHouse(House *newHouse);

    // verif functions:
    bool canBuy(Food *food, int quantity);

    bool canBuy(IAnimal *animal, int age);

    bool canBuy(Chicken *chicken, bool gender);

    void checkHunger(IAnimal *animal, int daysSinceHunger);

    // show functions :
    void showZoo(Time *date);

    void showAllTigers(Time date);

    void showAllEagles(Time date);

    void showAllChicken(Time date);

    int typeHouseNbr(string type);


    // sell functions
    void sellHouse(House *houseType);

    void sellAnimal(int houseIndex, int animalIndex, Time *date);

    // zoo actions

    void addHouse(House *house);

    void feedAnimals();

    void chikenEggSpawing(Time *date);

    bool isMaleReady();

    void breedTigers(Time *date);

    void checkTigerGestation(Time *date);

    void getVisits(Time *date);

    void checkAnimalAges(Time *date);

    void montlyActions(Time *date);

    void dailyActions(Time *date);

    void addGrant();

    void beSick();

    void checkSick();

    // special events
    void fire();

    void animalTheft();

    void pest();

    void rottenFlesh();
};


#endif //ZOOREWORK_ZOO_H
