#include <stdlib.h>

#include <ultra64.h>
#include <PR/ultrasched.h>
#include "lib/sched.h"
#include "lib/vars.h"
#include "constants.h"
#include "game/camdraw.h"
#include "game/cheats.h"
#include "game/debug.h"
#include "game/file.h"
#include "game/lang.h"
#include "game/race.h"
#include "game/body.h"
#include "game/stubs/game_000840.h"
#include "game/stubs/game_000850.h"
#include "game/stubs/game_000860.h"
#include "game/stubs/game_000870.h"
#include "game/smoke.h"
#include "game/stubs/game_0008e0.h"
#include "game/stubs/game_0008f0.h"
#include "game/stubs/game_000900.h"
#include "game/stubs/game_000910.h"
#include "game/tex.h"
#include "game/stubs/game_00b180.h"
#include "game/stubs/game_00b200.h"
#include "game/challenge.h"
#include "game/title.h"
#include "game/pdmode.h"
#include "game/objectives.h"
#include "game/endscreen.h"
#include "game/playermgr.h"
#include "game/text.h"
#include "game/gfxmemory.h"
#include "game/lang.h"
#include "game/lv.h"
#include "game/timing.h"
#include "game/music.h"
#include "game/stubs/game_175f50.h"
#include "game/game_175f90.h"
#include "game/zbuf.h"
#include "game/game_1a78b0.h"
#include "game/mplayer/mplayer.h"
#include "game/pak.h"
#include "game/splat.h"
#include "game/utils.h"
#include "bss.h"
#include "lib/audiomgr.h"
#include "lib/args.h"
#include "lib/boot.h"
#include "lib/vm.h"
#include "lib/rzip.h"
#include "lib/vi.h"
#include "lib/fault.h"
#include "lib/crash.h"
#include "lib/dma.h"
#include "lib/joy.h"
#include "lib/main.h"
#include "lib/snd.h"
#include "lib/memp.h"
#include "lib/mema.h"
#include "lib/model.h"
#include "lib/profile.h"
#include "lib/videbug.h"
#include "lib/debughud.h"
#include "lib/anim.h"
#include "lib/rdp.h"
#include "lib/lib_34d0.h"
#include "lib/lib_2f490.h"
#include "lib/rmon.h"
#include "lib/rng.h"
#include "lib/str.h"
#include "data.h"
#include "types.h"
#include "system.h"

extern u8 *g_MempHeap;
extern u32 g_MempHeapSize;

void rng_set_seed(u32 seed);

bool var8005d9b0 = false;
s32 g_StageNum = STAGE_TITLE;
u32 g_MainMemaHeapSize = 1024 * 300;
bool var8005d9bc = false;
s32 var8005d9c0 = 0;
s32 var8005d9c4 = 0;
bool g_MainGameLogicEnabled = true;
u32 g_MainNumGfxTasks = 0;
bool g_MainIsEndscreen = false;
s32 g_DoBootPakMenu = 0;

u32 var8005dd3c = 0x00000000;
u32 var8005dd40 = 0x00000000;
u32 var8005dd44 = 0x00000000;
u32 var8005dd48 = 0x00000000;
u32 var8005dd4c = 0x00000000;
u32 var8005dd50 = 0x00000000;
s32 g_MainChangeToStageNum = -1;
bool g_MainIsDebugMenuOpen = false;

