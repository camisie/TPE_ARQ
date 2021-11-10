#include <stdint.h>
#include <library.h>
#include <syscalls.h>
#include <videoDriver.h>
#include <keyboardDriver.h>
#include <timerDriver.h>
#include <time.h>

#define WHITE_COLOR 0xFFFFFF


int sys_read(int length, char *toRead) {
    return readBuffer(length, toRead);
}

int sys_write(int length, char *toWrite, int row, int col, int color) {
    return printStringFrom(toWrite, length, row, col, color);
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
    fillWithRegisters(firstP);
}

void sys_clear() {
    clearScreen();
}

void sys_divide() {
    divideScreen(WHITE_COLOR);
}

int getScreenHeight() {
    return screenHeight();
}

int getScreenWidth() {
    return screenWidth();
}
