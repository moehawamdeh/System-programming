#include<stdio.h>
#include<stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

typedef struct{
char line[100];
int flag;
}Data;

const key_t memKey=312253;
const int FLAG_DATA_RDY=6;
const int FLAG_DONE=5;
