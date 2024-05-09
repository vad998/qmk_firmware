/**
 * Copyright 2022 Charly Delay <charly@codesink.dev> (@0xcharly)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

enum charybdis_keymap_layers {
    LAYER_BASE = 0,
    LAYER_LOWER,
    LAYER_RAISE,
    LAYER_POINTER,
};

// Tap Dance declarations
enum {
    TD_ESC_CAPS,
    TD_T_LKB,
    TD_Y_RKB,
    TD_G_LKB,
    TD_H_RKB,
    TD_B_LKB,
    TD_N_RKB,
    TD_F_LKB,
    TD_J_RKB,
};

// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [TD_ESC_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_CAPS),
    // Tap once for T, twice for {
    [TD_T_LKB] = ACTION_TAP_DANCE_DOUBLE(KC_T, KC_LEFT_BRACKET),
    // Tap once for T, twice for {
    [TD_Y_RKB] = ACTION_TAP_DANCE_DOUBLE(KC_Y, KC_RIGHT_BRACKET),
    // Tap once for T, twice for {
    [TD_G_LKB] = ACTION_TAP_DANCE_DOUBLE(KC_G, KC_LEFT_CURLY_BRACE),
    // Tap once for T, twice for {
    [TD_H_RKB] = ACTION_TAP_DANCE_DOUBLE(KC_H, KC_RIGHT_CURLY_BRACE),
    // Tap once for T, twice for {
    [TD_B_LKB] = ACTION_TAP_DANCE_DOUBLE(KC_B, KC_LEFT_ANGLE_BRACKET),
    // Tap once for T, twice for {
    [TD_N_RKB] = ACTION_TAP_DANCE_DOUBLE(KC_N, KC_RIGHT_ANGLE_BRACKET),
    // Tap once for T, twice for {
    [TD_F_LKB] = ACTION_TAP_DANCE_DOUBLE(KC_F, KC_LEFT_PAREN),
    // Tap once for T, twice for {
    [TD_J_RKB] = ACTION_TAP_DANCE_DOUBLE(KC_J, KC_RIGHT_PAREN),

};

/** \brief Automatically enable sniping-mode on the pointer layer. */
#define CHARYBDIS_AUTO_SNIPING_ON_LAYER LAYER_POINTER

#ifdef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
static uint16_t auto_pointer_layer_timer = 0;

#    ifndef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS
#        define CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS 1000
#    endif // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS

#    ifndef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD
#        define CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD 8
#    endif // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD
#endif     // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE

#define LOWER MO(LAYER_LOWER)
#define RAISE MO(LAYER_RAISE)
#define PT_Z LT(LAYER_POINTER, KC_Z)
#define PT_SLSH LT(LAYER_POINTER, KC_SLSH)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_BASE] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       TD(TD_ESC_CAPS),     KC_Q,    KC_W,    KC_E,    KC_R,    KC_T, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_LBRC,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_DEL, MT(MOD_LCTL, KC_A), MT(MOD_LSFT, KC_S), MT(MOD_LALT, KC_D), MT(MOD_LGUI, KC_F), TD(TD_G_LKB), TD(TD_H_RKB), MT(MOD_RCTL, KC_J), MT(MOD_RSFT, KC_K), MT(MOD_LALT, KC_L), MT(MOD_RGUI, KC_SCLN), KC_QUOT,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_LSFT,    PT_Z,    KC_X,    KC_C,    KC_V,    KC_B, KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RBRC,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                  KC_LCTL,  LOWER,   MT(MOD_LGUI,KC_ENT), KC_BSPC, LT(RAISE, KC_SPC)
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),
 
  [LAYER_LOWER] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       KC_TILDE, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,       KC_6,       KC_7,    KC_8,    KC_9, KC_0,    KC_F17,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_GRAVE, KC_EXCLAIM, KC_AT, KC_HASH, KC_DOLLAR, KC_PERCENT, KC_CIRCUMFLEX, KC_AMPERSAND, KC_ASTERISK, KC_LEFT_PAREN, KC_RIGHT_PAREN, KC_F18,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, KC_PIPE, KC_UNDERSCORE, KC_PLUS, KC_BACKSLASH,  KC_F15,    KC_F16, KC_EQUAL, KC_MINS, XXXXXXX, KC_F8, KC_F14,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                  KC_LGUI, XXXXXXX, KC_LALT,    KC_LCTL, KC_LALT
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),

  [LAYER_RAISE] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       KC_F1,   KC_F2,    KC_F3,    KC_F4,   KC_F5,   KC_F6,    KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,   KC_F12,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_DEL, KC_TAB, KC_PSCR, C(KC_LEFT), C(KC_RGHT), EE_CLR,       EE_CLR,  XXXXXXX,  KC_UP,  XXXXXXX, KC_VOLU, KC_VOLD,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, KC_LGUI, XXXXXXX, KC_HOME,  KC_END, QK_BOOT,  QK_BOOT, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, KC_MUTE,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                  KC_LCTL, KC_LSFT, KC_LALT,    _______, XXXXXXX
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),

  [LAYER_POINTER] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DPI_MOD, S_D_MOD,    S_D_MOD, DPI_MOD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_DEL, KC_LGUI, KC_LCTL, KC_LSFT, KC_LALT, XXXXXXX,    XXXXXXX, KC_RCTL, KC_RSFT, KC_RALT, KC_RGUI, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, _______, KC_ACL0, KC_ACL1, DRGSCRL,  CARRETM,   QK_BOOT, EE_CLR,  SNIPING, XXXXXXX, _______, XXXXXXX,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                  KC_BTN2, KC_BTN1, KC_BTN3,    KC_BTN3, KC_BTN1
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),
};
// clang-format on

#ifdef POINTING_DEVICE_ENABLE
#    ifdef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    if (abs(mouse_report.x) > CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD || abs(mouse_report.y) > CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD) {
        if (auto_pointer_layer_timer == 0) {
            layer_on(LAYER_POINTER);
#        ifdef RGB_MATRIX_ENABLE
            rgb_matrix_mode_noeeprom(RGB_MATRIX_NONE);
            rgb_matrix_sethsv_noeeprom(HSV_GREEN);
#        endif // RGB_MATRIX_ENABLE
        }
        auto_pointer_layer_timer = timer_read();
    }
    return mouse_report;
}

void matrix_scan_user(void) {
    if (auto_pointer_layer_timer != 0 && TIMER_DIFF_16(timer_read(), auto_pointer_layer_timer) >= CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS) {
        auto_pointer_layer_timer = 0;
        layer_off(LAYER_POINTER);
#        ifdef RGB_MATRIX_ENABLE
        rgb_matrix_mode_noeeprom(RGB_MATRIX_DEFAULT_MODE);
#        endif // RGB_MATRIX_ENABLE
    }
}
#    endif // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE

#    ifdef CHARYBDIS_AUTO_SNIPING_ON_LAYER
layer_state_t layer_state_set_user(layer_state_t state) {
    charybdis_set_pointer_sniping_enabled(layer_state_cmp(state, CHARYBDIS_AUTO_SNIPING_ON_LAYER));
    return state;
}
#    endif // CHARYBDIS_AUTO_SNIPING_ON_LAYER
#endif     // POINTING_DEVICE_ENABLE

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(RAISE, KC_SPC):
            return TAPPING_TERM + 1250;
        case MT(MOD_LALT, KC_A):
            return 400;
        default:
            return TAPPING_TERM;
    }
}