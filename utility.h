#ifndef UTILITY_H_INCLUDED
#define UTILITY_H_INCLUDED

// pair
typedef struct _pair{
    int first;
    int second;
}pair;

pair make_pair(int x, int y);

// min / max
int min(int x, int y);
int max(int x, int y);
#endif // UTILITY_H_INCLUDED
