#include <time.h>
#include <keyboardDriver.h>
#include <videoDriver.h>

#define TIMER 0
#define KEYBOARD 1

static void int_20();
static void int_21(uint64_t *rsp);

void irqDispatcher(uint64_t irq, uint64_t *rsp) {
    switch (irq) {
        case TIMER:
            int_20();
            break;
        case KEYBOARD:
            int_21(rsp);
            break;
    }
    return;
}

void int_20() {
    timerHandler();
}

void int_21(uint64_t *rsp) {
    keyboardHandler(rsp);
}
