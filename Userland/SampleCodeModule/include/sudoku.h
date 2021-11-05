#ifndef sudoku_h
#define sudoku_h

#include <stdio.h>

#define N 9

int getint(const char message[], ... );

void printSudoku(const int board[N][N]);

int readNumber(int *x, int *y);

#endif 
