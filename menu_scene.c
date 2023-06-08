#include "menu_scene.h"

vector* menu_buttons;


void menu_init(){
    menu_buttons = newVector();
    Button *start_button = newButton(WIDTH / 2, HEIGHT / 2, 300, 60, menu_start_button_on_click, menu_start_button_init, menu_start_button_destroy, menu_start_button_draw);
    start_button->display = true;
    vector_push_back(menu_buttons, start_button);
    font = al_load_ttf_font("./font/pirulen.ttf",24,0);
}
void menu_process(ALLEGRO_EVENT event){
    if( event.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP ){
        int sz = menu_buttons->size;
        for(int i = 0; i < sz; i++)
            if(((Button*)menu_buttons->objects[i])->display == true && mouseInButton((Button*)menu_buttons->objects[i], event.mouse.x, event.mouse.y))
                ButtonOnClick((Button*)menu_buttons->objects[i]);
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