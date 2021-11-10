#ifndef hangman_h
#define hangman_h

#include <standardIO.h>

void runHangman(int entry);

void play();

char readLetter(void);

void printWord(const char word[], const short found[]);

int completeWord(const char word[], const short found[]);

int checkLetter(const char word[], char letter, short found[]);

#endif /* hangman_h */
