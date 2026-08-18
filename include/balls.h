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
};
struct Cir *ball_many_init(int count_of_balls);
struct Cir *ball_one_init();
void ball_one_clear(struct Cir *cir);
void check_mouse_coll(struct Cir *c);
void def_phys(struct Cir *cir, float g);
void check_wall_coll(struct Cir *cir);
void check_keys(struct Cir *c);
void ball_one_main(struct Cir *cir, float g);
void show_one_ball_stats(struct Cir *cir);