#include <hangmanHandler.h>
#include <syscalls.h>
#include <standardIO.h>
#include <types.h>
#include <string.h>
#include <stdint.h>
#include <lib64.h>
#include <apps.h>
#include <stopwatch.h>
#include <sudoku.h>
#include <miniHangman.h>
#include <shell.h>


#define MEM_BYTES 32
#define BUFFER64_BITS 20

char array[] = {121, 27, 3, 4, 5, 6, 7, 8, 9, 10, 11};

programs commands[] = {{"about",       about,          "Information about the O.S and authors."},
                       {"help",        showApps,       "Menu of the differents apps."},
                       {"time",        time,           "Displays the systems current time."},
                       {"inforeg",     infoReg,        "Displays the registers current state."},
                       {"printmem",    printMem,       "Prints on screen the first 32 bytes from a given position."},
                       {"hangman",     hangman,        "Standalone version of a Pokemon-inspired Hangman"},
                       {"clear",       clear,          "Clears the current screen."},
                       {"exceptionZ",  throwDivZero,   "Throws a divide by zero exception"},
                       {"exceptionOP", throwInvOpCode, "Throws an invalid Operation Code Exception"},
                       {"games", runGames, "Hangman - Sudoku - Stopwatch - Time"},
                       {"pokeball", getPokeball, "Catch a pokemon!"}
};

int checkArgs(int args, int expected);

void infoReg(int args, char argv[][25]) {
    if (!checkArgs(args, 0)) return;

    char regis[][4] = {"R15", "R14", "R13", "R12", "R11", "R10", "R9 ", "R8 ", "RSI", "RDI", "RBP", "RDX", "RCX", "RBX",
                       "RAX", "RIP", "CS ", "FLG", "RSP"};
    uint64_t values[REGISTERS_AMOUNT];
    getRegisters(values);
    char buffer[BUFFER64_BITS] = {0};

    for (int i = 0; i < REGISTERS_AMOUNT; i++) {
        turnToBaseN(values[i], 16, buffer, BUFFER64_BITS);
        printc(regis[i], 0xaa08d0);
        printc(":  ", 0xaa08d0);
        print("0x");
        println(buffer);
    }

}

void printMem(int args, char argv[][25]) {
    if (!checkArgs(args, 1)) return;

    char *dir = (char *) stringToInt(argv[1]);
    char dump[MEM_BYTES];
    memoryDump(dir, dump);
    char buffer[BUFFER64_BITS] = {0};
    char valueBuffer[35] = {0};
    for (int i = 0; i < MEM_BYTES / 8; i++) {
        turnToBaseN((uint64_t)(dir + i * 8), 16, buffer, BUFFER64_BITS);
        print(buffer);
        print(":  ");
        for (int j = 0; j < 8; j++) {
            char memValue[3];
            turnToBaseN(dump[i * 8 + j], 16, memValue, 3);
            strcpy(valueBuffer + j * 3, memValue);
            valueBuffer[26 + j] = (dump[i * 8 + j] >= 0x21 && dump[i * 8 + j]) ? dump[i * 8 + j] : '.';
        }
        for (int k = 2; k < 24; k += 3) {
            valueBuffer[k] = ' ';
        }
        valueBuffer[24] = '|';
        valueBuffer[25] = ' ';
        valueBuffer[34] = 0;
        print(valueBuffer);
        println(" ");
    }
}

void time(int args, char argv[][25]) {
    if (!checkArgs(args, 0)) return;
    dateInfo info;
    getTime(&info);
    char fecha[19] = {0};
    print("Local date & time: ");
    dateToString(&info, fecha, '/', 18);
    print(fecha);
    println("");
}

void getLocalTime(void) {
    dateInfo info;
    getTime(&info);
    char fecha[19] = {0};
    timeToString(&info, fecha, '/', 9);
    printFrom(fecha, 200, 775);
}

void showApps(int args, char argv[][25]) {
    if (!checkArgs(args, 0)) return;

    int color = 0xf03fcd;

    for (int i = 0; i < PROGRAMS; i++) {
        printc(commands[i].name, color);
        printc(": ", color);
        printcln(commands[i].description, 0xcfd7e6);
    }
}

void hangman(int args, char argv[][25]) {            //hacer despues para que se pueda abrir el juego en una ventana de la shell
    hangmanHandler(args, argv);
}

void clear(int args, char argv[][25]) {
    if (!checkArgs(args, 0)) return;
    clearScreen();
}

void throwDivZero() {
    int a = 0;
    int b = 5;
    a = b / a;
}

void throwInvOpCode() {
    invalidOpCode();
}

void about() {
    printcln("PokeOS 1.0 by Camila Sierra, Malena Vasquez & Magdalena Flores Levalle.", 0xcfd7e6);
}

int checkArgs(int args, int expected) {
    if (args != expected) {
        println("Invalid number of arguments");
        return 0;
    }
    return 1;
}

void runGames() {
    clearScreen();
    divideScreen();
    initStopwatch();
    startMiniHangman();
    startSudoku();
    printFrom("Local time: ", 200, 675);

    int exit = 0;
    while(!exit) {
        getLocalTime();
        char c = getChar();
        // if(c == '\n')
        //     DELETE_BUFFER;
        if(c >= 'a' && c <= 'z') {
            playMiniHangman(c);
        }
        else if(c >= '1' && c <= '9') {
            playSudoku(c);
        }
        else if(c == 'P') {
            changeStatus();
        }
        else if(c == 'R') {
            resetStopwatch();
        }
        else if(c == '0') {
            exit = 1;
        }
        stopwatch();
    }
    returnToShell();
}

void getPokeball() {
    int num = rand() % 20;
    iChooseYou(num);
}
