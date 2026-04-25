
#include <stdio.h>
#include "raylib.h"
#include "raymath.h"
#include "player.h"
#include "coin.h"

int main()
{

    const int ScreenWidth = 1280;
    const int ScreenHeight = 950;

    Player player = {.box = {.x = 0, .y = 0, .width = ScreenWidth / 8, .height = ScreenHeight / 8}};
    player.box.x = ScreenWidth / 2;
    player.box.y = ScreenHeight / 2;

    Coin coins[] = {
        {.box = {.x = 842, .y = 4215, .width = ScreenWidth / 10, .height = ScreenHeight / 10}, .show_it = true},
        {.box = {.x = 2103, .y = 157, .width = ScreenWidth / 10, .height = ScreenHeight / 10}, .show_it = true},
        {.box = {.x = 4891, .y = 3320, .width = ScreenWidth / 10, .height = ScreenHeight / 10}, .show_it = true},
        {.box = {.x = 1250, .y = 3750, .width = ScreenWidth / 10, .height = ScreenHeight / 10}, .show_it = true},
        {.box = {.x = 842, .y = 1250, .width = ScreenWidth / 10, .height = ScreenHeight / 10}, .show_it = true},
        {.box = {.x = 3750, .y = 1250, .width = ScreenWidth / 10, .height = ScreenHeight / 10}, .show_it = true},
        {.box = {.x = 1250, .y = 3750, .width = ScreenWidth / 10, .height = ScreenHeight / 10}, .show_it = true},
        {.box = {.x = 3750, .y = 3750, .width = ScreenWidth / 10, .height = ScreenHeight / 10}, .show_it = true},
        {.box = {.x = 2500, .y = 2700, .width = ScreenWidth / 10, .height = ScreenHeight / 10}, .show_it = true},
        {.box = {.x = 3000, .y = 2900, .width = ScreenWidth / 10, .height = ScreenHeight / 10}, .show_it = true},
        {.box = {.x = 1000, .y = 2340, .width = ScreenWidth / 10, .height = ScreenHeight / 10}, .show_it = true},
        {.box = {.x = 2500, .y = 1000, .width = ScreenWidth / 10, .height = ScreenHeight / 10}, .show_it = true}};

    Camera2D camera = {0};
    camera.target = (Vector2){player.box.x + 20.0f, player.box.y + 20.0f};
    camera.offset = (Vector2){ScreenWidth / 2.0f, ScreenHeight / 2.0f};
    camera.rotation = 0.0f;
    camera.zoom = 0.9f;
    int score = 0;
    float timer = 60.0f;
    bool is_running = true;

    InitWindow(ScreenWidth, ScreenHeight, "game");
    SetTargetFPS(60);

    while (!WindowShouldClose())

    {
        const int size = sizeof(coins) / sizeof(coins[0]);
        for (int i = 0; i < size; i++)
        {
            coin_update(&coins[i]);
            if (CheckCollisionRecs(player.box, coins[i].box) && coins[i].show_it)
            {
                printf("collision!\n");
                score++;
                coins[i].show_it = false;
            }
            else
            {
                printf("No collision\n");
            }
        }
        if (timer > 0) // גורם לשחקן לא לזוז
        {
            player_update(&player);
            is_running = false;
        }
        if (is_running)
        {
            player_update(&player);
        }

        camera.target = (Vector2){player.box.x + 20, player.box.y + 20};
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawFPS(10, 10);
        DrawText(TextFormat("Score %d", score), 10, 30, 20, BLACK);
        DrawText(TextFormat("timer %.2f", timer), 10, 50, 20, BLACK);

        BeginMode2D(camera);
        for (int i = 0; i < 5000; i += 100)
        {
            DrawLine(i, 0, i, 5000, LIGHTGRAY);
            DrawLine(0, i, 5000, i, LIGHTGRAY);
        }

        player_render(&player);
        for (int i = 0; i < size; i++)
        {
            coin_render(&coins[i]);
            // printf("player| x: %f y: %f\n", player.box.x, player.box.y);
            // printf("coin|  x: %f y: %f\n", coins[i].box.x, coins[i].box.y);
        }

        EndMode2D();

        if (timer > 0)
            timer -= GetFrameTime();
        if (timer <= 0)
        {
            DrawText(TextFormat("your score is %d", score), 360, 450, 100, BLACK);
            DrawText(TextFormat("time over!"), 360, 350, 100, BLACK);
        }
        else if (score == 12)
        {
            DrawText(TextFormat("your score is %d", score), 360, 450, 100, BLACK);
            DrawText(TextFormat("You win!"), 360, 350, 100, BLACK);
        }
        EndDrawing();
    }

    CloseWindow();
}
