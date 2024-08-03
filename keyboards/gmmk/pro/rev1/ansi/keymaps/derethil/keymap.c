
#include <stdint.h>
#include "process_tap_dance.h"
#include QMK_KEYBOARD_H
#include "encoder.c"

enum {
    TD_ESC_CAPS,
};

tap_dance_action_t tap_dance_actions[] = {[TD_ESC_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_CAPS)};

// clang-format off

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//    ┌─────────────────┬──────┬──────┬────┬────┬────┬────┬────┬────┬────┬──────┬───────┬──────┬──────┐      ┌──────┐
//    │       esc       │  f1  │  f2  │ f3 │ f4 │ f5 │ f6 │ f7 │ f8 │ f9 │ f10  │  f11  │ f12  │ pscr │      │ mute │
//    ├─────────────────┼──────┼──────┼────┼────┼────┼────┼────┼────┼────┼──────┼───────┼──────┼──────┤      ├──────┤
//    │        `        │  1   │  2   │ 3  │ 4  │ 5  │ 6  │ 7  │ 8  │ 9  │  0   │   -   │  =   │ bspc │      │ del  │
//    ├─────────────────┼──────┼──────┼────┼────┼────┼────┼────┼────┼────┼──────┼───────┼──────┼──────┤      ├──────┤
//    │       tab       │  q   │  w   │ e  │ r  │ t  │ y  │ u  │ i  │ o  │  p   │   [   │  ]   │  \   │      │ ins  │
//    ├─────────────────┼──────┼──────┼────┼────┼────┼────┼────┼────┼────┼──────┼───────┼──────┴──────┤      ├──────┤
//    │ TD(TD_ESC_CAPS) │  a   │  s   │ d  │ f  │ g  │ h  │ j  │ k  │ l  │  ;   │   '   │     ent     │      │ home │
//    ├─────────────────┴──────┼──────┼────┼────┼────┼────┼────┼────┼────┼──────┼───────┼─────────────┼──────┼──────┤
//    │          lsft          │  z   │ x  │ c  │ v  │ b  │ n  │ m  │ ,  │  .   │   /   │    rsft     │  up  │ end  │
//    ├─────────────────┬──────┼──────┼────┴────┴────┴────┴────┴────┴────┼──────┼───────┼──────┬──────┼──────┼──────┤
//    │      lctl       │ lgui │ lalt │               spc                │ ralt │ MO(1) │ rctl │ left │ down │ rght │
//    └─────────────────┴──────┴──────┴──────────────────────────────────┴──────┴───────┴──────┴──────┴──────┴──────┘
[0] = LAYOUT(
  KC_ESC          , KC_F1   , KC_F2   , KC_F3 , KC_F4 , KC_F5 , KC_F6 , KC_F7 , KC_F8 , KC_F9   , KC_F10  , KC_F11  , KC_F12  , KC_PSCR ,           KC_MUTE,
  KC_GRV          , KC_1    , KC_2    , KC_3  , KC_4  , KC_5  , KC_6  , KC_7  , KC_8  , KC_9    , KC_0    , KC_MINS , KC_EQL  , KC_BSPC ,           KC_DEL ,
  KC_TAB          , KC_Q    , KC_W    , KC_E  , KC_R  , KC_T  , KC_Y  , KC_U  , KC_I  , KC_O    , KC_P    , KC_LBRC , KC_RBRC , KC_BSLS ,           KC_INS ,
  TD(TD_ESC_CAPS) , KC_A    , KC_S    , KC_D  , KC_F  , KC_G  , KC_H  , KC_J  , KC_K  , KC_L    , KC_SCLN , KC_QUOT ,            KC_ENT ,           KC_HOME,
  KC_LSFT                   , KC_Z    , KC_X  , KC_C  , KC_V  , KC_B  , KC_N  , KC_M  , KC_COMM , KC_DOT  , KC_SLSH ,           KC_RSFT , KC_UP   , KC_END ,
  KC_LCTL         , KC_LGUI , KC_LALT ,                         KC_SPC                          , KC_RALT , MO(1)   , KC_RCTL , KC_LEFT , KC_DOWN , KC_RGHT
),

//    ┌─────┬─────────┬─────────┬─────────┬─────────┬──────┬──────┬─────────┬──────┬──────┬──────┬──────┬─────┬─────────┐          ┌─────────┐
//    │     │ RGB_TOG │ RGB_VAI │ RGB_VAD │ RGB_HUI │ mprv │ mnxt │  mply   │ mstp │ mute │ vold │ volu │     │         │          │         │
//    ├─────┼─────────┼─────────┼─────────┼─────────┼──────┼──────┼─────────┼──────┼──────┼──────┼──────┼─────┼─────────┤          ├─────────┤
//    │     │         │         │         │         │      │      │         │      │      │      │      │     │         │          │         │
//    ├─────┼─────────┼─────────┼─────────┼─────────┼──────┼──────┼─────────┼──────┼──────┼──────┼──────┼─────┼─────────┤          ├─────────┤
//    │     │         │         │         │         │      │      │         │      │      │      │      │     │ QK_BOOT │          │         │
//    ├─────┼─────────┼─────────┼─────────┼─────────┼──────┼──────┼─────────┼──────┼──────┼──────┼──────┼─────┴─────────┤          ├─────────┤
//    │     │         │         │         │         │      │      │         │      │      │      │      │               │          │         │
//    ├─────┴─────────┼─────────┼─────────┼─────────┼──────┼──────┼─────────┼──────┼──────┼──────┼──────┼───────────────┼──────────┼─────────┤
//    │               │         │         │         │      │      │ NK_TOGG │      │      │      │      │               │ RGB_MOD  │         │
//    ├─────┬─────────┼─────────┼─────────┴─────────┴──────┴──────┴─────────┴──────┴──────┼──────┼──────┼─────┬─────────┼──────────┼─────────┤
//    │     │         │         │                                                         │      │      │     │ RGB_SPD │ RGB_RMOD │ RGB_SPI │
//    └─────┴─────────┴─────────┴─────────────────────────────────────────────────────────┴──────┴──────┴─────┴─────────┴──────────┴─────────┘
[1] = LAYOUT(
  _______ , RGB_TOG , RGB_VAI , RGB_VAD , RGB_HUI , KC_MPRV , KC_MNXT , KC_MPLY , KC_MSTP , KC_MUTE , KC_VOLD , KC_VOLU , _______ , _______ ,            _______,
  _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ ,            _______,
  _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , QK_BOOT ,            _______,
  _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ ,           _______ ,            _______,
  _______           , _______ , _______ , _______ , _______ , _______ , NK_TOGG , _______ , _______ , _______ , _______ ,           _______ , RGB_MOD  , _______,
  _______ , _______ , _______ ,                               _______                               , _______ , _______ , _______ , RGB_SPD , RGB_RMOD , RGB_SPI
)
};

