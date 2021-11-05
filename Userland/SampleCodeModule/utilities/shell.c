#include <shell.h>
#include <string.h>
#include <standardIO.h>
#include <syscalls.h>
#include <stdint.h>
#include <apps.h>

#define CHUNK 200

//-------------------------------------------
//                  POKEOS
//-------------------------------------------

char *initGreet = "user@TPArqui:~$ ";

void initShell() {
    char c;
    printOSLogo();
    println("");
    while (1) {
        printc(initGreet, 0x22ab00);
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

void printOSLogo(void) {
    println("PPPPPPPPPPPPPPPPP        OOOOOOOOO     KKKKKKKKK    KKKKKKKEEEEEEEEEEEEEEEEEEEEEE     OOOOOOOOO        SSSSSSSSSSSSSSS");
    println("P::::::PPPPPP:::::P  OO:::::::::::::OO K:::::::K    K:::::KE::::::::::::::::::::E OO:::::::::::::OO S:::::SSSSSS::::::S");
    println("PP:::::P     P:::::PO:::::::OOO:::::::OK:::::::K   K::::::KEE::::::EEEEEEEEE::::EO:::::::OOO:::::::OS:::::S     SSSSSSS");
    println("P::::P     P:::::PO::::::O   O::::::OKK::::::K  K:::::KKK  E:::::E       EEEEEEO::::::O   O::::::OS:::::S");
    println("P::::P     P:::::PO:::::O     O:::::O  K:::::K K:::::K     E:::::E             O:::::O     O:::::OS:::::S");
    println("P::::PPPPPP:::::P O:::::O     O:::::O  K::::::K:::::K      E::::::EEEEEEEEEE   O:::::O     O:::::O S::::SSSS");
    println("P:::::::::::::PP  O:::::O     O:::::O  K:::::::::::K       E:::::::::::::::E   O:::::O     O:::::O  SS::::::SSSSS");
    println("P::::PPPPPPPPP    O:::::O     O:::::O  K:::::::::::K       E:::::::::::::::E   O:::::O     O:::::O    SSS::::::::SS");
    println("P::::P            O:::::O     O:::::O  K::::::K:::::K      E::::::EEEEEEEEEE   O:::::O     O:::::O       SSSSSS::::S");
    println("P::::P            O:::::O     O:::::O  K:::::K K:::::K     E:::::E             O:::::O     O:::::O            S:::::S");
    println("P::::P            O::::::O   O::::::OKK::::::K  K:::::KKK  E:::::E       EEEEEEO::::::O   O::::::O            S:::::S");
    println("PP::::::PP          O:::::::OOO:::::::OK:::::::K   K::::::KEE::::::EEEEEEEE:::::EO:::::::OOO:::::::OSSSSSSS     S:::::S");
    println("P::::::::P           OO:::::::::::::OO K:::::::K    K:::::KE::::::::::::::::::::E OO:::::::::::::OO S::::::SSSSSS:::::S");
    println("P::::::::P             OO:::::::::OO   K:::::::K    K:::::KE::::::::::::::::::::E   OO:::::::::OO   S:::::::::::::::SS");
    println("PPPPPPPPPP               OOOOOOOOO     KKKKKKKKK    KKKKKKKEEEEEEEEEEEEEEEEEEEEEE     OOOOOOOOO      SSSSSSSSSSSSSSS");
}
