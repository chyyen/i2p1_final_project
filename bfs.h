#ifndef BFS_H_INCLUDED
#define BFS_H_INCLUDED

// Queue part
int queue_X[500];
int queue_Y[500];
int queueFrontIndex;
int queueBackIndex;

void QueuePush(int x, int y);
void QueuePop();
void QueueClear();
int QueueSize();
int QueueFrontX();
int QueueFrontY();

// BFS part
int dx[4];
int dy[4];
int next[30][30];
int distance[30][30];

int BlockValid(int x, int y);
int PrevStep(int x, int y);
extern void BFS(int sx, int sy, int ex, int ey);
extern int GetNextStep(int x, int y); // encode as 30 * x + y, -1 if not found

#endif // BFS_H_INCLUDED
