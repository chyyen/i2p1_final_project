#include "global.h"
#include "button.h"
#include "menu_start_button.h"
#include "utility.h"

void menu_init();
void menu_process(ALLEGRO_EVENT event);
void menu_draw();
void menu_destroy();

extern vector* menu_buttons;