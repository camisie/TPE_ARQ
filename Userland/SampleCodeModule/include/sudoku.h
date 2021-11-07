#ifndef sudoku_h
#define sudoku_h

#include <standardIO.h>
#include <syscalls.h>
#include <stdarg.h>
#include <shell.h>
#include <gameHandler.h>

#define N 9
#define ERROR_CODE -1

// int getint(const char message[], ... );

void printSudoku(int board[N][N]);

int readNumber(int *x, int *y);

int hasPrevSudGame();

void runSudoku(int entry);

void playSudoku();

#endif
