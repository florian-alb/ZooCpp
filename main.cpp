#include <iostream>
#include "Menu/Menu.h"

#include "Animals/Tiger.h"
#include "Animals/Chicken.h"
#include "Animals/Eagle.h"


using namespace std;

int main(){
    Menu menu;

    Time currentDate(0,1,1);

    Zoo *zoo = new Zoo("Zoo", 80000);
    Tiger *tiger = new Tiger("", true);
    Eagle *eagle = new Eagle("", true);
    Chicken *chicken = new Chicken("", true);

    Meat *meat = new Meat(5);
    Seeds *seeds = new Seeds(2.5);

    Tiger *tiger1 = new Tiger("Tiger1", true);
    Tiger *tiger2 = new Tiger("Tiger2", false);
    Tiger *tiger3 = new Tiger("Tiger3", true);
    Tiger *tiger4 = new Tiger("Tiger4", false);

    Eagle *eagle1 = new Eagle("Eagle1", true);
    Eagle *eagle2 = new Eagle("Eagle2", false);
    Eagle *eagle3 = new Eagle("Eagle3", true);
    Eagle *eagle4 = new Eagle("Eagle4", false);

    Chicken *rooster = new Chicken("Rooster", true);

    Chicken *hen1 = new Chicken("Hen1", false);
    Chicken *hen2 = new Chicken("Hen2", false);
    Chicken *hen3 = new Chicken("Hen3", false);
    Chicken *hen4 = new Chicken("Hen4", false);
    Chicken *hen5 = new Chicken("Hen5", false);
    Chicken *hen6 = new Chicken("Hen6", false);
    Chicken *hen7 = new Chicken("Hen7", false);
    Chicken *hen8 = new Chicken("Hen8", false);
    Chicken *hen9 = new Chicken("Hen9", false);
    Chicken *hen10 = new Chicken("Hen10", false);


    House *tigerHouse1 = new House("Tiger");
    House *tigerHouse2 = new House("Tiger");
    House *eagleHouse1 = new House("Eagle");
    House *eagleHouse2 = new House("Eagle");
    House *chickenHouse1 = new House("Chicken");

    zoo->addHouse(tigerHouse1);
    zoo->addHouse(tigerHouse2);
    zoo->addHouse(eagleHouse1);
    zoo->addHouse(eagleHouse2);
    zoo->addHouse(chickenHouse1);

    tigerHouse1->addAnimal(tiger1);
    tigerHouse1->addAnimal(tiger2);
    tigerHouse2->addAnimal(tiger3);
    tigerHouse2->addAnimal(tiger4);

    eagleHouse1->addAnimal(eagle1);
    eagleHouse1->addAnimal(eagle2);
    eagleHouse2->addAnimal(eagle3);
    eagleHouse2->addAnimal(eagle4);

    chickenHouse1->addAnimal(rooster);
    chickenHouse1->addAnimal(hen1);
    chickenHouse1->addAnimal(hen2);
    chickenHouse1->addAnimal(hen3);
    chickenHouse1->addAnimal(hen4);
    chickenHouse1->addAnimal(hen5);
    chickenHouse1->addAnimal(hen6);
    chickenHouse1->addAnimal(hen7);
    chickenHouse1->addAnimal(hen8);
    chickenHouse1->addAnimal(hen9);
    chickenHouse1->addAnimal(hen10);

    zoo->setMeat(100);  // 100kg of meat
    zoo->setSeeds(50);  // 50kg of seeds

    tigerHouse1->sellAnimal(0, &currentDate, *zoo);

    zoo->showZoo(&currentDate);

    while (currentDate.getYear() < 10 ) // 10 years of game
    {
        zoo->showZoo(&currentDate);

        /* --- month loop --- */
        bool nextMonth = false;
        while (!nextMonth){
            nextMonth = menu.monthlyGame(currentDate, zoo, tiger, eagle, chicken, meat, seeds);
        }

        /* --- check new year --- */
        if (!currentDate.checkNewYear()){
            /* --- next month --- */
            currentDate.newMonth();
            cout << currentDate.getMonth() << endl;
            zoo->montlyActions(&currentDate);
        } else {
            cout << " new year " << endl;
            zoo->addGrant();
        }
    }
}
