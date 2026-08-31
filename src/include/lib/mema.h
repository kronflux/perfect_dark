#ifndef _IN_LIB_MEMA_H
#define _IN_LIB_MEMA_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void mema_defrag(void);
void mema_init(void);
void mema_reset(void *ptr, u64 size);
void mema_print(void);
void *mema_alloc(u64 size);
uintptr_t mema_grow(uintptr_t addr, u64 amount);
void _memaFree(uintptr_t addr, u64 size);
void mema_free(void *addr, u64 size);
u64 mema_get_longest_free(void);
bool mema_realloc(uintptr_t addr, u64 oldsize, u64 newsize);

#endif
