//
// Ravine (MP)
//

#include "stagesetup.h"

extern s32 intro[];
extern u32 props[];
extern struct path paths[];
extern struct ailist ailists[];

struct stagesetup setup = {
	NULL,
	NULL,
	NULL,
	intro,
	props,
	paths,
	ailists,
	NULL,
};

u32 props[] = {
	lift(0x0100, MODEL_RAVINELIFT, PAD_AREC_00BC, OBJFLAG_00000008 | OBJFLAG_XTOPADBOUNDS | OBJFLAG_YTOPADBOUNDS | OBJFLAG_ZTOPADBOUNDS | OBJFLAG_IGNOREFLOORCOLOUR | OBJFLAG_INVINCIBLE | OBJFLAG_UNCOLLECTABLE | OBJFLAG_FORCENOBOUNCE | OBJFLAG_01000000 | OBJFLAG_CANNOT_ACTIVATE, OBJFLAG2_NOFALL | OBJFLAG2_FALLWITHOUTROTATION | OBJFLAG2_IMMUNETOGUNFIRE | OBJFLAG2_BULLETPROOF | OBJFLAG2_IMMUNETOEXPLOSIONS, 0, 1000, 0x00bc, 0x00bb, 0x00ba, -1, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000071c, 0x0010aaaa, 0x00000000)
	endprops
};

u8 unregistered_func1[] = {
	set_ailist(CHR_SELF, GAILIST_IDLE)
	endlist
};

u8 unregistered_func2[] = {
	set_ailist(CHR_SELF, GAILIST_IDLE)
	endlist
};

s32 intro[] = {
	endintro
};

struct path paths[] = {
	{ NULL, 0, 0 },
};

struct ailist ailists[] = {
	{ NULL, 0 },
};
