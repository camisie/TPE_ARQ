#include <videoDriver.h>
#include <stdint.h>
#include <library.h>
#include <registers.h>
#include <naiveConsole.h>
#include <font.h>
#include <colors.h>


int printStringFrom(char *string, int length, int row, int col, int color) {
    int printedCharacters = 0;

    if (row == -1 || col == -1) {
        for (int i = 0; i < length; i++) {
            if (drawChar(string[i], color)) {
                printedCharacters++;
            }
        }
    } else {
        for (int i = 0; i < length; i++) {
            if (drawCharFrom(string[i], row, col, color)) {
                col += CHAR_WIDTH;
                if (col >= 1024) {
                    row += CHAR_HEIGHT;
                    col = 0;
                }
                if (row >= 768) {
                    row = 0;
                }
                printedCharacters++;
            }
        }
    }
    return printedCharacters;
}

int printError(char *string) {
    printcln(string, RED);
    return 0;

}

void println(char *string) {
    print(string);
    print("\n");
}

void print(char *string) {
    printStringFrom(string, strlen(string), -1, -1, WHITE);
}

void printc(char *string, int color) {
    printStringFrom(string, strlen(string), -1, -1, color);
}

void printcln(char *string, int color) {
    printc(string, color);
    print("\n");
}

int strlen(char *string) {
    int length = 0;
    while (*string != 0) {
        length++;
        string++;
    }
    return length;
}
