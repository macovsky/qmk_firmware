#include QMK_KEYBOARD_H

#define BASE 0
#define GAME 1
#define NAVI 2
#define SYS 3
#define RGB 4

#define SYS_ESC LT(SYS, KC_ESC)
#define RGB_RBR LT(RGB, KC_RBRC)
#define SFT_CAPS SFT_T(KC_CAPS)

/* mods */
#define SFT_A SFT_T(KC_A)
#define CTRL_S CTL_T(KC_S)
#define ALT_D ALT_T(KC_D)
#define GUI_F GUI_T(KC_F)

#define GUI_J GUI_T(KC_J)
#define ALT_K ALT_T(KC_K)
#define CTRL_L CTL_T(KC_L)
#define SFT_SCLN SFT_T(KC_SCLN)

#define QUIT G(KC_Q)
#define BROWSER G(A(KC_B))
#define RELOAD G(KC_R)
#define TABL S(G(KC_LBRC))
#define TABR S(G(KC_RBRC))

#define TERM G(A(KC_T))
#define EMACS G(A(KC_E))
#define TELE G(A(KC_G))
#define ZOOM G(A(KC_Z))

// TODO
#define DISC G(A(KC_V))
#define DISCJ S(G(A(KC_J)))
#define DISCK S(G(A(KC_K)))

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  TMUX
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT(
    KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,    KC_F6,        KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,     KC_F12,   _______, KC_SLEP,
    KC_EQL,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                   KC_6,    KC_7,    KC_8,    KC_9,    KC_0,       KC_MINS,  _______, DF(GAME),
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                   KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,       KC_BSLS,  _______, _______, _______,
    SFT_CAPS,SFT_A,   CTRL_S,  ALT_D,   GUI_F,   KC_G,     KC_BSPC,      KC_H,    GUI_J,   ALT_K,   CTRL_L,  SFT_SCLN,   KC_QUOT,  _______, _______,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,     _______,      KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,    _______,           _______,
    TMUX,    KC_GRV,  _______,          MO(NAVI),      SYS_ESC, KC_ENT,  KC_SPC,           _______,          KC_LBRC,    RGB_RBR,  _______, _______, _______),
  [GAME] = LAYOUT(
    KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,    KC_F6,        KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,     KC_F12,   _______, KC_SLEP,
    KC_EQL,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                   KC_6,    KC_7,    KC_8,    KC_9,    KC_0,       KC_MINS,  DF(BASE),_______,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                   KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,       KC_BSLS,  _______, _______, _______,
    SFT_CAPS,KC_A,    KC_S,    KC_D,    KC_F,    KC_G,     KC_BSPC,      KC_H,    GUI_J,   ALT_K,   CTRL_L,  SFT_SCLN,   KC_QUOT,  _______, _______,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,     _______,      KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,    _______,           _______,
    KC_GRV,  KC_GRV,  _______,          MO(NAVI),      SYS_ESC, KC_ENT,  KC_SPC,           _______,          KC_LBRC,    RGB_RBR,  _______, _______, _______),
  [NAVI] = LAYOUT(
    _______, _______, _______, _______, _______, _______,   _______,     _______, _______, _______, KC_MUTE, KC_VOLD,    KC_VOLU,  _______, _______,
    _______, _______, _______, _______, _______, _______,                _______, _______, _______, _______, _______,    _______,  _______, _______,
    _______, QUIT,    _______, EMACS,   RELOAD,  TERM,                   KC_GRV,  KC_LBRC, KC_RBRC, _______, _______,    _______,  _______, _______, _______,
    _______, _______, _______, _______, _______, TELE,      KC_DEL,      KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,_______,    _______,  _______, _______,
    _______, ZOOM,    _______, _______, _______, BROWSER,   _______,     _______, KC_PGDN, KC_PGUP, _______, _______,    _______,           _______,
    _______, _______, _______,          _______,       EMACS,   TERM,    BROWSER,          _______,          _______,    _______,  _______, _______, _______),
  [SYS] = LAYOUT(
    QK_BOOT, _______, _______, _______, _______, _______,   _______,     _______, _______, _______, KC_MUTE, KC_VOLD,    KC_VOLU,  _______, _______,
    _______, _______, _______, _______, _______, _______,                _______, _______, _______, _______, _______,    _______,  _______, _______,
    _______, _______, _______, _______, _______, _______,                _______, TABL,    TABR,    _______, _______,    _______,  _______, _______, _______,
    _______, _______, _______, _______, _______, _______,   _______,     KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______,    _______,  _______, _______,
    _______, _______, _______, _______, _______, _______,   _______,     _______, KC_WH_D, KC_WH_U, _______, _______,    _______,           _______,
    _______, _______, _______,          _______,       _______, KC_BTN1, KC_BTN2,          _______,          _______,    _______,  _______, _______, _______),
  [RGB] = LAYOUT(
    _______, _______, _______, _______, _______, _______,   _______,     _______, _______, _______, _______, _______,    _______,  _______, _______,
    _______, _______, _______, _______, _______, _______,                _______, _______, _______, _______, _______,    _______,  _______, _______,
    RGB_TOG, RGB_MOD, RGB_VAI, RGB_HUI, _______, _______,                _______, _______, _______, _______, _______,    _______,  _______, _______, _______,
    _______, RGB_SPD, RGB_VAD, RGB_SPI, _______, _______,   _______,     _______, _______, _______, _______, _______,    _______,  _______, _______,
    _______, _______, _______, _______, _______, _______,   _______,     _______, _______, _______, _______, _______,    _______,           _______,
    _______, _______, _______,          _______,       _______, _______, _______,          _______,          _______,    _______,  _______, _______, _______),
};
    /* _______, _______, _______, _______, _______, _______,   _______,     _______, _______, _______, _______, _______, _______, _______, _______, */
    /* _______, _______, _______, _______, _______, _______,                _______, _______, _______, _______, _______, _______, _______, _______, */
    /* _______, _______, _______, _______, _______, _______,                _______, _______, _______, _______, _______, _______, _______, _______, _______, */
    /* _______, _______, _______, _______, _______, _______,   _______,     _______, _______, _______, _______, _______, _______, _______, _______, */
    /* _______, _______, _______, _______, _______, _______,   _______,     _______, _______, _______, _______, _______, _______,          _______, */
    /* _______, _______, _______,          _______,       _______, _______, _______,          _______,          _______, _______, _______, _______, _______) */

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
