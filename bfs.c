#include "bfs.h"
#include <stdio.h>

pair queue[500];
int queueFrontIndex = 0;
int queueBackIndex = 0;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1 ,0, 0};
pair next[30][30];
int distance[30][30];

void QueuePush(int x, int y){
    queue[queueBackIndex] = make_pair(x, y);
    queueBackIndex += 1;
    if(queueBackIndex == 500)
        queueBackIndex = 0;
}

void QueuePop(){
    queueFrontIndex += 1;
    if(queueFrontIndex == 500)
        queueFrontIndex = 0;
}

pair QueueFront(){
    return queue[queueFrontIndex];
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
    int i = get_rand(0, 4), tmp = i;
    do{
        if(BlockValid(x + dx[i], y + dy[i]) && distance[x + dx[i]][y + dy[i]] == distance[x][y] - 1)
            return i;
        i = (i + 1) % 4;
    }while(i != tmp);
    return -1;
}

extern void BFS(int sx, int sy, int ex, int ey){
    // Initiate distance
    for(int i = 0; i < 30; i++)
        for(int j = 0; j < 30; j++)
            distance[i][j] = -1, next[i][j] = make_pair(-1, -1);
    QueueClear();
    QueuePush(sx, sy);
    distance[sx][sy] = 0;
    while(QueueSize() > 0){
        pair cur = QueueFront();
        QueuePop();
        for(int i = 0; i < 4; i++){
            if(BlockValid(cur.first + dx[i], cur.second + dy[i]) && distance[cur.first + dx[i]][cur.second + dy[i]] == -1){
                QueuePush(cur.first + dx[i], cur.second + dy[i]);
                distance[cur.first + dx[i]][cur.second + dy[i]] = distance[cur.first][cur.second] + 1;
            }
        }
    }
    int curX = ex, curY = ey;
    next[curX][curY] = make_pair(curX, curY);
    while(curX != sx || curY != sy){
        int prev = PrevStep(curX, curY);
        next[curX + dx[prev]][curY + dy[prev]] = make_pair(curX, curY);
        curX += dx[prev];
        curY += dy[prev];
    }
}

extern pair GetNextStep(int x, int y){
    return make_pair(next[x][y].first * 64 + 32, next[x][y].second * 64 + 32);
}