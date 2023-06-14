#ifndef BATTLE_SCENE_H_INCLUDED
#define BATTLE_SCENE_H_INCLUDED

#include "global.h"

enum BattleState{
    CutScene,
    PlayerTurn,
    EnemyTurn,
    PlayerWin,
    PlayerLose
};

enum ATTACK_TYPE{
    CASTER,
    ASSASSIN,
    RIDER
};

typedef struct _player{
    int hp;
    int atk;
    int def;
    enum ATTACK_TYPE type;
}player;

extern enum BattleState state;
extern int player_damage, enemy_damage;
extern double cut_scene_timer;
extern char damage_info[100];

void battle_scene_update(double delta_time);
void calculate_damage();
void battle_scene_process(ALLEGRO_EVENT event);
void battle_scene_init();
void battle_scene_draw();
void battle_scene_destroy();

#endif // BATTLE_SCENE_H_INCLUDED
