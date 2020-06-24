#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  TMUX
};

#define PROG 0
#define NAVI 1

#define NAVI_ESC LT(NAVI, KC_ESC)
#define NAVI_ENT LT(NAVI, KC_ENT)
#define COMPOSE  KC_RALT

#define ENG LGUI(LALT(LCTL(KC_E)))
#define RUS LGUI(LALT(LCTL(KC_R)))

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
#define DISCRD LGUI(KC_D)
#define TELE LGUI(KC_G)
#define CHROM LGUI(KC_B)
#define TERM LGUI(KC_T)

/* chromium */
#define GC_LFT LCTL(LSFT(KC_TAB))
#define GC_RGT LCTL(KC_TAB)
#define GC_CLS LCTL(KC_W)
/* #define GC_RST LGUI(LSFT(KC_T)) */
/* #define GC_REL LCTL(KC_R) */
/* #define GC_NEW LCTL(KC_T) */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [PROG] = LAYOUT(
    KC_ESC,  KC_F1,  KC_F2,   KC_F3,    KC_F4,    KC_F5,       KC_F6,     KC_F7,     KC_F8,
    KC_EQL,  KC_1,   KC_2,    KC_3,     KC_4,     KC_5,
    KC_TAB,  KC_Q,   KC_W,    KC_E,     KC_R,     KC_T,
    KC_LSFT, SFT_A,  CTRL_S,  ALT_D,    GUI_F,    KC_G,
    TMUX,    KC_Z,   KC_X,    KC_C,     KC_V,     KC_B,
             KC_GRV, KC_TILD, KC_LEFT,  KC_RGHT,
                                                  KC_TAB,      KC_HOME,
                                                               KC_END,
                                        KC_BSPC,  NAVI_ESC,    ENG,


    KC_F9,   KC_F10, KC_F11,  KC_F12,   KC__MUTE, KC__VOLDOWN, KC__VOLUP, _______,   KC_SLEP,
                              KC_6,     KC_7,     KC_8,        KC_9,      KC_0,      KC_MINS,
                              KC_Y,     KC_U,     KC_I,        KC_O,      KC_P,      KC_BSLS,
                              KC_H,     GUI_J,    ALT_K,       CTRL_L,    SFT_SCLN,  KC_QUOT,
                              KC_N,     KC_M,     KC_COMM,     KC_DOT,    KC_SLSH,   COMPOSE,
                                        KC_DOWN,  KC_UP,       KC_LBRC,   KC_RBRC,
                     KC_PGUP, KC_TAB,
                     KC_PGDN,
                     RUS,     NAVI_ENT, KC_SPC
  ),

  [NAVI] = LAYOUT(
    _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, KC_PSCREEN,
    _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,
             _______, _______, _______, _______,
                                                 _______, _______,
                                                          _______,
                                        _______, _______, _______,

    RESET,   _______, _______, _______, _______, _______, _______, _______, RESET,
                               _______, _______, _______, _______, _______, _______,
                               _______, _______, _______, _______, _______, _______,
                               KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,
                               _______, GC_LFT,  GC_RGT,  GC_CLS,  _______, _______,
                                        _______, _______, _______,  _______,
                      _______, DISCRD,
                      _______,
                      TELE,    TERM,    CHROM
  )
};

void matrix_init_user(void) {
}

void matrix_scan_user(void) {
}

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

void led_set_user(uint8_t usb_led) {
}
