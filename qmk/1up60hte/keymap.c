#include QMK_KEYBOARD_H

// Layers
#define _BASE   0 // Base (QWERTY)
#define _DVORAK 1
#define _GAME   2
#define _FN     3 // Function
#define _LAYER  4 // Default layer switching

#define BASE   DF(_BASE)
#define DVORAK DF(_DVORAK)
#define GAME   DF(_GAME)

// Aliases
#define ___V___ KC_TRNS
#define _______ KC_NO

// Compound keys
#define CP_GRV  LT(_FN, KC_GRV) // Grave-Fn
#define CP_SPC  LT(_FN, KC_SPC) // Space-Fn
#define CP_DEL  LT(_FN, KC_DEL) // Delete-Fn
#define CP_CAPS CTL_T(KC_ESC)   // Caps Lock key

// Macros
#define M_FLASK 0 // PoE Flask Piano (1,2,3,4,5)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_tsangan(
      /* Base layer
      * ,-----------------------------------------------------------------------------------------------------------------------.
      * |  Esc  |   1   |   2   |   3   |   4   |   5   |   6   |   7   |   8   |   9   |   0   |   -   |   =   |   \   | `~+FN |
      * |-----------------------------------------------------------------------------------------------------------------------+
      * |   Tab    |   Q   |   W   |   E   |   R   |   T   |   Y   |   U   |   I   |   O   |   P   |   [   |   ]   | Backspace  |
      * |-----------------------------------------------------------------------------------------------------------------------+
      * | Esc + Ctrl |   A   |   S   |   D   |   F   |   G   |   H   |   J   |   K   |   L   |   ;   |   '   |       Enter      |
      * |-----------------------------------------------------------------------------------------------------------------------+
      * |      Shift     |   Z   |   X   |   C   |   V   |   B   |   N   |   M   |   ,   |   .   |   /   |    RShift    |Del+LT2|
      * |-----------------------------------------------------------------------------------------------------------------------+
      * |   Ctrl    |  GUI  |    Alt    |                         Space                         |    Alt    |  GUI  |   Ctrl    |
      * `-----------------------------------------------------------------------------------------------------------------------'
      */
      KC_ESC,     KC_1,     KC_2,     KC_3,  KC_4,  KC_5,    KC_6,  KC_7,  KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSLS,  CP_GRV,
      KC_TAB,     KC_Q,     KC_W,     KC_E,  KC_R,  KC_T,    KC_Y,  KC_U,  KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSPC,
      CP_CAPS,    KC_A,     KC_S,     KC_D,  KC_F,  KC_G,    KC_H,  KC_J,  KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT ,
      KC_LSFT,    KC_Z,     KC_X,     KC_C,  KC_V,  KC_B,    KC_N,  KC_M,  KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,            KC_DEL ,
      KC_LCTL,    KC_LGUI,  KC_LALT,                            CP_SPC,                                  KC_RALT,  KC_RGUI,  KC_RCTL),
  [_DVORAK] = LAYOUT_tsangan(
      KC_ESC,     KC_1,     KC_2,     KC_3,  KC_4,  KC_5,    KC_6,  KC_7,  KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSLS,  CP_GRV,
      KC_TAB,     KC_Q,     KC_W,     KC_E,  KC_R,  KC_T,    KC_Y,  KC_U,  KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSPC,
      CP_CAPS,    KC_A,     KC_S,     KC_D,  KC_F,  KC_G,    KC_H,  KC_J,  KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT ,
      KC_LSFT,    KC_Z,     KC_X,     KC_C,  KC_V,  KC_B,    KC_N,  KC_M,  KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,            KC_DEL ,
      KC_LCTL,    KC_LGUI,  KC_LALT,                            CP_SPC,                                  KC_RALT,  KC_RGUI,  KC_RCTL),
  [_GAME] = LAYOUT_tsangan(
      M(M_FLASK), KC_1,     KC_2,     KC_3,  KC_4,  KC_5,    KC_6,  KC_7,  KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSLS,  CP_GRV,
      KC_TAB,     KC_Q,     KC_W,     KC_E,  KC_R,  KC_T,    KC_Y,  KC_U,  KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSPC,
      CP_CAPS,    KC_A,     KC_S,     KC_D,  KC_F,  KC_G,    KC_H,  KC_J,  KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT ,
      KC_LSFT,    KC_Z,     KC_X,     KC_C,  KC_V,  KC_B,    KC_N,  KC_M,  KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,            KC_DEL ,
      KC_LCTL,    KC_LGUI,  KC_LALT,                            KC_SPC,                                  KC_RALT,  KC_RGUI,  KC_RCTL),
  [_FN] = LAYOUT_tsangan(
      MO(_LAYER), ___V___,  ___V___,  ___V___,  ___V___,  ___V___,  ___V___,  ___V___,  ___V___,  ___V___,  ___V___,  ___V___,  ___V___,  ___V___,  ___V___,
      ___V___,    ___V___,  ___V___,  ___V___,  ___V___,  ___V___,  ___V___,  ___V___,  ___V___,  ___V___,  ___V___,  ___V___,  ___V___,  ___V___,
      CP_CAPS,    ___V___,  ___V___,  ___V___,  ___V___,  ___V___,  ___V___,  ___V___,  ___V___,  ___V___,  ___V___,  ___V___,            ___V___ ,
      ___V___,    ___V___,  ___V___,  ___V___,  ___V___,  ___V___,  ___V___,  ___V___,  ___V___,  ___V___,  ___V___,  ___V___,            ___V___ ,
      ___V___,    ___V___,  ___V___,                                     KC_SPC,                                      ___V___,  ___V___,  ___V___),
  [_LAYER] = LAYOUT_tsangan(
		_______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
		_______,  BASE,     DVORAK,   GAME,     _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
		_______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            RESET,
		_______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
		_______,  _______,  _______,                                     _______,                                     _______,  _______,  _______),
};


const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
	keyevent_t event = record->event;

	switch (id) {
		case M_FLASK:
			if (record->event.pressed) {
				return MACRO( T(1), T(2), T(3), T(4), T(5), END );
			}
			break;
	}
	return MACRO_NONE;
}


void matrix_init_user(void) {
  //user initialization
}

void matrix_scan_user(void) {
  //user matrix
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return true;
}
