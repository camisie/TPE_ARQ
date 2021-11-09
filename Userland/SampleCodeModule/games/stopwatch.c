#include <stopWatch.h>
#include <syscalls.h>
#include <standardIO.h>

static int secAux = 0;
static int minAux = 0;

void initStopwatch() {
    secAux = 0;
    minAux = 0;
    printstring(10, 20, "Instructions:");
    printstring(30, 20,"- Press 'P' to play/pause");
    printstring(40, 20,"- Press 'R' to reset");
    printstring(50, 20,"Make sure letters entered are in uppercase!");
    printstring(200, 125, "CHRONOMETER:");
    // changeCursorState(0);
    setStopwatch(0);
    return;
}

void stopwatch() {
    int stopwatchTicks = getStopwatchTicks();
    int millis = stopwatchTicks * 5000 / 91;

    if (millis < 10) {
        printstring(200, 400, "0%d", millis);
    }
    else {
        printstring(200, 400, "%d", millis);
    }

    int sec = stopwatchTicks * 91/ 5;
    int min = sec / 60;
    sec %= 60;

    if (sec != secAux) {
        secAux = sec;
        if (sec < 10) {
            printstring(200, 350,"0%d::", sec);

        }
        else {
            printstring(200, 350,"%d::", sec);
        }
    }

    if (min != minAux) {
        printstring(200, 250,"0%d::", min);
        minAux = min;
    }
    return;
}
