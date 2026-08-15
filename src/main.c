#include "raylib.h"
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include "grid.h"
#include "raylib.h"


int main() {
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(400, 400, "PhysicSimulation");
    SetTargetFPS(60);
   
    while(!WindowShouldClose()) {
        
        
        BeginDrawing();
            draw_grid(20);
            ClearBackground(LIGHTGRAY);
            DrawText(TextFormat("FPS: %i", GetFPS()), 20, 20, 5, RED);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}