#include QMK_KEYBOARD_H
#include "version.h"
#include "keymap_german.h"
#include "keymap_nordic.h"
#include "keymap_french.h"
#include "keymap_spanish.h"
#include "keymap_hungarian.h"
#include "keymap_swedish.h"
#include "keymap_br_abnt2.h"
#include "keymap_canadian_multilingual.h"
#include "keymap_german_ch.h"
#include "keymap_jp.h"
#include "keymap_korean.h"
#include "keymap_bepo.h"
#include "keymap_italian.h"
#include "keymap_slovenian.h"
#include "keymap_lithuanian_azerty.h"
#include "keymap_danish.h"
#include "keymap_norwegian.h"
#include "keymap_portuguese.h"
#include "keymap_contributions.h"
#include "keymap_czech.h"
#include "keymap_romanian.h"
#include "keymap_russian.h"
#include "keymap_uk.h"
#include "keymap_estonian.h"
#include "keymap_belgian.h"
#include "keymap_us_international.h"

#define KC_MAC_UNDO LGUI(KC_Z)
#define KC_MAC_CUT LGUI(KC_X)
#define KC_MAC_COPY LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)
#define KC_PC_UNDO LCTL(KC_Z)
#define KC_PC_CUT LCTL(KC_X)
#define KC_PC_COPY LCTL(KC_C)
#define KC_PC_PASTE LCTL(KC_V)
#define ES_LESS_MAC KC_GRAVE
#define ES_GRTR_MAC LSFT(KC_GRAVE)
#define ES_BSLS_MAC ALGR(KC_6)
#define NO_PIPE_ALT KC_GRAVE
#define NO_BSLS_ALT KC_EQUAL
#define LSA_T(kc) MT(MOD_LSFT | MOD_LALT, kc)
#define BP_NDSH_MAC ALGR(KC_8)
#define MOON_LED_LEVEL LED_LEVEL

#define TMUX_LAYER 1

enum custom_keycodes {
  RGB_SLD = ML_SAFE_RANGE,
  HSV_0_255_255,
  HSV_86_255_128,
  HSV_172_255_255,
  ES_LSPO,
  ES_RSPC,
  KC_TMUX_U,
  KC_TMUX_HLEFT,
  KC_TMUX_HDOWN,
  KC_TMUX_HUP,
  KC_TMUX_HRIGHT,
};


enum tap_dance_codes {
  DANCE_0,
  DANCE_1,
  DANCE_2,
  DANCE_3,
  DANCE_4,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_moonlander(
    ES_OVRR,        KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           ES_CCED,                                        TD(DANCE_1),    KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           ES_PLUS,        
    ES_DQUO,        KC_DOT,         KC_COMMA,       ES_NTIL,        KC_P,           KC_Y,           ES_ACUT,                                        TD(DANCE_2),    KC_F,           KC_G,           KC_C,           KC_H,           KC_L,           ES_GRV,         
    KC_LGUI,        LSFT_T(KC_A),   LCTL_T(KC_O),   LALT_T(KC_E),   KC_TMUX_U,      TD(DANCE_0),    TT(2),                                                                          TD(DANCE_3),    RSFT_T(KC_D),   KC_R,           KC_T,           KC_N,           KC_S,           ES_MINS,        
    ES_APOS,        ES_LESS,        KC_Q,           KC_J,           KC_K,           KC_X,                                           KC_B,           KC_M,           KC_W,           KC_V,           KC_Z,           ES_PIPE,        
    ES_IEXL,        KC_HOME,        KC_PGDOWN,      KC_PGUP,        KC_END,         RALT_T(KC_APPLICATION),                                                                                                LCTL_T(KC_ESCAPE),KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       MO(3),          
    KC_SPACE,       KC_BSPACE,      KC_DELETE,                      TD(DANCE_4),    KC_TAB,         KC_ENTER
  ),
  [1] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_Z,           KC_P,           KC_N,           KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TMUX_HLEFT,        KC_TMUX_HDOWN,        KC_TMUX_HUP,          KC_TMUX_HRIGHT,       KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [2] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_TRANSPARENT,                                 KC_PSCREEN,     KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,         
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_WH_LEFT,  KC_MS_WH_DOWN,  KC_MS_WH_UP,    KC_MS_WH_RIGHT, KC_F12,         
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, TO(0),                                                                          KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_UP,       KC_MS_RIGHT,    KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MEDIA_PLAY_PAUSE,                                                                                                KC_AUDIO_MUTE,  KC_MEDIA_PREV_TRACK,KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,KC_MEDIA_NEXT_TRACK,KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_MS_BTN3,     KC_MS_BTN2,     KC_MS_BTN1
  ),
  [3] = LAYOUT_moonlander(
    DYN_REC_STOP,   DYN_MACRO_PLAY1,DYN_MACRO_PLAY2,KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, RESET,          
    AU_TOG,         DYN_REC_START1, DYN_REC_START2, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    MU_TOG,         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    MU_MOD,         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, WEBUSB_PAIR,    HSV_0_255_255,  HSV_86_255_128, HSV_172_255_255,RGB_MOD,                                                                                                        RGB_TOG,        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    RGB_VAD,        RGB_VAI,        TOGGLE_LAYER_COLOR,                RGB_SLD,        RGB_HUD,        RGB_HUI
  ),
};

