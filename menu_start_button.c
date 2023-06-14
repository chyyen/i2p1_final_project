#include "menu_start_button.h"

void menu_start_button_on_click(Button* button) {
    next_window = 1;
}

void menu_start_button_init(Button* button) {
    button->display = true;
}

void menu_start_button_destroy(Button* button) {

}

void menu_start_button_draw(Button* button) {
    al_draw_rectangle(button->x - button->w / 2, button->y - button->h / 2, button->x + button->w / 2, button->y + button->h / 2, al_map_rgb(255, 255, 255), 0);
    al_draw_text(font, al_map_rgb(0, 0, 0), WIDTH / 2, HEIGHT / 2 - 18, ALLEGRO_ALIGN_CENTRE, "Start");
}