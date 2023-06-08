#include "game_scene.h"

void game_update(){
    character_update();
}

void game_process(ALLEGRO_EVENT event){
    if(event.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
        if(event.mouse.button == 1){
            set_destination(event.mouse.x, event.mouse.y);
        }
    }
    character_process(event);
}

void game_scene_init(){
    character_init();
    font = al_load_ttf_font("./font/pirulen.ttf",12,0);
    floorBackground = al_load_bitmap("./image/floor.png");
    dirtBackground = al_load_bitmap("./image/dirt.png");
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

    character_draw();
    fclose(fp);
}
void game_scene_destroy(){
    al_destroy_bitmap(floorBackground);
    character_destroy();
}
