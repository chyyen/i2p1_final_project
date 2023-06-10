#include "character.h"

// the state of character
Character chara;
ALLEGRO_SAMPLE *sample = NULL;

int destX, destY;

void character_init(){
    // load character images
    for(int i = 1 ; i <= 2 ; i++){
        char temp[50];
        //sprintf( temp, "./image/char_move%d.png", i );
        chara.img_move[i-1] = al_load_bitmap("./image/milos.png");
    }
    for(int i = 1 ; i <= 2 ; i++){
        char temp[50];
        //sprintf( temp, "./image/char_atk%d.png", i );
        chara.img_atk[i-1] = al_load_bitmap("./image/milos.png");
    }
    // load effective sound
    sample = al_load_sample("./sound/atk_sound.wav");
    chara.atk_Sound  = al_create_sample_instance(sample);
    al_set_sample_instance_playmode(chara.atk_Sound, ALLEGRO_PLAYMODE_ONCE);
    al_attach_sample_instance_to_mixer(chara.atk_Sound, al_get_default_mixer());

    // initial the geometric information of character
    chara.width = al_get_bitmap_width(chara.img_move[0]);
    chara.height = al_get_bitmap_height(chara.img_move[0]);
    chara.x = WIDTH/2;
    chara.y = HEIGHT/2;
    chara.dir = false;
    destX = WIDTH / 128;
    destY = HEIGHT / 128;

    // initial the animation component
    chara.state = STOP;
    chara.anime = 0;
    chara.anime_time = 30;

}
void character_process(ALLEGRO_EVENT event){
    // process the animation
    if( event.type == ALLEGRO_EVENT_TIMER ){
        if( event.timer.source == fps ){
            chara.anime++;
            chara.anime %= chara.anime_time;
        }
    // process the keyboard event
    }else if( event.type == ALLEGRO_EVENT_KEY_DOWN ){
        key_state[event.keyboard.keycode] = true;
        chara.anime = 0;
    }else if( event.type == ALLEGRO_EVENT_KEY_UP ){
        key_state[event.keyboard.keycode] = false;
    }
}
void character_update(){
    int blockX = chara.x / 64, blockY = chara.y / 64;
    Pair nextStep = GetNextStep(blockX, blockY);
    if(chara.x != destX * 64 + 32 || chara.y != destY * 64 + 32){
        int direction_x = (nextStep.first - chara.x) / abs(nextStep.first - chara.x);
        int direction_y = (nextStep.second - chara.y) / abs(nextStep.second - chara.y);
        int length_x = min(5, (nextStep.first - chara.x) / direction_x);
        int length_y = min(5, (nextStep.second - chara.y) / direction_y);
        //if(get_rand(0, 2) == 1)
            move_character(direction_x * length_x, (length_x ? 0 : direction_y * length_y));
        //else
         //   move_character((length_y ? 0 : direction_x * length_x), direction_y * length_y);
        chara.state = MOVE;
    }
    else
        chara.state = STOP;
}
void character_draw(){
    al_draw_bitmap(chara.img_move[0], chara.x - chara.width / 2, chara.y - chara.height / 2, 0);
}

void move_character(int x, int y){
    chara.x += x;
    chara.y += y;
    chara.state = MOVE;
}

void character_destroy(){
    al_destroy_bitmap(chara.img_atk[0]);
    al_destroy_bitmap(chara.img_atk[1]);
    al_destroy_bitmap(chara.img_move[0]);
    al_destroy_bitmap(chara.img_move[1]);
    al_destroy_sample_instance(chara.atk_Sound);
}

void set_destination(int x, int y){
    destX = x / 64;
    destY = y / 64;
    int blockX = chara.x / 64, blockY = chara.y / 64;
    if(destX != blockX || destY != blockY){
        BFS(blockX, blockY, destX, destY);
    }
}

int get_character_state(){
    return chara.state;
}