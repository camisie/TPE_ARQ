#include <stdio.h>
#include <syscalls.h>
#include <standardIO.h>
#include <stdarg.h>
#include <string.h>

#define CHAR_COLOR 0xFFFFFF

void println(char *toPrint) {
    printcFrom(toPrint, -1, -1, CHAR_COLOR);
    print("\n");
}

void print(char *toPrint) {
    printcFrom(toPrint, -1, -1, CHAR_COLOR);
}

void printc(char *toPrint, int color) {
    printcFrom(toPrint, -1, -1, color);
}

void printcln(char *toPrint, int color) {
    printc(toPrint, color);
    print("\n");
}

void printcFrom(char *toPrint, int row, int col, int color) {
    write(toPrint, row, col, color);
}

void printFrom(char *toPrint, int row, int col) {
    printcFrom(toPrint, row, col, CHAR_COLOR);
}

char getChar() {
    char c;
    read(&c, 1);
    return c;
}

void removeChar() {
    print("\b");
}

void putChar(char c) {
    char buffer[2] = {0};
    *buffer = c;
    print(buffer);
}

void putCharFrom(char c, int row, int col) {
    char buffer[2] = {0};
    *buffer = c;
    printFrom(buffer, row, col);
}

void scan(char * buff) {
  int ch = 0;
  int index = 0;
  while (ch != '\n') {
    if (ch)
      buff[index++] = ch;
      putChar(ch);
      ch = getChar();
  }
  putChar('\n');
}

void printstring(char * fmt, ...) {
  va_list vl;
  va_start(vl, fmt);
  char * auxPtr;
  char buffer[128] = {0};
  char tmp[20];
  int i = 0, j = 0;
  while (fmt && fmt[i]) {
    if (fmt[i] == '%') {
      i++;
      switch(fmt[i]) {
        case 'c':
        buffer[j++] = (char)va_arg( vl, int );
        break;
        case 'd':
        itoa(va_arg( vl, int ), tmp, 10);
        strcpy(&buffer[j], tmp);
        j+=strlen(tmp);
        break;
        case 's':
        auxPtr = va_arg(vl, char*);
        strcpy(&buffer[j],auxPtr);
        j+=strlen(auxPtr);
        break;
        case 'x':
        itoa(va_arg( vl, int ), tmp, 16);
        strcpy(&buffer[j], tmp);
        j+=strlen(tmp);
        break;
        case 'X': //long hexa
        itoa(va_arg( vl, uint64_t ), tmp, 16);
        strcpy(&buffer[j], tmp);
        j+=strlen(tmp);
        break;
      }
    } else {
      buffer[j++] = fmt[i];
    }
    i++;
  }
  print(buffer);
}
