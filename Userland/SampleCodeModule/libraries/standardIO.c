#include <stdio.h>
#include <syscalls.h>
#include <standardIO.h>
#include <stdarg.h>
#include <string.h>

#define CHAR_COLOR 0xFFFFFF
#define DELETE_BUFFER while (getchar() != '\n')
#define MAX_NUM_LEN 13
#define ISNUM(c) ((c) >= '0' && (c) <= '9')

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

int getint(const char * message, int row, int col) {
  printstring(row, col,"%s", message);
  char auxx;
  char num[MAX_NUM_LEN] = {0};
  int numLen = 0;
  int isQ = 0;
  while ((auxx = getChar()) != '\n' && numLen < MAX_NUM_LEN) {
      if (auxx != 0) {
        if (auxx == '\b') {
          if (numLen > 0) {
            num[--numLen] = 0;
            removeChar();
          }
          if (isQ) {
            isQ = 0;
            removeChar();
          }
        } else if ((auxx == 'q' || auxx == 'Q') && !isQ && numLen == 0) {
          isQ = 1;
          putCharFrom(auxx, row, col+strlen(message)*8);
        } else if (auxx >= '0' && auxx <= '9' && !isQ) {
          num[numLen++] = auxx;
          putCharFrom(auxx, row, col+strlen(message)*8);
        }
      }
  }
  if (isQ) {
    return QUIT_CODE;
  }
  return atoi(num);
}

void printstring(int row, int col, char * fmt, ...) {
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
  printFrom(buffer, row, col);
}
