#include "raylib.h"
#include <math.h>
#include <stdlib.h>
#include <time.h>
 
struct Cir {
    Vector2 vec;
    int rad;
    float velocity_y;
    float velocity_x;
    float bounce;
    float rubbing;
};

struct Cir *ball_many_init(int count_of_balls) {
    srand(time(NULL));
    struct Cir *arr = malloc(sizeof(struct Cir) * count_of_balls);
    for (int i = 0; i < count_of_balls;i++) {
        arr[i].vec.x = 400;
        arr[i].vec.y = 200;
        arr[i].rad = 10;
        arr[i].velocity_x = rand() % 50;
        arr[i].velocity_y = rand() % 50;
        arr[i].bounce = -0.5;
    }
    return arr;
}

struct Cir *ball_one_init() {
    srand(time(NULL));
    struct Cir *arr = malloc(sizeof(struct Cir));
    arr->vec.x = 400;
    arr->vec.y = 200;
    arr->rad = 10;
    arr->velocity_x = rand() % 50;
    arr->velocity_y = rand() % 50;
    arr->bounce = -0.5;
    arr->rubbing = 0.9;
    return arr;
}

void ball_one_clear(struct Cir *cir) {
    free(cir);
}

void check_mouse_coll(struct Cir *c) {
    int dx = c->vec.x - GetMouseX();
    int dy = c->vec.y - GetMouseY();

    if ((dx * dx) + (dy * dy) <= c->rad * c->rad) {
        c->velocity_y += -1.5;
    }
}

void def_phys(struct Cir *cir, float g) {
    cir->velocity_y += g;
    cir->vec.y += cir->velocity_y;
    cir->vec.x += cir->velocity_x;
}

void check_wall_coll(struct Cir *cir) {
    if ((cir->vec.y + cir->rad) >= GetScreenHeight() && (cir->velocity_y > 0)) {
        cir->vec.y = GetScreenHeight() - cir->rad;
        cir->velocity_y = cir->velocity_y * cir->bounce;
        cir->velocity_x *= cir->rubbing; 
    }

    if ((cir->vec.y - cir->rad) <= 0) {
        cir->vec.y = 0 + cir->rad;
        cir->velocity_y = cir->velocity_y * cir->bounce;
    }

    if ((cir->vec.x + cir->rad) >= GetScreenWidth() && (cir->velocity_x > 0)) {
        cir->vec.x = GetScreenWidth() - cir->rad;
        cir->velocity_x = cir->velocity_x * cir->bounce;
    }

    if ((cir->vec.x - cir->rad) <= 0) {
        cir->vec.x = 0 + cir->rad;
        cir->velocity_x = cir->velocity_x * cir->bounce;
    }

}

void check_keys(struct Cir *c) {
    if (IsKeyDown(KEY_W)) {
        c->velocity_y += -0.5;
    }
    if (IsKeyDown(KEY_S)) {
        c->velocity_y += 0.5;
    }
    if (IsKeyDown(KEY_A)) {
        c->velocity_x += -0.5;
    }
    if (IsKeyDown(KEY_D)) {
        c->velocity_x += 0.5;
    }

    if (IsKeyDown(KEY_SPACE)) {
        c->vec.x = 400;
        c->vec.y = 200;
    }
}


void ball_one_main(struct Cir *cir, float g) {
    check_keys(cir);
    check_mouse_coll(cir);
    def_phys(cir, g);
    check_wall_coll(cir);
    DrawCircle(cir->vec.x, cir->vec.y, cir->rad, BLACK);
}

void show_one_ball_stats(struct Cir *cir) {
    DrawText(TextFormat("x: %1.f", cir->vec.x), 20, 30, 15, RED);
    DrawText(TextFormat("y: %1.f", cir->vec.y), 70, 30, 15, RED);
    DrawText(TextFormat("x speed: %1.f", cir->velocity_x), 10, 60, 15, RED);
    DrawText(TextFormat("y speed: %1.f", cir->velocity_y), 100, 60, 15, RED);
}