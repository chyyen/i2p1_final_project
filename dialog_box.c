#include "dialog_box.h"

struct _dialog_box dialog_box;

void draw_dialog_box(){
    char *s = (char*)vector_at(dialog_box.current_loading_dialog, 0);
    assert(s != NULL);
    al_draw_filled_rounded_rectangle(100, 500, 1500, 800, 25, 25, al_map_rgba(0, 0, 0, 180));
    al_draw_text(font, al_map_rgb(255, 255, 255), 150, 550, ALLEGRO_ALIGN_LEFT, s);
}

void init_dialog_box(){
    dialog_box.display = false;
    dialog_box.index = 0;
    dialog_box.len = 0;
    dialog_box.dialog = new_vector();
    dialog_box.current_loading_dialog = new_vector();
}

void load_next_dialog(){
    int *idx = &dialog_box.index;
    if(*idx >= dialog_box.len){
        dialog_box.display = false;
        return;
    }
    vector_clear(dialog_box.current_loading_dialog);
    char *c = dialog_box.buffer;
    for(;*idx < dialog_box.len; (*idx)++){
        *c = *(char*)vector_at(dialog_box.dialog, *idx);
        if(*c == '\n'){
            (*idx)++;
            break;
        }
        vector_push_back(dialog_box.current_loading_dialog, (void*)c);
        c++;
    }
    *c = '\0';
    vector_push_back(dialog_box.current_loading_dialog, (void*)c);
}

void assign_dialog_box(FILE *file){
    dialog_box.buffer = (char*)malloc(sizeof(char) * 100);
    dialog_box.display = true;
    dialog_box.index = 0;
    dialog_box.len = 0;
    char *c = dialog_box.buffer;
    while((*c = fgetc(file)) != EOF) {
        vector_push_back(dialog_box.dialog, (void*)c);
        dialog_box.len++;
        c++;
    }
    *c = '\0';
    vector_push_back(dialog_box.dialog, (void*)c);
    printf("%s\n", (char*)vector_at(dialog_box.dialog, 0));
    load_next_dialog();
}
