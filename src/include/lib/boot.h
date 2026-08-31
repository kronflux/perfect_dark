#ifndef _IN_LIB_BOOT_H
#define _IN_LIB_BOOT_H
#include <ultra64.h>

/* osGetMemSize is declared in PR/os_system.h. The decomp declares it here
 * instead, split s32/u32 by VERSION for matching; the host build has a single
 * u32 implementation in port/src/libultra.c, so the split is omitted. */

void boot(void);
s32 boot_get_mem_size(void);
void *boot_allocate_stack(s32 threadid, s32 size);
void boot_create_threads(void *arg);
void boot_check_stack_overflow(void);

#endif
