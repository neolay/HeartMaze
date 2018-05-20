#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>

#define MAXQSIZE 1000
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10

typedef struct
{
	int x;
	int y;
	int di;
}Block;