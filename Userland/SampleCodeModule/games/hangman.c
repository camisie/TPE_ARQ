#include <standardIO.h>
#include <stdarg.h>
#include <hangman.h>
#include <pokemon.h>
#include <syscalls.h>
// #include <gameHandler.h>

//Macro para vaciar el buffer
#define DELETE_BUFFER while (getChar() != '\n')

//Cantidad de errores permitidos
#define CHANCES 6

//Longitud maxima que puede tener una palabra
#define WORDLEN 20

// #define ERROR_CODE -1

int exitSaveH = 0, exitWithoutSaveH = 0;

int hasPrevGame() {
    return exitSaveH;
}

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

        n = getint("Enter a number from 1 to 20: ");
        // if (n == ERROR_CODE) {
        //     askYesNoQuit();
        // }    
        
    } while(n > 9 || n < 0);


    /* Elegir una palabra*/
    word = dictionary[n - 1];


    // printLogo();

    // print("\nGotta catch 'em all! Welcome to pokemon-hangman, the game where you have to guess the pokemon's name in order to win!\n");
    // print("You have maximum 6 mistakes allowed :o Remember that all alphabet are in lower case\n");
    // print("\nA wild pokemon has appeared! (◍ㅇᆽㅇ◍) Good luck :)\n");

    do {
        //putChar("/n");
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
        //print("\n\nOh no! The wild %s fled! (╯°□°)╯︵◓ Better try next time :(\n");
    else{
        printstring("\n\nGotcha! %s was caught! Congrats!\n\n", word);
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

        if(letter != '\n')
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

// int getintH(const char message[], ... ) {
//     int n, leave = 0;
//     va_list ap;
//
//     do {
//         va_start(ap, message);
//         vprintf(message, ap);
//         va_end(ap);
//
//         if ( scanf("%d",&n) != 1)
//         {
//             print("\nIncorrect data\n");
//             DELETE_BUFFER;
//         }
//         else
//             leave = 1;
//     } while (! leave);
//     DELETE_BUFFER;
//     return n;
// }
