#ifndef BFS_H_INCLUDED
#define BFS_H_INCLUDED

#include "utility.h"

// Queue part
extern pair queue[500];
extern int queueFrontIndex;
extern int queueBackIndex;

void QueuePush(int x, int y);
void QueuePop();
void QueueClear();
int QueueSize();
pair QueueFront();

// BFS part
extern int dx[4];
extern int dy[4];
extern int distance[30][30];
extern pair next[30][30];


int BlockValid(int x, int y);
int PrevStep(int x, int y);
void BFS(int sx, int sy, int ex, int ey);
pair GetNextStep(int x, int y); // return coordinate of next step

#endif // BFS_H_INCLUDED
