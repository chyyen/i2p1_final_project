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

// vector
void vector_push_back(vector* v, void* object){
    if(v->size == v->capacity){
        v->capacity *= 2;
        void** newObjects = malloc(sizeof(void*) * v->capacity);
        for(int i = 0; i < v->size; i++)
            newObjects[i] = v->objects[i];
        free(v->objects);
        v->objects = newObjects;
    }
    v->objects[v->size] = object;
    v->size += 1;
}

void vector_pop_back(vector* v){
    v->size -= 1;
}

void* vector_at(vector* v, int index){
    return v->objects[index];
}

int vector_get_size(vector* v){
    return v->size;
}

vector *newVector(){
    vector *v = malloc(sizeof(vector));
    v->capacity = 0;
    v->size = 0;
    return v;
}

// random
int get_rand(int l, int r){
    static long long seed = 1;
    seed = seed * 48271 % 2147483647;
    return (seed % (r - l)) + l;
}