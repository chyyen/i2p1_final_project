#include "dialog_button.h"

void dialog_button_on_click(Button* button) {
    load_next_dialog();
}

void dialog_button_init(Button* button) {
    button->display = true;
}

void dialog_button_destroy(Button* button) {
}

void dialog_button_draw(Button* button) {
    al_draw_filled_triangle(1450, 725, 1406.7, 700, 1406.7, 750, al_map_rgb(255, 255, 255));
}