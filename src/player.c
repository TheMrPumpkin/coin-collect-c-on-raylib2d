#include "raylib.h"
#include "player.h"

void player_update(Player *player)
{

    if (IsKeyDown(KEY_UP))
    {
        player->box.y -= 15;
    }

    if (IsKeyDown(KEY_DOWN))
    {
        player->box.y += 15;
    }

    if (IsKeyDown(KEY_RIGHT))
    {
        player->box.x += 15;
    }

    if (IsKeyDown(KEY_LEFT))
    {
        player->box.x -= 15;
    }
    if (player->box.x < 0)
    {
        player->box.x = 0;
    }
    if (player->box.y < 0)
    {
        player->box.y = 0;
    }
    if (player->box.x > 5000)
    {
        player->box.x = 5000 - player->box.width;
    }
    if (player->box.y > 5000)
    {
        player->box.y = 5000 - player->box.height;
    }
}

void player_render(Player *player)
{
    DrawRectangleRec(player->box, ORANGE);
}