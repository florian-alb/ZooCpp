cmake_minimum_required(VERSION 3.24)
project(zooRework)

set(CMAKE_CXX_STANDARD 20)

add_executable(zooRework main.cpp Animals/Chicken.cpp Animals/Chicken.h Animals/Tiger.cpp Animals/Tiger.h Animals/Eagle.cpp Animals/Eagle.h Animals/IAnimal.cpp Animals/IAnimal.h Time/Time.cpp Time/Time.h Zoo/Zoo.cpp Zoo/Zoo.h Food/Food.cpp Food/Food.h Food/Meat.cpp Food/Meat.h Food/Seeds.cpp Food/Seeds.h House/House.cpp House/House.h Menu/Menu.cpp Menu/Menu.h Random/Random.cpp Random/Random.h Egg/EagleEgg.cpp Egg/EagleEgg.h Egg/Egg.cpp Egg/Egg.h Egg/ChickenEgg.cpp Egg/ChickenEgg.h)
