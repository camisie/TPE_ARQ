#include <standardIO.h>
#include <stdarg.h>
#include <hangman.h>
#include <pokemon.h>
#include <syscalls.h>
#include <gameHandler.h>

//Macro para vaciar el buffer
#define DELETE_BUFFER while (getChar() != '\n')

//Cantidad de errores permitidos
#define CHANCES 6

//Longitud maxima que puede tener una palabra
#define WORDLEN 20

// #define ERROR_CODE -1

// int exitSaveH = 0, exitWithoutSaveH = 0;
//
// int hasPrevGame() {
//     return exitSaveH;
// }

void runHangman(int entry) {
    clearScreen();
    // if (entry == 0 || exitWithoutSaveH) newGame(); //initializes or clears board
    play(); //setea exitSaveH=0 y llama a play
}

void play(){

    char dictionary[][WORDLEN] = {"bulbasaur", "butterfree", "charmander", "marowak", "slowpoke", "eevee", "gastly", "geodude", "growlithe", "jigglypuff", "meowth", "pidgey", "pikachu", "poliwag", "ponyta", "psyduck", "rattata", "ditto", "squirtle", "horsea"};
    char letter, *word;
    int mistakes = 0;
    short found[WORDLEN] = {0};

    int n;

      do {
        print("Enter \"q\" if you want to quit the game. Once you start, there's no turning back!\n");
        n = getint("Enter a number from 1 to 20: ", -1, -1);
        putChar('\n');
        if (n == QUIT_CODE) {
          if(askYesNoQuit()) {
            return;
          }
        }
      } while(n < 0 || n >= 20);

    /* Elegir una palabra*/
    word = dictionary[n - 1];


    // printLogo();

    // print("\nGotta catch 'em all! Welcome to pokemon-hangman, the game where you have to guess the pokemon's name in order to win!\n");
    // print("You have maximum 6 mistakes allowed :o Remember that all alphabet are in lower case\n");
    // print("\nA wild pokemon has appeared! (◍ㅇᆽㅇ◍) Good luck :)\n");

    do {
        println("");
        printWord(word, found);
        letter = readLetter();
        if (!checkLetter(word, letter, found))
        {
            mistakes++;
            if (CHANCES - mistakes > 0)
                printstring(-1, -1, "Attack missed!\tRemaining attempts: %d", CHANCES - mistakes);
        }
        putChar('\n');
    } while (mistakes < CHANCES && !completeWord(word, found));

    if (mistakes == CHANCES)
        printstring(-1, -1,"\n\nOh no! The wild %s fled! Better try next time :(\n", word);
        //print("\n\nOh no! The wild %s fled! (╯°□°)╯︵◓ Better try next time :(\n");
    else{
        putChar('\n');
        printWord(word, found);
        printstring(-1,-1,"\n\nGotcha! %s was caught! Congrats!\n\n", word);
        //print("\n\nGotcha! %s was caught! (∩ᄑ_ᄑ)⊃*･｡*･ Congrats!\n\n");
        iChooseYou(n-1);
    }
    return;

}

char readLetter(void) {
    char letter;
    print("Please enter a letter: ");
    do {

        letter = getChar();

        if(letter == '\n')
            DELETE_BUFFER;

    } while(letter < 'a' || letter > 'z');

    return letter;
}

int checkLetter(const char word[], char letter, short found[]) {
    int i, ok = 0;

    for (i = 0; word[i]; i++)
        if (word[i] == letter)
        {
            ok = 1;
            found[i] = 1;
        }
    return ok;
}

void printWord(const char word[], const short found[]) {
    int i;

    for (i = 0; word[i]; i++)
    {
        if (found[i])
            putChar(word[i]);
        else
            putChar('_');
        putChar(' ');
    }
    putChar('\n');
}

int completeWord(const char word[], const short found[]) {
    int i, complete = 1;

    for (i = 0; word[i] && complete; i++)
        if (found[i] == 0)
            complete = 0;

    return complete;
}