enum tmux_state {
    TMUX_DISABLED = 0,
    TMUX_TIMER_RUNNING,
    TMUX_WAITING_KEY,
    TMUX_TAPPING,
    TMUX_HOLDING,
};

typedef struct {
    enum tmux_state state;
    uint16_t timer;
} tmux_t;

static tmux_t tmux_ctx;

bool tmux_handle(uint16_t keycode, keyrecord_t *record);
bool tmux_hold(uint16_t keycode, keyrecord_t *record);
void tmux_tap(uint16_t keycode, keyrecord_t *record);

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case ES_LSPO:
      perform_space_cadet(record, keycode, KC_LSFT, KC_LSFT, KC_8);
      return false;
    case ES_RSPC:
      perform_space_cadet(record, keycode, KC_LSFT, KC_LSFT, KC_9);
      return false;
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
    case HSV_0_255_255:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(0,255,255);
      }
      return false;
    case HSV_86_255_128:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(86,255,128);
      }
      return false;
    case HSV_172_255_255:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(172,255,255);
      }
      return false;
    case KC_TMUX_U:
      return tmux_handle(KC_U, record);
    case KC_TMUX_HLEFT:
      return tmux_hold(KC_LEFT, record);
    case KC_TMUX_HDOWN:
      return tmux_hold(KC_DOWN, record);
    case KC_TMUX_HUP:
      return tmux_hold(KC_UP, record);
    case KC_TMUX_HRIGHT:
      return tmux_hold(KC_RIGHT, record);
  }

  // All the holding keys are already processed so any other kind of key must be a tapping one
  if ((tmux_ctx.state >= TMUX_WAITING_KEY) && IS_KEY(keycode)) {
    tmux_tap(keycode, record);
  }

  return true;
}

bool tmux_handle(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        tmux_ctx.state = TMUX_TIMER_RUNNING;
        tmux_ctx.timer = timer_read();
    } else {
        if (tmux_ctx.state == TMUX_TIMER_RUNNING) {
            tap_code(keycode);
        } else {
            // If the tmux key is released without any tapped key tap ctrl-b
            // to allow use keys with the same hand that held the tmux key
            if (tmux_ctx.state == TMUX_WAITING_KEY) {
                tap_code16(LCTL(KC_B));
            } if (tmux_ctx.state == TMUX_HOLDING) {
                unregister_code(KC_B);
                unregister_code(KC_LCTL);
            }
            layer_off(TMUX_LAYER);
        }
        tmux_ctx.state = TMUX_DISABLED;
    }
    return true;
}

