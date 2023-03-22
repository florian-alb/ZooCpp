//
// Created by Florian ALBORA on 19/03/2023.
//
#include <random>
#include "Zoo.h"
#include "../Animals/Tiger.h"
#include "../Random/Random.h"

//#include "../Animals/Eagle.h"
//#include "../Animals/Chicken.h"

using namespace std;

Zoo::Zoo(string name, int money) : m_name(name), m_money(money), m_seeds(0), m_meat(0) {};


// getters:

double Zoo::getMoney() {
    return m_money;
}

float Zoo::getMeat() {
    return m_meat;
}

float Zoo::getSeeds() {
    return m_seeds;
}

int Zoo::getHouseSize(int index) {
    return zooHouses[index]->getLen();
}

// setters:
void Zoo::setMoney(double money) {
    m_money += money;
}

void Zoo::setMeat(float quantity) {
    m_meat += quantity;
}

void Zoo::setSeeds(float quantity) {
    m_seeds += quantity;
}

void Zoo::setPartner(Time *date) {
    vector<IAnimal *> eagles;
    for (auto *house: zooHouses) {
        if (house->getType() == "Eagle") {
            for (auto *animal: house->getHouse()) {
                eagles.push_back(animal);
            }
        }
    }
    for (auto *eagle: eagles) {
        IAnimal *femaleEagle = nullptr;
        IAnimal *maleEagle = nullptr;
        if (eagle->getPartner() == nullptr && eagle->getAge(*date).getYear() >= 4) {
            if (eagle->getGender()) {
                maleEagle = eagle;
            } else {
                femaleEagle = eagle;
            }
            if (femaleEagle != nullptr && maleEagle != nullptr) {
                maleEagle->setPartner(femaleEagle);
                femaleEagle->setPartner(maleEagle);
                femaleEagle = nullptr;
                maleEagle = nullptr;
            }
        }
    }
}


// buy functions:
void Zoo::buyFood(Food *food, int quantity) {
    m_money -= quantity * food->getPrice();
    food->updateFood(quantity, *this);
}

void Zoo::buyAnimal(Tiger *animal, int age, Time date) {
    for (auto *house: zooHouses) {
        string animaltype = typeid(animal).name();
        if (animaltype.find(house->getType())) {
            m_money -= animal->getPrice(age);
            animal->setBirthDate(age, date.getYear(), date.getMonth(), date.getDay());
            house->addAnimal(animal);
            return;
        }
    }
    cout << "there is no suitable habitat for the animal\n"
            "You need more space.\n"
            "Transaction cancelled" << endl;
}

void Zoo::buyAnimal(Eagle *animal, int age, Time date) {
    for (auto *house: zooHouses) {
        string animaltype = typeid(animal).name();
        if (animaltype.find(house->getType())) {
            m_money -= animal->getPrice(age);
            animal->setBirthDate(age, date.getYear(), date.getMonth(), date.getDay());
            house->addAnimal(animal);
            return;
        }
    }
    cout << "there is no suitable habitat for the animal\n"
            "You need more space.\n"
            "Transaction cancelled" << endl;
}

void Zoo::buyAnimal(Chicken *animal, bool gender, Time date) {
    for (auto *house: zooHouses) {
        string animaltype = typeid(animal).name();
        if (animaltype.find(house->getType())) {
            m_money -= animal->getPrice(gender);
            animal->setBirthDate(1, date.getYear(), date.getMonth(), date.getDay());
            house->addAnimal(animal);
            return;
        }
    }
    cout << "there is no suitable habitat for the animal\n"
            "You need more space.\n"
            "Transaction cancelled" << endl;
}

void Zoo::buyHouse(House *newHouse) {
    m_money -= newHouse->getPrice();
    addHouse(newHouse);
};


// verif functions:
bool Zoo::canBuy(Food *food, int quantity) {
    if (quantity * food->getPrice() <= getMoney()) {
        return true;
    }
    return false;
}

bool Zoo::canBuy(IAnimal *animal, int age) {
    if (animal->getPrice(age) <= getMoney()) {
        return true;
    }
    return false;
}

bool Zoo::canBuy(Chicken *chicken, bool gender) {
    if (gender && chicken->getPrice(1) <= getMoney()) {
        return true;
    } else if (!gender && chicken->getPrice(2) <= getMoney()) {
        return true;
    }
    return false;
}

// show functions :

void Zoo::showAllTigers(Time date) {
    int i = 0;
    for (auto *house: zooHouses) {
        if (house->getType() == "Tiger") {
            cout << "House n°" << i << "\n" << endl;
            house->showAnimals(&date);
            cout << "------------------o--------------------" << endl;
        }
        i++;
    }
}

