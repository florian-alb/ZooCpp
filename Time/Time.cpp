#include <iostream>
#include "Time.h"

using namespace std;


Time::Time(int year, int month, int day) : m_year(year), m_month(month), m_day(day) {}

void Time::newMonth() {
    m_month += 1;
    m_day = 0;
    cout << m_month << endl;
}

bool Time::checkNewYear() {
    if (m_month > 12) {
        m_year += 1;
        m_month = 1;
        cout << m_year << endl;
        return true;
    }
    return false;
}

void Time::setYear(int year) {
    m_year = year;
}

void Time::setMonth(int month) {
    m_month = month;
}

void Time::setDay(int day) {
    m_day = day;
}

int Time::getYear() {
    return m_year;
}

int Time::getMonth() {
    return m_month;
}

int Time::getDay() {
    return m_day;
}

int Time::totalMonthsFromStartOfYear() const {
    return (m_year - 1) * 12 + (m_month - 1);
}

int Time::monthsBetweenDates(const Time &dateToCompare) {
    int months1 = this->totalMonthsFromStartOfYear() + this->m_month;
    int months2 = dateToCompare.totalMonthsFromStartOfYear() + dateToCompare.m_month;
    return months2 - months1;
}
