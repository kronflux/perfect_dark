#include <ultra64.h>
#include "constants.h"
#include "bss.h"
#include "lib/dma.h"
#include "lib/memp.h"
#include "data.h"
#include "types.h"

void tex_init(void)
{
	extern u8 EXT_SEG _textureslistSegmentRomStart;
	extern u8 EXT_SEG _textureslistSegmentRomEnd;

	u32 len = ((REF_SEG _textureslistSegmentRomEnd - REF_SEG _textureslistSegmentRomStart) + 15) & -16;

	g_Textures = memp_alloc(len, MEMPOOL_PERMANENT);

	dma_exec(g_Textures, (romptr_t) REF_SEG _textureslistSegmentRomStart, len);
}
