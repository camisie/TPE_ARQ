#ifndef MINI_HANGMAN_HANDLER_H
#define MINI_HANGMAN_HANDLER_H

#include <hangman.h>
#include <standardIO.h>
#include <string.h>
#include <hangmanHandler.h>
#include <syscalls.h>
#include <maths.h>
#include <pokemon.h>

#define SCREEN_HEIGTH 16

void miniHangmanHandler(int args, char argv[][25]); //en hangmanHandler.c

void miniGreeting();

#endif
