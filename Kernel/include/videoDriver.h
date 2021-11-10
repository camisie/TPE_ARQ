#ifndef VIDEO_DRIVER_H
#define VIDEO_DRIVER_H

void drawPixel(int row, int col, int color);

int drawCharFrom(int character, int row, int col, int color);

int drawChar(int character, int color);

void clearScreen();

void divideScreen(int color);

void checkPosition();

void shift();

void clearLine(int yPos);

void insertEnter();

void backspace();

#endif
