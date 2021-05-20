#include QMK_KEYBOARD_H

#define PROG 0
#define NAVI 1

#define NAVI_ESC LT(NAVI, KC_ESC)
#define COMPOSE  KC_RALT

/* switch locale */
#define CTL_CAPS  LCTL_T(KC_CAPS)
#define SFT_CAPS  RSFT(KC_CAPS)

/* mods */
#define SFT_A SFT_T(KC_A)
#define CTRL_S CTL_T(KC_S)
#define ALT_D ALT_T(KC_D)
#define GUI_F GUI_T(KC_F)

#define GUI_J GUI_T(KC_J)
#define ALT_K ALT_T(KC_K)
#define CTRL_L CTL_T(KC_L)
#define SFT_SCLN SFT_T(KC_SCLN)

/* apps */
#define EMACS LGUI(KC_E)
#define TERM LGUI(KC_T)
#define BROWSER LGUI(KC_B)

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  TMUX
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [PROG] = LAYOUT(
    KC_GESC, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,    KC_F6,       KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______,
    KC_EQL,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, _______, _______,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                  KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS, _______, _______, _______,
    KC_LSFT, SFT_A,   CTRL_S,  ALT_D,   GUI_F,   KC_G,     _______,     KC_H,    GUI_J,   ALT_K,   CTRL_L,  SFT_SCLN,KC_QUOT, _______, _______,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,     _______,     KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, COMPOSE,          _______,
    TMUX,    KC_GRAVE,CTL_CAPS,         MO(NAVI),     NAVI_ESC, KC_ENT, KC_SPC,           SFT_CAPS,         KC_LBRC, KC_RBRC, _______, _______, _______),
  [NAVI] = LAYOUT(
    RESET,   _______, _______, _______, _______, _______,   _______,    _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,               _______, _______, _______, _______, _______, _______, _______, _______,
    RGB_TOG, RGB_MOD, RGB_VAI, RGB_HUI, _______, _______,               _______, _______, _______, _______, KC_PSCR, _______, _______, _______, _______,
    _______, RGB_SPD, RGB_VAD, RGB_SPI, _______, _______,   _______,    KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, _______,_______, _______, _______,
    _______, _______, _______, _______, _______, _______,   _______,    _______, _______, _______, _______, _______, _______,          _______,
    _______, _______, _______,          _______,       _______, KC_DEL, KC_BSPC,          _______,          _______, _______, _______, _______, _______)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case TMUX:
            if (record->event.pressed) {
                register_code(KC_LCTL);
                tap_code(KC_F);
            } else {
                unregister_code(KC_LCTL);
            }
            break;
    }
    return true;
}
