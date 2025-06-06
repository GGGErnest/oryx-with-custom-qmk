#include QMK_KEYBOARD_H
#include "version.h"
#define MOON_LED_LEVEL LED_LEVEL
#define ML_SAFE_RANGE SAFE_RANGE

enum custom_keycodes {
  RGB_SLD = ML_SAFE_RANGE,
  MAC_LOCK,
};



#define DUAL_FUNC_0 LT(13, KC_F13)
#define DUAL_FUNC_1 LT(3, KC_B)
#define DUAL_FUNC_2 LT(3, KC_F1)
#define DUAL_FUNC_3 LT(3, KC_3)
#define DUAL_FUNC_4 LT(5, KC_F)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_voyager(
    KC_BRIGHTNESS_UP,KC_BRIGHTNESS_DOWN,KC_SYSTEM_WAKE, KC_SYSTEM_SLEEP,MAC_LOCK,       KC_SYSTEM_POWER,                                KC_MEDIA_STOP,  KC_MEDIA_PLAY_PAUSE,KC_MEDIA_PREV_TRACK,KC_MEDIA_NEXT_TRACK,KC_AUDIO_VOL_UP,KC_AUDIO_VOL_DOWN,
    KC_TAB,         KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,                                           KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           TG(3),          
    KC_ESCAPE,      MT(MOD_LGUI, KC_A),MT(MOD_LALT, KC_S),MT(MOD_LCTL, KC_D),MT(MOD_LSFT, KC_F),KC_G,                                           MEH_T(KC_H),    MT(MOD_LSFT, KC_J),MT(MOD_RCTL, KC_K),MT(MOD_LALT, KC_L),MT(MOD_RGUI, KC_SCLN),KC_QUOTE,       
    DUAL_FUNC_0,    KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,                                           KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH,       OSM(MOD_HYPR),  
                                                    MO(1),          KC_SPACE,                                       KC_ENTER,       LT(2, KC_BSPC)
  ),
  [1] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_EXLM,        KC_AT,          KC_HASH,        KC_DLR,         KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_LPRN,        KC_RPRN,        KC_PLUS,        KC_MINUS,       KC_TRANSPARENT, 
    KC_TRANSPARENT, DUAL_FUNC_1,    DUAL_FUNC_2,    DUAL_FUNC_3,    KC_ASTR,        KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_LBRC,        MT(MOD_RCTL, KC_RBRC),MT(MOD_LALT, KC_EQUAL),DUAL_FUNC_4,    KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TILD,        KC_GRAVE,       KC_SLASH,       KC_QUES,        KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_LCBR,        KC_RCBR,        KC_BSLS,        KC_PIPE,        KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [2] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_1,           KC_2,           KC_3,           KC_4,           KC_5,                                           KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, MT(MOD_LALT, KC_HOME),MT(MOD_LCTL, KC_PAGE_UP),MT(MOD_LCTL, KC_PGDN),KC_END,                                         KC_LEFT,        KC_DOWN,        MT(MOD_RCTL, KC_UP),MT(MOD_LALT, KC_RIGHT),KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [3] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,                                          KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_TRANSPARENT, 
    TOGGLE_LAYER_COLOR,RGB_TOG,        RGB_VAD,        RGB_VAI,        RGB_MODE_FORWARD,RGB_SLD,                                        KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       KC_TRANSPARENT, KC_TRANSPARENT, 
    RGB_SAD,        RGB_SAI,        RGB_HUD,        RGB_HUI,        RGB_SPD,        RGB_SPI,                                        KC_F11,         KC_F12,         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, TO(0)
  ),
};

const uint16_t PROGMEM combo0[] = { MT(MOD_RCTL, KC_K), MT(MOD_LSFT, KC_J), COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(combo0, KC_ESCAPE),
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MT(MOD_LSFT, KC_F):
            return TAPPING_TERM -30;
        case DUAL_FUNC_0:
            return TAPPING_TERM -30;
        case KC_SPACE:
            return TAPPING_TERM -80;
        case MEH_T(KC_H):
            return TAPPING_TERM -30;
        case MT(MOD_LSFT, KC_J):
            return TAPPING_TERM -30;
        case KC_ENTER:
            return TAPPING_TERM -80;
        case LT(2, KC_BSPC):
            return TAPPING_TERM -60;
        case KC_DOWN:
            return TAPPING_TERM -30;
        default:
            return TAPPING_TERM;
    }
}

extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [0] = { {186,223,186}, {186,223,186}, {186,223,186}, {186,223,186}, {186,223,186}, {186,223,186}, {186,223,186}, {186,223,186}, {186,223,186}, {186,223,186}, {186,223,186}, {186,223,186}, {186,223,186}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {186,223,186}, {186,223,186}, {186,223,186}, {186,223,186}, {186,223,186}, {186,223,186}, {186,223,186}, {186,223,186}, {186,223,186}, {186,223,186}, {186,223,186}, {186,223,186}, {186,223,186}, {186,223,186}, {186,223,186}, {186,223,186}, {186,223,186}, {186,223,186}, {186,223,186}, {186,223,186}, {186,223,186}, {186,223,186}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {186,223,186}, {186,223,186}, {186,223,186}, {186,223,186}, {186,223,186}, {186,223,186}, {186,223,186}, {186,223,186}, {186,223,186} },

    [1] = { {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255} },

    [2] = { {58,255,255}, {58,255,255}, {58,255,255}, {58,255,255}, {58,255,255}, {58,255,255}, {58,255,255}, {58,255,255}, {58,255,255}, {58,255,255}, {58,255,255}, {58,255,255}, {58,255,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {58,255,255}, {58,255,255}, {58,255,255}, {58,255,255}, {58,255,255}, {58,255,255}, {58,255,255}, {58,255,255}, {58,255,255}, {58,255,255}, {58,255,255}, {58,255,255}, {58,255,255}, {58,255,255}, {58,255,255}, {58,255,255}, {58,255,255}, {58,255,255}, {58,255,255}, {58,255,255}, {58,255,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {58,255,255}, {58,255,255}, {58,255,255}, {58,255,255}, {58,255,255}, {58,255,255}, {58,255,255}, {58,255,255}, {58,255,255} },

    [3] = { {168,245,210}, {168,245,210}, {168,245,210}, {168,245,210}, {168,245,210}, {168,245,210}, {168,245,210}, {168,245,210}, {168,245,210}, {168,245,210}, {168,245,210}, {168,245,210}, {168,245,210}, {168,245,210}, {168,245,210}, {168,245,210}, {168,245,210}, {168,245,210}, {168,245,210}, {168,245,210}, {168,245,210}, {168,245,210}, {168,245,210}, {168,245,210}, {168,245,210}, {168,245,210}, {168,245,210}, {168,245,210}, {168,245,210}, {168,245,210}, {168,245,210}, {168,245,210}, {168,245,210}, {168,245,210}, {168,245,210}, {168,245,210}, {168,245,210}, {168,245,210}, {168,245,210}, {168,245,210}, {168,245,210}, {168,245,210}, {168,245,210}, {168,245,210}, {168,245,210}, {168,245,210}, {168,245,210}, {168,245,210}, {168,245,210}, {168,245,210}, {168,245,210}, {168,245,210} },

};

void set_layer_color(int layer) {
  for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        RGB rgb = hsv_to_rgb( hsv );
        float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
        rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b );
    }
  }
}

bool rgb_matrix_indicators_user(void) {
  if (rawhid_state.rgb_control) {
      return false;
  }
  if (keyboard_config.disable_layer_led) { return false; }
  switch (biton32(layer_state)) {
    case 0:
      set_layer_color(0);
      break;
    case 1:
      set_layer_color(1);
      break;
    case 2:
      set_layer_color(2);
      break;
    case 3:
      set_layer_color(3);
      break;
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
  return true;
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case MAC_LOCK:
      HCS(0x19E);

    case DUAL_FUNC_0:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_DELETE);
        } else {
          unregister_code16(KC_DELETE);
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_CAPS);
        } else {
          unregister_code16(KC_CAPS);
        }  
      }  
      return false;
    case DUAL_FUNC_1:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_PERC);
        } else {
          unregister_code16(KC_PERC);
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_LEFT_GUI);
        } else {
          unregister_code16(KC_LEFT_GUI);
        }  
      }  
      return false;
    case DUAL_FUNC_2:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_CIRC);
        } else {
          unregister_code16(KC_CIRC);
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_LEFT_ALT);
        } else {
          unregister_code16(KC_LEFT_ALT);
        }  
      }  
      return false;
    case DUAL_FUNC_3:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_AMPR);
        } else {
          unregister_code16(KC_AMPR);
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_LEFT_CTRL);
        } else {
          unregister_code16(KC_LEFT_CTRL);
        }  
      }  
      return false;
    case DUAL_FUNC_4:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_UNDS);
        } else {
          unregister_code16(KC_UNDS);
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_RIGHT_GUI);
        } else {
          unregister_code16(KC_RIGHT_GUI);
        }  
      }  
      return false;
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
  }
  return true;
}


