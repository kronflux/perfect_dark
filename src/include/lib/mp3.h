#ifndef _IN_LIB_MP3_H
#define _IN_LIB_MP3_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void mp3_init(ALHeap *heap);
void mp3_play_file(uintptr_t romaddr, s32 filesize);
void mp3_stop(void);
void mp3_pause(void);
void mp3_unpause(void);
s32 mp3_is_busy(void);
void mp3_set_vol(s32 arg0, bool arg1);
void mp3_set_pan(s32 arg0, bool arg1);
s32 mp3_make_samples(s32 arg0, Acmd **cmd);
void mp3_update_vars(struct mp3vars *vars);
void mp3_set_dma_func(void *fn);
void mp3_dma(void);

#endif
