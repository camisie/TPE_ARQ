#include <miniHangman.h>

void printWordMini(const char word[], const short found[]);
char readLetterMini(void);
void printPokeballMini(void);

void miniPlay(){

    char dictionary[][WORDLEN] = {"bulbasaur", "butterfree", "charmander", "marowak", "slowpoke", "eevee", "gastly", "geodude", "growlithe", "jigglypuff", "meowth", "pidgey", "pikachu", "poliwag", "ponyta", "psyduck", "rattata", "ditto", "squirtle", "horsea"};
    char letter, *word;
    int mistakes = 0;
    short found[WORDLEN] = {0};

    int n;

     do {
        printstring(420, 20,"Welcome to MINI-HANGMAN");
        n = getint("Enter a number from 1 to 20: ", 440, 20);
        if (n == QUIT_CODE) {
          if(askYesNoQuit()) {
            return;
          }
        }
      } while(n < 0 || n >= 20);

    /* Elegir una palabra*/
    word = dictionary[n - 1];

    do {
        printWordMini(word, found);
        letter = readLetterMini();
        if (!checkLetter(word, letter, found))
        {
            mistakes++;
            if (CHANCES - mistakes > 0)
                printstring(480,20,"Attack missed! Remaining attempts: %d", CHANCES - mistakes);
        }
    } while (mistakes < CHANCES && !completeWord(word, found));

    if (mistakes == CHANCES) {
        printstring(540,20,"Oh no! The wild %s fled! Better try next time :(", word);
    }
    else {
        printWordMini(word, found);
        printstring(540,20,"Gotcha! %s was caught! Congrats!", word);
        printPokeballMini();
    }
    return;

}

char readLetterMini(void) {
    char letter;
    do {

        letter = getChar();

        if(letter == '\n')
            DELETE_BUFFER;

    } while(letter < 'a' || letter > 'z');

    return letter;
}


void printWordMini(const char word[], const short found[]) {
    int i;
    int row = 500, col = 20;
    for (i = 0; word[i]; i++)
    {
        if (found[i])
            putCharFrom(word[i], row, col);
        else
            putCharFrom('_', row, col);
        putCharFrom(' ', row, col + 20);
        col += 40;
    }
}

void printPokeballMini(void) {
    printFrom("       ____    ", 550, 100);
    printFrom("     /#####\\   ", 570, 100);
    printFrom("   /#########\\     ", 580, 100);
    printFrom("  |=====O=====|   ",600, 100);
    printFrom("   \\         /   ",620, 100);
    printFrom("     '_____'    ",640, 100);
}

// int completeWordMini(const char word[], const short found[]) {
//     int i, complete = 1;
//
//     for (i = 0; word[i] && complete; i++)
//         if (found[i] == 0)
//             complete = 0;
//
//     return complete;
// }
