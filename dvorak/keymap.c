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

#define TH_ACTION(keycode_tap, keycode_hold) \
    { .keep_hold = false, .state = TH_DISABLED, .kc_tap = keycode_tap, .kc_hold = keycode_hold }

#define TKH_ACTION(keycode_tap, keycode_hold) \
    { .keep_hold = true, .state = TH_DISABLED, .kc_tap = keycode_tap, .kc_hold = keycode_hold }

#define TH_KEY(kc) [kc-TAP_HOLD_START-1]

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

  // Tap-hold section
  TAP_HOLD_START,
  TH_VIMWINDOW_RALT,
  TH_SQUARE_BRACKETS,
  TH_CURLY_BRACKETS,
  TH_ROUND_BRACKETS,
  TH_EQUAL_EXCLAMATION,
  TH_SLASH_HASH,
  TAP_HOLD_END,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_moonlander(
    ES_BSLS,        KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           TODO,                                           TH_SQUARE_BRACKETS,     KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           ES_PLUS,
    ES_DQUO,        KC_DOT,         KC_COMMA,       ES_NTIL,        KC_P,           KC_Y,           TH_SLASH_HASH,                                  TH_CURLY_BRACKETS,      KC_F,           KC_G,           KC_C,           KC_H,           KC_L,           ES_GRV,
    KC_LGUI,        LSFT_T(KC_A),   LCTL_T(KC_O),   LALT_T(KC_E),   KC_TMUX_U,      KC_I,           TT(2),                                          TH_ROUND_BRACKETS,      RSFT_T(KC_D),   KC_R,           KC_T,           KC_N,           KC_S,           ES_MINS,
    ES_APOS,        ES_LESS,        KC_Q,           KC_J,           KC_K,           KC_X,                                                                                   KC_B,           KC_M,           KC_W,           KC_V,           KC_Z,           ES_ACUT,
    ES_IEXL,        KC_HOME,        KC_PGDOWN,      KC_PGUP,        KC_END,                         TH_VIMWINDOW_RALT,                              LCTL_T(KC_ESCAPE),                      KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       ES_PIPE,
                                                                    KC_SPACE,       KC_BSPACE,      KC_DELETE,                                      TH_EQUAL_EXCLAMATION,   KC_TAB,         KC_ENTER
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
    ES_OVRR,        KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_PSCREEN,                                     KC_TRANSPARENT, KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,         
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_WH_LEFT,  KC_MS_WH_DOWN,  KC_MS_WH_UP,    KC_MS_WH_RIGHT, KC_F12,         
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, TO(0),                                                                          KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_UP,       KC_MS_RIGHT,    KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MEDIA_PLAY_PAUSE,                                                                                                KC_AUDIO_MUTE,  KC_MEDIA_PREV_TRACK,KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,KC_MEDIA_NEXT_TRACK,MO(3),          
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
    uint16_t time;
} tmux_t;

static tmux_t tmux_ctx = { .state = TMUX_DISABLED };

void tmux_handle(uint16_t keycode, keyrecord_t *record);
void tmux_hold(uint16_t keycode, keyrecord_t *record);
void tmux_tap(uint16_t keycode, keyrecord_t *record);


enum tap_hold_state {
    TH_DISABLED = 0,
    TH_TAPPING,
    TH_HOLDING,
};

typedef struct {
    const uint16_t kc_tap;
    const uint16_t kc_hold;
    const bool keep_hold;
    enum tap_hold_state state;
    uint16_t time;
} tap_hold_action_t;

static tap_hold_action_t tap_hold_actions[TAP_HOLD_END-TAP_HOLD_START-1] = {
    TH_KEY(TH_VIMWINDOW_RALT)    = TKH_ACTION(LCTL(KC_W), KC_RALT), // vim window  &  keep right alt
    TH_KEY(TH_SQUARE_BRACKETS)   = TH_ACTION(RALT(ES_GRV), RALT(ES_PLUS)), // [  &  ]
    TH_KEY(TH_CURLY_BRACKETS)    = TH_ACTION(RALT(ES_ACUT), RALT(ES_CCED)), // {  &  }
    TH_KEY(TH_ROUND_BRACKETS)    = TH_ACTION(LSFT(KC_8), LSFT(KC_9)), // (  &  )
    TH_KEY(TH_EQUAL_EXCLAMATION) = TH_ACTION(LSFT(KC_0), LSFT(KC_1)), // =  &  !
    TH_KEY(TH_SLASH_HASH)        = TH_ACTION(LSFT(KC_7), RALT(KC_3)), // /  &  #
};

void tap_hold_handle(tap_hold_action_t* action, keyrecord_t *record);


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // Check if the key is a tmux one
  switch (keycode) {
    case KC_TMUX_U:
      tmux_handle(KC_U, record);
      break;
    case KC_TMUX_HLEFT:
      tmux_hold(KC_LEFT, record);
      break;
    case KC_TMUX_HDOWN:
      tmux_hold(KC_DOWN, record);
      break;
    case KC_TMUX_HUP:
      tmux_hold(KC_UP, record);
      break;
    case KC_TMUX_HRIGHT:
      tmux_hold(KC_RIGHT, record);
      break;
    default:
      // All the holding keys are already processed so any other kind of key must be a tapping one
      if ((tmux_ctx.state >= TMUX_WAITING_KEY) && IS_KEY(keycode)) {
        tmux_tap(keycode, record);
      }
  }

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
    case TAP_HOLD_START ... TAP_HOLD_END:
      tap_hold_handle(&tap_hold_actions[keycode-TAP_HOLD_START-1], record);
      break;
  }

  return true;
}

void tmux_handle(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        tmux_ctx.state = TMUX_TIMER_RUNNING;
        tmux_ctx.time = record->event.time;
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
}

void tmux_hold(uint16_t keycode, keyrecord_t *record) {
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

void tap_hold_handle(tap_hold_action_t* action, keyrecord_t *record) {
    if (record->event.pressed) {
        action->state = TH_TAPPING;
        action->time = record->event.time;
    } else {
        if (action->state == TH_TAPPING) {
            tap_code16(action->kc_tap);
        } else if ((action->state == TH_HOLDING) && action->keep_hold) {
            unregister_code(action->kc_hold);
        }
        action->state = TH_DISABLED;
    }
}

void matrix_scan_user(void) {
    if (tmux_ctx.state == TMUX_TIMER_RUNNING) {
        if (timer_elapsed(tmux_ctx.time) > TAPPING_TERM) {
            tmux_ctx.state = TMUX_WAITING_KEY;
            layer_on(TMUX_LAYER);
        }
    }

    for (uint8_t i = 0; i < TAP_HOLD_END-TAP_HOLD_START-1; ++i) {
        tap_hold_action_t* action = &tap_hold_actions[i];
        if ((action->state == TH_TAPPING) && (timer_elapsed(action->time) > TAPPING_TERM)) {
            action->state = TH_HOLDING;
            if (action->keep_hold) {
                register_code(action->kc_hold);
            } else {
                tap_code16(action->kc_hold);
            }
        }
    }
}
