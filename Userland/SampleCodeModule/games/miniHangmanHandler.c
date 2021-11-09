#include <miniHangmanHandler.h>

void miniHangmanHandler(int args, char argv[][25]) {
  println("You're about to start a new hangman game. Are you sure? [Y/n]");
  askYesNo();
}

void miniGreeting() {
	int heigth = 250;
    clearScreen();
    printMiniLogo();

    heigth += SCREEN_HEIGTH * 2;

    heigth += SCREEN_HEIGTH;
    printFrom("Instructions:\n", heigth += SCREEN_HEIGTH, 0);
    printFrom("Press ENTER to begin your adventure", heigth += SCREEN_HEIGTH, 0);
    // printFrom("Press \"q\" to quit without saving or \"p\" to pause your game", heigth += SCREEN_HEIGTH, 0);
    printFrom("\nGotta catch 'em all!\n", heigth += SCREEN_HEIGTH, 0);
    printFrom("Welcome to pokemon-hangman, the game where you have to guess the pokemon's name in order to win!\n", heigth += SCREEN_HEIGTH, 0);
    printFrom("You have maximum 6 mistakes allowed :o Remember that all alphabet are in lower case\n", heigth += SCREEN_HEIGTH, 0);
    printFrom("\nA wild pokemon has appeared! Good luck :)\n", heigth += SCREEN_HEIGTH, 0);
    printFrom("Enjoy!", heigth += SCREEN_HEIGTH, 0);
    while ((getChar()) != '\n');
}
