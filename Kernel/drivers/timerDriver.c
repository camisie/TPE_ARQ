#include <lib.h>
#include <timerDriver.h>

#define UNI 15
#define DEC 240

void getLocalDate(date myDate) {
    int sec = getSeconds();
    int min = getMinutes();
    int hour = getHours();
    int day = getDay();
    int month = getMonth();
    int year = getYear();

    myDate->day = ((day & DEC) >> 4) * 10;
    myDate->day += (day & UNI);

    myDate->month = ((month & DEC) >> 4) * 10;
    myDate->month += (month & UNI);

    myDate->year = ((year & DEC) >> 4) * 10;
    myDate->year += (year & UNI);

    myDate->seconds = ((sec & DEC) >> 4) * 10;
    myDate->seconds += (sec & UNI);

    myDate->minutes = ((min & DEC) >> 4) * 10;
    myDate->minutes += (min & UNI);

    myDate->hour = ((hour & DEC) >> 4) * 10;
    myDate->hour += (hour & UNI);
}
