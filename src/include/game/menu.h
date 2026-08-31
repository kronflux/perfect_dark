#ifndef IN_GAME_MENU_H
#define IN_GAME_MENU_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

extern const struct menucolourpalette g_MenuColours[];
extern const struct menucolourpalette g_MenuWave1Colours[];
extern const struct menucolourpalette g_MenuWave2Colours[];

void menu_tick(void);

void menu_stop(void);

void menu_play_sound(s32 menusound);
bool menu_is_solo_mission_or_mp(void);
bool current_player_is_menu_open_in_solo_or_mp(void);
bool menu_has_no_background(void);
void menu_set_banner(s32 bannernum, bool allplayers);

#if VERSION >= VERSION_NTSC_1_0
Gfx *menu_render_banner(Gfx *gdl, s32 x1, s32 y1, s32 x2, s32 y2, bool big, s32 msgnum, s32 arg7, s32 arg8);
#else
Gfx *menu_render_banner(Gfx *gdl, s32 x1, s32 y1, s32 x2, s32 y2, bool big, s32 msgnum);
#endif

struct menudfc *menu_find_item_redraw_info(struct menuitem *item);
void menu_set_item_redraw_timer(struct menuitem *item, f32 arg1);
void menu_remove_item_redraw_info(struct menuitem *item);
void menu_increment_item_redraw_timers(void);
void menu_remove_all_item_redraw_info(void);
char *menu_resolve_text(uintptr_t thing, void *dialogoritem);
char *menu_resolve_param2_text(struct menuitem *item);
char *menu_resolve_dialog_title(struct menudialogdef *dialogdef);
void menu_get_item_blocks_required(struct menuitem *item, s32 *arg1);
void menu_calculate_item_size(struct menuitem *item, s16 *width, s16 *height, struct menudialog *dialog);
void dialog_init_blocks(struct menudialogdef *dialogdef, struct menudialog *dialog, struct menu *menu);
void dialog0f0f1ef4(struct menudialog *dialog);
void dialog_calculate_content_size(struct menudialogdef *dialogdef, struct menudialog *dialog, struct menu *menu);
s32 dialog_find_item(struct menudialog *dialog, struct menuitem *item, s32 *rowindex, s32 *colindex);
bool menu_is_scrollable_unscrollable(struct menuitem *item);
bool menu_is_item_disabled(struct menuitem *item, struct menudialog *dialog);
bool menu_is_item_focusable(struct menuitem *item, struct menudialog *dialog, s32 arg2);
struct menuitem *dialog_find_item_at_col_y(s32 targety, s32 colindex, struct menudialogdef *dialogdef, s32 *rowindexptr, struct menudialog *dialog);
struct menuitem *dialog_find_first_item(struct menudialog *dialog);
struct menuitem *dialog_find_first_item_right(struct menudialog *dialog);
void dialog_change_item_focus_vertically(struct menudialog *dialog, s32 updown);
s32 dialog_change_item_focus_horizontally(struct menudialog *dialog, s32 leftright);
s32 dialog_change_item_focus(struct menudialog *dialog, struct menuinputs *inputs);
void menu_open_dialog(struct menudialogdef *dialogdef, struct menudialog *arg1, struct menu *menu);
void menu_push_dialog(struct menudialogdef *dialogdef);

#if VERSION >= VERSION_NTSC_1_0
bool menu_save_file(s32 arg0);
#else
void menu_save_file(s32 arg0);
#endif

void menu_close_dialog(void);
void menu_update_cur_frame(void);
void menu_pop_dialog(void);
void menu_replace_current_dialog(struct menudialogdef *dialogdef);
void menu_configure_model(struct menumodel *menumodel, f32 x, f32 y, f32 z, f32 rotx, f32 roty, f32 rotz, f32 scale, u8 flags);
void menu_unset_model(struct menumodel *menumodel);
Gfx *menu_render_model(Gfx *gdl, struct menumodel *menumodel, s32 modeltype);
void menu_get_team_titlebar_colours(u32 *top, u32 *middle, u32 *bottom);
Gfx *menu_apply_scissor(Gfx *gdl);
Gfx *dialog_render(Gfx *gdl, struct menudialog *dialog, struct menu *menu, bool lightweight);
void menu_get_cont_pads(s8 *contpadnum1, s8 *contpadnum2);
void menu_calculate_swipe_direction(s32 arg0, s32 *vdir, s32 *hdir);

#if VERSION >= VERSION_JPN_FINAL
void menu_find_available_size(s32 *xmin, s32 *ymin, s32 *xmax, s32 *ymax, struct menudialog *dialog);
#else
void menu_find_available_size(s32 *xmin, s32 *ymin, s32 *xmax, s32 *ymax);
#endif

void dialog_calculate_position(struct menudialog *dialog);
void menu_close(void);
void menu_save_and_close_all(void);
void menu_save_and_push_root_dialog(struct menudialogdef *dialogdef, s32 root);
void menu_set_background(s32 bg);
void menu_hide_pressstart_labels(void);
void menu_push_root_dialog(struct menudialogdef *dialogdef, s32 arg1);
void menu_push_root_dialog_and_pause(struct menudialogdef *dialogdef, s32 root);
Gfx *menu_render_dialog(Gfx *gdl, struct menudialog *dialog, struct menu *menu, bool lightweight);
Gfx *menu_render_dialogs(Gfx *gdl);
void menu_reset_model(struct menumodel *menumodel, u32 allocationlen, bool allocate);
void menu_reset(void);
void menu_swipe(s32 direction);
void dialog_tick(struct menudialog *dialog, struct menuinputs *inputs, u32 tickflags);
void dialog_init_items(struct menudialog *dialog);
void menu_consider_unpause(void);
void menu_process_input(void);
Gfx *menu_render_background_layer1(Gfx *gdl, u8 bg, f32 frac);
Gfx *menu_render_background_layer2(Gfx *gdl, u8 bg, f32 frac);
Gfx *menu_render(Gfx *gdl);
u32 menu_choose_music(void);
u32 menu_get_root(void);
void menu_push_pak_dialog_for_player(struct menudialogdef *dialogdef, s32 playernum, s32 arg2);
char *menu_text_save_device_name(struct menuitem *item);
s32 menu_pak_num_to_player_num(s32 paknum);
bool menu_is_ready_for_pak_error(s32 device, s32 arg1);
void menu_push_pak_error_dialog(s32 arg0, s32 arg1);
void menu_set_source_pos(struct coord *pos);
void menu_queue_save(s32 arg0);
struct menudialog *menu_is_dialog_open(struct menudialogdef *dialogdef);
struct chrdata *current_player_get_commanding_aibot(void);

MenuItemHandlerResult menuhandler000fcc34(s32 operation, struct menuitem *item, union handlerdata *data);
MenuItemHandlerResult am_pick_target_menu_list(s32 operation, struct menuitem *item, union handlerdata *data);
MenuItemHandlerResult menuhandler_repair_pak(s32 operation, struct menuitem *item, union handlerdata *data);
MenuItemHandlerResult menuhandler_retry_save_pak(s32 operation, struct menuitem *item, union handlerdata *data);
MenuItemHandlerResult menuhandler_warn_repair_pak(s32 operation, struct menuitem *item, union handlerdata *data);

s32 menuAlt1Pressed(s32 playerNum);
s32 menuAlt2Pressed(s32 playerNum);
s32 menuAltAnyPressed(s32 playerNum);

extern const char var7f1b2658[];
extern const char var7f1b265c[];
extern const char var7f1b2660[];
extern const char var7f1b2664[];

#endif
