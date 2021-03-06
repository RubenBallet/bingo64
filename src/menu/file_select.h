#ifndef FILE_SELECT_H
#define FILE_SELECT_H

#include "types.h"

#define MENU_LAYER_MAIN 1
#define MENU_LAYER_SUBMENU 2

#define MENU_ERASE_HOVER_NONE 0
#define MENU_ERASE_HOVER_YES 1
#define MENU_ERASE_HOVER_NO 2

enum MainMenuButtonStates {
    MENU_BUTTON_STATE_DEFAULT,
    MENU_BUTTON_STATE_GROWING,
    MENU_BUTTON_STATE_FULLSCREEN,
    MENU_BUTTON_STATE_SHRINKING,
    MENU_BUTTON_STATE_ZOOM_IN_OUT,
    MENU_BUTTON_STATE_ZOOM_IN,
    MENU_BUTTON_STATE_ZOOM_OUT
};

enum MenuButtonTypes {
    MENU_BUTTON_NONE = -1, // no button selected (on main menu screen)

    // Main Menu (SELECT FILE)
    MENU_BUTTON_MAIN_MIN,
    MENU_BUTTON_PLAY_FILE_A = MENU_BUTTON_MAIN_MIN,
    MENU_BUTTON_PLAY_FILE_B,
    MENU_BUTTON_PLAY_FILE_C,
    MENU_BUTTON_PLAY_FILE_D,
    MENU_BUTTON_SCORE,
    MENU_BUTTON_COPY,
    MENU_BUTTON_ERASE,
    MENU_BUTTON_MAIN_MAX,

    // Score Menu (CHECK FILE)
    MENU_BUTTON_SCORE_MIN = MENU_BUTTON_MAIN_MAX,
    MENU_BUTTON_SCORE_FILE_A = MENU_BUTTON_SCORE_MIN,
    MENU_BUTTON_SCORE_FILE_B,
    MENU_BUTTON_SCORE_FILE_C,
    MENU_BUTTON_SCORE_FILE_D,
    MENU_BUTTON_SCORE_RETURN,
    MENU_BUTTON_SCORE_COPY_FILE,
    MENU_BUTTON_SCORE_ERASE_FILE,
    MENU_BUTTON_SCORE_MAX,

    // Copy Menu (COPY FILE)
    MENU_BUTTON_COPY_MIN = MENU_BUTTON_SCORE_MAX,
    MENU_BUTTON_COPY_FILE_A = MENU_BUTTON_COPY_MIN,
    MENU_BUTTON_COPY_FILE_B,
    MENU_BUTTON_COPY_FILE_C,
    MENU_BUTTON_COPY_FILE_D,
    MENU_BUTTON_COPY_RETURN,
    MENU_BUTTON_COPY_CHECK_SCORE,
    MENU_BUTTON_COPY_ERASE_FILE,
    MENU_BUTTON_COPY_MAX,

    // Erase Menu (ERASE FILE)
    MENU_BUTTON_ERASE_MIN = MENU_BUTTON_COPY_MAX,
    MENU_BUTTON_ERASE_FILE_A = MENU_BUTTON_ERASE_MIN,
    MENU_BUTTON_ERASE_FILE_B,
    MENU_BUTTON_ERASE_FILE_C,
    MENU_BUTTON_ERASE_FILE_D,
    MENU_BUTTON_ERASE_RETURN,
    MENU_BUTTON_ERASE_CHECK_SCORE,
    MENU_BUTTON_ERASE_COPY_FILE,
    MENU_BUTTON_ERASE_MAX,

    // Sound Mode Menu (SOUND SELECT)
    MENU_BUTTON_SOUND_MODE = MENU_BUTTON_ERASE_MAX,
    MENU_BUTTON_SOUND_MIN,
    MENU_BUTTON_STEREO = MENU_BUTTON_SOUND_MIN,
    MENU_BUTTON_MONO,
    MENU_BUTTON_HEADSET,

    // Seed Menu (SEED)
    MENU_BUTTON_SEED_RESET,
    MENU_BUTTON_SEED_RETURN,
    MENU_BUTTON_SOUND_MAX
};

enum ScoreMenuMessageID {
    SCORE_MSG_CHECK_FILE,
    SCORE_MSG_NOSAVE_DATA
};

enum CopyMenuMessageID {
    COPY_MSG_MAIN_TEXT,
    COPY_MSG_COPY_WHERE,
    COPY_MSG_NOSAVE_EXISTS,
    COPY_MSG_COPY_COMPLETE,
    COPY_MSG_SAVE_EXISTS
};

enum CopyMenuActionPhase {
    COPY_PHASE_MAIN,
    COPY_PHASE_COPY_WHERE,
    COPY_PHASE_COPY_COMPLETE
};

enum EraseMenuMessageID {
    ERASE_MSG_MAIN_TEXT,
    ERASE_MSG_PROMPT,
    ERASE_MSG_NOSAVE_EXISTS,
    ERASE_MSG_MARIO_ERASED,
    ERASE_MSG_SAVE_EXISTS
};

enum EraseMenuActionPhase {
    ERASE_PHASE_MAIN,
    ERASE_PHASE_PROMPT,
    ERASE_PHASE_MARIO_ERASED
};

enum SoundModeMenuActionPhase {
    SOUND_MODE_PHASE_MAIN
};

extern u32 gGlobalTimer;

extern void beh_yellow_background_menu_init(void);
extern void beh_yellow_background_menu_loop(void);
extern void bhv_menu_button_init(void);
extern void bhv_menu_button_loop(void);
extern void bhv_menu_button_manager_init(void);
extern void bhv_menu_button_manager_loop(void);
extern Gfx *geo_file_select_strings_and_menu_cursor(s32 callContext, struct GraphNode *node,
                                                    f32 mtx[4][4]);
extern s32 lvl_init_menu_values_and_cursor_pos(s32 arg, s32 unused);
extern s32 lvl_update_obj_and_load_file_selected(s32 arg, s32 unused);

#endif /* FILE_SELECT_H */
