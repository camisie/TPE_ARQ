#include <library.h>
#include <stdint.h>
#include <registers.h>
#include <naiveConsole.h>

#define ZERO_EXCEPTION_ID 0
#define INVALID_OPCODE_ID 6
#define BUFFER64_BITS 20
#define RED_COLOR 0xFF0000
#define WHITE_COLOR 0xFFFFFF

static void zeroDivision();
static void invalidOpcode();
void printRegisters(uint64_t *rsp);

void exceptionDispatcher(int exception, uint64_t *rsp) {
    switch (exception) {
        case ZERO_EXCEPTION_ID:
            zeroDivision();
            break;
        case INVALID_OPCODE_ID:
            invalidOpcode();
            break;
    }
    printRegisters(rsp);
}

static void zeroDivision() {
    printcln("Cannot divide by 0.", RED_COLOR);
}

static void invalidOpcode() {
    printcln("Invalid operation code.",RED_COLOR);
}

void printRegisters(uint64_t *rsp) {
    char buffer[BUFFER64_BITS] = {0};

    char registerNames[][4] = {"R15", "R14", "R13", "R12", "R11", "R10", "R9 ", "R8 ", "RSI", "RDI", "RBP", "RDX", "RCX", "RBX",
                       "RAX", "RIP", "CS ", "FLG", "RSP"};

    for (int i = 0; i < TOTAL_REGISTERS; i++) {
        printc(registerNames[i], WHITE_COLOR);
        printc(": ", WHITE_COLOR);
        turnToBaseN(rsp[i], 16, buffer, BUFFER64_BITS);
        printcln(buffer, WHITE_COLOR);
    }
}
