#include QMK_KEYBOARD_H
extern bool g_suspend_state;

// Layers
#define _BASE 0 // Base
#define _FN   1 // Function
#define _AV   2 // Audio/Visual
#define _NUMP 3 // Numpad

// Aliases
#define _______ KC_TRNS
#define XXXXXXX KC_NO

// Compound keys
#define CP_RSFT RSFT_T(KC_SLSH) // Right shift key
#define CP_DEL  LT(_AV, KC_DEL) // Delete key
#define CP_CAPS CTL_T(KC_ESC)   // Caps Lock key


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT(
      /* Base layer
      * ,---------------------------------------------------------------------------------------------------------------------.
      * |  ` ~  |   1   |   2   |   3   |   4   |   5   |   6   |   7   |   8   |   9   |   0   |   -   |   =   |  Backspace  |
      * |---------------------------------------------------------------------------------------------------------------------+
      * |   Tab    |   Q   |   W   |   E   |   R   |   T   |   Y   |   U   |   I   |   O   |   P   |   [   |   ]   |     \    |
      * |---------------------------------------------------------------------------------------------------------------------+
      * | Esc + Ctrl |   A   |   S   |   D   |   F   |   G   |   H   |   J   |   K   |   L   |   ;   |   '   |      Enter     |
      * |---------------------------------------------------------------------------------------------------------------------+
      * |      Shift     |   Z   |   X   |   C   |   V   |   B   |   N   |   M   |   ,   |   .   | / + RShift |   ▲   |Del+LT2|
      * |---------------------------------------------------------------------------------------------------------------------+
      * |   Ctrl  |   GUI   |   Alt   |                     Space                     |  RAlt |  LT1  |   ◄   |   ▼   |   ►   |
      * `---------------------------------------------------------------------------------------------------------------------'
      */
      KC_GRV,   KC_1,     KC_2,     KC_3,  KC_4,  KC_5,    KC_6,  KC_7,  KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,\
      KC_TAB,   KC_Q,     KC_W,     KC_E,  KC_R,  KC_T,    KC_Y,  KC_U,  KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,\
      CP_CAPS,  KC_A,     KC_S,     KC_D,  KC_F,  KC_G,    KC_H,  KC_J,  KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT ,\
      KC_LSFT,  KC_Z,     KC_X,     KC_C,  KC_V,  KC_B,    KC_N,  KC_M,  KC_COMM,  KC_DOT,   CP_RSFT,  KC_UP,              CP_DEL ,\
      KC_LCTL,  KC_LGUI,  KC_LALT,                KC_SPC,                KC_RALT,  MO(_FN),  KC_LEFT,  KC_DOWN,            KC_RGHT),
  [_FN] = LAYOUT(
      TO(_NUMP), KC_F1,  KC_F2,   KC_F3,   KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,   KC_F10,    KC_F11,   KC_F12,   KC_DEL ,\
      XXXXXXX,  XXXXXXX, KC_UP,   XXXXXXX, XXXXXXX,  XXXXXXX,  KC_CALC,  XXXXXXX,  KC_INS,   XXXXXXX,  KC_PSCR,  KC_SLCK,  KC_PAUS,  RESET  ,\
      XXXXXXX,  KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,\
      XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_PGUP,            KC_INS ,\
      XXXXXXX,  XXXXXXX, XXXXXXX,                    XXXXXXX,                      XXXXXXX,  _______,  KC_HOME,  KC_PGDN,            KC_END),
  [_AV] = LAYOUT(
      XXXXXXX,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,     KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_DEL ,\
      XXXXXXX,  RGB_TOG,  XXXXXXX,  RGB_HUI,  RGB_HUD,  RGB_SAI,  RGB_SAD,  RGB_VAI,  RGB_VAD,   RGB_MOD,  XXXXXXX,  XXXXXXX,  XXXXXXX,  RESET  ,\
      XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  RGB_SPI,   RGB_SPD,  XXXXXXX,  XXXXXXX,            _______,\
      XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,  KC_VOLU,            KC_MUTE,\
      XXXXXXX,  XXXXXXX,  XXXXXXX,                      XXXXXXX,                      XXXXXXX,   XXXXXXX,  KC_MPRV,  KC_VOLD,            KC_MNXT),
  [_NUMP] = LAYOUT(
      KC_NLCK,  KC_PSLS,  KC_PAST,  KC_PMNS,  KC_PPLS,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, KC_PSLS,  KC_PAST,  KC_PMNS,  KC_PPLS, _______,\
      _______,  KC_P7,    KC_P8,    KC_P9,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_P7,   KC_P8,    KC_P9,    XXXXXXX,  XXXXXXX,  TO(_BASE),\
      _______,  KC_P4,    KC_P5,    KC_P6,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_P4,   KC_P5,    KC_P6,    XXXXXXX,            KC_PENT,\
      _______,  KC_P1,    KC_P2,    KC_P3,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_P1,   KC_P2,    KC_P3,    _______,            _______,\
      _______,  KC_P0,    KC_PDOT,                      KC_PENT,                      KC_P0,   KC_PDOT,  _______,  _______,            _______),
};



void rgb_matrix_layer_helper (uint8_t red, uint8_t green, uint8_t blue, bool default_layer) {
  rgb_led led;
  for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
    led = g_rgb_leds[i];
    if (led.matrix_co.raw < 0xFF) {
      if (led.modifier) {
        rgb_matrix_set_color( i, red, green, blue );
      }
    }
  }
}

