#include <time.h>
#include <stdint.h>

static unsigned long ticks = 0;
static unsigned long chronometerTicks = 0;
int chronometerEnabled = 0;

void timerHandler() {
    ticks++;
    if (chronometerEnabled) {
        chronometerTicks++;
    }
}

int ticks_elapsed() {
    return ticks;
}

int seconds_elapsed() {
    return ticks / 18;
}

void setStopwatch(int option) {
    //reset
    if(option == 0) {
        chronometerEnabled = 1;
        chronometerTicks = 0;
    }
    //pause <-> play
    else if(option == 1 && chronometerEnabled == 0) {
        chronometerEnabled = 1;
    }
    else {
        chronometerEnabled = 0;
    }
}

int getStopwatchTicks() {
    return chronometerTicks++;
}
