#ifndef SHELL_H
#define SHELL_H

void initShell();
int hasProgram(char *input);
int tokenizeArguments(char *toToken, char tokens[10][25]);
void printOSLogo(void);


#endif
