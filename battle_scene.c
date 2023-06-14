#include "battle_scene.h"

player me, enemy;
int player_damage = 0, enemy_damage = 0;
double cut_scene_timer = 0;
char damage_info[100];
char tmp[100];
enum BattleState state = PlayerTurn;

void battle_scene_update(double delta_time){
   if(state == CutScene){
        cut_scene_timer += delta_time;
        //printf("cut scene timer: %lf\n", cut_scene_timer);
   }
}

void calculate_damage(){
    if(me.type == enemy.type)
        player_damage = enemy_damage = 2;
    else if(me.type == CASTER){
        if(enemy.type == RIDER)
            player_damage = 5, enemy_damage = 0;
        else
            player_damage = 0, enemy_damage = 5;
    }
    else if(me.type == ASSASSIN){
        if(enemy.type == CASTER)
            player_damage = 5, enemy_damage = 0;
        else
            player_damage = 0, enemy_damage = 5;
    }
    else if(me.type == RIDER){
        if(enemy.type == ASSASSIN)
            player_damage = 5, enemy_damage = 0;
        else
            player_damage = 0, enemy_damage = 5;
    }
}

void battle_scene_process(ALLEGRO_EVENT event){
    if(state == PlayerTurn){
        if(event.type == ALLEGRO_EVENT_KEY_UP){
            bool player_turn_end = true;
            switch(event.keyboard.keycode){
                case ALLEGRO_KEY_Q:
                    me.type = CASTER;
                    break;
                case ALLEGRO_KEY_W:
                    me.type = ASSASSIN;
                    break;
                case ALLEGRO_KEY_E:
                    me.type = RIDER;
                    break;
                default:
                    player_turn_end = false;
                    break;
            }
            if(player_turn_end){
                state = EnemyTurn;
                puts("enemy turn");
            }
        }
    }
    else if(state == EnemyTurn) {
        enemy.type = get_rand(0, 3);
        calculate_damage();
        state = CutScene;
        sprintf(damage_info, "Player damage: %d, Enemy damage: %d", player_damage, enemy_damage);
        puts("cut scene");
    }
    else if(state == CutScene){
        if(cut_scene_timer >= 1.0){
            me.hp -= player_damage;
            enemy.hp -= enemy_damage;
            if(me.hp <= 0)
                state = PlayerLose;
            else if(enemy.hp <= 0)
                state = PlayerWin;
            else
                state = PlayerTurn;
            cut_scene_timer = 0;
        }
    }
    else if(state == PlayerWin || state == PlayerLose) {
        if (event.type == ALLEGRO_EVENT_KEY_DOWN) {
            if(event.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
                next_window = 1;
        }
    }
}

void battle_scene_init(){
    puts("init battle scene ing...");
    // initialize font
    font = al_load_ttf_font("./font/pirulen.ttf",16,0);
    // initialize background
    me.hp = 10;
    enemy.hp = 10;
    state = PlayerTurn;
    puts("battle scene init");
    puts("player turn");
}

void battle_scene_draw(){
    // draw map
    for(int i = 0; i < 13; i++){
        for (int j = 0; j < 25; j++){
            if(mapString[i][j] == '0')
                al_draw_bitmap(floorBackground, j * 64, i * 64, 0);
            else
                al_draw_bitmap(dirtBackground, j * 64, i * 64, 0);
        }
    }
    al_draw_filled_rectangle(0, 0, WIDTH, HEIGHT, al_map_rgba(0, 0, 0, 120));
    // load info
    sprintf(tmp, "Player HP: %d     Enemy HP: %d", me.hp, enemy.hp);
    al_draw_text(font, al_map_rgb(255, 255, 255),  WIDTH / 2, 20, ALLEGRO_ALIGN_CENTER, tmp);
    if(state == CutScene){
        al_draw_text(font, al_map_rgb(255, 255, 255), WIDTH / 2, HEIGHT / 4, ALLEGRO_ALIGN_CENTER, damage_info);
    }
    if(state == PlayerTurn){
        al_draw_text(font, al_map_rgb(255, 255, 255),  WIDTH / 2, HEIGHT / 4 + HEIGHT / 2, ALLEGRO_ALIGN_CENTER, "Choose your type");
    }
    if(state == PlayerWin){
        al_draw_text(font, al_map_rgb(255, 255, 255),  WIDTH / 2,  HEIGHT / 2, ALLEGRO_ALIGN_CENTER, "You win!");
        al_draw_text(font, al_map_rgb(255, 255, 255),  WIDTH / 2,  HEIGHT / 2 + 20, ALLEGRO_ALIGN_CENTER, "Press ESC to quit");
    }
    if(state == PlayerLose){
        al_draw_text(font, al_map_rgb(255, 255, 255),  WIDTH / 2,  HEIGHT / 2, ALLEGRO_ALIGN_CENTER, "You lose!");
        al_draw_text(font, al_map_rgb(255, 255, 255),  WIDTH / 2,  HEIGHT / 2 + 20, ALLEGRO_ALIGN_CENTER, "Press ESC to quit");
    }
}

void battle_scene_destroy(){

}