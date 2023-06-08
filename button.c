#include "button.h"
#include <stdlib.h>

Button* newButton(int x, int y, int w, int h,
                  void (*OnClickCallback)(Button*), void (*InitButton)(Button*), void (*DestroyButton)(Button*), void (*Draw)(Button*)) {
    Button *button = malloc(sizeof(Button));
    button->x = x;
    button->y = y;
    button->w = w;
    button->h = h;
    button->display = false;
    button->OnClickCallback = OnClickCallback;
    button->InitButton = InitButton;
    button->DestroyButton = DestroyButton;
    button->Draw = Draw;
    return button;
}

void ButtonOnClick(Button* button) {
    button->OnClickCallback(button);
}

void ButtonInit(Button* button) {
    button->InitButton(button);
}

void ButtonDestroy(Button* button) {
    button->DestroyButton(button);
}

void DrawButton(Button* button) {
    button->Draw(button);
}

bool mouseInButton(Button *button, int x, int y){
    return (x >= button->x - button->w / 2 && x <= button->x + button->w / 2 && y >= button->y - button->h / 2 && y <= button->y + button->h / 2);
}