void rgb_matrix_indicators_user(void) {
  uint8_t this_led = host_keyboard_leds();
  if (!g_suspend_state) {
    switch (biton32(layer_state)) {
      case _FN:
        rgb_matrix_layer_helper(0xFF, 0x00, 0x00, false);
        break;

      case _AV:
        rgb_matrix_layer_helper(0x00, 0xFF, 0x00, false);
        break;

      case _NUMP:
        if ( this_led & (1<<USB_LED_NUM_LOCK)) {
          rgb_matrix_set_color(13, 0xFF, 0x00, 0x00);
        } else {
          rgb_matrix_set_color(13, 0x00, 0x00, 0x00);
        }
        rgb_matrix_set_color(0, 0x00, 0xFF, 0x00);
        rgb_matrix_set_color(1, 0x00, 0x00, 0x00);
        rgb_matrix_set_color(1, 0x00, 0xFF, 0x00);
        rgb_matrix_set_color(2, 0x00, 0xFF, 0x00);
        rgb_matrix_set_color(3, 0x00, 0xFF, 0x00);
        rgb_matrix_set_color(4, 0x00, 0xFF, 0x00);
        rgb_matrix_set_color(5, 0x00, 0x00, 0x00);
        rgb_matrix_set_color(6, 0x00, 0x00, 0x00);
        rgb_matrix_set_color(7, 0x00, 0x00, 0x00);
        rgb_matrix_set_color(8, 0x00, 0x00, 0x00);
        rgb_matrix_set_color(9, 0xFF, 0xFF, 0x00);
        rgb_matrix_set_color(10, 0xFF, 0xFF, 0x00);
        rgb_matrix_set_color(11, 0xFF, 0xFF, 0x00);
        rgb_matrix_set_color(12, 0xFF, 0xFF, 0x00);
        rgb_matrix_set_color(14, 0x00, 0x00, 0xFF);
        rgb_matrix_set_color(15, 0x00, 0x00, 0x00);
        rgb_matrix_set_color(16, 0x00, 0x00, 0x00);
        rgb_matrix_set_color(17, 0x00, 0xFF, 0x00);
        rgb_matrix_set_color(18, 0x00, 0xFF, 0x00);
        rgb_matrix_set_color(19, 0x00, 0xFF, 0x00);
        rgb_matrix_set_color(20, 0x00, 0x00, 0x00);
        rgb_matrix_set_color(21, 0x00, 0x00, 0x00);
        rgb_matrix_set_color(22, 0x00, 0x00, 0x00);
        rgb_matrix_set_color(23, 0x00, 0x00, 0x00);
        rgb_matrix_set_color(24, 0xFF, 0xFF, 0x00);
        rgb_matrix_set_color(25, 0xFF, 0xFF, 0x00);
        rgb_matrix_set_color(26, 0xFF, 0xFF, 0x00);
        rgb_matrix_set_color(27, 0x00, 0x00, 0x00);
        rgb_matrix_set_color(28, 0x00, 0xFF, 0x00);
        rgb_matrix_set_color(29, 0x00, 0x00, 0x00);
        rgb_matrix_set_color(30, 0x00, 0xFF, 0x00);
        rgb_matrix_set_color(31, 0x00, 0xFF, 0x00);
        rgb_matrix_set_color(32, 0x00, 0xFF, 0x00);
        rgb_matrix_set_color(33, 0x00, 0x00, 0x00);
        rgb_matrix_set_color(34, 0x00, 0x00, 0x00);
        rgb_matrix_set_color(35, 0x00, 0x00, 0x00);
        rgb_matrix_set_color(36, 0x00, 0x00, 0x00);
        rgb_matrix_set_color(37, 0xFF, 0xFF, 0x00);
        rgb_matrix_set_color(38, 0xFF, 0xFF, 0x00);
        rgb_matrix_set_color(39, 0xFF, 0xFF, 0x00);
        rgb_matrix_set_color(40, 0x00, 0x00, 0x00);
        rgb_matrix_set_color(41, 0x00, 0x00, 0x00);
        rgb_matrix_set_color(42, 0x00, 0x00, 0x00);
        rgb_matrix_set_color(43, 0x00, 0xFF, 0x00);
        rgb_matrix_set_color(44, 0x00, 0xFF, 0x00);
        rgb_matrix_set_color(45, 0x00, 0xFF, 0x00);
        rgb_matrix_set_color(46, 0x00, 0x00, 0x00);
        rgb_matrix_set_color(47, 0x00, 0x00, 0x00);
        rgb_matrix_set_color(48, 0x00, 0x00, 0x00);
        rgb_matrix_set_color(49, 0x00, 0x00, 0x00);
        rgb_matrix_set_color(50, 0xFF, 0xFF, 0x00);
        rgb_matrix_set_color(51, 0xFF, 0xFF, 0x00);
        rgb_matrix_set_color(52, 0xFF, 0xFF, 0x00);
        rgb_matrix_set_color(53, 0x00, 0x00, 0x00);
        rgb_matrix_set_color(54, 0x00, 0x00, 0x00);
        rgb_matrix_set_color(55, 0x00, 0x00, 0x00);
        rgb_matrix_set_color(56, 0x00, 0x00, 0x00);
        rgb_matrix_set_color(57, 0x00, 0xFF, 0x00);
        rgb_matrix_set_color(58, 0x00, 0xFF, 0x00);
        rgb_matrix_set_color(59, 0xFF, 0x00, 0x00);
        rgb_matrix_set_color(60, 0xFF, 0xFF, 0x00);
        rgb_matrix_set_color(61, 0xFF, 0xFF, 0x00);
        rgb_matrix_set_color(62, 0x00, 0x00, 0x00);
        break;

      /*case _LAYER4:
        rgb_matrix_layer_helper(0xFF, 0xFF, 0x00, false);
        break;*/
    }
  }
  if ( this_led & (1<<USB_LED_CAPS_LOCK)) {
    rgb_matrix_set_color(40, 0xFF, 0xFF, 0xFF);
  }

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
