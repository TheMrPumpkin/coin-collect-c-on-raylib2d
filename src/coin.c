#include "raylib.h"
#include "coin.h"

void coin_update(Coin *coin)
{
}
void coin_render(Coin *coin)
{

    if (coin->show_it)
    {
        DrawRectangleRec(coin->box, RED);
    }
}