#include <sudoku.h>

#define N 9

int exitSave = 0, exitWithoutSave = 0;

int hasPrevSudGame() {
    return exitSave;
}

void clearLine(int row, int col) {
    printstring(row, col, "                                 ");
}

void runSudoku(int entry) {
    clearScreen();
    // if (entry == 0 || exitWithoutSave) newGame(); //initializes or clears board
    playSudoku(); //setea exitSave=0 y llama a play
}


void playSudoku(){

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


    while(found < 81){
        printSudoku(board);
        num = readNumber(&x, &y);
        if(board[x][y] != 0) {
            printstring(675,675,"This position is already taken!");
        }
        else if(num != completeBoard[x][y]) {
            printstring(675,675,"Wrong number :( Try again!");
        }
        else if (num == QUIT_CODE) {
            return;
        }
        else {
            printstring(675,675,"Good job :) Keep going!");
            board[x][y] = num;
            found += 1;
        }
    }
    printSudoku(completeBoard);
    print("Well done! You are a genius!");
    return;

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

int readNumber(int *x, int *y) {
    int num;
    do {
      *x = getint("Enter row number: ", 650, 675);
      clearLine(675, 675);
      if (*x == QUIT_CODE) {
        if(askYesNoQuit()) {
          return QUIT_CODE;
        }
      }
      *x -= 1;
    } while(*x < 0 || *x >= 9);
    clearLine(650, 675);


    do {
        *y = getint("Enter column number: ", 650, 675);
        clearLine(675, 675);
        if (*y == QUIT_CODE) {
          if(askYesNoQuit()) {
            return QUIT_CODE;
          }
        }
        *y -= 1;
    } while(*y < 0 || *y >= 9);
    clearLine(650, 675);
    do {
        num = getint("Enter number (1-9): ", 650, 675);
        clearLine(675, 675);
        if (num == QUIT_CODE) {
          if(askYesNoQuit()) {
            return QUIT_CODE;
          }
        }
    } while(num <= 0 || num > 9);
    clearLine(650, 675);
    return num;
}
