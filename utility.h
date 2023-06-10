#ifndef UTILITY_H_INCLUDED
#define UTILITY_H_INCLUDED

#include <stdlib.h>

// pair
typedef struct _pair{
    int first;
    int second;
}pair;

pair make_pair(int x, int y);

// vector
typedef struct _vector{
    int capacity, size;
    void** objects;
}vector;

void vector_push_back(vector* v, void* object);
void vector_pop_back(vector* v);
void* vector_at(vector* v, int index);
int vector_get_size(vector* v);
void vector_clear(vector* v);
vector *newVector();

// min / max
int min(int x, int y);
int max(int x, int y);

// random
int get_rand(int l, int r);

#endif // UTILITY_H_INCLUDED
