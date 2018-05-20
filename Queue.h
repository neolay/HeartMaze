#pragma once
#include "public.h"

typedef struct {

	Block *base;
	int front;
	int rear;
}SqQueue;

void initQueue(SqQueue &Q)
{
	Q.base = (Block*)malloc(MAXQSIZE * sizeof(Block));
	if (!Q.base)
		return;
	Q.front = Q.rear = 0;
}

void enQueue(SqQueue &Q, Block e)
{
	if ((Q.rear + 1) % MAXQSIZE == Q.front)
		return;

	Q.base[Q.rear] = e;
	Q.rear = (Q.rear + 1) % MAXQSIZE;
}

int getLength(SqQueue Q)
{
	return (Q.rear - Q.front + MAXQSIZE) % MAXQSIZE;
}

void deQueue(SqQueue &Q, Block &e)
{
	if (Q.front == Q.rear)
		return;
	srand((unsigned)time(NULL));
	int randIdx = rand() % getLength(Q);
	e = Q.base[randIdx];
	Q.base[randIdx] = Q.base[Q.rear - 1];
	Q.base[Q.rear - 1] = e;

	Q.rear = (Q.rear - 1) % MAXQSIZE;
}

bool isEmpty(SqQueue Q)
{
	if (Q.front == Q.rear)
		return true;
	else
		return false;
}