void Zoo::showAllEagles(Time date) {
    int i = 0;
    for (auto *house: zooHouses) {
        if (house->getType() == "Eagle") {
            cout << "House n°" << i << "\n" << endl;
            house->showAnimals(&date);
            cout << "------------------o--------------------" << endl;
        }
        i++;
    }
}

void Zoo::showAllChicken(Time date) {
    int i = 0;
    for (auto *house: zooHouses) {
        if (house->getType() == "Chicken") {
            cout << "House n°" << i << "\n" << endl;
            house->showAnimals(&date);
            cout << "------------------o--------------------" << endl;
        }
        i++;
    }
}

void Zoo::showZoo(Time *date) {
    cout << "\t TIGERS :" << endl;
    showAllTigers(*date);
    cout << "\t EAGLES :" << endl;
    showAllEagles(*date);
    cout << "\t CHICKENS :" << endl;
    showAllChicken(*date);
    cout << "\t MONEY : " << getMoney() << endl;
    cout << "\t SEEDS : " << getSeeds() << endl;
    cout << "\t MEAT : " << getMeat() << endl;
}

int Zoo::typeHouseNbr(string type) {
    int count = 0;
    for (auto *house: zooHouses) {
        if (house->getType() == type) {
            count++;
        }
    }
    return count;
}

// sell functions
void Zoo::sellAnimal(int houseIndex, int animalIndex, Time *date) {
    zooHouses[houseIndex]->sellAnimal(animalIndex, date, *this);
}

void Zoo::sellHouse(House *houseType) {
    for (int i = 0; i < zooHouses.size(); i++) {
        if (zooHouses[i]->getType() == houseType->getType() && zooHouses[i]->getLen() == 0) {
            m_money += zooHouses[i]->getSellPrice();
            delete zooHouses[i];
            zooHouses.erase(zooHouses.begin() + i);
            return;
        }
    }
    cout << "We can't sell this house. There are animals inside." << endl;
}


// Zoo functions
void Zoo::addHouse(House *house) {
    zooHouses.push_back(house);
}

void Zoo::checkEagleEggs(Time *date) {
    for (auto *egg: eagleNursery) {
        if (egg->getEggDate().daysBetweenDates(*date) >= egg->getCovertime()) {
            for (auto *house : zooHouses){
                if (house->getType()=="Eagle"){
                    house->addNewEagle(date);
                    //house->addNewEagle(date); perte de 1 des 2 oeufs
                }
            }
        }
    }
}

void Zoo::feedAnimals() {
    for (auto *house: zooHouses) {
        house->feedAnimals(*this);
    }
}

void Zoo::chikenEggSpawing(Time *date) {
//    for (int i = 0; i < size(chickenZoo); i++) {
//        if (!chickenZoo[i]->getGender() && !chickenZoo[i]->getSick() && !chickenZoo[i]->getHungry() &&
//            isMaleReady()) {
//            chickenZoo[i]->eggSpawning(date);
//        }
//    }
}

bool Zoo::isMaleReady() {
//    for (int i = 0; i < size(chickenZoo); i++) {
//        if (chickenZoo[i]->getGender() && !chickenZoo[i]->getSick() && !chickenZoo[i]->getHungry()) {
//            return true;
//        }
//    }
//    return false;
}

void Zoo::breedTigers(Time *date) {
    vector<IAnimal *> tigers;

    int numMales = 0, numFemales = 0;
    for (auto *house: zooHouses) {
        int space = 0;
        // check if there is enough space
        if (house->getType().find("Tiger") && house->getSize() - house->getLen() >= 1) {
            space += house->getSize() - house->getLen();
        }
        if (space < 3) {
            cout << "Error: not enough space for breeding, buy one or 2 more Tiger houses" << endl;
            return;
        }
        if (house->getType().find("Tiger")) {
            for (auto *animal: house->getHouse()) {
                if (animal->getAge(*date).getYear() >= 4 && !animal->getHungry()) {
                    if (animal->getGender()) {
                        tigers.push_back(animal);
                        numMales++;
                    } else {
                        tigers.push_back(animal);
                        numFemales++;
                    }
                }
            }
        }
    }
    // If there are at least two tigers of opposite genders, try to breed them
    if (numMales > 0 && numFemales > 0) {
        // Find a female tiger that is not already pregnant and has not been pregnant in the last 20 months
        IAnimal *femaleTiger = nullptr;
        for (IAnimal *tiger: tigers) {
            if (tiger->canBePregnant(date)) {
                femaleTiger = tiger;
                break;
            }
        }
        if (femaleTiger != nullptr) {
            femaleTiger->setPregnant(true);
            femaleTiger->setLastPregnancyDate(date);
            cout << "Tiger breeding successful, " << femaleTiger->getName() << " is now pregnant!" << endl;
            return;
        } else {
            cout << "No female Tiger ready to be a mother :(" << endl;
        }
    } else {
        cout << "Error: not enough tigers of opposite genders for breeding" << endl;
    }
}

