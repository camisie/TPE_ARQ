#include <hangman.h>
#include <standardIO.h>
#include <string.h>
#include <hangmanHandler.h>
#include <syscalls.h>
#include <maths.h>
#include <pokemon.h>

#define SCREEN_HEIGTH 16
#define RED_GREETING 0xFF6347
#define MIDDLE_TITLE_P 200
#define MIDDLE_TITLE_H 300
#define WORDLEN 20


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

void greeting() {
    int heigth = 0;
    clearScreen();
    //printLogo();
    //heigth += SCREEN_HEIGTH;
    heigth += SCREEN_HEIGTH * 8;

    printcFrom("                                     ,'\\ ", heigth += SCREEN_HEIGTH, MIDDLE_TITLE_P, RED_GREETING);
    printcFrom("       _.----.        ____         ,'  _\\   ___    ___     ____", heigth += SCREEN_HEIGTH, MIDDLE_TITLE_P, RED_GREETING);
    printcFrom("   _,-'       `.     |    |  /`.   \\,-'    |   \\  /   |   |    \\  |`.", heigth += SCREEN_HEIGTH, MIDDLE_TITLE_P, RED_GREETING);
    printcFrom("   \\      __    \\    '-.  | /   `.  ___    |    \\/    |   '-.   \\ |  |", heigth += SCREEN_HEIGTH, MIDDLE_TITLE_P, RED_GREETING);
    printcFrom("    \\.    \\ \\   |  __  |  |/    ,','_  `.  |          | __  |    \\|  |", heigth += SCREEN_HEIGTH, MIDDLE_TITLE_P, RED_GREETING);
    printcFrom("      \\    \\/   /,' _`.|      ,' / / / /   |          ,' _`.|     |  |", heigth += SCREEN_HEIGTH, MIDDLE_TITLE_P, RED_GREETING);
    printcFrom("       \\     ,-'/  /   \\    ,'   | \\/ / ,`.|         /  /   \\  |     |", heigth += SCREEN_HEIGTH, MIDDLE_TITLE_P, RED_GREETING);
    printcFrom("        \\    \\ |   \\_/  |   `-.  \\    `'  /|  |    ||   \\_/  | |\\    |", heigth += SCREEN_HEIGTH, MIDDLE_TITLE_P, RED_GREETING);
    printcFrom("         \\    \\ \\      /       `-.`.___,-' |  |\\  /| \\      /  | |   |", heigth += SCREEN_HEIGTH, MIDDLE_TITLE_P, RED_GREETING);
    printcFrom("          \\    \\ `.__,'|  |`-._    `|      |__| \\/ |  `.__,'|  | |   |", heigth += SCREEN_HEIGTH, MIDDLE_TITLE_P, RED_GREETING);
    printcFrom("           \\_.-'       |__|    `-._ |              '-.|     '-.| |   |", heigth += SCREEN_HEIGTH, MIDDLE_TITLE_P, RED_GREETING);
    printcFrom("                                   `'                            '-._|", heigth += SCREEN_HEIGTH, MIDDLE_TITLE_P, RED_GREETING);

    heigth += SCREEN_HEIGTH;

    printcFrom("--------------------------------------------", heigth += SCREEN_HEIGTH, MIDDLE_TITLE_H, RED_GREETING);
    printcFrom("| #  #   #   #   #  #### #   #   #   #   # |", heigth += SCREEN_HEIGTH, MIDDLE_TITLE_H, RED_GREETING);
    printcFrom("| #  #  # #  ##  # #     ## ##  # #  ##  # |", heigth += SCREEN_HEIGTH, MIDDLE_TITLE_H, RED_GREETING);
    printcFrom("| #### ##### # # # #  ## # # # ##### # # # |", heigth += SCREEN_HEIGTH, MIDDLE_TITLE_H, RED_GREETING);
    printcFrom("| #  # #   # #  ## #   # #   # #   # #  ## |", heigth += SCREEN_HEIGTH, MIDDLE_TITLE_H, RED_GREETING);
    printcFrom("| #  # #   # #   #  ###  #   # #   # #   # |", heigth += SCREEN_HEIGTH, MIDDLE_TITLE_H, RED_GREETING);
    printcFrom("--------------------------------------------", heigth += SCREEN_HEIGTH, MIDDLE_TITLE_H, RED_GREETING);
   

    heigth += SCREEN_HEIGTH;
    int color = 0xFFEA00;
    printcFrom("\nInstructions:", heigth += SCREEN_HEIGTH, 0, color);
    printcFrom("\nPress ENTER to begin your adventure", heigth += SCREEN_HEIGTH, 0, color);
    printcFrom("\nPress \"q\" to quit without saving or \"p\" to pause your game", heigth += SCREEN_HEIGTH, 0, color);
    printcFrom("\nGotta catch 'em all! Welcome to pokemon-hangman, the game where you have to guess the pokemon's name in order to win!", heigth += SCREEN_HEIGTH, 0, color);
    printcFrom("\nYou have maximum 6 mistakes allowed :o Remember that all alphabet are in lower case", heigth += SCREEN_HEIGTH, 0, color);
    printcFrom("\nA wild pokemon has appeared! Good luck :)\n", heigth += SCREEN_HEIGTH, 0, color);
    printcFrom("\nEnjoy!", heigth += SCREEN_HEIGTH, 0, color);
    while ((getChar()) != '\n');
}
