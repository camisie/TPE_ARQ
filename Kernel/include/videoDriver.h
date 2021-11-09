#ifndef VIDEO_DRIVER_H
#define VIDEO_DRIVER_H

void drawPixel(int row, int col, int color);

int drawCharFrom(int character, int row, int col, int color);

int drawChar(int character, int color);

void clearScreen();

int screenHeight();

int screenWidth();

void divideScreen(int color);

#endif
