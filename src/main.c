#include "raylib.h"
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include "grid.h"
#include "raylib.h"
#include <balls.h>

int main() {
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(1000, 600, "SandBox");
    SetTargetFPS(60);
    struct Cir *cir = ball_one_init();
    float g = 0.1f;
    while(!WindowShouldClose()) {
        
        
        BeginDrawing();
            draw_grid(15);
            ball_one_main(cir, g);
            ClearBackground(LIGHTGRAY);
            DrawText(TextFormat("FPS: %i", GetFPS()), 20, 20, 5, RED);
            show_one_ball_stats(cir);
        EndDrawing();
    }
    ball_one_clear(cir);
    CloseWindow();
    return 0;
}