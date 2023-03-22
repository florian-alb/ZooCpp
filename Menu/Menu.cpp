//
// Created by Florian ALBORA on 19/03/2023.
//


#include "Menu.h"

using namespace std;


void Menu::mainMenu() {
    // Afficher le menu d'actions disponibles
    cout << "\nMain Menu :\n"
            "Select an action : \n"
            "SHOW ZOO -> type '0' \n"
            "BUY MENU -> type '1' \n"
            "SELL MENU -> type '2'\n"
            "NEXT MONTH -> type '3' "
         << endl;
}

void Menu::buyMenu() {
    cout << "\nWhat do you want to buy?\n"
            "ANIMAL -> type '1' \n"
            "HOUSE -> type '2'\n"
            "FOOD -> type '3' \n"
            "EXIT MENU -> type '4'"
         << endl;
}

void Menu::sellMenu() {
    cout << "\nWhat do you want to sell?\n"
            "ANIMAL -> type '1' \n"
            "HOUSE -> type '2'\n"
            "EXIT MENU -> type '3'"
         << endl;
}

void Menu::buyAnimalMenu() {
    cout << "\nWhat animal do you ant to buy?\n"
            "TIGER -> type '1' \n"
            "CHICKEN -> type '2'\n"
            "EAGLE -> type '3'\n"
            "EXIT MENU -> type '4'"
         << endl;
}

void Menu::buyHouseMenu() {
    cout << "\nWhat animal house do you ant to buy?\n"
            "TIGER -> type '1' \n"
            "CHICKEN -> type '2'\n"
            "EAGLE -> type '3'\n"
            "EXIT MENU -> type '4'"
         << endl;
}

void Menu::buyFoodMenu() {
    cout << "\nWhat food do you ant to buy?\n"
            "MEAT -> type '1' \n"
            "SEEDS -> type '2'\n"
            "EXIT MENU -> type '3'"
         << endl;
}

void Menu::sellHouseMenu() {
    cout << "\nWhat animal house do you ant to sell?\n"
            "TIGER -> type '1' \n"
            "CHICKEN -> type '2'\n"
            "EAGLE -> type '3'\n"
            "EXIT MENU -> type '4'"
         << endl;
}

void Menu::sellAnimalMenu() {
    cout << "\nWhat animal type do you ant to sell?\n"
            "TIGER -> type '1' \n"
            "CHICKEN -> type '2'\n"
            "EAGLE -> type '3'\n"
            "EXIT MENU -> type '4'"
         << endl;
}

void Menu::askGender(string animal) {
    if (animal == "Chicken") {
        cout << "\nWhat do you need ? \n"
                "ROOSTER ( male ) : 100$ -> type '1' \n"
                "HEN ( female ) : 20$ -> type '2'\n"
                "EXIT MENU -> type '3'"
             << endl;
    } else {
        cout << "\nWhat gender for your " << animal << " ?\n"
                                                       "MALE -> type '1' \n"
                                                       "FEMALE -> type '2'\n"
                                                       "EXIT MENU -> type '3'"
             << endl;
    }
}

void Menu::askAge(string youngPrice, string adultPrice, string oldPrice) {
    cout << "\nWhat food do you ant to buy?\n"
            "YOUNG : 6 month " << youngPrice << " -> type '1' \n"
                                                "ADULT : 4 years " << adultPrice << " -> type '2'\n"
                                                                                    "OLD : 14 years " << oldPrice
         << " -> type '3'\n"
            "EXIT MENU -> type '4'"
         << endl;
}

