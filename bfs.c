#include "bfs.h"
#include <stdio.h>

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1 ,0, 0};
Pair next[30][30];
int distance[30][30];

int BlockValid(int x, int y){
    return (x >= 0 && x < 25 && y >= 0 && y < 13);
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
    Queue* queue = new_queue();
    // Initiate distance
    for(int i = 0; i < 30; i++)
        for(int j = 0; j < 30; j++)
            distance[i][j] = -1, next[i][j] = make_pair(-1, -1);
    Pair* tmp = (Pair*)malloc(sizeof(Pair) * 400);
    *tmp = make_pair(sx, sy);
    queue_clear(queue);
    queue_push(queue, (void*)tmp);
    tmp++;
    distance[sx][sy] = 0;
    while(queue_get_size(queue) > 0){
        Pair cur = *(Pair*) queue_front(queue);
        queue_pop(queue);
        for(int i = 0; i < 4; i++){
            if(BlockValid(cur.first + dx[i], cur.second + dy[i]) && distance[cur.first + dx[i]][cur.second + dy[i]] == -1){
                *tmp = make_pair(cur.first + dx[i], cur.second + dy[i]);
                queue_push(queue, (void*)tmp);
                distance[tmp->first][tmp->second] = distance[cur.first][cur.second] + 1;
                tmp++;
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

extern Pair GetNextStep(int x, int y){
    return make_pair(next[x][y].first * 64 + 32, next[x][y].second * 64 + 32);
}