#include "battle_scene.h"
#include "button.h"
#include "battle_type_button.h"

player me, enemy;
int player_damage = 0, enemy_damage = 0;
double cut_scene_timer = 0;
char damage_info[100];
char tmp[100];
enum BattleState state = PlayerTurn;

Vector_pointer *battle_buttons;
Button *caster_button, *assassin_button, *rider_button, *shield_button;

void battle_scene_update(double delta_time){
   if(state == CutScene){
        cut_scene_timer += delta_time;
        //printf("cut scene timer: %lf\n", cut_scene_timer);
   }
}

void calculate_damage(){
    if(me.class == enemy.class) {
        player_damage = enemy_damage = (me.class == SHIELD ? 0 : 2);
    }
    else if(me.class == SHIELD){
        player_damage = 1;
        enemy_damage = 0;
    }
    else if(me.class == CASTER){
        if(enemy.class == RIDER)
            player_damage = 5, enemy_damage = 0;
        else
            player_damage = 0, enemy_damage = 5;
    }
    else if(me.class == ASSASSIN){
        if(enemy.class == CASTER)
            player_damage = 5, enemy_damage = 0;
        else
            player_damage = 0, enemy_damage = 5;
    }
    else if(me.class == RIDER){
        if(enemy.class == ASSASSIN)
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
                    me.class = CASTER;
                    break;
                case ALLEGRO_KEY_W:
                    me.class = ASSASSIN;
                    break;
                case ALLEGRO_KEY_E:
                    me.class = RIDER;
                    break;
                default:
                    player_turn_end = false;
                    break;
            }
            if(player_turn_end){
                state = EnemyTurn;
            }
        }
        else if(event.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
            for(int i = 0; i < battle_buttons->size; i++) {
                Button *button = battle_buttons->objects[i];
                if (button->display == true && mouseInButton(button, event.mouse.x, event.mouse.y)) {
                    ButtonOnClick(button);
                    break;
                }
            }
            state = EnemyTurn;
        }
    }
    else if(state == EnemyTurn) {
        enemy.class = get_rand(0, 4);
        calculate_damage();
        state = CutScene;
        sprintf(damage_info, "Player damage: %d, Enemy damage: %d", player_damage, enemy_damage);
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
    // initialize button
    caster_button = newButton(250, 85, 100, 100, al_load_bitmap("./image/caster.png"), caster_type_button_on_click, caster_type_button_init, caster_type_button_destroy, caster_type_button_draw);
    assassin_button = newButton(250, 85 + 170, 100, 100, al_load_bitmap("image/assassin.png"), assassin_type_button_on_click, assassin_type_button_init, assassin_type_button_destroy, assassin_type_button_draw);
    rider_button = newButton(250, 85 + 2 * 170, 100, 100, al_load_bitmap("image/rider.png"), rider_type_button_on_click, rider_type_button_init, rider_type_button_destroy, rider_type_button_draw);
    shield_button = newButton(250, 85 + 3 * 170, 100, 100, al_load_bitmap("image/shield.png"), shield_type_button_on_click, shield_type_button_init, shield_type_button_destroy, shield_type_button_draw);
    ButtonInit(caster_button);
    ButtonInit(assassin_button);
    ButtonInit(rider_button);
    ButtonInit(shield_button);
    battle_buttons = new_vector_pointer();
    vector_pointer_push_back(battle_buttons, (void*)caster_button);
    vector_pointer_push_back(battle_buttons, (void*)assassin_button);
    vector_pointer_push_back(battle_buttons, (void*)rider_button);
    vector_pointer_push_back(battle_buttons, (void*)shield_button);
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
    for(int i = 0; i < battle_buttons->size; i++) {
        Button *button = battle_buttons->objects[i];
        if (button->display == true) {
            DrawButton(button);
        }
    }
    // load info
    sprintf(tmp, "Player HP: %d     Enemy HP: %d", me.hp, enemy.hp);
    al_draw_text(font, al_map_rgb(255, 255, 255),  WIDTH / 2, 20, ALLEGRO_ALIGN_CENTER, tmp);
    if(state == CutScene){
        al_draw_text(font, al_map_rgb(255, 255, 255), WIDTH / 2, HEIGHT / 4, ALLEGRO_ALIGN_CENTER, damage_info);
    }
    if(state == PlayerTurn){
        al_draw_text(font, al_map_rgb(255, 255, 255),  WIDTH / 2, HEIGHT / 4 + HEIGHT / 2, ALLEGRO_ALIGN_CENTER, "Choose your class");
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