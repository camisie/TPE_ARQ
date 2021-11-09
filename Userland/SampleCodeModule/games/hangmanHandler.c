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

void hangmanHandler() {
    println("You're about to start a new hangman game. Are you sure? [Y/n]");
    askYesNo();
    return;
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
	int heigth = 250;
    clearScreen();
    printLogo();
  //
  //   printcFrom("--------------------------------------------", heigth += SCREEN_HEIGTH, MIDDLE_TITLE, YELLOW_GREETING);
	// printcFrom("| #  #   #   #   #  #### #   #   #   #   # |", heigth += SCREEN_HEIGTH, MIDDLE_TITLE, YELLOW_GREETING);
	// printcFrom("| #  #  # #  ##  # #     ## ##  # #  ##  # |", heigth += SCREEN_HEIGTH, MIDDLE_TITLE, YELLOW_GREETING);
	// printcFrom("| #### ##### # # # #  ## # # # ##### # # # |", heigth += SCREEN_HEIGTH, MIDDLE_TITLE, YELLOW_GREETING);
	// printcFrom("| #  # #   # #  ## #   # #   # #   # #  ## |", heigth += SCREEN_HEIGTH, MIDDLE_TITLE, YELLOW_GREETING);
	// printcFrom("| #  # #   # #   #  ###  #   # #   # #   # |", heigth += SCREEN_HEIGTH, MIDDLE_TITLE, YELLOW_GREETING);
	// printcFrom("--------------------------------------------", heigth += SCREEN_HEIGTH, MIDDLE_TITLE, YELLOW_GREETING);
    heigth += SCREEN_HEIGTH * 2;

    heigth += SCREEN_HEIGTH;
    printFrom("Instructions:\n", heigth += SCREEN_HEIGTH, 0);
    printFrom("Press ENTER to begin your adventure", heigth += SCREEN_HEIGTH, 0);
    // printFrom("Press \"q\" to quit without saving or \"p\" to pause your game", heigth += SCREEN_HEIGTH, 0);
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
