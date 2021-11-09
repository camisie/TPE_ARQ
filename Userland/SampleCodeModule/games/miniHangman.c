#include <miniHangman.h>

void runMiniHangman(int entry) {
    clearScreen();
    miniPlay();
}

void miniPlay(){

    char dictionary[][WORDLEN] = {"bulbasaur", "butterfree", "charmander", "marowak", "slowpoke", "eevee", "gastly", "geodude", "growlithe", "jigglypuff", "meowth", "pidgey", "pikachu", "poliwag", "ponyta", "psyduck", "rattata", "ditto", "squirtle", "horsea"};
    char letter, *word;
    int mistakes = 0;
    short found[WORDLEN] = {0};

    int n;

      do {
        print("Enter \"q\" if you want to quit the game. Once you start, there's no turning back!\n");
        n = getint("Enter a number from 1 to 20: ");
        putChar('\n');
        if (n == QUIT_CODE) {
          if(askYesNoQuit()) {
            return;
          }
        }
      } while(n < 0 || n >= 20);

    /* Elegir una palabra*/
    word = dictionary[n - 1];

    do {
        println("");
        printWord(word, found);
        letter = readLetter();
        if (!checkLetter(word, letter, found))
        {
            mistakes++;
            if (CHANCES - mistakes > 0)
                printstring("Attack missed!\tRemaining attempts: %d", CHANCES - mistakes);
        }
        putChar('\n');
    } while (mistakes < CHANCES && !completeWord(word, found));

    if (mistakes == CHANCES)
        printstring("\n\nOh no! The wild %s fled! Better try next time :(\n", word);
    else{
        printstring("\n\nGotcha! %s was caught! Congrats!\n\n", word);
        printPokeball();
    }
    return;

}