void Menu::buyAnimal(int animal, Zoo *zoo, Tiger *tiger, Eagle *eagle, Chicken *chicken, Time date) {
    bool gender;
    int age;
    string name;
    switch (animal) {
        case TIGER:
            askGender("Tiger");
            gender = askUserGender();
            askAge("3 000$", "120 000$", "60 000$");
            age = askAction(age);

            if (zoo->canBuy(tiger, age)) {
                cout << "Set a name for your animal" << endl;
                name = askName();
                zoo->buyAnimal(new Tiger(name, gender), age, date);
            } else {
                cout << "Sorry, your are broke my friend. Not enough money to buy this" << endl;
            }
            break;

        case CHICKEN:
            ChickenGender chickenGender;
            askGender("Chicken");
            chickenGender = askChikenGender();

            if (zoo->canBuy(chicken, chickenGender.gender)) {
                cout << "Set a name for your animal" << endl;
                name = askName();
                zoo->buyAnimal(new Chicken(name, chickenGender.gender), chickenGender.userValue, date);
            } else {
                cout << "Sorry, your are broke my friend. Not enough money to buy this" << endl;
            }
            break;

        case EAGLE:
            askGender("Eagle");
            gender = askUserGender();
            askAge("1 000$", "4 000$", "2 000$");
            age = askAction(age);

            if (zoo->canBuy(eagle, age)) {
                cout << "Set a name for your animal" << endl;
                name = askName();
                zoo->buyAnimal(new Eagle(name, gender), age, date);
            } else {
                cout << "Sorry, your are broke my friend. Not enough money to buy this" << endl;
            }
            break;

        case 4:
            return;
        default:
            cout << "\nInvalid choice. Please try again." << endl;
            break;
    }
}

void Menu::buyFood(int food, Zoo *zoo, Meat *meat, Seeds *seeds) {
    int quantity;
    switch (food) {
        case MEAT:
            cout << "\nHow many kg of MEAT do you want to buy? : $5/kg" << endl;
            quantity = askAction(quantity);

            if (zoo->canBuy(meat, quantity)) {
                zoo->buyFood(meat, quantity);
            } else {
                cout << "Sorry, your are broke my friend. Not enough money to buy this" << endl;
            }
            break;

        case SEEDS:
            cout << "\nHow many kg of SEEDS do you want to buy? : $2.5/kg" << endl;
            quantity = askAction(quantity);
            if (zoo->canBuy(seeds, quantity)) {
                zoo->buyFood(seeds, quantity);
            } else {
                cout << "Sorry, your are broke my friend. Not enough money to buy this" << endl;
            }
            break;

        default:
            cout << "\nInvalid choice. Please try again." << endl;
    }
}

void Menu::buyHouse(int animal, Zoo *zoo) {
    switch (animal) {
        case TIGER:
            if (zoo->getMoney() >= 2000) {
                zoo->buyHouse(new House("Tiger"));
            } else {
                cout << "Sorry, your are broke my friend. Not enough money to buy this" << endl;
            }
            break;

        case CHICKEN:
            if (zoo->getMoney() >= 300) {
                zoo->buyHouse(new House("Chicken"));
            } else {
                cout << "Sorry, your are broke my friend. Not enough money to buy this" << endl;
            }
            break;

        case EAGLE:
            if (zoo->getMoney() >= 2000) {
                zoo->buyHouse(new House("Eagle"));
            } else {
                cout << "Sorry, your are broke my friend. Not enough money to buy this" << endl;
            }
            break;

        default:
            cout << "\nInvalid choice. Please try again." << endl;
    }
}

void Menu::sellHouse(int animal, Zoo *zoo) {
    switch (animal) {
        case TIGER:
            zoo->sellHouse(new House("Tiger"));
            break;
        case EAGLE:
            zoo->sellHouse(new House("Eagle"));
            break;
        case CHICKEN:
            zoo->sellHouse(new House("Chicken"));
            break;
        default:
            cout << "\nInvalid choice. Please try again." << endl;
    }
}

void Menu::sellAnimal(int animal, Zoo *zoo, Time date) {
    switch (animal) {
        int houseIndex;
        int animalIndex;
        case TIGER:
            zoo->showAllTigers(date);
            houseIndex = askSellAction("Enter the number of the house where the animal for sale is located > ");
            animalIndex = askSellAction("Enter the number of the animal to sell > ");

            if (houseIndex < 0 || houseIndex > zoo->typeHouseNbr("Tiger")) {
                cout << "This house do not exist" << endl;
                return;
            }
            if (animalIndex < 0 || animalIndex > zoo->getHouseSize(houseIndex)) {
                cout << "This animal do not exist" << endl;
                return;
            }
            zoo->sellAnimal(houseIndex, animalIndex, &date);
            break;
        case EAGLE:
            zoo->showAllTigers(date);
            houseIndex = askSellAction("Enter the number of the house where the animal for sale is located > ");
            animalIndex = askSellAction("Enter the number of the animal to sell > ");

            if (houseIndex < 0 || houseIndex > zoo->typeHouseNbr("Tiger")) {
                cout << "This house do not exist" << endl;
                return;
            }
            if (animalIndex < 0 || animalIndex > zoo->getHouseSize(houseIndex)) {
                cout << "This animal do not exist" << endl;
                return;
            }
            zoo->sellAnimal(houseIndex, animalIndex, &date);
            break;
        case CHICKEN:
            zoo->showAllTigers(date);
            houseIndex = askSellAction("Enter the number of the house where the animal for sale is located > ");
            animalIndex = askSellAction("Enter the number of the animal to sell > ");

            if (houseIndex < 0 || houseIndex > zoo->typeHouseNbr("Tiger")) {
                cout << "This house do not exist" << endl;
                return;
            }
            if (animalIndex < 0 || animalIndex > zoo->getHouseSize(houseIndex)) {
                cout << "This animal do not exist" << endl;
                return;
            }
            zoo->sellAnimal(houseIndex, animalIndex, &date);
            break;
        default:
            cout << "\nInvalid choice. Please try again." << endl;
    }
}

