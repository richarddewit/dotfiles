#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Base layer
 * ,-----------------------------------------------------------------------------------------------------------------------------.
 * |  ` ~  |   1   |   2   |   3   |   4   |   5   |   6   |   7   |   8   |   9   |   0   |   -   |   =   |  Backspace  | PrtSc |
 * |-----------------------------------------------------------------------------------------------------------------------------+
 * |   Tab    |   Q   |   W   |   E   |   R   |   T   |   Y   |   U   |   I   |   O   |   P   |   [   |   ]   |     \    | Menu  |
 * |-----------------------------------------------------------------------------------------------------------------------------+
 * | Esc + Ctrl |   A   |   S   |   D   |   F   |   G   |   H   |   J   |   K   |   L   |   ;   |   '   |      Enter     | Enter |
 * |-----------------------------------------------------------------------------------------------------------------------------+
 * |      Shift     |   Z   |   X   |   C   |   V   |   B   |   N   |   M   |   ,   |   .   |   /   |   RShift   |   ▲   |  Del  |
 * |-----------------------------------------------------------------------------------------------------------------------------+
 * |   Ctrl  |   GUI   |   Alt   |        Space        |   LT1   |      Space      |  RAlt  |  LT1   |   |   ◄   |   ▼   |   ►   |
 * `-------------------------------------------------------------------------------------------------'   `-----------------------'
 */
	[0] = LAYOUT_all(
        KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_NO, KC_BSPC, KC_PSCR,
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS, KC_APP,
        LCTL_T(KC_ESC), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT, KC_ENT,
        KC_LSFT, KC_NO, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_UP, KC_DEL,
        KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, MO(1), KC_SPC, KC_ALGR, MO(1), KC_NO, KC_LEFT, KC_DOWN, KC_RGHT
    ),
/* FN layer
 * ,-----------------------------------------------------------------------------------------------------------------------------.
 * |  Esc  |  F1   |  F2   |  F3   |  F4   |  F5   |  F6   |  F7   |  F8   |  F9   |  F10  |  F11  |  F12  |   Delete    | PrtSc |
 * |-----------------------------------------------------------------------------------------------------------------------------+
 * |    ▽     |       |   ▲   |       |       |  Ins  | Home  | PgDn  | PgUp  |  End  | BckSp |  Del  |  Ins  |  Reset   | ScrLk |
 * |-----------------------------------------------------------------------------------------------------------------------------+
 * |     ▽      |   ◄   |   ▼   |   ►   |       |  Del  |   ◄   |   ▼   |   ▲   |   ►   | Enter | NPEnt |                | Pause |
 * |-----------------------------------------------------------------------------------------------------------------------------+
 * |       ▽        |  F13  |  F14  |  F15  |  F16  |       |  NP/  |  NP*  |  NP-  |  NP+  |  NP=  |            | PgUp  |  Ins  |
 * |-----------------------------------------------------------------------------------------------------------------------------+
 * |    ▽    |    ▽    |    ▽    |          ▽          |    ▽    |        ▽        |   ▽    |   ▽    |   | Home  | PgDn  |  End  |
 * `-------------------------------------------------------------------------------------------------'   `-----------------------'
 */
	[1] = LAYOUT_all(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NO, KC_DEL,  KC_PSCR,
        KC_TRNS, KC_NO,   KC_UP,   KC_NO,   KC_NO,   KC_INS,  KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_BSPC, KC_DEL,  KC_INS,  RESET,          KC_SLCK,
        KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT, KC_NO,   KC_DEL,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_ENT,  KC_PENT, KC_TRNS,                 KC_PAUS,
        KC_TRNS, KC_NO,   KC_F13,  KC_F14,  KC_F15,  KC_F16,  KC_NO,   KC_PSLS, KC_PAST, KC_PMNS, KC_PPLS, KC_PEQL, KC_TRNS,        KC_PGUP, KC_INS,
        KC_TRNS, KC_TRNS, KC_TRNS,        KC_TRNS,         KC_TRNS,        KC_TRNS,      KC_TRNS, KC_TRNS, KC_NO,          KC_HOME, KC_PGDN, KC_END
    )
};
