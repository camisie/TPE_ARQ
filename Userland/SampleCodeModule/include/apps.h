#ifndef APPS_H
#define APPS_H

#include <stdint.h>

#define PROGRAMS 11

typedef struct {
    char name[12];

    void (*f)(int, char [][25]);

    char description[200];
} programs;

extern programs commands[PROGRAMS];

void infoReg(int args, char argv[][25]);

void printMem(int args, char argv[][25]);

void time(int args, char argv[][25]);

void showApps(int args, char argv[][25]);

void hangman(int args, char argv[][25]);

void sudoku(int args, char argv[][25]);

void clear(int args, char argv[][25]);

void throwDivZero();

void throwInvOpCode();

void about();

void runGames();

void getLocalTime(void);

void getPokeball();


#endif
