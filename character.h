#include "global.h"
#include "bfs.h"
#include "utility.h"
#include <math.h>

extern int destX;
extern int destY;

enum {STOP = 0, MOVE, ATK};
typedef struct character
{
    int x, y; // the position of image
    int width, height; // the width and height of image
    bool dir; // left: false, right: true
    int state; // the state of character
    ALLEGRO_BITMAP *img_move[2];
    ALLEGRO_BITMAP *img_atk[2];
    ALLEGRO_SAMPLE_INSTANCE *atk_Sound;
    int anime; // counting the time of animation
    int anime_time; // indicate how long the animation
}Character;
extern Character chara;

void character_init();
void character_process(ALLEGRO_EVENT event);
void character_update(double delta_time);
void character_draw();
void character_destroy();
void move_character(int dx, int dy);
void set_destination(int x, int y);
int get_character_state();
