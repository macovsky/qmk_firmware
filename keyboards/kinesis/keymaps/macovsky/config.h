#ifndef CONFIG_USER_H
#define CONFIG_USER_H

#include "../../config.h"

// https://beta.docs.qmk.fm/using-qmk/software-features/tap_hold#ignore-mod-tap-interrupt
#define IGNORE_MOD_TAP_INTERRUPT
// #define PERMISSIVE_HOLD
#define TAPPING_TERM 300

// https://beta.docs.qmk.fm/using-qmk/software-features/one_shot_keys
// #define ONESHOT_TAP_TOGGLE 2  /* Tapping this number of times holds the key until tapped once again. */
// #define ONESHOT_TIMEOUT 1000  /* Time (in ms) before the one shot key is released */

// https://beta.docs.qmk.fm/using-qmk/advanced-keycodes/feature_leader_key#per-key-timing-on-leader-keys
// #define LEADER_PER_KEY_TIMING
// #define LEADER_TIMEOUT 250
#endif
