#ifndef BUTTON_H_INCLUDED
#define BUTTON_H_INCLUDED

#include "global.h"

typedef struct _button {
    int x, y, w, h;
    bool display;
    void (*OnClickCallback)(struct _button*);
    void (*Draw)(struct _button*);
    void (*InitButton)(struct _button*);
    void (*DestroyButton)(struct _button*);
} Button;

Button* newButton(int x, int y, int w, int h,
                  void (*OnClickCallback)(Button*), void (*InitButton)(Button*), void (*DestroyButton)(Button*), void (*Draw)(Button*));
void ButtonOnClick(Button* button);
void ButtonInit(Button* button);
void ButtonDestroy(Button* button);
void DrawButton(Button* button);
bool mouseInButton(Button* button, int x, int y);

#endif
