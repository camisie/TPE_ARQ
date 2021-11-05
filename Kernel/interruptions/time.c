#include <time.h>
#include <stdint.h>

static unsigned long ticks = 0;

typedef struct function {
    void (*f)(void);

    int enabled;
} function;

function alarm = {0, 0};

void timerHandler() {
    ticks++;
    if (alarm.enabled) {
        alarm.f();
    }
}

int ticks_elapsed() {
    return ticks;
}

int seconds_elapsed() {
    return ticks / 18;
}
