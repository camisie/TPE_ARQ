#include <hangman.h>
#include <standardIO.h>
#include <string.h>
#include <hangmanHandler.h>
#include <syscalls.h>
#include <maths.h>
#include <pokemon.h>

#define SCREEN_HEIGTH 16
#define YELLOW_GREETING 0xFFE81F
#define MIDDLE_TITLE 296
#define WORDLEN 20

// void printHangmanInfo();

void printHangmanMenu();

char askYesNo();

void greeting();

void hangmanHandler(int args, char argv[][25]) {
    if (args == 0 || strcmp(argv[1], "new") == 0 || strcmp(argv[1], "-n") == 0 || strcmp(argv[1], "start") == 0 ||
        strcmp(argv[1], "-s") == 0) {
        if (hasPrevGame()) println("There's a game already loaded. Are you sure you want to start a new one? [Y/n]");
        else println("You're about to start a new hangman game. Are you sure? [Y/n]");
        askYesNo();
    } else if (strcmp(argv[1], "resume") == 0 || strcmp(argv[1], "-r") == 0 || strcmp(argv[1], "continue") == 0 ||
               strcmp(argv[1], "-c") == 0) {
        if (hasPrevGame()) {
            println("Please wait! The game will resume just from where you left it!");
            runHangman(1);
        } else {
            println("There doesn't seem to be a previous game saved in memory. Start a new game? [Y/n]");
            askYesNo();
        }
    } else if (strcmp(argv[1], "help") == 0 || strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "menu") == 0 ||
               strcmp(argv[1], "-m") == 0) {
        printHangmanMenu();
    } else {
        print(argv[1]);
        println(": command not found");
    }
    return;
}

// void printHangmanInfo() {
//     if (hasPrevGame()) {
//         int white = getWhiteTime();
//         int black = getBlackTime();
//         char timeW[6] = {0};
//         char timeB[6] = {0};
//         print("It's Player ");
//         print(isWhitesTurn() ? "1" : "2");
//         print(" turn to move. ");
//         print("Player 1 has ");
//         itoa(white / 60, timeW, 2);
//         timeW[2] = ':';
//         itoa(white % 60, timeW + 3, 2);
//         print(timeW);
//         print(" seconds elapsed und Player 2 has ");;
//         itoa(black / 60, timeB, 2);
//         timeB[2] = ':';
//         itoa(black % 60, timeB + 3, 2);
//         print(timeB);
//         println(" seconds in total.");
//         print("The difference between them is of 00:");
//         char dif[3] = {0};
//         itoa(abs(white - black), dif, 2);
//         print(dif);
//         println(" seconds. Remember that the game will finish if the difference reaches a minute.");
//         println("To resume the game please insert chess resume or chess -r.");
//     } else {
//         println("There's no game saved in memory...");
//         println("Want to start a new game? Enter chess start or chess -s to begin!");
//     }

// }

void printHangmanMenu() {
    int color = 0xf03fcd;
    printc("hangman new, -n", color);
    printc(": ", color);
    printcln("   Starts a new game.", 0xcfd7e6);
    printc("resume, -r", color);
    printc(": ", color);
    printcln("Resumes last loaded game.", 0xcfd7e6);
    printc("hangman help, -h", color);
    printc(": ", color);
    printcln("  Displays a menu with the different valid options.", 0xcfd7e6);
    printc("hangman info, -i", color);
    printc(": ", color);
    printcln("  Displays information about the elapsed game.", 0xcfd7e6);
}

char askYesNo() {
    char ans;
    while ((ans = getChar()) != 'n' && ans != 'y' && ans != 'Y') {
        if (ans != 0) {
            println("Invalid option. Please enter 'Y' if you want to start a new hangman game. If not, enter 'n'.");
        }
    }
    if (ans == 'n') {
        println("Need help? Enter hangman help or hangman -h to display a menu of the different options from which you can choose");
    } else if (ans == 'Y' || ans == 'y') {
        greeting(); //starting a new hangman game
        runHangman(0);
    }
    return ans;
}

