#include <stdint.h>
#include <library.h>
#include <syscalls.h>
#include <videoDriver.h>
#include <keyboardDriver.h>
#include <timerDriver.h>
#include <time.h>
#include <colors.h>

int sys_read(int length, char *toRead) {
    return readBuffer(length, toRead);
}

int sys_write(int length, char *toWrite, int row, int col, int color) {
    return printStringFrom(toWrite, length, row, col, color);
}

int sys_draw(int *matrix, int row, int col, int rows, int columns) {
    return drawMatrix(matrix, row, col, rows, columns);
}

void getTime(date myDate) {
    getLocalDate(myDate);
}

void getMem(char *dir, char *dump) {
    for (int i = 0; i < MEM_BYTES; i++ ) {
        dump[i] = dir[i];
    }
}

void getRegisters(uint64_t firstP[]) {
    fillWithRegs(firstP);
}

void sys_clear() {
    clearScreen();
}

void sys_divide() {
    divideScreen(WHITE);
}

int getScreenHeight() {
    return screenHeight();
}

int getScreenWidth() {
    return screenWidth();
}
