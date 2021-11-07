#ifndef SHELL_H
#define SHELL_H

#include <string.h>
#include <standardIO.h>
#include <syscalls.h>
#include <stdint.h>
#include <apps.h>

void startShell();
void runShell();
int hasProgram(char *input);
int tokenizeArguments(char *toToken, char tokens[10][25]);
void printOSLogo(void);
void returnToShell();


#endif
