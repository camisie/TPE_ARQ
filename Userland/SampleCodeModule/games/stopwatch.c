#include <stopWatch.h>
#include <syscalls.h>
#include <standardIO.h>

static long initialTicks = 0;

void initStopwatch() {
    printstring(10, 20, "Instructions:");
    printstring(30, 20,"- Press 'P' to play/pause");
    printstring(40, 20,"- Press 'R' to reset");
    printstring(50, 20,"Make sure letters entered are in uppercase!");
    printstring(200, 125, "CHRONOMETER:");
    // changeCursorState(0);
    initialTicks = getTicksElapsed();
    setStopwatch(0);
    return;
}

void stopwatch() {
    long currentTicks = getTicksElapsed();
    int stopwatchTicks = currentTicks-initialTicks;
    long millis = stopwatchTicks * 55;
    int centiSec = (millis % 1000)/10;
    int secs = (millis % 60000)/1000;
    int mins = (millis % 3600000)/60000;
    printstring(200, 400,"%d::%d::%d", mins, secs, centiSec);
}
