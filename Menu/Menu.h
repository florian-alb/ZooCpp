//
// Created by Florian ALBORA on 19/03/2023.
//

#ifndef ZOOREWORK_MENU_H
#define ZOOREWORK_MENU_H

#include <iostream>
#include "../Zoo/Zoo.h"
#include "../Food/Meat.h"
#include "../Food/Seeds.h"
#include "../Animals/Tiger.h"

using namespace std;

const int TIGER = 1;
const int CHICKEN = 2;
const int EAGLE = 3;

const int MEAT = 1;
const int SEEDS = 2;

class Menu {

public:
    struct ChickenGender {
        int userValue;
        bool gender;
    };


    void mainMenu();

    void buyMenu();

    void sellMenu();

    void buyAnimalMenu();

    void buyHouseMenu();

    void buyFoodMenu();

    void sellHouseMenu();

    void sellAnimalMenu();

    void askGender(string animal);

    void askAge(string youngPrice, string adultPrice, string oldPrice);

    void buyAnimal(int animal, Zoo *zoo, Tiger *tiger, Eagle *eagle, Chicken *chicken, Time date);

    void buyFood(int food, Zoo *zoo, Meat *meat, Seeds *seeds);

    void buyHouse(int animal, Zoo *zoo);

    void sellHouse(int animal, Zoo *zoo);

    void sellAnimal(int animal, Zoo *zoo, Time date);

    void handleBuyMenuChoice(int choice, Zoo *zoo, Tiger *tiger, Eagle *eagle, Chicken *chicken, Meat *meat, Seeds *seeds, Time date);

    void handleSellMenuChoice(int choice, Zoo *zoo, Time date);

    int askAction(int choice);

    int askSellAction(string textToask);

    bool askUserGender();

    ChickenGender askChikenGender();

    string askName();

    bool monthlyGame(Time date, Zoo *zoo, Tiger *tiger, Eagle *eagle, Chicken *chicken, Meat *meat, Seeds *seeds);
};

#endif //ZOOREWORK_MENU_H
