#ifndef MENU_START_BUTTON_H_INCLUDED
#define MENU_START_BUTTON_H_INCLUDED

#include "button.h"
#include "global.h"

void menu_start_button_init(Button* button);
void menu_start_button_draw(Button* button);
void menu_start_button_on_click(Button* button);
void menu_start_button_destroy(Button* button);

#endif // MENU_START_BUTTON_H_INCLUDED
