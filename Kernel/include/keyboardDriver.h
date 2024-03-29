#ifndef KEY_DRIVER_H
#define KEY_DRIVER_H

#include <stdint.h>

void keyboardHandler(uint64_t *rsp);

int readBuffer(int length, char *toWrite);

void snapshot(uint64_t *rsp);

void saveRegisters(uint64_t *buffer);

extern unsigned char getScancode();

#endif
