#include "utility.h"

//-----------------------------------------------------------------------------------
// pair
Pair make_pair(int x, int y){
    Pair p;
    p.first = x;
    p.second = y;
    return p;
}
//-----------------------------------------------------------------------------------


//-----------------------------------------------------------------------------------
// min / max
int min(int x, int y){ return x < y ? x : y; }
int max(int x, int y){ return x > y ? x : y; }
//-----------------------------------------------------------------------------------


//-----------------------------------------------------------------------------------
// vector
// pointer
void vector_pointer_push_back(Vector_pointer* v, void* object){
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
void vector_pointer_pop_back(Vector_pointer* v){ v->size -= 1; }
void* vector_pointer_at(Vector_pointer* v, int index){ return v->objects[index]; }
int vector_pointer_get_size(Vector_pointer* v){ return v->size; }
void vector_pointer_clear(Vector_pointer* v){
    for(int i = 0; i < v->size; i++)
        if(v->objects[i])
            free(v->objects[i]);
    v->size = 0;
}
void vector_pointer_destroy(Vector_pointer* v){
    vector_pointer_clear(v);
    free(v->objects);
    free(v);
}
Vector_pointer *new_vector_pointer(){
    Vector_pointer *v = malloc(sizeof(Vector_pointer));
    v->objects = malloc(sizeof(void*));
    v->capacity = 1;
    v->size = 0;
    return v;
}
// int
void vector_int_push_back(Vector_int* v, int object){
    if(v->size == v->capacity){
        v->capacity *= 2;
        int* newObjects = malloc(sizeof(int) * v->capacity);
        for(int i = 0; i < v->size; i++)
            newObjects[i] = v->objects[i], newObjects[i + v->size] = 0;
        free(v->objects);
        v->objects = newObjects;
    }
    v->objects[v->size] = object;
    v->size += 1;
}
void vector_int_pop_back(Vector_int* v){ v->size -= 1; }
int vector_int_at(Vector_int* v, int index){ return v->objects[index]; }
int vector_int_get_size(Vector_int* v){ return v->size; }
void vector_int_clear(Vector_int* v){ v->size = 0; }
void vector_int_destroy(Vector_int* v){ free(v->objects), free(v); }
Vector_int *new_vector_int(){
    Vector_int *v = malloc(sizeof(Vector_int));
    v->objects = malloc(sizeof(int));
    v->capacity = 1;
    v->size = 0;
    return v;
}
// double
void vector_double_push_back(Vector_double* v, double object){
    if(v->size == v->capacity){
        v->capacity *= 2;
        double* newObjects = malloc(sizeof(double*) * v->capacity);
        for(int i = 0; i < v->size; i++)
            newObjects[i] = v->objects[i], newObjects[i + v->size] = 0.0;
        free(v->objects);
        v->objects = newObjects;
    }
    v->objects[v->size] = object;
    v->size += 1;
}
void vector_double_pop_back(Vector_double* v){ v->size -= 1; }
double vector_double_at(Vector_double* v, int index){ return v->objects[index]; }
int vector_double_get_size(Vector_double* v){ return v->size; }
void vector_double_clear(Vector_double* v){ v->size = 0; }
void vector_double_destroy(Vector_double* v){ free(v->objects), free(v); }
Vector_double *new_vector_double(){
    Vector_double *v = malloc(sizeof(Vector_double));
    v->objects = malloc(sizeof(double));
    v->capacity = 1;
    v->size = 0;
    return v;
}
// char
void vector_char_push_back(Vector_char* v, char object){
    if(v->size == v->capacity){
        v->capacity *= 2;
        char* newObjects = malloc(sizeof(char*) * v->capacity);
        for(int i = 0; i < v->size; i++)
            newObjects[i] = v->objects[i], newObjects[i + v->size] = 0.0;
        free(v->objects);
        v->objects = newObjects;
    }
    v->objects[v->size] = object;
    v->size += 1;
}
void vector_char_pop_back(Vector_char* v){ v->size -= 1; }
char vector_char_at(Vector_char* v, int index){ return v->objects[index]; }
int vector_char_get_size(Vector_char* v){ return v->size; }
void vector_char_clear(Vector_char* v){ v->size = 0; }
void vector_char_destroy(Vector_char* v){ free(v->objects), free(v); }
Vector_char *new_vector_char(){
    Vector_char *v = malloc(sizeof(Vector_char));
    v->objects = malloc(sizeof(char));
    v->capacity = 1;
    v->size = 0;
    return v;
}
// pair
void vector_pair_push_back(Vector_pair* v, Pair object){
    if(v->size == v->capacity){
        v->capacity *= 2;
        Pair* newObjects = malloc(sizeof(Pair*) * v->capacity);
        for(int i = 0; i < v->size; i++)
            newObjects[i] = v->objects[i], newObjects[i + v->size] = make_pair(0, 0);
        free(v->objects);
        v->objects = newObjects;
    }
    v->objects[v->size] = object;
    v->size += 1;
}
void vector_pair_pop_back(Vector_pair* v){ v->size -= 1; }
Pair vector_pair_at(Vector_pair* v, int index){ return v->objects[index]; }
int vector_pair_get_size(Vector_pair* v){ return v->size; }
void vector_pair_clear(Vector_pair* v){ v->size = 0; }
void vector_pair_destroy(Vector_pair* v){ free(v->objects), free(v); }
Vector_pair *new_vector_pair(){
    Vector_pair *v = malloc(sizeof(Vector_pair));
    v->objects = malloc(sizeof(Pair));
    v->capacity = 1;
    v->size = 0;
    return v;
}
//-----------------------------------------------------------------------------------


//-----------------------------------------------------------------------------------
// queue
// pointer
void queue_pointer_push(Queue_pointer* que, void* object){
    vector_pointer_push_back(que->v, object);
    que->back += 1;
    que->size += 1;
}
void queue_pointer_pop(Queue_pointer* que){
    if(que->size > 0) {
        que->front += 1;
        que->size -= 1;
    }
}
void queue_pointer_clear(Queue_pointer* que){
    vector_pointer_clear(que->v);
    que->front = 0;
    que->back = 0;
    que->size = 0;
}
void* queue_pointer_at(Queue_pointer* que, int index){ return vector_pointer_at(que->v, index + que->front); }
void* queue_pointer_front(Queue_pointer* que){ return queue_pointer_at(que, 0); }
int queue_pointer_get_size(Queue_pointer* que){ return que->size; }
void queue_pointer_destroy(Queue_pointer* que){ vector_pointer_destroy(que->v), free(que); }
Queue_pointer *new_queue_pointer(){
    Queue_pointer *q = malloc(sizeof(Queue_pointer));
    q->v = new_vector_pointer();
    q->size = 0;
    q->front = 0;
    q->back = 0;
    return q;
}
// int
void queue_int_push(Queue_int* que, int object){
    vector_int_push_back(que->v, object);
    que->back += 1;
    que->size += 1;
}
void queue_int_pop(Queue_int* que){
    if(que->size > 0) {
        que->front += 1;
        que->size -= 1;
    }
}
void queue_int_clear(Queue_int* que){
    vector_int_clear(que->v);
    que->front = 0;
    que->back = 0;
    que->size = 0;
}
int queue_int_at(Queue_int* que, int index){ return vector_int_at(que->v, index + que->front); }
int queue_int_front(Queue_int* que){ return queue_int_at(que, 0); }
int queue_int_get_size(Queue_int* que){ return que->size; }
void queue_int_destroy(Queue_int* que){ vector_int_destroy(que->v), free(que); }
Queue_int *new_queue_int(){
    Queue_int *q = malloc(sizeof(Queue_int));
    q->v = new_vector_int();
    q->size = 0;
    q->front = 0;
    q->back = 0;
    return q;
}
// pair
void queue_pair_push(Queue_pair* que, Pair object){
    vector_pair_push_back(que->v, object);
    que->back += 1;
    que->size += 1;
}
void queue_pair_pop(Queue_pair* que){
    if(que->size > 0) {
        que->front += 1;
        que->size -= 1;
    }
}
void queue_pair_clear(Queue_pair* que){
    vector_pair_clear(que->v);
    que->front = 0;
    que->back = 0;
    que->size = 0;
}
Pair queue_pair_at(Queue_pair* que, int index){ return vector_pair_at(que->v, index + que->front); }
Pair queue_pair_front(Queue_pair* que){ return queue_pair_at(que, 0); }
int queue_pair_get_size(Queue_pair* que){ return que->size; }
void queue_pair_destroy(Queue_pair* que){ vector_pair_destroy(que->v), free(que); }
Queue_pair *new_queue_pair(){
    Queue_pair *q = malloc(sizeof(Queue_pair));
    q->v = new_vector_pair();
    q->size = 0;
    q->front = 0;
    q->back = 0;
    return q;
}
//-----------------------------------------------------------------------------------



//-----------------------------------------------------------------------------------
// random
int get_rand(int l, int r){
    static long long seed = 1;
    seed = seed * 48271 % 2147483647;
    return (seed % (r - l)) + l;
}
//-----------------------------------------------------------------------------------
