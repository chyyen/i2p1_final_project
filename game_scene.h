#include "character.h"
#include "global.h"
#include "dialog_button.h"
#include "dialog_box.h"

void game_update();
void game_process(ALLEGRO_EVENT event);
void game_scene_init();
void game_scene_draw();
void game_scene_destroy();

extern Vector *buttons;
extern Button *dialogButton;