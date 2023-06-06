#include "utility.h"

// pair
pair make_pair(int x, int y){
    pair p;
    p.first = x;
    p.second = y;
    return p;
}

// min / max
int min(int x, int y){
    return x < y ? x : y;
}

int max(int x, int y){
    return x > y ? x : y;
}