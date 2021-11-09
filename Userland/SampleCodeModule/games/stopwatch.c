#include <stopWatch.h>
#include <syscalls.h>
#include <standardIO.h>

static long initialTicks = 0;
static long currentTicks = 0;
static int running = 1;

void initStopwatch() {
    printstring(10, 20, "Instructions:");
    printstring(30, 20,"- Press 'P' to play/pause");
    printstring(40, 20,"- Press 'R' to reset");
    printstring(50, 20,"Make sure letters entered are in uppercase!");
    printstring(200, 125, "CHRONOMETER:");
    initialTicks = getTicksElapsed();
    currentTicks = initialTicks;
    return;
}

void stopwatch() {
    if(running) {
        currentTicks = getTicksElapsed();
    }
    int stopwatchTicks = currentTicks-initialTicks;
    long millis = stopwatchTicks * 55;
    int centiSec = (millis % 1000)/10;
    int secs = (millis % 60000)/1000;
    int mins = (millis % 3600000)/60000;
    printstring(200, 250,"%d::%d::%d", mins, secs, centiSec);
}

void resetStopwatch() {
    initialTicks = getTicksElapsed();
    currentTicks = initialTicks;
}

void changeStatus() {
    if(running) {
        running = 0;
    }
    else {
        running = 1;
    }
}
