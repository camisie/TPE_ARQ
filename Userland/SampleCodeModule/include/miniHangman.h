#ifndef MINI_HANGMAN_h
#define MINI_HANGMAN_h

#include <standardIO.h>
#include <standardIO.h>
#include <stdarg.h>
#include <hangman.h>
#include <pokemon.h>
#include <syscalls.h>
#include <gameHandler.h>

//Macro para vaciar el buffer
#define DELETE_BUFFER while (getChar() != '\n')

//Cantidad de errores permitidos
#define CHANCES 6

//Longitud maxima que puede tener una palabra
#define WORDLEN 20

void playMiniHangman(char letter);
void startMiniHangman();

#endif