bool tmux_hold(uint16_t keycode, keyrecord_t *record) {
    if (tmux_ctx.state != TMUX_HOLDING) {
        tmux_ctx.state = TMUX_HOLDING;
        register_code(KC_LCTL);
        register_code(KC_B);
    }
    if (record->event.pressed) {
        register_code(keycode);
    } else {
        unregister_code(keycode);
    }
    return true;
}

void tmux_tap(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (tmux_ctx.state) {
            case TMUX_HOLDING:
                unregister_code(KC_B);
                unregister_code(KC_LCTL);
            case TMUX_WAITING_KEY:
                tmux_ctx.state = TMUX_TAPPING;
            case TMUX_TAPPING:
                tap_code16(LCTL(KC_B));
            default:
        }
    }
}

void matrix_scan_user(void) {
    if (tmux_ctx.state == TMUX_TIMER_RUNNING) {
        if (timer_elapsed(tmux_ctx.timer) > TAPPING_TERM) {
            tmux_ctx.state = TMUX_WAITING_KEY;
            layer_on(TMUX_LAYER);
        }
    }
}

typedef struct {
    bool is_press_action;
    uint8_t step;
} tap;

enum {
    SINGLE_TAP = 1,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_HOLD,
    DOUBLE_SINGLE_TAP,
    MORE_TAPS
};

static tap dance_state[5];

uint8_t dance_step(qk_tap_dance_state_t *state);

uint8_t dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}


void on_dance_0(qk_tap_dance_state_t *state, void *user_data);
void dance_0_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_0_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_0(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_I);
        tap_code16(KC_I);
        tap_code16(KC_I);
    }
    if(state->count > 3) {
        tap_code16(KC_I);
    }
}

void dance_0_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[0].step = dance_step(state);
    switch (dance_state[0].step) {
        case SINGLE_TAP: register_code16(KC_I); break;
        case SINGLE_HOLD: register_code16(LCTL(KC_W)); break;
        case DOUBLE_TAP: register_code16(KC_I); register_code16(KC_I); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_I); register_code16(KC_I);
    }
}

void dance_0_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[0].step) {
        case SINGLE_TAP: unregister_code16(KC_I); break;
        case SINGLE_HOLD: unregister_code16(LCTL(KC_W)); break;
        case DOUBLE_TAP: unregister_code16(KC_I); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_I); break;
    }
    dance_state[0].step = 0;
}
void on_dance_1(qk_tap_dance_state_t *state, void *user_data);
void dance_1_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_1_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_1(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(RALT(ES_GRV));
        tap_code16(RALT(ES_GRV));
        tap_code16(RALT(ES_GRV));
    }
    if(state->count > 3) {
        tap_code16(RALT(ES_GRV));
    }
}

void dance_1_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[1].step = dance_step(state);
    switch (dance_state[1].step) {
        case SINGLE_TAP: register_code16(RALT(ES_GRV)); break;
        case SINGLE_HOLD: register_code16(RALT(ES_PLUS)); break;
        case DOUBLE_TAP: register_code16(RALT(ES_GRV)); register_code16(RALT(ES_GRV)); break;
        case DOUBLE_SINGLE_TAP: tap_code16(RALT(ES_GRV)); register_code16(RALT(ES_GRV));
    }
}

void dance_1_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[1].step) {
        case SINGLE_TAP: unregister_code16(RALT(ES_GRV)); break;
        case SINGLE_HOLD: unregister_code16(RALT(ES_PLUS)); break;
        case DOUBLE_TAP: unregister_code16(RALT(ES_GRV)); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(RALT(ES_GRV)); break;
    }
    dance_state[1].step = 0;
}
void on_dance_2(qk_tap_dance_state_t *state, void *user_data);
void dance_2_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_2_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_2(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(RALT(ES_ACUT));
        tap_code16(RALT(ES_ACUT));
        tap_code16(RALT(ES_ACUT));
    }
    if(state->count > 3) {
        tap_code16(RALT(ES_ACUT));
    }
}

