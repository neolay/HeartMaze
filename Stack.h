#pragma once
#include "public.h"

typedef struct
{
	Block *base;
	Block *top;
	int stacksize;
}SqStack;

void initStack(SqStack &S)
{
	S.base = (Block*)malloc(STACK_INIT_SIZE * sizeof(Block));
	if (!S.base)
		return;
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
}

void push(SqStack &S, Block e)
{
	if (S.top - S.base >= S.stacksize)
	{
		S.base = (Block*)realloc(S.base, (S.stacksize + STACKINCREMENT) * sizeof(Block));
		if (!S.base)
			return;
		S.top = S.base + S.stacksize;
		S.stacksize += STACKINCREMENT;
	}
	*S.top = e;
	S.top++;
}

void pop(SqStack &S, Block&e)
{
	if (S.top == S.base)
		return;
	S.top--;
	e = *S.top;
}

bool isEmpty(SqStack S)
{
	if (S.top == S.base)
		return true;
	else
		return false;
}