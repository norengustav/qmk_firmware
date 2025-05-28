// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum sofle_layers {
    /* _M_XYZ = Mac Os, _W_XYZ = Win/Linux */
    _BASE,
    _SYM,
    _NAV,
    _MOUSE,
    _NUM,
    _FUN,
    _MEDIA,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* LAYER TEMPLATE
[_TEMP] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,                _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                    _______, _______, _______, _______, _______,                _______, _______, _______, _______, _______
),
*/

[_BASE] = LAYOUT(
  XXXXXXX,      XXXXXXX,    XXXXXXX,     XXXXXXX,     XXXXXXX, XXXXXXX,                                  XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,        XXXXXXX, XXXXXXX,
  XXXXXXX,         KC_Q,       KC_W,        KC_E,        KC_R,    KC_T,                                     KC_Y,        KC_U,        KC_I,        KC_O,           KC_P, KC_BSLS,
  XXXXXXX,LGUI_T(KC_A),LALT_T(KC_S),LCTL_T(KC_D),LSFT_T(KC_F),    KC_G,                                     KC_H,LSFT_T(KC_J),LCTL_T(KC_K),LALT_T(KC_L),LGUI_T(KC_SCLN), KC_QUOT,
  KC_LCTL,         KC_Z,       KC_X,        KC_C,        KC_V,    KC_B, XXXXXXX,                XXXXXXX,    KC_N,        KC_M,     KC_COMM,      KC_DOT,        KC_SLSH, XXXXXXX,
       XXXXXXX, XXXXXXX, LT(_MEDIA, KC_ESC),LT(_NAV, KC_SPC),LT(_MOUSE, KC_TAB),                LT(_NUM, KC_ENT),LT(_SYM, KC_BSPC),LT(_FUN, KC_DEL), XXXXXXX, KC_RALT
),

[_SYM] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX,  KC_GRV,   KC_LT,   KC_GT, KC_MINS, KC_BSLS,                                  KC_CIRC, KC_LCBR, KC_RCBR,  KC_DLR,   KC_AT, XXXXXXX,
  KC_QUOT, KC_EXLM, KC_ASTR, KC_SLSH,  KC_EQL, KC_UNDS,                                  KC_HASH, KC_LPRN, KC_RPRN, KC_COLN, KC_SCLN, XXXXXXX,
  KC_QUES, KC_TILD, KC_PLUS, KC_LBRC, KC_RBRC, KC_DQUO, _______,                _______, KC_AMPR, KC_PERC, KC_COMM,  KC_DOT, KC_PIPE, XXXXXXX,
                    _______, _______, _______, _______, _______,                _______, _______, _______, _______, _______
),

[_NAV] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX,  KC_INS, KC_CAPS, KC_PSCR,  KC_ESC,                                  KC_UNDO, KC_COPY, KC_PSTE,  KC_CUT, KC_AGIN, XXXXXXX,
  XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_BSPC,                                  KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, KC_PGUP, KC_PGDN,  KC_SPC,  KC_ENT, _______,                _______, KC_HOME, KC_PGDN, KC_PGUP,  KC_END, XXXXXXX, XXXXXXX,
                    _______, _______, _______, _______, _______,                _______, _______, _______, _______, _______
),

[_MOUSE] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, MS_ACL0, MS_ACL1, MS_ACL2,  KC_ESC,                                  KC_UNDO, KC_COPY, KC_PSTE,  KC_CUT, KC_AGIN, XXXXXXX,
  XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_BSPC,                                  MS_LEFT, MS_DOWN,   MS_UP, MS_RGHT, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  KC_SPC,  KC_ENT, _______,                _______, MS_WHLL, MS_WHLD, MS_WHLU,  MS_WHLR, XXXXXXX, XXXXXXX,
                    _______, _______, _______, _______, _______,                KC_BTN2, KC_BTN1, KC_BTN3, _______, _______
),

[_NUM] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX,  KC_NUM,    KC_8,    KC_7,    KC_6,  KC_ESC,                                  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX,    KC_2,    KC_1,    KC_0,    KC_9,                                  XXXXXXX, KC_PLUS, KC_MINS, KC_EQL, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX,    KC_5,    KC_4,    KC_3,  KC_ENT, _______,                _______, XXXXXXX, KC_SLSH, KC_ASTR, XXXXXXX, XXXXXXX, XXXXXXX,
                    _______, _______, _______, _______, _______,                _______, _______, _______, _______, _______
),

[_FUN] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX,  KC_F11,   KC_F8,   KC_F7,   KC_F6,  KC_ESC,                                  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX,  KC_F10,   KC_F2,   KC_F1, XXXXXXX,   KC_F9,                                  XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX,  KC_F12,   KC_F5,   KC_F4,   KC_F3,  KC_ENT, _______,                _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                    _______, _______, _______, _______, _______,                _______, _______, _______, _______, _______
),

[_MEDIA] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX,                                  XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, KC_MUTE, KC_VOLD, KC_VOLU, XXXXXXX, _______,                _______, XXXXXXX, KC_MUTE, KC_VOLD, KC_VOLU, XXXXXXX, XXXXXXX,
                    _______, _______, _______, _______, _______,                _______, _______, _______, _______, _______
),

};
