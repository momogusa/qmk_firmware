#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _LAYER1 1
#define _LAYER2 2

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LAYER1,
  LAYER2,
};

// Fillers to make layering more clear

#define ___ KC_NO
#define _o_ KC_TRNS

#define KC_SLBRC S(KC_LBRC)
#define KC_SRBRC S(KC_RBRC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Qwerty
   * ,--------------------------------------------------------------------------------------------------------------------.
   * | Tab    |  Q  |  W   |  E   |  R   |  T  |  -   |                 |  =   |  Y  |  U   |  I   |  O   |  P   |  \     |
   * |--------+-----+------+------+------+-----+------+-----------------+------+-----+------+------+------+------+--------|
   * | LCtrl  |  A  |  S   |  D   |  F   |  G  |  [   |                 |  ]   |  H  |  J   |  K   |  L   |  ;   |  "     |
   * |--------+-----+------+------+------+-----+------------------------+------+-----+------+------+------+------+--------|
   * | LShift |  Z  |  X   |  C   |  V   |  B  |      |                 |      |  N  |  M   |  ,   |  .   |  /   | RShift |
   * |--------------+------+------+------+-----+------+-----+------+----+------+-----+------+------+------+---------------|
   * | Esc    |     | LALT | LGUI |||||||| SPC | BSPC | DEL ||||||||    | Enter|  L1 ||||||||  F12 | RALT | RGUI | RCtrl  |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_QWERTY] = LAYOUT( \
    KC_TAB,  KC_Q, KC_W,    KC_E,    KC_R, KC_T,   KC_MINS,               KC_EQL,  KC_Y,   KC_U, KC_I,    KC_O,    KC_P,    KC_BSLS, \
    KC_LCTL, KC_A, KC_S,    KC_D,    KC_F, KC_G,   KC_LBRC,               KC_RBRC, KC_H,   KC_J, KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
    KC_LSFT, KC_Z, KC_X,    KC_C,    KC_V, KC_B,   ___,                   ___,     KC_N,   KC_M, KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, \
    KC_ESC,  ___,  KC_LALT, KC_LGUI,       KC_SPC, KC_BSPC, KC_DEL,  ___, KC_ENT,  LAYER1,       KC_F12,  KC_RALT, KC_RGUI, KC_RCTL  \
  ),

  /* Layer1
   * ,----------------------------------------------------------------------------------------------------------------.
   * | ESC  |  1  |  2  |  3  |  4   |  5  |      |                  |     |  6   |  7   |  8    |  9    |  0  | BSPC |
   * |------+-----+-----+-----+------+-----+------+------------------+-----+------+------+-------+-------+-----+------|
   * |   *  |  [  |  {  |  =  |  -   |  `  |      |                  |     | LEFT | DOWN |  UP   | RIGHT |     | DEL  |
   * |------+-----+-----+-----+------+-----+-------------------------+-----+------+------+-------+-------+-----+------|
   * |   *  |  ]  |  }  |  +  |  _   |  ~  |  *   |                  |  *  |      |      | LANG1 | LANG2 |     |  *   |
   * |------+-----+-----+-----+------+-----+------+-----+------+-----+-----+------+------+-------+-------+-----+------|
   * |   *  |  *  |  *  |  *  ||||||||  L2 |  *   |  *  ||||||||  *  |  *  |      ||||||||  *    |  *    |  *  |  *   |
   * ,--------------------------------------------------------------------------------------------------------------------.
   */
  [_LAYER1] = LAYOUT(
    KC_ESC, KC_1,    KC_2,     KC_3,    KC_4,    KC_5,    ___,            ___, KC_6,    KC_7,    KC_8,     KC_9,     KC_0, KC_BSPC, \
    _o_,    KC_LBRC, KC_SLBRC, KC_EQL,  KC_MINS, KC_GRV,  ___,            ___, KC_LEFT, KC_DOWN, KC_UP,    KC_RIGHT, ___,  KC_DEL, \
    _o_,    KC_RBRC, KC_SRBRC, KC_PLUS, KC_UNDS, KC_TILD, _o_,            _o_, ___,     ___,     KC_LANG2, KC_LANG1, ___,  _o_, \
    _o_,    _o_,     _o_,      _o_,              LAYER2,  _o_, _o_,  _o_, _o_, ___,              _o_,      _o_,      _o_,  _o_ \
  ),

  /* Layer2
  * ,---------------------------------------------------------------------------------------------------------------------------.
  * | ESC |   F1    |   F2    |   F3  |   F4     |  F5 |     |                   |     |  F6  |  F7    |  F8  |  F9 | F10 | F11 |
  * |-----+---------+---------+-------+----------+-----+-----+-------------------+-----+------+--------+------+-----+-----+-----|
  * |  *  | MS_LEFT | MS_DOWN | MS_UP | MS_RIGHT |     |     |                   |     | HOME | PGDOWN | PGUP | END |     | F12 |
  * |-----+---------+---------+-------+----------+-----------+-------------------+-----+------+--------+------+-----+-----+-----|
  * |  *  |         |         | BTN1  | BTN2     |     |  *  |                   |  *  |      |        |      |     |     |  *  |
  * |-----+---------+---------+-------+----------+-----+-----+-----+-----+-------+-----+------+--------+------+-----+-----+-----|
  * |  *  |  *      |  *      |  *    ||||||||||||     |  *  |  *  ||||||| RESET |  *  |      ||||||||||  *   |  *  |  *  |  *  |
  * ,--------------------------------------------------------------------------------------------------------------------------.
  */
  [_LAYER2] = LAYOUT(
    KC_ESC, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5, ___,              ___, KC_F6,   KC_F7,     KC_F8,   KC_F9,  KC_F10, KC_F11, \
    _o_,    KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, ___,   ___,              ___, KC_HOME, KC_PGDOWN, KC_PGUP, KC_END, ___,    KC_F12, \
    _o_,    ___,     ___,     KC_BTN1, KC_BTN2, ___,   _o_,              _o_, ___,     ___,       ___,     ___,    ___,    _o_, \
    _o_,    _o_,     _o_,     _o_,              ___,   _o_, _o_,  RESET, _o_, ___,                _o_,     _o_,    _o_,    _o_ \
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LAYER1:
      if (record->event.pressed) {
        layer_on(_LAYER1);
      } else {
        layer_off(_LAYER1);
      }
      return false;
      break;
    case LAYER2:
      if (record->event.pressed) {
        layer_on(_LAYER2);
      } else {
        layer_off(_LAYER2);
      }
      return false;
      break;
  }
  return true;
}