struct stageallocation g_StageAllocations8Mb[] = {
	{ STAGE_CITRAINING,    "-ml0 -me0 -mgfx120 -mvtx98 -ma400"             },
	{ STAGE_DEFECTION,     "-ml0 -me0 -mgfx110 -mgfxtra80 -mvtx100 -ma700" },
	{ STAGE_INVESTIGATION, "-ml0 -me0 -mgfx110 -mgfxtra80 -mvtx100 -ma700" },
	{ STAGE_EXTRACTION,    "-ml0 -me0 -mgfx110 -mgfxtra80 -mvtx100 -ma700" },
	{ STAGE_CHICAGO,       "-ml0 -me0 -mgfx110 -mgfxtra80 -mvtx100 -ma700" },
	{ STAGE_G5BUILDING,    "-ml0 -me0 -mgfx110 -mgfxtra80 -mvtx100 -ma700" },
	{ STAGE_VILLA,         "-ml0 -me0 -mgfx110 -mgfxtra80 -mvtx100 -ma600" },
	{ STAGE_INFILTRATION,  "-ml0 -me0 -mgfx110 -mgfxtra80 -mvtx100 -ma500" },
	{ STAGE_RESCUE,        "-ml0 -me0 -mgfx110 -mgfxtra80 -mvtx100 -ma500" },
	{ STAGE_ESCAPE,        "-ml0 -me0 -mgfx110 -mgfxtra80 -mvtx100 -ma500" },
	{ STAGE_AIRBASE,       "-ml0 -me0 -mgfx110 -mgfxtra80 -mvtx100 -ma700" },
	{ STAGE_AIRFORCEONE,   "-ml0 -me0 -mgfx110 -mgfxtra80 -mvtx100 -ma700" },
	{ STAGE_CRASHSITE,     "-ml0 -me0 -mgfx110 -mgfxtra80 -mvtx100 -ma700" },
	{ STAGE_PELAGIC,       "-ml0 -me0 -mgfx110 -mgfxtra80 -mvtx100 -ma700" },
	{ STAGE_DEEPSEA,       "-ml0 -me0 -mgfx110 -mgfxtra80 -mvtx100 -ma700" },
	{ STAGE_DEFENSE,       "-ml0 -me0 -mgfx110 -mgfxtra80 -mvtx100 -ma700" },
	{ STAGE_ATTACKSHIP,    "-ml0 -me0 -mgfx110 -mgfxtra80 -mvtx100 -ma700" },
	{ STAGE_SKEDARRUINS,   "-ml0 -me0 -mgfx110 -mgfxtra80 -mvtx100 -ma700" },
	{ STAGE_MP_SKEDAR,     "-ml0 -me0 -mgfx200 -mvtx200 -ma400"            },
	{ STAGE_MP_RAVINE,     "-ml0 -me0 -mgfx200 -mvtx200 -ma400"            },
	{ STAGE_MP_PIPES,      "-ml0 -me0 -mgfx200 -mvtx200 -ma400"            },
	{ STAGE_MP_G5BUILDING, "-ml0 -me0 -mgfx200 -mvtx200 -ma400"            },
	{ STAGE_MP_SEWERS,     "-ml0 -me0 -mgfx200 -mvtx200 -ma400"            },
	{ STAGE_MP_WAREHOUSE,  "-ml0 -me0 -mgfx200 -mvtx200 -ma400"            },
	{ STAGE_MP_BASE,       "-ml0 -me0 -mgfx200 -mvtx200 -ma400"            },
	{ STAGE_MP_COMPLEX,    "-ml0 -me0 -mgfx200 -mvtx200 -ma400"            },
	{ STAGE_MP_TEMPLE,     "-ml0 -me0 -mgfx200 -mvtx200 -ma400"            },
	{ STAGE_MP_FELICITY,   "-ml0 -me0 -mgfx200 -mvtx200 -ma400"            },
	{ STAGE_MP_AREA52,     "-ml0 -me0 -mgfx200 -mvtx200 -ma400"            },
	{ STAGE_MP_GRID,       "-ml0 -me0 -mgfx200 -mvtx200 -ma400"            },
	{ STAGE_MP_CARPARK,    "-ml0 -me0 -mgfx200 -mvtx200 -ma400"            },
	{ STAGE_MP_RUINS,      "-ml0 -me0 -mgfx200 -mvtx200 -ma400"            },
	{ STAGE_MP_FORTRESS,   "-ml0 -me0 -mgfx200 -mvtx200 -ma400"            },
	{ STAGE_MP_VILLA,      "-ml0 -me0 -mgfx200 -mvtx200 -ma400"            },
	{ STAGE_TEST_RUN,      "-ml0 -me0 -mgfx200 -mvtx200 -ma400"            },
	{ STAGE_TEST_MP2,      "-ml0 -me0 -mgfx200 -mvtx200 -ma400"            },
	{ STAGE_TEST_MP6,      "-ml0 -me0 -mgfx200 -mvtx200 -ma400"            },
	{ STAGE_TEST_MP7,      "-ml0 -me0 -mgfx200 -mvtx200 -ma400"            },
	{ STAGE_TEST_MP8,      "-ml0 -me0 -mgfx200 -mvtx200 -ma400"            },
	{ STAGE_TEST_MP14,     "-ml0 -me0 -mgfx200 -mvtx200 -ma400"            },
	{ STAGE_TEST_MP16,     "-ml0 -me0 -mgfx200 -mvtx200 -ma400"            },
	{ STAGE_TEST_MP17,     "-ml0 -me0 -mgfx200 -mvtx200 -ma400"            },
	{ STAGE_TEST_MP18,     "-ml0 -me0 -mgfx200 -mvtx200 -ma400"            },
	{ STAGE_TEST_MP19,     "-ml0 -me0 -mgfx200 -mvtx200 -ma400"            },
	{ STAGE_TEST_MP20,     "-ml0 -me0 -mgfx200 -mvtx200 -ma400"            },
	{ STAGE_TEST_ASH,      "-ml0 -me0 -mgfx120 -mvtx98 -ma400"             },
	{ STAGE_28,            "-ml0 -me0 -mgfx120 -mvtx98 -ma400"             },
	{ STAGE_MBR,           "-ml0 -me0 -mgfx120 -mvtx100 -ma700"            },
	{ STAGE_TEST_SILO,     "-ml0 -me0 -mgfx200 -mvtx200 -ma400"            },
	{ STAGE_24,            "-ml0 -me0 -mgfx120 -mvtx98 -ma400"             },
	{ STAGE_MAIANSOS,      "-ml0 -me0 -mgfx120 -mvtx100 -ma500"            },
	{ STAGE_RETAKING,      "-ml0 -me0 -mgfx120 -mvtx98 -ma400"             },
	{ STAGE_TEST_DEST,     "-ml0 -me0 -mgfx120 -mvtx98 -ma400"             },
	{ STAGE_2B,            "-ml0 -me0 -mgfx120 -mvtx98 -ma400"             },
	{ STAGE_WAR,           "-ml0 -me0 -mgfx120 -mvtx98 -ma400"             },
	{ STAGE_TEST_UFF,      "-ml0 -me0 -mgfx120 -mvtx98 -ma400"             },
	{ STAGE_TEST_OLD,      "-ml0 -me0 -mgfx120 -mvtx98 -ma400"             },
	{ STAGE_DUEL,          "-ml0 -me0 -mgfx120 -mvtx100 -ma700"            },
	{ STAGE_TEST_LAM,      "-ml0 -me0 -mgfx120 -mvtx98 -ma400"             },
	{ STAGE_TEST_ARCH,     "-ml0 -me0 -mgfx200 -mvtx200 -ma400"            },
	{ STAGE_TEST_LEN,      "-ml0 -me0 -mgfx120 -mvtx98 -ma300"             },
	{ STAGE_TITLE,         "-ml0 -me0 -mgfx80 -mvtx20 -ma001"              },
	{ 0,                   "-ml0 -me0 -mgfx120 -mvtx98 -ma300"             },
};

