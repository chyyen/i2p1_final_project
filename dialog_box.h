#ifndef DIALOG_BOX_H_INCLUDED
#define DIALOG_BOX_H_INCLUDED

#include "global.h"

struct _dialog_box{
    bool display;
    int index;
    int len;
    char* buffer;
    Vector* dialog;
    Vector* current_loading_dialog;
};

extern struct _dialog_box dialog_box;

void draw_dialog_box();
void init_dialog_box();
void load_next_dialog();
void assign_dialog_box(FILE *file);

#endif // DIALOG_BOX_H_INCLUDED
