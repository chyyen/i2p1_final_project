#include "global.h"
#include "game_scene.h"
#include "menu_scene.h"
#include "battle_scene.h"

int Game_establish();
void game_init();
void game_begin();
void update(double delta_time);
int process_event();
void game_draw();
int game_run();
void game_destroy();
