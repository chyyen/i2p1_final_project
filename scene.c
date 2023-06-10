#include "scene.h"

ALLEGRO_FONT *font = NULL;
ALLEGRO_BITMAP *floorBackground = NULL;
ALLEGRO_BITMAP *dirtBackground = NULL;

char mapString[30];
FILE *fp = NULL;

// function of menu
void menu_init(){
    font = al_load_ttf_font("./font/pirulen.ttf",12,0);
}
void menu_process(ALLEGRO_EVENT event){
    if( event.type == ALLEGRO_EVENT_KEY_UP )
        if( event.keyboard.keycode == ALLEGRO_KEY_ENTER )
            judge_next_window = true;
}
void menu_draw(){
    al_clear_to_color(al_map_rgb(100,100,100));
    al_draw_text(font, al_map_rgb(255,255,255), WIDTH/2, HEIGHT/2+220 , ALLEGRO_ALIGN_CENTRE, "Press 'Enter' to start");
    al_draw_rectangle(WIDTH/2-150, 510, WIDTH/2+150, 550, al_map_rgb(255, 255, 255), 0);
}
void menu_destroy(){
    al_destroy_font(font);
}

// function of game_scene
void game_scene_init(){
    character_init();
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
        }
        j++;
    }
    character_draw();
    fclose(fp);
}
void game_scene_destroy(){
    al_destroy_bitmap(floorBackground);
    character_destroy();
}
