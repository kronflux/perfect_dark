#ifndef _IN_GAME_GAME_13C510_H
#define _IN_GAME_GAME_13C510_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void artifacts_clear(void);
void artifacts_tick(void);
u16 floatToN64Depth(f32 arg0);
s32 artifactsFloatToInt(f32 arg0);
void artifacts_calculate_glares_for_room(s32 roomnum);
u8 artifactsClamp(u8 arg0, u8 arg1);
Gfx *artifacts_configure_for_glares(Gfx *gdl);
Gfx *artifacts_unconfigure_for_glares(Gfx *gdl);
Gfx *artifacts_render_glares_for_room(Gfx *gdl, s32 roomnum);
#ifndef PLATFORM_N64
bool artifactTestLos(struct coord *spec, struct coord *roompos, s32 xi, s32 yi);
#endif

#endif
