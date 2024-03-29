#include <sudoku.h>
#define PINK_COLOR 0xf03fcd
#define GREEN_COLOR 0x00FF00
#define ORANGE_COLOR 0xFFA500

#define N 9

int xPos, yPos;

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

void clearLine(int row, int col) {
    printstring(row, col, "                                 ");
}

void startSudoku() {
    printcFrom("Welcome to SUDOKU!", 450, 690, ORANGE_COLOR);
    printSudoku(board);
    findNextPos(&xPos, &yPos);
    printstring(675,650,"Enter number for pos {%d, %d}: ", xPos+1, yPos+1);
}


void playSudoku(char c) {
    int num = c - '0';
    clearLine(675, 650);
    clearLine(700, 650);
    if(num != completeBoard[xPos][yPos]) {
        printcFrom("Wrong number :( Try again!", 700, 650, PINK_COLOR);
    }
    else if (num == QUIT_CODE) {
        return;
    }
    else {
        printcFrom("Good job :) Keep going!", 700, 650, GREEN_COLOR);
        board[xPos][yPos] = num;
        printSudoku(board);
    }
    int next = findNextPos(&xPos, &yPos);
    printstring(675,650,"Enter number for pos {%d, %d}: ", xPos+1, yPos+1);
}

void printSudoku(int board[N][N]) {
    int row = 500, col = 675;
    for(int i = 0; i < N; i++) {;
        for(int j = 0; j < N; j++) {
            printstring(row, col, "%d", board[i][j]);
            col += 20;
        }
        col = 675;
        row += 15;
    }
}

int findNextPos(int *x, int *y) {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(board[i][j] == 0) {
                *x = i;
                *y = j;
                return 1;
            }
        }
    }
    return 0;
}