void Menu::handleBuyMenuChoice(int choice, Zoo *zoo, Tiger *tiger, Eagle *eagle, Chicken *chicken, Meat *meat, Seeds *seeds,
                         Time date) {
    switch (choice) {
        case 1:
            int animal;
            buyAnimalMenu();
            buyAnimal(askAction(animal), zoo, tiger, eagle, chicken, date);
            break;
        case 2:
            int house;
            buyHouseMenu();
            buyHouse(askAction(house), zoo);
            break;
        case 3:
            int food;
            buyFoodMenu();
            buyFood(askAction(food), zoo, meat, seeds);
            break;
        case 4:
            return;
        default:
            cout << "\nInvalid choice. Please try again." << endl;
            break;
    }
}

void Menu::handleSellMenuChoice(int choice, Zoo *zoo, Time date) {
    switch (choice) {
        case 1:
            int toSell;
            sellAnimalMenu();
            toSell = askAction(toSell);
            sellAnimal(toSell, zoo, date);
            break;
        case 2:
            int animal;
            sellHouseMenu();
            animal = askAction(animal);
            sellHouse(animal, zoo);
            break;
        case 3:
            return;
        default:
            cout << "\nInvalid choice. Please try again." << endl;
            break;
    }
}

int Menu::askAction(int choice) {
    while (true) {
        cout << "\nAction > ";
        if (!(cin >> choice)) {
            // An error occurred when reading from cin
            cin.clear(); // Clear the error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard any invalid input
            cout << "Invalid input. Please try again.\n";
        } else {
            // Input operation succeeded
            return choice;
        }
    }
}

int Menu::askSellAction(string textToask) {
    int choice;
    while (true) {
        cout << textToask;
        if (!(cin >> choice)) {
            // An error occurred when reading from cin
            cin.clear(); // Clear the error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard any invalid input
            cout << "Invalid input. Please try again.\n";
        } else {
            // Input operation succeeded
            return choice;
        }
    }
}

bool Menu::askUserGender() {
    int input;
    cout << "Your choice > ";
    while (!(cin >> input) || (input != 1 && input != 2)) {
        cout << "Invalid input. Please enter 1 for male or 2 for female." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return (input == 1);
}

Menu::ChickenGender Menu::askChikenGender() {
    ChickenGender result;
    cout << "Your choice > ";
    cin >> result.userValue;
    while (cin.fail() || (result.userValue != 1 && result.userValue != 2)) {
        cout << "Invalid input. Please enter 1 for male or 2 for female: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> result.userValue;
    }
    result.gender = (result.userValue == 1);
    return result;
}

string Menu::askName() {
    string name;
    cout << "\nName >";
    cin >> name;
    return name;
}

bool Menu::monthlyGame(Time date, Zoo *zoo, Tiger *tiger, Eagle *eagle, Chicken *chicken, Meat *meat, Seeds *seeds) {
    mainMenu();
    int menu = askAction(menu);
    switch (menu) {
        case 0:
            zoo->showZoo(&date);

        case 1:
            int buyChoise;
            buyMenu();
            handleBuyMenuChoice(askAction(buyChoise), zoo, tiger, eagle, chicken, meat, seeds, date);
            return false;
        case 2:
            int sellChoise;
            sellMenu();
            handleSellMenuChoice(askAction(sellChoise), zoo, date);
            return false;

        case 3:
            cout << "\nNext month" << endl;
            return true; // next month

        default:
            cout << "\nInvalid choice. Please try again." << endl;
            break;
    }
    return false;
}
