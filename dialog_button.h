#ifndef DIALOG_BUTTON_H_INCLUDED
#define DIALOG_BUTTON_H_INCLUDED

#include "global.h"
#include "button.h"
#include "dialog_box.h"

void dialog_button_init(Button* button);
void dialog_button_draw(Button* button);
void dialog_button_on_click(Button* button);
void dialog_button_destroy(Button* button);

#endif // DIALOG_BUTTON_H_INCLUDED
