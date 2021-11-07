#include <sudoku.h>
#include <standardIO.h>
#include <string.h>
#include <sudokuHandler.h>
#include <syscalls.h>
#include <maths.h>

#define SCREEN_HEIGTH 70
#define YELLOW_GREETING 0xFFE81F
#define MIDDLE_TITLE 296
#define WORDLEN 20

void printSudokuMenu();

char askYesNoSud();

void greetingSud();

void sudokuHandler(int args, char argv[][25]) {
    if (args == 0 || strcmp(argv[1], "new") == 0 || strcmp(argv[1], "-n") == 0 || strcmp(argv[1], "start") == 0 ||
        strcmp(argv[1], "-s") == 0) {
        if (hasPrevSudGame()) println("There's a game already loaded. Are you sure you want to start a new one? [Y/n]");
        else println("You're about to start a new sudoku game. Are you sure? [Y/n]");
        askYesNoSud();
    } else if (strcmp(argv[1], "resume") == 0 || strcmp(argv[1], "-r") == 0 || strcmp(argv[1], "continue") == 0 ||
               strcmp(argv[1], "-c") == 0) {
        if (hasPrevSudGame()) {
            println("Please wait! The game will resume just from where you left it!");
            runSudoku(1);
        } else {
            println("There doesn't seem to be a previous game saved in memory. Start a new game? [Y/n]");
            askYesNoSud();
        }
    } else if (strcmp(argv[1], "help") == 0 || strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "menu") == 0 ||
               strcmp(argv[1], "-m") == 0) {
        printSudokuMenu();
    } else {
        print(argv[1]);
        println(": command not found");
    }
    return;
}


void printSudokuMenu() {
    int color = 0xf03fcd;
    printc("sudoku new, -n", color);
    printc(": ", color);
    printcln("   Starts a new game.", 0xcfd7e6);
    printc("resume, -r", color);
    printc(": ", color);
    printcln("Resumes last loaded game.", 0xcfd7e6);
    printc("sudoku help, -h", color);
    printc(": ", color);
    printcln("  Displays a menu with the different valid options.", 0xcfd7e6);
    printc("sudoku info, -i", color);
    printc(": ", color);
    printcln("  Displays information about the elapsed game.", 0xcfd7e6);
}

char askYesNoSud() {
    char ans;
    while ((ans = getChar()) != 'n' && ans != 'y' && ans != 'Y') {
        if (ans != 0) {
            println("Invalid option. Please enter 'Y' if you want to start a new sudoku game. If not, enter 'n'.");
        }
    }
    if (ans == 'n') {
        println("Need help? Enter sudoku help or sudoku -h to display a menu of the different options from which you can choose");
    } else if (ans == 'Y' || ans == 'y') {
        greetingSud(); //starting a new sudoku game
        runSudoku(0);
    }
    return ans;
}


void greetingSud() {
	int heigth = 0;
    clearScreen();

    heigth += SCREEN_HEIGTH;
    printFrom("Instructions:", heigth += SCREEN_HEIGTH, 0);
    printFrom("Press ENTER to begin your adventure", heigth += SCREEN_HEIGTH, 0);
    printFrom("Press \"q\" to quit", heigth += SCREEN_HEIGTH, 0);
    printFrom("Welcome to Sudoku! Are you ready to play?\n", heigth += SCREEN_HEIGTH, 0);
    printFrom("Here are the rules:\n", heigth += SCREEN_HEIGTH, 0);
    printFrom("Rule 1 - Each row must contain the numbers from 1 to 9, without repetitions\n", heigth += SCREEN_HEIGTH, 0);
    printFrom("Rule 2 - Each column must contain the numbers from 1 to 9, without repetitions\n", heigth += SCREEN_HEIGTH, 0);
    printFrom("Rule 3 - The digits can only occur once per block (nonet)\n", heigth += SCREEN_HEIGTH, 0);
    printFrom("Rule 4 - The sum of every single row, column and nonet must equal 45\n", heigth += SCREEN_HEIGTH, 0);
    printFrom("\nHave fun!\n\n", heigth += SCREEN_HEIGTH, 0);

    while ((getChar()) != '\n');
}
