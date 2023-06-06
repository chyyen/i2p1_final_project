#include "bfs.h"
#include <allegro5/allegro.h>

int queue_X[500];
int queue_Y[500];
int queueFrontIndex = 0;
int queueBackIndex = 0;

bool firstTime = false;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1 ,0, 0};
int next[30][30];
int distance[30][30];

void QueuePush(int x, int y){
    queue_X[queueBackIndex] = x;
    queue_Y[queueBackIndex] = y;
    queueBackIndex += 1;
    if(queueBackIndex == 500)
        queueBackIndex = 0;
}

void QueuePop(){
    queueFrontIndex += 1;
    if(queueFrontIndex == 500)
        queueFrontIndex = 0;
}

int QueueFrontX(){
    return queue_X[queueFrontIndex];
}

int QueueFrontY(){
    return queue_Y[queueFrontIndex];
}

void QueueClear(){
    queueFrontIndex = 0;
    queueBackIndex = 0;
}

int QueueSize(){
    if(queueBackIndex >= queueFrontIndex)
        return queueBackIndex - queueFrontIndex;
    else
        return queueBackIndex + 500 - queueFrontIndex;
}

int BlockValid(int x, int y){
    return (x >= 0 && x < 25 && y >= 0 && y < 15);
}

int PrevStep(int x, int y){
    for(int i = 0; i < 4; i++){
        if(BlockValid(x + dx[i], y + dy[i]) && distance[x + dx[i]][y + dy[i]] == distance[x][y] - 1)
            return i;
    }
    return -1;
}

extern void BFS(int sx, int sy, int ex, int ey){
    // Initiate distance
    for(int i = 0; i < 30; i++)
        for(int j = 0; j < 30; j++)
            distance[i][j] = -1, next[i][j] = -1;
    QueueClear();
    QueuePush(sx, sy);
    distance[sx][sy] = 0;
    while(QueueSize() > 0){
        int x = QueueFrontX();
        int y = QueueFrontY();
        QueuePop();
        for(int i = 0; i < 4; i++){
            if(BlockValid(x + dx[i], y + dy[i]) && distance[x + dx[i]][y + dy[i]] == -1){
                QueuePush(x + dx[i], y + dy[i]);
                distance[x + dx[i]][y + dy[i]] = distance[x][y] + 1;
            }
        }
    }
    int curX = ex, curY = ey;
    next[curX][curY] = -1;
    while(curX != sx || curY != sy){
        int prev = PrevStep(curX, curY);
        next[curX + dx[prev]][curY + dy[prev]] = curX * 30 + curY;
        curX += dx[prev];
        curY += dy[prev];
    }
}

extern int GetNextStep(int x, int y){
    return next[x][y];
}