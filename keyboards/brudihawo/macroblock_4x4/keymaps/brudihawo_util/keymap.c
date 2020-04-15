#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

#define _NUM 0
#define _MOD 1


#define CT_COMMA     0
#define CT_SLASH     1
#define CT_TIMES     2
#define CT_PLUS      3
#define CT_ENTER     4
#define CT_MINUS     5
#define CT_ASTERISK  6

/*
 *  LAYER 0
 *
 *  +-----+-----+-----+-----+
 *  |     |     |     |  +  |
 *  |  7  |  8  |  9  |     |
 *  |     |     |     |TD(1)|
 *  +-----+-----+-----+-----+
 *  |     |     |     |  -  |
 *  |  4  |  5  |  6  |     |
 *  |     |     |     |  (  |
 *  +-----+-----+-----+-----+
 *  |     |     |     |  *  |
 *  |  1  |  2  |  3  |     |
 *  |     |     |     |  )  |
 *  +-----+-----+-----+-----+
 *  |  0  |  ,  | ENT |  /  |
 *  |     |     |     |     |
 *  |LT(1)|  .  |  =  | TAB |
 *  +-----+-----+-----+-----+
 *   
 *  LAYER 1
 *   
 *  +-----+-----+-----+-----+
 *  |     |     |     |  +  |
 *  | DEL | U P | BSP |     |
 *  |     |     |     |TD(1)|
 *  +-----+-----+-----+-----+
 *  |     |     |     |     |
 *  | LFT | ESC | RGT |CTR+C|
 *  |     |     |     |     |
 *  +-----+-----+-----+-----+
 *  |     |     |     |     |
 *  | ENT | DWN | SFT |CTR+X|
 *  |     |     |     |     |
 *  +-----+-----+-----+-----+
 *  |  0  |     |     |     |
 *  |     |CTR+Z|CTR+Y|CTR+V|
 *  |LT(1)|     |     |     |
 *  +-----+-----+-----+-----+
 *
 *  LAYER 2 -- NOT IMPLEMENTED
 *   
 *  +-----+-----+-----+-----+
 *  |     |     |     |     |
 *  |  1  |  2  |  3  |  4  |
 *  |     |     |     |     |
 *  +-----+-----+-----+-----+
 *  |     |     |     |     |
 *  |  5  |  6  |  7  |  8  |
 *  |     |     |     |     |
 *  +-----+-----+-----+-----+
 *  |     |     |     |     |
 *  |  9  |  W  |  0  |  R  |
 *  |     |     |     |     |
 *  +-----+-----+-----+-----+
 *  |     |     |     |     |
 *  |  A  |  S  |  D  |  F  |
 *  |     |     |     |     |
 *  +-----+-----+-----+-----+
 * 
 *
*/


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT(
    KC_7,        KC_8,         KC_9,         TD(CT_PLUS), \
    KC_4,        KC_5,         KC_6,         TD(CT_MINUS), \
    KC_1,        KC_2,         KC_3,         TD(CT_ASTERISK), \
    LT(1, KC_0), TD(CT_COMMA), TD(CT_ENTER), TD(CT_SLASH)),
  [1] = LAYOUT(
    KC_DEL,      KC_UP,        KC_BSPACE,    TD(CT_PLUS), \
    KC_LEFT,     KC_ESCAPE,    KC_RIGHT,     LCTL(KC_C), \
    KC_ENTER,    KC_DOWN,      KC_LSHIFT,    LCTL(KC_X), \
    KC_TRNS,     LCTL(KC_Z),   LCTL(KC_Y),   LCTL(KC_V))
};

qk_tap_dance_action_t tap_dance_actions[] = {
  [CT_COMMA]    = ACTION_TAP_DANCE_DOUBLE(KC_COMMA, KC_DOT),
  [CT_SLASH]    = ACTION_TAP_DANCE_DOUBLE(KC_KP_SLASH, KC_TAB),
  [CT_PLUS]     = ACTION_TAP_DANCE_LAYER_TOGGLE(KC_KP_PLUS, 1),
  [CT_MINUS]    = ACTION_TAP_DANCE_DOUBLE(KC_KP_MINUS, LSFT(KC_8)),
  [CT_ASTERISK] = ACTION_TAP_DANCE_DOUBLE(KC_KP_ASTERISK, LSFT(KC_9)),
  [CT_ENTER]    = ACTION_TAP_DANCE_DOUBLE(KC_KP_ENTER, LSFT(KC_0)),
};

