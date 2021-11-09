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

      printstring(420, 20,"Welcome to MINI-HANGMAN! Gotta catch 'em all!");
      printstring(440, 20,"Guess the pokemon's name in order to win!");
      printstring(460, 20, "You have maximum 6 mistakes allowed :o");

      dateInfo info;
      getTime(&info);
      n = info.seconds % 20;
      // if (n == QUIT_CODE) {
      //   if(askYesNoQuit()) {
      //     return;
      //   }
      // }

    /* Elegir una palabra*/
    word = dictionary[n];

    do {
        printWordMini(word, found);
        letter = readLetterMini();
        if (!checkLetter(word, letter, found))
        {
            mistakes++;
            if (CHANCES - mistakes > 0)
                printstring(490,20,"Attack missed! Remaining attempts: %d", CHANCES - mistakes);
        }
    } while (mistakes < CHANCES && !completeWord(word, found));

    if (mistakes == CHANCES) {
        printstring(560,20,"Oh no! The wild %s fled! Better try next time :(", word);
    }
    else {
        printWordMini(word, found);
        printstring(560,20,"Gotcha! %s was caught! Congrats!", word);
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
    int row = 520, col = 20;
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
    printFrom("       ___    ", 570, 100);
    printFrom("     /#####\\   ", 590, 100);
    printFrom("   /#########\\     ", 605, 100);
    printFrom("  |=====O=====|   ",620, 100);
    printFrom("   \\         /   ",640, 100);
    printFrom("     '_____'    ",650, 100);
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
