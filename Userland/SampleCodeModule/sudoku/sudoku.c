#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "sudoku.h"

#define DELETE_BUFFER while (getchar() != '\n')

#define N 9

int main(void) {

    int board[N][N] = {
        {7, 0, 0, 4, 9, 0, 0, 3, 0},
        {0, 9, 0, 0, 5, 0, 0, 6, 7},
        {0, 8, 0, 0, 3, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 2, 1, 4},
        {0, 0, 0, 9, 0, 3, 0, 0, 0},
        {6, 7, 5, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 3, 2, 0, 0, 8, 0},
        {2, 6, 0, 0, 1, 0, 0, 4, 0},
        {0, 1, 0, 0, 6, 4, 0, 0, 5}
       };
    
    int completeBoard[N][N] = {
        {7, 5, 2, 4, 9, 6, 1, 3, 8},
        {3, 9, 1, 2, 5, 8, 4, 6, 7},
        {4, 8, 6, 7, 3, 1, 9, 5, 2},
        {8, 3, 9, 6, 7, 5, 2, 1, 4},
        {1, 2, 4, 9, 8, 3, 5, 7, 6},
        {6, 7, 5, 1, 4, 2, 8, 9, 3},
        {5, 4, 7, 3, 2, 9, 6, 8, 1},
        {2, 6, 8, 5, 1, 7, 3, 4, 9},
        {9, 1, 3, 8, 6, 4, 7, 2, 5}
       };

    int num, x, y;
    int found = 30;
    
    printf("Welcome to Sudoku! Are you ready to play?\n");
    printf("Here are the rules:\n");
    printf("Rule 1 - Each row must contain the numbers from 1 to 9, without repetitions\n");
    printf("Rule 2 - Each column must contain the numbers from 1 to 9, without repetitions\n");
    printf("Rule 3 - The digits can only occur once per block (nonet)\n");
    printf("Rule 4 - The sum of every single row, column and nonet must equal 45\n");
    printf("\nHave fun!\n\n");
    
    while(found < 81){
        printSudoku(board);
        num = readNumber(&x, &y);
        if(board[x][y] != 0)
            printf("\nThis position is already taken!\n\n");
        else if(num != completeBoard[x][y]){
            printf("\nWrong number :( Try again!\n\n");
        }
        else {
            printf("\nGood job :) Keep going!\n\n");
            board[x][y] = num;
            found += 1;
        }
    }

    printSudoku(completeBoard);
    printf("\nWell done! You are a genius!\n");
    
    return 0;
    
}


int getint(const char message[], ... ) {
    int n, leave = 0;
    va_list ap;
        
    do {
        va_start(ap, message);
        vprintf(message, ap);
        va_end(ap);

        if ( scanf("%d",&n) != 1)
        {
            printf("\nIncorrect data\n");
            DELETE_BUFFER;
        }
        else
            leave = 1;
    } while (! leave);
    DELETE_BUFFER;
    return n;
}

void printSudoku(const int board[N][N]) {
    printf("    1  2  3     4  5  6     7  8  9 \n");
    printf("    -  -  -  -  -  -  -  -  -  -  - \n");
    for(int i=0; i < N; i++){
        if(i !=0 && i%3 == 0){
            printf("    -  -  -  -  -  -  -  -  -  -  - \n");
        }
        printf("%d |", i+1);
        for(int j=0; j < N; j++){
            if(j !=0 && j%3 == 0){
                printf(" | ");
            }
            printf(" %d ",board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int readNumber(int *x, int *y) {
    int num;
    do {
        *x = (getint("Please enter your row number: ")-1);
    }while(*x < 0 || *x > 9);
    
    do {
        *y = (getint("Please enter your column number: ")-1);
    }while(*y < 0 || *y > 9);
    
    do {
        num = getint("Please enter a number between 1 and 9: ");
    } while(num < 0 || num > 9);
    
    return num;
}

