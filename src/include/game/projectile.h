#ifndef _IN_GAME_GAME_096360_H
#define _IN_GAME_GAME_096360_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void mtx_load_random_rotation(Mtxf *mtx);
void projectile_load_random_speed_rotation(struct coord *arg0, Mtxf *mtx);
void projectile_update_fall(f32 *arg0, f32 *arg1, f32 arg2);
void projectile_update_matrix(Mtxf *arg0, Mtxf *arg1, s32 count);

#endif
