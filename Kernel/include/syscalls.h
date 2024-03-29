#ifndef SYSCALLS_H
#define SYSCALLS_H

#define SYS_READ_ID 0
#define SYS_WRITE_ID 1
#define SYS_CLEAR_ID 3
#define SYS_INFOREG_ID 8
#define SYS_PRINTMEM_ID 9
#define SYS_TIME_ID 10
#define DIVIDE_SCREEN_ID 14
#define STOPWATCHTICKS_ID 16
#define TICKSELAPSED_ID 17
#define MEM_BYTES 32

#include <timerDriver.h>
#include <stdint.h>

int sys_read(int length, char *toRead);

int sys_write(int length, char *toWrite, int row, int col, int color);

void sys_divide();

void sys_clear();

void getTime(date myDate);

void getMem(char *dir, char *dump);

void getRegisters(uint64_t firstP[]);

#endif
