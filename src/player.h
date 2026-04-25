#pragma once
#include "raylib.h"
typedef struct
{
    Rectangle box;
} Player;

void player_update(Player *player);
void player_render(Player *player);