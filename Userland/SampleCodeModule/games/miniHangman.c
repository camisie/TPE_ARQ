#include <miniHangman.h>

#define RED_COLOR 0xFF0000
#define GREY_COLOR 0x808080
#define YELLOW_COLOR 0xFFEA00

void printWordMini(const char word[], const short found[]);
char readLetterMini(void);
void printPokeballMini(void);

char *word;
short found[WORDLEN];
char dictionary[][WORDLEN] = {"bulbasaur", "butterfree", "charmander", "marowak", "slowpoke", "eevee", "gastly", "geodude", "growlithe", "jigglypuff", "meowth", "pidgey", "pikachu", "poliwag", "ponyta", "psyduck", "rattata", "ditto", "squirtle", "horsea"};
int mistakes;

void startMiniHangman() {
    printcFrom("Welcome to MINI-HANGMAN! Gotta catch 'em all!", 420, 20, YELLOW_COLOR);
    printcFrom("Guess the pokemon's name in order to win!", 440, 20, YELLOW_COLOR);
    printcFrom("You have maximum 6 mistakes allowed :o", 460, 20, YELLOW_COLOR);

    dateInfo info;
    getTime(&info);
    int n = info.seconds % 20;
    word = dictionary[n];

    mistakes = 0;
    for(int i = 0; i < WORDLEN; i++) {
        found[i] = 0;
    }
    printWordMini(word, found);
}

void playMiniHangman(char letter) {
    if(mistakes < CHANCES && !completeWord(word, found)) {
        if (!checkLetter(word, letter, found)) {
            mistakes++;
            if (CHANCES - mistakes > 0) {
                printstring(490,20,"Attack missed! Remaining attempts: %d", CHANCES - mistakes);
            }
        }
        else {
            printWordMini(word, found);
        }
    }
    else {
        if (mistakes == CHANCES) {
            printstring(560,20,"Oh no! The wild %s fled! Better try next time :(", word);
        }
        else {
            printWordMini(word, found);
            printstring(560,20,"Gotcha! %s was caught! Congrats!", word);
            printPokeballMini();
        }
    }
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
    printcFrom("       ___    ", 570, 100,RED_COLOR);
    printcFrom("     /#####\\   ", 590, 100,RED_COLOR);
    printcFrom("   /#########\\     ", 605, 100,RED_COLOR);
    printcFrom("  |=====O=====|   ",620, 100,GREY_COLOR );
    printFrom("   \\         /   ",640, 100);
    printFrom("     ` ___ '    ",650, 100);
}
