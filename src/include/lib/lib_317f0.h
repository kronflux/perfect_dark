#ifndef _IN_LIB_LIB_317F0_H
#define _IN_LIB_LIB_317F0_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void func00033090(struct sndstate *handle);
void func00033100(struct sndstate *state);
u16 sndp_count_states(s16 *numfreeptr, s16 *numallocedptr);
void sndp_set_addref_callback(void *fn);
struct sndstate *func00033390(s32 arg0, ALSound *sound);
void sndp_set_removeref_callback(void *fn);
s32 sndp_get_state(struct sndstate *handle);
struct sndstate *func00033820(s32 arg0, s16 soundnum, u16 vol, ALPan pan, f32 pitch, u8 fxmix, u8 fxbus, struct sndstate **handleptr);
void sndp_stop_sound(struct sndstate *handle);
void func00033bc0(struct sndstate *handle);
void func00033db0(void);
void func00033dd8(void);
void sndp_post_event(struct sndstate *handle, s16 type, s32 data);
u16 func00033ec4(u8 index);
struct sndstate *sndp_get_head_state(void);
ALMicroTime sndp_get_curtime(void);
void func00033f44(u8 index, u16 volume);

#endif
