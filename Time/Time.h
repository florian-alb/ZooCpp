//
// Created by Florian ALBORA on 19/03/2023.
//

#ifndef ZOOREWORK_TIME_H
#define ZOOREWORK_TIME_H


#include <iostream>
#include <vector>

using namespace std;


class Time {
    int m_year;
    int m_month;
    int m_day;

public:

    Time(int year, int month, int day);

    void newMonth();

    bool checkNewYear();

    void setYear(int year);

    void setMonth(int month);

    void setDay(int day);
    int getYear();

    int getMonth();

    int getDay();

    int totalMonthsFromStartOfYear() const ;

    int monthsBetweenDates(const Time &dateToCompare);


};



#endif //ZOOREWORK_TIME_H
