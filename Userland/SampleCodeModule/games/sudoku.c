#include <standardIO.h>
#include <stdarg.h>
#include <sudoku.h>
#include <syscalls.h>

#define DELETE_BUFFER while (getchar() != '\n')

#define N 9

int exitSave = 0, exitWithoutSave = 0;

int hasPrevSudGame() {
    return exitSave;
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

    // printf("Welcome to Sudoku! Are you ready to play?\n");
    // printf("Here are the rules:\n");
    // printf("Rule 1 - Each row must contain the numbers from 1 to 9, without repetitions\n");
    // printf("Rule 2 - Each column must contain the numbers from 1 to 9, without repetitions\n");
    // printf("Rule 3 - The digits can only occur once per block (nonet)\n");
    // printf("Rule 4 - The sum of every single row, column and nonet must equal 45\n");
    // printf("\nHave fun!\n\n");

    while(found < 81){
        printSudoku(board);
        num = readNumber(&x, &y);
        if(board[x][y] != 0)
            print("\nThis position is already taken!\n\n");
        else if(num != completeBoard[x][y]){
            print("\nWrong number :( Try again!\n\n");
        }
        else {
            print("\nGood job :) Keep going!\n\n");
            board[x][y] = num;
            found += 1;
        }
    }

    printSudoku(completeBoard);
    print("\nWell done! You are a genius!\n");

    return;

}


// int getint(const char message[], ... ) {
//     int n, leave = 0;
//     va_list ap;
//
//     do {
//         va_start(ap, message);
//         vprint(message, ap);
//         va_end(ap);
//
//         if ( scanf("%d",&n) != 1)
//         {
//             print("\nIncorrect data\n");
//             DELETE_BUFFER;
//         }
//         else
//             leave = 1;
//     } while (! leave);
//     DELETE_BUFFER;
//     return n;
// }

void printSudoku(int board[N][N]) {
    print("    1  2  3     4  5  6     7  8  9 \n");
    print("    -  -  -  -  -  -  -  -  -  -  - \n");
    for(int i=0; i < N; i++){
        if(i !=0 && i%3 == 0){
            print("    -  -  -  -  -  -  -  -  -  -  - \n");
        }
        char rta = i + 1;
        // print("rta");
        // print("%d |", i+1);
        putChar(rta);
        print("|");
        //print(" | ");

        for(int j=0; j < N; j++){
            if(j !=0 && j%3 == 0){
                print(" | ");

            }
            //putChar(board[i][j]);
            // putChar(board[i][j]);
            char rtaB = board[i][j];
            putChar(rtaB);
            // print(" %d ",board[i][j]);
        }
        print("\n");
    }
    print("\n");
}

int readNumber(int *x, int *y) {
    int num;
    do {
        *x = (getChar("Please enter your row number: ")-1);
    }while(*x < 0 || *x > 9);

    do {
        *y = (getChar("Please enter your column number: ")-1);
    }while(*y < 0 || *y > 9);

    do {
        num = getChar("Please enter a number between 1 and 9: ");
    } while(num < 0 || num > 9);

    return num;
}
