#include "game_scene.h"

Vector *buttons;
Button *dialogButton;

void game_update(){
    character_update();
}

void game_process(ALLEGRO_EVENT event){
    if(event.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
        if(event.mouse.button == 1){
            if(dialog_box.display == true)
                ButtonOnClick(dialogButton);
            else
                set_destination(event.mouse.x, event.mouse.y);
        }
    }
    character_process(event);
}

void game_scene_init(){
    puts("init ing...");
    // initialize font
    font = al_load_ttf_font("./font/pirulen.ttf",16,0);
    // initialize background
    floorBackground = al_load_bitmap("./image/floor.png");
    dirtBackground = al_load_bitmap("./image/dirt.png");
    // initialize character
    character_init();
    // initialize dialog box
    init_dialog_box();
    fp = fopen("dialogs/dialog1.txt", "r");
    assign_dialog_box(fp);
    fclose(fp);
    puts("dialog box init");
    // initialize buttons
    dialogButton = newButton(1400, 700, 50, 50, dialog_button_on_click, dialog_button_init, dialog_button_destroy, dialog_button_draw);
    buttons = new_vector();
    dialog_button_init(dialogButton);
    vector_push_back(buttons, (void*)dialogButton);
    puts("game scene init");
}

void game_scene_draw(){
    fp = fopen("maps/map1.txt", "r");
    // draw map
    int j = 0;
    while(fgets(mapString, 30, fp) != NULL) {
        for (int i = 0; i < 25; i++){
            if(mapString[i] == '0')
                al_draw_bitmap(floorBackground, i * 64, j * 64, 0);
            else
                al_draw_bitmap(dirtBackground, i * 64, j * 64, 0);
            char temp[10];
            sprintf(temp, "(%d,%d)", i, j);
            al_draw_text(font, al_map_rgb(0,0,0), i * 64 + 32, j * 64 + 24 , ALLEGRO_ALIGN_CENTRE, temp);
        }
        j++;
    }

    if(get_character_state() == MOVE){
        al_draw_rectangle(destX * 64, destY * 64, destX * 64 + 64, destY * 64 + 64, al_map_rgb(0, 0, 0), 3);
    }
    fclose(fp);
    // draw character
    character_draw();
    // draw dialog box
    if(dialog_box.display == true)
        draw_dialog_box();
    dialogButton->display = dialog_box.display;
    // draw buttons
    for(int i = 0; i < buttons->size; i++){
        Button *button = (Button*)vector_at(buttons, i);
        if(button->display == true)
            DrawButton(button);
    }
}
void game_scene_destroy(){
    al_destroy_bitmap(floorBackground);
    character_destroy();
}
