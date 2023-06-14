#include "battle_type_button.h"
#include "battle_scene.h"

// caster part
void caster_type_button_on_click(Button* button) { me.class = CASTER; }
void caster_type_button_init(Button* button) { button->display = true; }
void caster_type_button_destroy(Button* button) {}
void caster_type_button_draw(Button* button) { al_draw_bitmap(button->image, button->x - button->w / 2, button->y - button->h / 2, 0); }
// assassin part
void assassin_type_button_on_click(Button* button) { me.class = ASSASSIN; }
void assassin_type_button_init(Button* button) { button->display = true; }
void assassin_type_button_destroy(Button* button) {}
void assassin_type_button_draw(Button* button) { al_draw_bitmap(button->image, button->x - button->w / 2, button->y - button->h / 2, 0); }
// rider part
void rider_type_button_on_click(Button* button) { me.class = RIDER; }
void rider_type_button_init(Button* button) { button->display = true; }
void rider_type_button_destroy(Button* button) {}
void rider_type_button_draw(Button* button) { al_draw_bitmap(button->image, button->x - button->w / 2, button->y - button->h / 2, 0); }
// shield part
void shield_type_button_on_click(Button* button) { me.class = SHIELD; }
void shield_type_button_init(Button* button) { button->display = true; }
void shield_type_button_destroy(Button* button) {}
void shield_type_button_draw(Button* button) { al_draw_bitmap(button->image, button->x - button->w / 2, button->y - button->h / 2, 0); }