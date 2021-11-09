#include <stopWatch.h>
#include <syscalls.h>
#include <standardIO.h>

static int secAux = 0;
static int minAux = 0;

void initStopwatch() {
    secAux = 0;
    minAux = 0;
    printstring(10, 20, "Instructions:");
    printstring(30, 20,"- Press 'p' to play/pause");
    printstring(40, 20,"- Press 'r' to reset");
    printstring(200, 125, "CHRONOMETER:");
    printstring(200, 250, "00::00::00");
    // changeCursorState(0);
    setStopwatch(0);
    return;
}

void stopwatch() {
    int stopwatchTicks = getStopwatchTicks();
    int dsec = stopwatchTicks % 100;

    if (dsec < 10) {
        printstring(200, 250, "0%d", dsec);
    }
    else {
        printstring(200, 300, "%d", dsec);
    }

    int sec = stopwatchTicks / 18;
    int min = sec / 60;
    sec = sec % 60;

    if (sec != secAux) {
        secAux = sec;
        if (sec < 10) {
            printstring(200, 275,"0%d::", sec);

        }
        else {
            printstring(200, 275,"%d::", sec);
        }
    }

    if (min != minAux) {
        printstring(200, 250,"0%d::", min);
        minAux = min;
    }
    return;
}
