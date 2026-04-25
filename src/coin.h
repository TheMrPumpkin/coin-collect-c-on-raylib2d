#pragma once
#define MAX_COINS 10
#include "raylib.h"

typedef struct
{
    Rectangle box;
    bool show_it;
} Coin;

void coin_update(Coin *coin);
void coin_render(Coin *coin);