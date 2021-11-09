#include <types.h>
#include <lib64.h>
#include <string.h>
#include <stdint.h>

#define READ_SYSCALL 0
#define WRITE_SYSCALL 1
#define CLEAR_SYSCALL 3
#define INFO_REG 8
#define MEM_DUMP 9
#define TIME_SYSCALL 10
#define SET_ALARM 11
#define SCREEN_HEIGHT 12
#define SCREEN_WIDTH 13
#define DIVIDE_SCREEN 14
#define SET_STOPWATCH 15
#define STOPWATCH_TICKS 16
#define TICKS_ELAPSED 17


int read(char *buffer, int length) {
    return _syscall(READ_SYSCALL, length, buffer);
}

int write(char *buffer, int row, int col, int color) {
    int length = strlen(buffer);
    return _syscall(WRITE_SYSCALL, length, buffer, row, col, color);
}

void clearScreen() {
    _syscall(CLEAR_SYSCALL);
}

void getTime(date myDate) {
    _syscall(TIME_SYSCALL, myDate);
}

void getRegisters(uint64_t *registers) {
    _syscall(INFO_REG, registers);
}

void memoryDump(char *dir, char *dump) {
    _syscall(MEM_DUMP, dir, dump);
}

int getHeight() {
    return _syscall(SCREEN_HEIGHT);
}

int getWidth() {
    return _syscall(SCREEN_WIDTH);
}

void divideScreen() {
     _syscall(DIVIDE_SCREEN);
}

void setStopwatch(int option) {
    _syscall(SET_STOPWATCH);
}

int getStopwatchTicks() {
    return _syscall(STOPWATCH_TICKS);
}

int getTicksElapsed() {
    return _syscall(TICKS_ELAPSED);
}
