#ifndef UTILITY_H_INCLUDED
#define UTILITY_H_INCLUDED

#include <stdlib.h>

//-----------------------------------------------------------------------------------
// pair
typedef struct _pair{
    int first;
    int second;
}Pair;

Pair make_pair(int x, int y);
//-----------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------
// vector
typedef struct _vector_pointer{
    int capacity, size;
    void** objects;
}Vector_pointer;
typedef struct _vector_int{
    int capacity, size;
    int *objects;
}Vector_int;
typedef struct _vector_double{
    int capacity, size;
    double *objects;
}Vector_double;
typedef struct _vector_pair{
    int capacity, size;
    Pair *objects;
}Vector_pair;
typedef struct _vector_char{
    int capacity, size;
    char *objects;
}Vector_char;

void vector_pointer_push_back(Vector_pointer* v, void* object);
void vector_pointer_pop_back(Vector_pointer* v);
void* vector_pointer_at(Vector_pointer* v, int index);
int vector_pointer_get_size(Vector_pointer* v);
void vector_pointer_clear(Vector_pointer* v);
void vector_pointer_destroy(Vector_pointer* v);
Vector_pointer *new_vector_pointer();

void vector_int_push_back(Vector_int* v, int object);
void vector_int_pop_back(Vector_int* v);
int vector_int_at(Vector_int* v, int index);
int vector_int_get_size(Vector_int* v);
void vector_int_clear(Vector_int* v);
void vector_int_destroy(Vector_int* v);
Vector_int *new_vector_int();

void vector_char_push_back(Vector_char* v, char object);
void vector_char_pop_back(Vector_char* v);
char vector_char_at(Vector_char* v, int index);
int vector_char_get_size(Vector_char* v);
void vector_char_clear(Vector_char* v);
void vector_char_destroy(Vector_char* v);
Vector_char *new_vector_char();

void vector_double_push_back(Vector_double* v, double object);
void vector_double_pop_back(Vector_double* v);
double vector_double_at(Vector_double* v, int index);
int vector_double_get_size(Vector_double* v);
void vector_double_clear(Vector_double* v);
void vector_double_destroy(Vector_double* v);
Vector_double *new_vector_double();

void vector_pair_push_back(Vector_pair* v, Pair object);
void vector_pair_pop_back(Vector_pair* v);
Pair vector_pair_at(Vector_pair* v, int index);
int vector_pair_get_size(Vector_pair* v);
void vector_pair_clear(Vector_pair* v);
void vector_pair_destroy(Vector_pair* v);
Vector_pair *new_vector_pair();
//-----------------------------------------------------------------------------------


//-----------------------------------------------------------------------------------
// queue
typedef struct _queue_pointer{
    int size, front, back;
    Vector_pointer* v;
}Queue_pointer;
typedef struct _queue_int{
    int size, front, back;
    Vector_int * v;
}Queue_int;
typedef struct _queue_pair{
    int size, front, back;
    Vector_pair * v;
}Queue_pair;

void queue_pointer_push(Queue_pointer* que, void* object);
void queue_pointer_pop(Queue_pointer* que);
void queue_pointer_clear(Queue_pointer* que);
void* queue_pointer_at(Queue_pointer* que, int index);
void* queue_pointer_front(Queue_pointer* que);
int queue_pointer_get_size(Queue_pointer* que);
void queue_pointer_destroy(Queue_pointer* que);
Queue_pointer *new_queue_pointer();

void queue_int_push(Queue_int* que, int object);
void queue_int_pop(Queue_int* que);
void queue_int_clear(Queue_int* que);
int queue_int_at(Queue_int* que, int index);
int queue_int_front(Queue_int* que);
int queue_int_get_size(Queue_int* que);
void queue_int_destroy(Queue_int* que);
Queue_int *new_queue_int();

void queue_pair_push(Queue_pair* que, Pair object);
void queue_pair_pop(Queue_pair* que);
void queue_pair_clear(Queue_pair* que);
Pair queue_pair_at(Queue_pair* que, int index);
Pair queue_pair_front(Queue_pair* que);
int queue_pair_get_size(Queue_pair* que);
void queue_pair_destroy(Queue_pair* que);
Queue_pair *new_queue_pair();
//-----------------------------------------------------------------------------------



//-----------------------------------------------------------------------------------
// min / max
int min(int x, int y);
int max(int x, int y);
//-----------------------------------------------------------------------------------


//-----------------------------------------------------------------------------------
// random
// get a random number in [l, r)
int get_rand(int l, int r);
//-----------------------------------------------------------------------------------

#endif // UTILITY_H_INCLUDED
