#include "dialog_box.h"

struct _dialog_box dialog_box;

void draw_dialog_box(){
    al_draw_filled_rounded_rectangle(100, 500, 1500, 800, 25, 25, al_map_rgba(0, 0, 0, 180));
    al_draw_text(font, al_map_rgb(255, 255, 255), 150, 550, ALLEGRO_ALIGN_LEFT, dialog_box.current_loading_dialog);
}

void init_dialog_box(){
    dialog_box.display = false;
    dialog_box.index = 0;
    dialog_box.len = 0;
}

void load_next_dialog(){
    int *idx = &dialog_box.index;
    if(*idx >= dialog_box.len){
        dialog_box.display = false;
        return;
    }
    int idx2 = 0;
    for(;*idx < dialog_box.len; (*idx)++){
        if(dialog_box.dialog[*idx] == '\n'){
            (*idx)++;
            break;
        }
        dialog_box.current_loading_dialog[idx2++] = dialog_box.dialog[*idx];
    }
    dialog_box.current_loading_dialog[idx2] = '\0';
}

void assign_dialog_box(FILE *file){
    dialog_box.display = true;
    dialog_box.index = 0;
    dialog_box.len = 0;
    char c;
    while((c = fgetc(file)) != EOF){
        dialog_box.dialog[dialog_box.len++] = c;
    }
    dialog_box.dialog[dialog_box.len] = '\0';
    load_next_dialog();
}