struct stageallocation g_StageAllocations4Mb[] = {
	{ STAGE_MP_SKEDAR,     "-ml0 -me0 -mgfx96 -mvtx96 -ma140"              },
	{ STAGE_MP_PIPES,      "-ml0 -me0 -mgfx96 -mvtx96 -ma140"              },
	{ STAGE_MP_AREA52,     "-ml0 -me0 -mgfx96 -mvtx96 -ma140"              },
	{ STAGE_MP_RAVINE,     "-ml0 -me0 -mgfx96 -mvtx96 -ma140"              },
	{ STAGE_MP_G5BUILDING, "-ml0 -me0 -mgfx96 -mvtx96 -ma140"              },
	{ STAGE_MP_SEWERS,     "-ml0 -me0 -mgfx96 -mvtx96 -ma140"              },
	{ STAGE_MP_WAREHOUSE,  "-ml0 -me0 -mgfx96 -mvtx96 -ma140"              },
	{ STAGE_MP_BASE,       "-ml0 -me0 -mgfx96 -mvtx96 -ma140"              },
	{ STAGE_MP_COMPLEX,    "-ml0 -me0 -mgfx96 -mvtx96 -ma140"              },
	{ STAGE_MP_TEMPLE,     "-ml0 -me0 -mgfx96 -mvtx96 -ma140"              },
	{ STAGE_MP_FELICITY,   "-ml0 -me0 -mgfx96 -mvtx96 -ma140"              },
	{ STAGE_MP_GRID,       "-ml0 -me0 -mgfx96 -mvtx96 -ma140"              },
	{ STAGE_TEST_RUN,      "-ml0 -me0 -mgfx96 -mvtx96 -ma140"              },
	{ STAGE_MP_CARPARK,    "-ml0 -me0 -mgfx96 -mvtx96 -ma140"              },
	{ STAGE_MP_RUINS,      "-ml0 -me0 -mgfx96 -mvtx96 -ma140"              },
	{ STAGE_MP_FORTRESS,   "-ml0 -me0 -mgfx96 -mvtx96 -ma130"              },
	{ STAGE_MP_VILLA,      "-ml0 -me0 -mgfx96 -mvtx96 -ma140"              },
	{ STAGE_TEST_MP2,      "-ml0 -me0 -mgfx96 -mvtx96 -ma115"              },
	{ STAGE_TEST_MP6,      "-ml0 -me0 -mgfx96 -mvtx96 -ma115"              },
	{ STAGE_TEST_MP7,      "-ml0 -me0 -mgfx96 -mvtx96 -ma115"              },
	{ STAGE_TEST_MP8,      "-ml0 -me0 -mgfx96 -mvtx96 -ma115"              },
	{ STAGE_TEST_MP14,     "-ml0 -me0 -mgfx96 -mvtx96 -ma115"              },
	{ STAGE_TEST_MP16,     "-ml0 -me0 -mgfx96 -mvtx96 -ma115"              },
	{ STAGE_TEST_MP17,     "-ml0 -me0 -mgfx96 -mvtx96 -ma115"              },
	{ STAGE_TEST_MP18,     "-ml0 -me0 -mgfx96 -mvtx96 -ma115"              },
	{ STAGE_TEST_MP19,     "-ml0 -me0 -mgfx96 -mvtx96 -ma115"              },
	{ STAGE_TEST_MP20,     "-ml0 -me0 -mgfx96 -mvtx96 -ma115"              },
	{ STAGE_TEST_LEN,      "-ml0 -me0 -mgfx100 -mvtx96 -ma120"             },
	{ STAGE_4MBMENU,       "-mgfx100 -mvtx50 -ma50"                        },
	{ STAGE_TITLE,         "-ml0 -me0 -mgfx80 -mvtx20 -ma001"              },
	{ 0,                   "-ml0 -me0 -mgfx100 -mvtx96 -ma300"             },
};

