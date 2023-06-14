#include "menu_scene.h"

Vector_pointer* menu_buttons;
Button* start_button;

void menu_init(){
    menu_buttons = new_vector_pointer();
    start_button = newButton(WIDTH / 2, HEIGHT / 2, 300, 100, NULL, menu_start_button_on_click, menu_start_button_init, menu_start_button_destroy, menu_start_button_draw);
    menu_start_button_init(start_button);
    vector_pointer_push_back(menu_buttons, start_button);
    font = al_load_ttf_font("./font/pirulen.ttf",24,0);
}
void menu_process(ALLEGRO_EVENT event){
    if( event.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP ){
        int sz = menu_buttons->size;
        for(int i = 0; i < sz; i++)
            if(((Button*)menu_buttons->objects[i])->display == true && mouseInButton((Button*)menu_buttons->objects[i], event.mouse.x, event.mouse.y))
                ButtonOnClick((Button*)menu_buttons->objects[i]);
    }
    if(event.type == ALLEGRO_EVENT_KEY_UP){
        if(event.keyboard.keycode == ALLEGRO_KEY_ENTER){
            next_window = 1;
            return;
        }
    }
}
void menu_draw(){
    al_clear_to_color(al_map_rgb(100,100,100));
    int sz = menu_buttons->size;
    for(int i = 0; i < sz; i++)
        if(((Button*)menu_buttons->objects[i])->display == true)
            DrawButton((Button*)menu_buttons->objects[i]);
}
void menu_destroy(){
    al_destroy_font(font);
}