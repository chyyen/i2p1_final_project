#ifndef UTILITY_H_INCLUDED
#define UTILITY_H_INCLUDED

#include <stdlib.h>

// pair
typedef struct _pair{
    int first;
    int second;
}Pair;

Pair make_pair(int x, int y);


// vector
typedef struct _vector{
    int capacity, size;
    void** objects;
}Vector;

void vector_push_back(Vector* v, void* object);
void vector_pop_back(Vector* v);
void* vector_at(Vector* v, int index);
int vector_get_size(Vector* v);
void vector_clear(Vector* v);
void vector_free_objects(Vector* v);
void destroy_vector(Vector* v);
Vector *new_vector();


// queue
typedef struct _queue{
    int size, front, back;
    Vector* v;
}Queue;

void queue_push(Queue* que, void* object);
void queue_pop(Queue* que);
void queue_clear(Queue* que);
void* queue_at(Queue* que, int index);
void* queue_front(Queue* que);
int queue_get_size(Queue* que);
void destroy_queue(Queue* que);
Queue *new_queue();

// min / max
int min(int x, int y);
int max(int x, int y);


// random
int get_rand(int l, int r);

#endif // UTILITY_H_INCLUDED