Gfx var8005dcc8[] = {
	gsSPSegment(0x00, 0x00000000),
	gsSPDisplayList(&var800613a0),
	gsSPDisplayList(&var80061380),
	gsDPFullSync(),
	gsSPEndDisplayList(),
};

s32 g_MainIsBooting = 1;

void main_init(void)
{
	s32 x;
	s32 i;
	s32 j;
	u32 addr;

	fault_init();
	dma_init();
	amgr_init();
	vars_init();
	memp_init();
	mema_init();
	joy_init();
	joy_reset();

	var8005d9b0 = rmon_is_disabled();

	g_Is4Mb = (osGetMemSize() <= 0x400000);
	g_VmShowStats = 0;

	// no copyright screen
	vi_set_mode(VIMODE_HI);
	vi_configure_for_legal();
	vi_black(true);
	vi_update_mode();

	files_init();

	if (var8005d9b0) {
		arg_set_string("          -ml0 -me0 -mgfx100 -mvtx50 -mt700 -ma400");
	}

	memp_set_heap(g_MempHeap, g_MempHeapSize);

	memp_reset_pool(MEMPOOL_8);
	memp_reset_pool(MEMPOOL_PERMANENT);
	crash_reset();
	challenges_init();
	utils_init();
	tex_init();
	lang_init();
	lv_init();
	cheats_init();
	text_init();
	dhud_init();
	playermgr_init();
	frametime_init();
	profile_init();
	smokes_init();
	mp_init(true);
	phead_init();
	paks_init();
	phead_init2();
	anims_init();
	races_init();
	bodies_init();
	title_init();

	model_set_distance_checks_disabled(true); // don't use LODs

	g_MainIsBooting = 0;
}

