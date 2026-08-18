#include "raylib.h"
#include <math.h>
#include <time.h>
#include <stdlib.h>

void draw_grid(int step) {
    int width = GetScreenWidth();
    int height = GetScreenHeight();

    for (int y = 0; y < height; y += step) {
        DrawLine(0, y, width, y, GRAY);
    }

    for (int x = 0; x < width; x += step) {
        DrawLine(x, 0, x, height, GRAY);
    }
}
