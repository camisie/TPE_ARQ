#ifndef sudoku_h
#define sudoku_h

#include <standardIO.h>
#include <syscalls.h>
#include <stdarg.h>

#define N 9

// int getint(const char message[], ... );

void printSudoku(int board[N][N]);

int readNumber(int *x, int *y);

int hasPrevSudGame();

void runSudoku(int entry);

void playSudoku();

#endif