void main_proc(void)
{
	main_init();
	rdp_init();
	snd_init();

	while (true) {
		main_loop();
	}
}

/**
 * It's suspected that this function would have allowed developers to override
 * the value of variables while the game is running in order to view their
 * effects immediately rather than having to recompile the game each time.
 *
 * The developers would have used rmon to create a table of name/value pairs,
 * then this function would have looked up the given variable name in the table
 * and written the new value to the variable's address.
 */
void main_override_variable(char *name, void *value)
{
	// empty
}

/**
 * This function enters an infinite loop which iterates once per stage load.
 * Within this loop is an inner loop which runs very frequently and decides
 * whether to run main_tick on each iteration.
 *
 * NTSC beta checks two shorts at an offset 64MB into the development board
 * and refuses to continue if they are not any of the allowed values.
 * Decomp patches these reads in its build system so it can be played
 * without the development board.
 */
void main_loop(void)
{
	s32 ending = false;
	s32 index;
	s32 numplayers;
	u32 stack;

	func0f175f98();

	var8005d9c4 = 0;
	arg_get_level(&g_StageNum);

	if (g_DoBootPakMenu) {
		g_Vars.pakstocheck = 0xfd;
		g_StageNum = STAGE_BOOTPAKMENU;
	}

	if (g_StageNum != STAGE_TITLE) {
		title_set_next_stage(g_StageNum);

		if (g_StageNum < STAGE_TITLE) {
			func0f01b148(0);

			if (arg_find_by_prefix(1, "-hard")) {
				lv_set_difficulty(arg_find_by_prefix(1, "-hard")[0] - '0');
			}
		}
	}

	if (g_StageNum == STAGE_CITRAINING && IS4MB()) {
		g_StageNum = STAGE_4MBMENU;
	}

	rng_set_seed(osGetCount());

	// Outer loop - this is infinite because ending is never changed
	while (!ending) {
		g_MainNumGfxTasks = 0;
		g_MainGameLogicEnabled = true;
		g_MainIsEndscreen = false;

		if (var8005d9b0 && var8005d9c4 == 0) {
			index = -1;

			if (IS4MB()) {
				if (g_StageNum < STAGE_TITLE && get_num_players() >= 2) {
					index = 0; \
					while (g_StageAllocations4Mb[index].stagenum) { \
						if (g_StageAllocations4Mb[index].stagenum == g_StageNum + 400) { \
							break; \
						} \
						index++;
					}

					if (g_StageAllocations4Mb[index].stagenum == 0) {
						index = -1;
					}
				}

				if (index);

				if (index < 0) {
					index = 0;
					while (g_StageAllocations4Mb[index].stagenum) {
						if (g_StageNum == g_StageAllocations4Mb[index].stagenum) {
							break;
						}

						index++;
					}
				}

				arg_set_string(g_StageAllocations4Mb[index].string);
			} else {
				// 8MB
				if (g_StageNum < STAGE_TITLE && get_num_players() >= 2) {
					index = 0; \
					while (g_StageAllocations8Mb[index].stagenum) { \
						if (g_StageNum + 400 == g_StageAllocations8Mb[index].stagenum) { \
							break; \
						} \
						index++;
					}

					if (g_StageAllocations8Mb[index].stagenum == 0) {
						index = -1;
					}
				}

				if (index < 0) {
					index = 0;

					while (g_StageAllocations8Mb[index].stagenum) {
						if (g_StageNum == g_StageAllocations8Mb[index].stagenum) {
							break;
						}

						index++;
					}
				}

				arg_set_string(g_StageAllocations8Mb[index].string);
			}
		}

		var8005d9c4 = 0;

		memp_reset_pool(MEMPOOL_7);
		memp_reset_pool(MEMPOOL_STAGE);
		files_stop(4);

		if (arg_find_by_prefix(1, "-ma")) {
			g_MainMemaHeapSize = strtol(arg_find_by_prefix(1, "-ma"), NULL, 0) * 1024;
		}

		mema_reset(memp_alloc(g_MainMemaHeapSize, MEMPOOL_STAGE), g_MainMemaHeapSize);
		lang_reset(g_StageNum);
		playermgr_reset();

		if (g_StageNum >= STAGE_TITLE) {
			numplayers = 0;
		} else {
			if (arg_find_by_prefix(1, "-play")) {
				numplayers = strtol(arg_find_by_prefix(1, "-play"), NULL, 0);
			} else {
				numplayers = 1;
			}

			if (get_num_players() >= 2) {
				numplayers = get_num_players();
			}
		}

		if (numplayers < 2) {
			g_Vars.bondplayernum = 0;
			g_Vars.coopplayernum = -1;
			g_Vars.antiplayernum = -1;
		} else if (arg_find_by_prefix(1, "-coop")) {
			g_Vars.bondplayernum = 0;
			g_Vars.coopplayernum = 1;
			g_Vars.antiplayernum = -1;
		} else if (arg_find_by_prefix(1, "-anti")) {
			g_Vars.bondplayernum = 0;
			g_Vars.coopplayernum = -1;
			g_Vars.antiplayernum = 1;
		}

		playermgr_allocate_players(numplayers);

		if (arg_find_by_prefix(1, "-mpbots")) {
			g_Vars.lvmpbotlevel = 1;
		}

		if (g_Vars.coopplayernum >= 0 || g_Vars.antiplayernum >= 0) {
			if (g_MpSetup.chrslots & 0xfff0) {
				g_MpSetup.storedbotbits = g_MpSetup.chrslots & 0xfff0;
			}
			g_MpSetup.chrslots = 0x03;
			mp_reset();
		} else if (g_Vars.perfectbuddynum) {
			mp_reset();
		} else if (g_Vars.mplayerisrunning == false
				&& (numplayers >= 2 || g_Vars.lvmpbotlevel || arg_find_by_prefix(1, "-play"))) {
			g_MpSetup.chrslots = 1;

			if (numplayers >= 2) {
				g_MpSetup.chrslots |= 1 << 1;
			}

			if (numplayers >= 3) {
				g_MpSetup.chrslots |= 1 << 2;
			}

			if (numplayers >= 4) {
				g_MpSetup.chrslots |= 1 << 3;
			}

			g_MpSetup.stagenum = g_StageNum;
			mp_reset();
		}

		gfxReset();
		joy_reset();
		dhud_reset();
		zbuf_reset(g_StageNum);
		lv_reset(g_StageNum);
		vi_reset(g_StageNum);
		frametime_calculate();
		profile_reset();

		while (g_MainChangeToStageNum < 0) {
			const s32 cycles = osGetCount() - g_Vars.thisframestartt;
			if (!g_Vars.mininc60 || (cycles >= g_Vars.mininc60 * CYCLES_PER_FRAME - CYCLES_PER_FRAME / 2)) {
				schedStartFrame(&g_Sched);
				main_tick();
				schedEndFrame(&g_Sched);
			}
			if (g_TickExtraSleep) {
				sysSleep(EXTRA_SLEEP_TIME);
			}
		}

		lv_stop();
		memp_disable_pool(MEMPOOL_STAGE);
		memp_disable_pool(MEMPOOL_7);
		files_stop(4);
		vi_black(true);
		pak0f116994();

		g_StageNum = g_MainChangeToStageNum;
		g_MainChangeToStageNum = -1;
	}
}

