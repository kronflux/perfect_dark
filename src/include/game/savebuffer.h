#ifndef IN_GAME_SAVEBUFFER_H
#define IN_GAME_SAVEBUFFER_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void ortho_configure_full_mtx(Mtxf *mtx);
void ortho_configure_mtx(Mtxf *mtx);
Gfx *ortho_begin(Gfx *gdl);
Gfx *ortho_end(Gfx *gdl);
Gfx *ortho_holoray_begin(Gfx *gdl, s32 arg1);
Gfx *ortho_holoray_end(Gfx *gdl);
Gfx *menugfx_draw_plane(Gfx *gdl, s32 x1, s32 y1, s32 x2, s32 y2, u32 colour1, u32 colour2, s32 type);
void savebuffer_or(struct savebuffer *buffer, u64 arg1, s32 arg2);
void savebuffer_write_bits(struct savebuffer *buffer, u64 value, s32 numbits, u8 *dst);
u64 savebuffer_read_bits(struct savebuffer *buffer, s32 offset);
void savebuffer_clear(struct savebuffer *buffer);
void savebufferWriteData(struct savebuffer *buffer, u8 *data, u8 len);
void savebufferReadString_ext(struct savebuffer *buffer, char *dst, bool addlinebreak, u8 len);
void savebuffer_read_string(struct savebuffer *buffer, char *dst, bool addlinebreak);
void savebufferWriteString_ext(struct savebuffer *buffer, char *src, u8 len);
void savebufferWriteString(struct savebuffer *buffer, char *src);
void func0f0d564c_ext(u8 *data, char *dst, bool addlinebreak, u8 len);
void savebuffer_bitstring_to_cstring(u8 *data, char *dst, bool addlinebreak);
void savebuffer_cstring_to_bitstring(u8 *dst, char *buffer);
void savebuffer_write_guid(struct savebuffer *buffer, struct fileguid *guid);
void savebuffer_read_guid(struct savebuffer *buffer, struct fileguid *guid);
void format_time(char *dst, s32 time60, s32 precision);
void ortho_reset(void);

#endif
