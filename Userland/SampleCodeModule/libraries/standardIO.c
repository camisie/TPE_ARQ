#include <stdio.h>
#include <syscalls.h>
#include <standardIO.h>
#include <stdarg.h>
#include <string.h>

#define CHAR_COLOR 0xFFFFFF
#define DELETE_BUFFER while (getchar() != '\n')
#define MAX_NUM_LEN 10

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

int getint(const char * message) {
  printstring("%s", message);
  char auxx;
  char num[MAX_NUM_LEN] = {0};
  int numLen = 0;
  while ((auxx = getChar()) != '\n' && numLen < MAX_NUM_LEN) {
      if (auxx != 0) {
          switch (auxx) {
              case '\b':
                  if (numLen > 0) {
                      num[--numLen] = 0;
                      removeChar();
                  }
                  break;
              default:
                  num[numLen++] = auxx;
                  putChar(auxx);
          }
      }
  }
  if (strcmp(auxx, 'q') == 0) {
    return -1;
  }
  return atoi(num);
}

// int scan(char * str, ...)
// {
//     va_list vl;
//     int i = 0, j=0, ret = 0;
//     char buff[100] = {0}, tmp[20], c;
//     char *out_loc;
//     while(c != '')
//     {
//         if (fread(&c, 1, 1, stdin))
//         {
//  	       buff[i] = c;
//  	       i++;
//  	    }
//  	}
//  	va_start( vl, str );
//  	i = 0;
//  	while (str && str[i])
//  	{
//  	    if (str[i] == '%')
//  	    {
//  	       i++;
//  	       switch (str[i])
//  	       {
//  	           case 'c':
//  	           {
// 	 	           *(char *)va_arg( vl, char* ) = buff[j];
// 	 	           j++;
// 	 	           ret ++;
// 	 	           break;
//  	           }
//  	           case 'd':
//  	           {
// 	 	           *(int *)va_arg( vl, int* ) =strtol(&buff[j], &out_loc, 10);
// 	 	           j+=out_loc -&buff[j];
// 	 	           ret++;
// 	 	           break;
//  	            }
//  	            case 'x':
//  	            {
// 	 	           *(int *)va_arg( vl, int* ) =strtol(&buff[j], &out_loc, 16);
// 	 	           j+=out_loc -&buff[j];
// 	 	           ret++;
// 	 	           break;
//  	            }
//  	        }
//  	    }
//  	    else
//  	    {
//  	        buff[j] =str[i];
//             j++;
//         }
//         i++;
//     }
//     va_end(vl);
//     return ret;
// }

// void scan(char * buffer) {
//     int aux = 0;
//     int index = 0;
//     while (aux != '\n') {
//         if(aux) {
//             buffer[index++] = aux;
//             putChar(aux);
//             aux = getChar();
//         }
//     }
//     putChar('\n');
// }

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