// void showLogo(){
// 	int heigth = 0
// 	printcFrom("\t\t--------------------------------------------\n", heigth += SCREEN_HEIGTH, MIDDLE_TITLE, YELLOW_GREETING);
// 	printcFrom("\t\t| #  #   #   #   #  #### #   #   #   #   # |\n", heigth += SCREEN_HEIGTH, MIDDLE_TITLE, YELLOW_GREETING);
// 	printcFrom("\t\t| #  #  # #  ##  # #     ## ##  # #  ##  # |\n", heigth += SCREEN_HEIGTH, MIDDLE_TITLE, YELLOW_GREETING);
// 	printcFrom("\t\t| #### ##### # # # #  ## # # # ##### # # # |\n", heigth += SCREEN_HEIGTH, MIDDLE_TITLE, YELLOW_GREETING);
// 	printcFrom("\t\t| #  # #   # #  ## #   # #   # #   # #  ## |\n", heigth += SCREEN_HEIGTH, MIDDLE_TITLE, YELLOW_GREETING);
// 	printcFrom("\t\t| #  # #   # #   #  ###  #   # #   # #   # |\n", heigth += SCREEN_HEIGTH, MIDDLE_TITLE, YELLOW_GREETING);
// 	printcFrom("\t\t--------------------------------------------\n", heigth += SCREEN_HEIGTH, MIDDLE_TITLE, YELLOW_GREETING);
// }

void greeting() {
	int heigth = 0;
    clearScreen();
    //printLogo();

    printcFrom("--------------------------------------------", heigth += SCREEN_HEIGTH, MIDDLE_TITLE, YELLOW_GREETING);
	printcFrom("| #  #   #   #   #  #### #   #   #   #   # |", heigth += SCREEN_HEIGTH, MIDDLE_TITLE, YELLOW_GREETING);
	printcFrom("| #  #  # #  ##  # #     ## ##  # #  ##  # |", heigth += SCREEN_HEIGTH, MIDDLE_TITLE, YELLOW_GREETING);
	printcFrom("| #### ##### # # # #  ## # # # ##### # # # |", heigth += SCREEN_HEIGTH, MIDDLE_TITLE, YELLOW_GREETING);
	printcFrom("| #  # #   # #  ## #   # #   # #   # #  ## |", heigth += SCREEN_HEIGTH, MIDDLE_TITLE, YELLOW_GREETING);
	printcFrom("| #  # #   # #   #  ###  #   # #   # #   # |", heigth += SCREEN_HEIGTH, MIDDLE_TITLE, YELLOW_GREETING);
	printcFrom("--------------------------------------------", heigth += SCREEN_HEIGTH, MIDDLE_TITLE, YELLOW_GREETING);
    heigth += SCREEN_HEIGTH * 2;

    heigth += SCREEN_HEIGTH;
    printFrom("Instructions:", heigth += SCREEN_HEIGTH, 0);
    printFrom("Press ENTER to begin your adventure", heigth += SCREEN_HEIGTH, 0);
    printFrom("Press \"q\" to quit without saving or \"p\" to pause your game", heigth += SCREEN_HEIGTH, 0);
    printFrom("\nGotta catch 'em all! Welcome to pokemon-hangman, the game where you have to guess the pokemon's name in order to win!\n", heigth += SCREEN_HEIGTH, 0);
    printFrom("You have maximum 6 mistakes allowed :o Remember that all alphabet are in lower case\n", heigth += SCREEN_HEIGTH, 0);
    printFrom("\nA wild pokemon has appeared! Good luck :)\n", heigth += SCREEN_HEIGTH, 0);
    // printFrom("Insert your game plays in the following notation:", heigth += SCREEN_HEIGTH, 0);
    // printFrom("First, put the coordinates of the piece you want to move, then to where you want to move it",
    //           heigth += SCREEN_HEIGTH, 0);
    // printFrom("For example, \"a1a3\" moves the piece from the position a1 to a3", heigth += SCREEN_HEIGTH, 0);
    // printFrom("Insert 00 to generate a  short clastling", heigth += SCREEN_HEIGTH, 0);
    // printFrom("Insert 000 to generate a  long clastling", heigth += SCREEN_HEIGTH, 0);
    // printFrom(
    //         "When executing a promotion, when the other side has been reached, a menu with options from which to choose will appear.",
    //         heigth += SCREEN_HEIGTH, 0);

    // heigth += SCREEN_HEIGTH;
    // printFrom("Dont worry if you mistype or enter an invalid move! We will take care of that!", heigth += SCREEN_HEIGTH,
    //           0);
    printFrom("Enjoy!", heigth += SCREEN_HEIGTH, 0);
    while ((getChar()) != '\n');
}