void Zoo::eagleEggs(Time *date) {
    vector<IAnimal *> eagles;
    for (auto *house: zooHouses) {
        if (house->getType() == "Eagle") {
            for (auto *eagle: house->getHouse()) {
                eagles.push_back(eagle);
            }
        }
    }
    for (auto *eagle: eagles) {
        if (!eagle->getGender() && eagle->getPartner() != nullptr) {
            eagleNursery.push_back(new EagleEgg(*date));
            eagleNursery.push_back(new EagleEgg(*date));
        }
    }
}

void Zoo::getVisits(Time *date) {
    auto *random = new Random();

    int tigerNbr = 0;
    int eagleNbr = 0;
    int chickenNbr = 0;
    int totalVisitors;

    double uncertainty = random->getUncertainty(0.8, 1.2);

    cout << uncertainty << endl;

    for (House *house: zooHouses) {
        if (house->getType() == "Tiger") {
            tigerNbr += house->getShowableAnimalsNbr();
        } else if (house->getType() == "Eagle") {
            eagleNbr += house->getShowableAnimalsNbr();
        } else {
            chickenNbr += house->getShowableAnimalsNbr();
        }
    }

    if (date->getMonth() >= 5 && date->getMonth() <= 9) {
        totalVisitors = uncertainty * (tigerNbr * 30 + eagleNbr * 15 + chickenNbr * 2);
    } else {
        totalVisitors = uncertainty * (tigerNbr * 5 + eagleNbr * 7 + chickenNbr * 0.5);
    }

    cout << "Visitors today :" << totalVisitors << endl;

    m_money += (17 + 13) / 4 * totalVisitors;

    delete random;
}

void Zoo::checkTigerGestation(Time *date) {
    for (auto *house: zooHouses) {
        if (house->getType().find("Tiger")) {
            house->checkGestation(date);
        }
    }
}

void Zoo::checkAnimalAges(Time *date) {
    for (auto *house: zooHouses) {
        house->checkAnimalAges(date);
    }
}

void Zoo::addGrant() {
    double tigerGrant = 0;
    double eagleGrant = 0;
    for (House *house: zooHouses) {
        if (house->getType().find("Tiger")) {
            tigerGrant += 43800 * house->getLen();
        }
    }
    for (House *house: zooHouses) {
        if (house->getType().find("Eagle")) {
            eagleGrant += 2190 * house->getLen();
        }
    }
    m_money += tigerGrant + eagleGrant;
}

void Zoo::fire() {
    // set probability of 1%
    auto *probability = new Random();
    if (probability->probability(1)) {
        // get a random house to burn it
        int randomHouse = probability->randomInt(zooHouses.size());
        zooHouses[randomHouse]->fire();
        delete zooHouses[randomHouse];
        zooHouses.erase(zooHouses.begin() + randomHouse);
    }
    delete probability;
}

void Zoo::animalTheft() {
    // set probability of 1%
    auto *probability = new Random();
    if (probability->probability(1)) {
        // get a random house
        int randomHouse = probability->randomInt(zooHouses.size());
        zooHouses[randomHouse]->animalTheft();
    }
    delete probability;
}

void Zoo::pest() {
    // set probability of 20%
    auto *probability = new Random();
    if (probability->probability(20)) {
        cout << (getSeeds() * 0.1) << "kg of seeds has been destructed..." << endl;
        setSeeds(-(getSeeds() * 0.1));
    }
    delete probability;
}

void Zoo::rottenFlesh() {
    // set probability of 10%
    auto *probability = new Random();
    if (probability->probability(10)) {
        cout << (getMeat() * 0.2) << "kg of meat has been destructed..." << endl;
        setMeat(-(getMeat() * 0.2));
    }
    delete probability;
}

void Zoo::beSick() {
    for (auto *house: zooHouses) {
        house->beSick();
    }
}

void Zoo::checkSick() {
    for (auto *house: zooHouses) {
        house->checkSick();
    }
}

void Zoo::dailyActions(Time *date) {
    feedAnimals();
    getVisits(date);
    chikenEggSpawing(date);
    checkSick();
    checkEagleEggs(date);
}

void Zoo::montlyActions(Time *date) {
    breedTigers(date);
    checkTigerGestation(date);
    checkAnimalAges(date);
    beSick();
    setPartner(date);
    // specials events
    fire();
    animalTheft();
    pest();
    rottenFlesh();
    // Eagles egg
    if (date->getMonth() == 5) {
        eagleEggs(date);
    }


    for (int i = 0; i < 30; i++) {
        cout << "Day: " << i << endl;
        dailyActions(date);
    }
}