void dance_2_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[2].step = dance_step(state);
    switch (dance_state[2].step) {
        case SINGLE_TAP: register_code16(RALT(ES_ACUT)); break;
        case SINGLE_HOLD: register_code16(RALT(ES_CCED)); break;
        case DOUBLE_TAP: register_code16(RALT(ES_ACUT)); register_code16(RALT(ES_ACUT)); break;
        case DOUBLE_SINGLE_TAP: tap_code16(RALT(ES_ACUT)); register_code16(RALT(ES_ACUT));
    }
}

void dance_2_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[2].step) {
        case SINGLE_TAP: unregister_code16(RALT(ES_ACUT)); break;
        case SINGLE_HOLD: unregister_code16(RALT(ES_CCED)); break;
        case DOUBLE_TAP: unregister_code16(RALT(ES_ACUT)); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(RALT(ES_ACUT)); break;
    }
    dance_state[2].step = 0;
}
void on_dance_3(qk_tap_dance_state_t *state, void *user_data);
void dance_3_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_3_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_3(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LSFT(KC_8));
        tap_code16(LSFT(KC_8));
        tap_code16(LSFT(KC_8));
    }
    if(state->count > 3) {
        tap_code16(LSFT(KC_8));
    }
}

void dance_3_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[3].step = dance_step(state);
    switch (dance_state[3].step) {
        case SINGLE_TAP: register_code16(LSFT(KC_8)); break;
        case SINGLE_HOLD: register_code16(LSFT(KC_9)); break;
        case DOUBLE_TAP: register_code16(LSFT(KC_8)); register_code16(LSFT(KC_8)); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LSFT(KC_8)); register_code16(LSFT(KC_8));
    }
}

void dance_3_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[3].step) {
        case SINGLE_TAP: unregister_code16(LSFT(KC_8)); break;
        case SINGLE_HOLD: unregister_code16(LSFT(KC_9)); break;
        case DOUBLE_TAP: unregister_code16(LSFT(KC_8)); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LSFT(KC_8)); break;
    }
    dance_state[3].step = 0;
}
void on_dance_4(qk_tap_dance_state_t *state, void *user_data);
void dance_4_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_4_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_4(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LSFT(KC_0));
        tap_code16(LSFT(KC_0));
        tap_code16(LSFT(KC_0));
    }
    if(state->count > 3) {
        tap_code16(LSFT(KC_0));
    }
}

void dance_4_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[4].step = dance_step(state);
    switch (dance_state[4].step) {
        case SINGLE_TAP: register_code16(LSFT(KC_0)); break;
        case SINGLE_HOLD: register_code16(LSFT(KC_1)); break;
        case DOUBLE_TAP: register_code16(LSFT(KC_0)); register_code16(LSFT(KC_0)); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LSFT(KC_0)); register_code16(LSFT(KC_0));
    }
}

void dance_4_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[4].step) {
        case SINGLE_TAP: unregister_code16(LSFT(KC_0)); break;
        case SINGLE_HOLD: unregister_code16(LSFT(KC_1)); break;
        case DOUBLE_TAP: unregister_code16(LSFT(KC_0)); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LSFT(KC_0)); break;
    }
    dance_state[4].step = 0;
}

qk_tap_dance_action_t tap_dance_actions[] = {
        [DANCE_0] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_0, dance_0_finished, dance_0_reset),
        [DANCE_1] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_1, dance_1_finished, dance_1_reset),
        [DANCE_2] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_2, dance_2_finished, dance_2_reset),
        [DANCE_3] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_3, dance_3_finished, dance_3_reset),
        [DANCE_4] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_4, dance_4_finished, dance_4_reset),
};
