#pragma once
#include "Stack.h"
#include "Queue.h"

#define N 37	
#define M 47
#define DELAY 1

typedef enum { MASK = 0, ROAD = 1, BACK = 2, INWALL = 3, OUTWALL = 4, EMPTYWALL = 5 } BlockType;
typedef enum { EAST = 6, SOUTH = 7, WEST = 8, NORTH = 9 } Direction;
typedef int Maze;

void initMaze(Maze maze[N][M], Block &in, Block &out);
void findPath(Maze maze[N][M], Block in, Block out);
void initBlock(Block &block, int x, int y, int di);
void showBlock(Maze maze[N][M]);
void updateMaze(Maze maze[N][M]);
int nextBlockX(int a, int di);
int nextBlockY(int b, int di);
bool inMaze(int x, int y);
void clearMask(int x, int y);
void gotoxy(int x, int y);
void hideCursor();
void initHeart();