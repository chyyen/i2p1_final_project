#include "global.h"

// variables for global usage
const float FPS = 60.0;
const int WIDTH = 1600;
const int HEIGHT = 960;
ALLEGRO_EVENT_QUEUE *event_queue = NULL;
ALLEGRO_TIMER *fps = NULL;
bool key_state[ALLEGRO_KEY_MAX] = {false};
bool judge_next_window = false;
ALLEGRO_FONT *font = NULL;
ALLEGRO_BITMAP *floorBackground = NULL;
ALLEGRO_BITMAP *dirtBackground = NULL;
FILE *fp = NULL;
char mapString[30];