#ifndef hangman_h
#define hangman_h

#include <standardIO.h>


int hasPrevGame();

void runHangman(int entry);

void play();

//Lee un int de la entrada standar
int getint(const char message[], ... );

char readLetter(void);

void printWord(const char word[], const short found[]);

int completeWord(const char word[], const short found[]);

int checkLetter(const char word[], char letter, short found[]);

#endif /* hangman_h */
