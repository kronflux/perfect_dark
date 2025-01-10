#ifndef _IN_LIB_BOOT_H
#define _IN_LIB_BOOT_H
#include <ultra64.h>

/* osGetMemSize is declared in PR/os_system.h. The decomp declares it here
 * instead, split s32/u32 by VERSION for matching; the host build has a single
 * u32 implementation in port/src/libultra.c, so the split is omitted. */

void boot(void);
s32 bootGetMemSize(void);
void *bootAllocateStack(s32 threadid, s32 size);
void bootCreateThreads(void *arg);
void bootCheckStackOverflow(void);

#endif
