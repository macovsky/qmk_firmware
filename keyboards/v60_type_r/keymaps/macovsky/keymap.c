#include QMK_KEYBOARD_H

#define FN        MO(1)
#define FN_CAPS   LT(1, KC_CAPS)
#define COMPOSE   KC_RALT

/* switch locale */
#define CTL_CAPS  LCTL_T(KC_CAPS)
#define SFT_CAPS  RSFT(KC_CAPS)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap 0: Default Layer (Qwerty)
   * ,-----------------------------------------------------------.
   * |Esc|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|   Bs  |
   * |-----------------------------------------------------------|
   * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|    \|
   * |-----------------------------------------------------------|
   * |Caps   |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return |
   * |-----------------------------------------------------------|
   * |LShift  |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /| RShift   |
   * |-----------------------------------------------------------|
   * |Ctrl|Gui |Alt |      Space              |Fn0 |Gui |App|Ctrl|
   * `-----------------------------------------------------------'
   */
  [0] = LAYOUT_60_ansi(
	       KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, \
	       KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, \
	       FN_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,  \
	       KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT,   \
	       CTL_CAPS,KC_LGUI, KC_LALT,          KC_SPC,                                      FN,      KC_RGUI, COMPOSE, SFT_CAPS),

  /* Keymap 1: FN Layer
   * ,-----------------------------------------------------------.
   * |`  | F1| F2| F3| F4| F5| F6| F7| F8| F9|F10|F11|F12|  Del  |
   * |-----------------------------------------------------------|
   * |     |   |Up |   |   |   |   |   |Prt|Scl|Pau|Up|   | Ins  |
   * |-----------------------------------------------------------|
   * |      |Lft|Dwn|Rig|   |   |   |   |Hme|PgU|Lef|Rig|        |
   * |-----------------------------------------------------------|
   * |        |   |   |   |   |VolD|VolU|Mut|End|PgD|Dwn|        |
   * |-----------------------------------------------------------|
   * |    |    |    |                        |    |    |    |    |
   * `-----------------------------------------------------------'
   */
  [1] = LAYOUT_60_ansi(
	       KC_GRV,    KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,     KC_F7,   KC_F8,   KC_F9,    KC_F10,  KC_F11,   KC_F12,  KC_DEL, \
	       _______,   _______,  KC_UP,    _______,  _______,  _______,  _______,   _______, KC_PSCR, KC_SLCK,  KC_PAUS, KC_UP,  _______,          KC_INS, \
	       _______,   KC_LEFT,  KC_DOWN,  KC_RIGHT, _______,  _______,  KC_LEFT,   KC_DOWN, KC_UP,   KC_RIGHT, KC_LEFT, KC_RIGHT,          _______,          \
	       _______,   _______,  _______,  _______,  _______,  KC_VOLD,  KC_VOLU,   KC_MUTE, KC_PGDN, KC_PGUP,  KC_DOWN,           _______,  \
	       _______,   _______,  _______,            _______,                                                           _______,  _______, _______, _______),

};

void led_set_user(uint8_t usb_led) {

}
