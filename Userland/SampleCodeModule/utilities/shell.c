#include <shell.h>

#define CHUNK 200
#define SCREEN_HEIGTH 16
#define BLUE_GREETING 0x00FFFF
#define MIDDLE_TITLE 40

//-------------------------------------------
//                  POKEOS
//-------------------------------------------

char *initGreet = "user@TPE_ARQ:~$ ";
int startup = 1;

void startShell() {
    if(startup) {
        printOSLogo();
        println("Enter help to see the commands available");
        startup = 0;
    }
    runShell();
}

void runShell() {
    char c;
    println("");
    
    while (1) {
        printc(initGreet, 0xFF8C00);
        char content[CHUNK] = {0};
        int contentLength = 0;
        while ((c = getChar()) != '\n') {
            if (c != 0) {
                switch (c) {
                    case '\b':
                        if (contentLength > 0) {
                            content[--contentLength] = 0;
                            removeChar();
                        }
                        break;
                    default:
                        content[contentLength++] = c;
                        putChar(c);
                }
            }
        }
        content[contentLength] = 0;
        if (contentLength > 0) {
            println("");
            char tokens[10][25] = {{0}}; //time param1
            int args = tokenizeArguments(content, tokens) - 1;// 1 es el nombre del programa
            int progAvail = hasProgram(tokens[0]);
            if (progAvail != -1) {
                commands[progAvail].f(args, tokens);

            } else {
                print(content);
                println(": command not found, try 'help' for help.");
            }
        } else {
            println("");
        }

        contentLength = 0;

    }
}

int tokenizeArguments(char *toToken, char tokens[10][25]) {
    return strtoks(toToken, ' ', tokens);
}

int hasProgram(char *input) {
    for (int i = 0; i < PROGRAMS; i++) {
        if (strcmp(input, commands[i].name) == 0) {
            return i;
        }
    }
    return -1;
}

void returnToShell() {
  clearScreen();
  runShell();
}


void printOSLogo(void) {
    int heigth = 0;
    heigth += SCREEN_HEIGTH * 16;
    printcFrom("PPPPPPPPPPPPPPPPP        OOOOOOOOO     KKKKKKKKK    KKKKKKKEEEEEEEEEEEEEEEEEEEEEE     OOOOOOOOO        SSSSSSSSSSSSSSS", heigth += SCREEN_HEIGTH, MIDDLE_TITLE, BLUE_GREETING);
    printcFrom("P::::::PPPPPP:::::P  OO:::::::::::::OO K:::::::K    K:::::KE::::::::::::::::::::E OO:::::::::::::OO S:::::SSSSSS::::::S", heigth += SCREEN_HEIGTH, MIDDLE_TITLE, BLUE_GREETING);
    printcFrom("PP:::::P     P:::::PO:::::::OOO:::::::OK:::::::K   K::::::KEE::::::EEEEEEEEE::::EO:::::::OOO:::::::OS:::::S     SSSSSSS", heigth += SCREEN_HEIGTH, MIDDLE_TITLE, BLUE_GREETING);
    printcFrom("P::::P     P:::::PO::::::O   O::::::OKK::::::K  K:::::KKK  E:::::E       EEEEEEO::::::O   O::::::OS:::::S", heigth += SCREEN_HEIGTH, MIDDLE_TITLE, BLUE_GREETING);
    printcFrom("P::::P     P:::::PO:::::O     O:::::O  K:::::K K:::::K     E:::::E             O:::::O     O:::::OS:::::S", heigth += SCREEN_HEIGTH, MIDDLE_TITLE, BLUE_GREETING);
    printcFrom("P::::PPPPPP:::::P O:::::O     O:::::O  K::::::K:::::K      E::::::EEEEEEEEEE   O:::::O     O:::::O S::::SSSS", heigth += SCREEN_HEIGTH, MIDDLE_TITLE, BLUE_GREETING);
    printcFrom("P:::::::::::::PP  O:::::O     O:::::O  K:::::::::::K       E:::::::::::::::E   O:::::O     O:::::O  SS::::::SSSSS", heigth += SCREEN_HEIGTH, MIDDLE_TITLE, BLUE_GREETING);
    printcFrom("P::::PPPPPPPPP    O:::::O     O:::::O  K:::::::::::K       E:::::::::::::::E   O:::::O     O:::::O    SSS::::::::SS", heigth += SCREEN_HEIGTH, MIDDLE_TITLE, BLUE_GREETING);
    printcFrom("P::::P            O:::::O     O:::::O  K::::::K:::::K      E::::::EEEEEEEEEE   O:::::O     O:::::O       SSSSSS::::S", heigth += SCREEN_HEIGTH, MIDDLE_TITLE, BLUE_GREETING);
    printcFrom("P::::P            O:::::O     O:::::O  K:::::K K:::::K     E:::::E             O:::::O     O:::::O            S:::::S", heigth += SCREEN_HEIGTH, MIDDLE_TITLE, BLUE_GREETING);
    printcFrom("P::::P            O::::::O   O::::::OKK::::::K  K:::::KKK  E:::::E       EEEEEEO::::::O   O::::::O            S:::::S", heigth += SCREEN_HEIGTH, MIDDLE_TITLE, BLUE_GREETING);
    printcFrom("PP::::::PP          O:::::::OOO:::::::OK:::::::K   K::::::KEE::::::EEEEEEEE:::::EO:::::::OOO:::::::OSSSSSSS     S:::::S", heigth += SCREEN_HEIGTH, MIDDLE_TITLE, BLUE_GREETING);
    printcFrom("P::::::::P           OO:::::::::::::OO K:::::::K    K:::::KE::::::::::::::::::::E OO:::::::::::::OO S::::::SSSSSS:::::S", heigth += SCREEN_HEIGTH, MIDDLE_TITLE, BLUE_GREETING);
    printcFrom("P::::::::P             OO:::::::::OO   K:::::::K    K:::::KE::::::::::::::::::::E   OO:::::::::OO   S:::::::::::::::SS", heigth += SCREEN_HEIGTH, MIDDLE_TITLE, BLUE_GREETING);
    printcFrom("PPPPPPPPPP               OOOOOOOOO     KKKKKKKKK    KKKKKKKEEEEEEEEEEEEEEEEEEEEEE     OOOOOOOOO      SSSSSSSSSSSSSSS", heigth += SCREEN_HEIGTH, MIDDLE_TITLE, BLUE_GREETING);
}