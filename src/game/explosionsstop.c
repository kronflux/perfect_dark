#include <ultra64.h>
#include "constants.h"
#include "game/prop.h"
#include "bss.h"
#include "lib/vi.h"
#include "data.h"
#include "types.h"

void explosions_stop(void)
{
	s32 i;

	g_ExplosionShakeTotalTimer = 0;
	vi_shake(0);

	if (g_Explosions) {
		for (i = 0; i < g_MaxExplosions; i++) {
			if (g_Explosions[i].prop) {
				prop_delist(g_Explosions[i].prop);
				prop_disable(g_Explosions[i].prop);
				prop_free(g_Explosions[i].prop);

				g_Explosions[i].prop = NULL;
			}
		}
	}
}
