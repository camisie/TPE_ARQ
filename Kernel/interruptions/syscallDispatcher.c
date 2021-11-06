#include <syscalls.h>

int syscallDispatcher(uint64_t call, uint64_t firstP, uint64_t secondP, uint64_t thirdP, uint64_t fourthP,
                      uint64_t fifthP) {
    switch (call) {
        case SYS_READ_ID:
            return sys_read((int) firstP, (char *) secondP);
        case SYS_WRITE_ID:
            return sys_write((int) firstP, (char *) secondP, (int) thirdP, (int) fourthP, (int) fifthP);
        case SYS_DRAW_ID:
            return sys_draw((int *) firstP, (int) secondP, (int) thirdP, (int) fourthP, (int) fifthP);
        case SYS_CLEAR_ID:
            sys_clear();
            return 0;
        case SYS_INFOREG_ID:
            getRegisters((uint64_t *) firstP);
            return 0;
        case SYS_PRINTMEM_ID:
            getMem((char *) firstP, (char *) secondP);
            return 0;
        case SYS_TIME_ID:
            getTime((date) firstP);
            return 0;
        case SCREEN_HEIGHT_ID:
            return getScreenHeight();
        case SCREEN_WIDTH_ID:
            return getScreenWidth();
        case DIVIDE_SCREEN_ID:
            sys_divide();
        default:
            return -1;
    }
    return -1;
}