void main_tick(void)
{
	Gfx *gdl = NULL;
	Gfx *gdlstart = NULL;
	OSScMsg msg = {OS_SC_DONE_MSG};
	s32 i;

	if (g_MainChangeToStageNum < 0) {
		frametime_calculate();
		profile_reset();
		profile_set_marker(PROFILE_MAINTICK_START);
		joy_debug_joy();
		sched_set_crash_enable2(false);

		if (g_MainGameLogicEnabled) {
			gdl = gdlstart = gfxGetMasterDisplayList();

			gDPSetTile(gdl++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
			gDPSetTile(gdl++, G_IM_FMT_RGBA, G_IM_SIZ_4b, 0, 0x0100, 6, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);

			lv_tick();
			playermgr_shuffle();

			if (g_StageNum < STAGE_TITLE) {
				for (i = 0; i < PLAYERCOUNT(); i++) {
					set_current_player_num(playermgr_get_player_at_order(i));

					if (g_StageNum != STAGE_TEST_OLD || !title_is_keeping_mode()) {
						vi_set_view_position(g_Vars.currentplayer->viewleft, g_Vars.currentplayer->viewtop);
						vi_set_fov_aspect_and_size(
								g_Vars.currentplayer->fovy, g_Vars.currentplayer->aspect,
								g_Vars.currentplayer->viewwidth, g_Vars.currentplayer->viewheight);
					}

					lv_tick_player();
				}
			}

			gdl = lv_render(gdl);

			if (debug_get_profile_mode() >= 2) {
				gdl = profile_render(gdl);
			}

			gDPFullSync(gdl++);
			gSPEndDisplayList(gdl++);
		}

		if (g_MainGameLogicEnabled) {
			gfxSwapBuffers();
			vi_update_mode();
		}

		rdp_create_task(gdlstart, gdl, 0, (uintptr_t) &msg);
		mema_print();
		profile_set_marker(PROFILE_MAINTICK_END);
	}
}

void main_end_stage(void)
{
	snd_stop_nosedive();

	if (!g_MainIsEndscreen) {
		pak0f11c6d0();
		joy_disable_temporarily();

		if (g_Vars.coopplayernum >= 0) {
			s32 prevplayernum = g_Vars.currentplayernum;
			s32 i;

			for (i = 0; i < PLAYERCOUNT(); i++) {
				set_current_player_num(i);
				endscreen_push_coop();
			}

			set_current_player_num(prevplayernum);
			music_start_menu();
		} else if (g_Vars.antiplayernum >= 0) {
			s32 prevplayernum = g_Vars.currentplayernum;
			s32 i;

			for (i = 0; i < PLAYERCOUNT(); i++) {
				set_current_player_num(i);
				endscreen_push_anti();
			}

			set_current_player_num(prevplayernum);
			music_start_menu();
		} else if (g_Vars.normmplayerisrunning) {
			mp_end_match();
		} else {
			endscreen_prepare();
			music_start_menu();
		}
	}

	g_MainIsEndscreen = true;
}

/**
 * Change to the given stage at the end of the current frame.
 */
void main_change_to_stage(s32 stagenum)
{
	pak0f11c6d0();

	g_MainChangeToStageNum = stagenum;
}

s32 main_get_stage_num(void)
{
	return g_StageNum;
}

void func0000e990(void)
{
	objectives_check_all();
	objectives_disable_checking();
	main_end_stage();
}
