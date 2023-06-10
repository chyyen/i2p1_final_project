#include "utility.h"

// pair
Pair make_pair(int x, int y){
    Pair p;
    p.first = x;
    p.second = y;
    return p;
}


// min / max
int min(int x, int y){ return x < y ? x : y; }
int max(int x, int y){ return x > y ? x : y; }


// vector
void vector_push_back(Vector* v, void* object){
    if(v->size == v->capacity){
        v->capacity *= 2;
        void** newObjects = malloc(sizeof(void*) * v->capacity);
        for(int i = 0; i < v->size; i++)
            newObjects[i] = v->objects[i], newObjects[i + v->size] = NULL;
        free(v->objects);
        v->objects = newObjects;
    }
    v->objects[v->size] = object;
    v->size += 1;
}

void vector_pop_back(Vector* v){
    v->size -= 1;
}

void* vector_at(Vector* v, int index){
    if(index >= v->size)
        return NULL;
    return v->objects[index];
}

int vector_get_size(Vector* v){
    return v->size;
}

void vector_clear(Vector* v){
    v->size = 0;
}

void vector_free_objects(Vector* v){
    for(int i = 0; i < v->size; i++)
        if(v->objects[i] != NULL)
            free(v->objects[i]);
    vector_clear(v);
    free(v->objects);
    v->capacity = 1;
    v->objects = malloc(sizeof(void*));
}

void destroy_vector(Vector* v){
    vector_free_objects(v);
    free(v);
}

Vector *new_vector(){
    Vector *v = malloc(sizeof(Vector));
    v->objects = malloc(sizeof(void*));
    v->capacity = 1;
    v->size = 0;
    return v;
}


// queue
void queue_push(Queue* que, void* object){
    vector_push_back(que->v, object);
    que->back += 1;
    que->size += 1;
}

void queue_pop(Queue* que){
    if(que->size > 0) {
        que->front += 1;
        que->size -= 1;
    }
}

void queue_clear(Queue* que){
    vector_clear(que->v);
    que->front = 0;
    que->back = 0;
    que->size = 0;
}

void* queue_at(Queue* que, int index){
    return vector_at(que->v, index + que->front);
}

void* queue_front(Queue* que){
    return queue_at(que, 0);
}

int queue_get_size(Queue* que){
    return que->size;
}

void destroy_queue(Queue* que){
    vector_free_objects(que->v);
    free(que->v);
    free(que);
}

Queue* new_queue(){
    Queue *q = malloc(sizeof(Queue));
    q->v = new_vector();
    q->size = 0;
    q->front = 0;
    q->back = 0;
    return q;
}


// random
int get_rand(int l, int r){
    static long long seed = 1;
    seed = seed * 48271 % 2147483647;
    return (seed % (r - l)) + l;
}