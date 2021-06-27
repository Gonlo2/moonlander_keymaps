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

#define TH_ACTION(keycode_tap, keycode_hold) \
    { .hold_behavior = HOLD_TAP, .state = TH_DISABLED, .kc_tap = keycode_tap, .kc_hold = keycode_hold }

#define TKH_ACTION(keycode_tap, keycode_hold) \
    { .hold_behavior = HOLD_KEEP, .state = TH_DISABLED, .kc_tap = keycode_tap, .kc_hold = keycode_hold }

#define TLH_ACTION(keycode_tap, layer) \
    { .hold_behavior = HOLD_LAYER, .state = TH_DISABLED, .kc_tap = keycode_tap, .kc_hold = layer }

#define TH_KEY(kc) [kc-TAP_HOLD_START-1]

enum layers {
    DVORAK_LAYER = 0,
    TMUX_LAYER = 1,
    SYMBOLS_LAYER = 2,
    EXTRA_LAYER = 3,
    OTHER_LAYER = 4,
};

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
  TH_O_LCTL,
  TH_E_LALT,
  TH_I_SYMBOLS,
  TAP_HOLD_END,
};



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [DVORAK_LAYER] = LAYOUT_moonlander(
    ES_OVRR,        KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           ES_HASH,                                        ES_CIRC,        KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           ES_PLUS,
    ES_APOS,        KC_DOT,         KC_COMMA,       ES_NTIL,        KC_P,           KC_Y,           ES_AT,                                          ES_ASTR,        KC_F,           KC_G,           KC_C,           KC_H,           KC_L,           ES_GRV,
    KC_LGUI,        LSFT_T(KC_A),   TH_O_LCTL,      TH_E_LALT,      KC_TMUX_U,      TH_I_SYMBOLS,   TT(3),                                                                          ES_SLSH,        RSFT_T(KC_D),   KC_R,           KC_T,           KC_N,           KC_S,           ES_UNDS,
    ES_DQUO,        ES_LESS,        KC_Q,           KC_J,           KC_K,           KC_X,                                           KC_B,           KC_M,           KC_W,           KC_V,           KC_Z,           ES_ACUT,
    MO(4),          KC_HOME,        KC_PGDOWN,      KC_PGUP,        KC_END,         TH_VIMWINDOW_RALT,                                                                                                LCTL_T(KC_ESCAPE),KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       ES_MINS,
    KC_SPACE,       KC_BSPACE,      KC_DELETE,                      ES_EQL,         KC_TAB,         KC_ENTER
  ),
  [TMUX_LAYER] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_Z,           KC_P,           KC_N,           KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TMUX_HLEFT,        KC_TMUX_HDOWN,        KC_TMUX_HUP,          KC_TMUX_HRIGHT,       KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [SYMBOLS_LAYER] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, ES_IQUE,        ES_LBRC,        ES_RBRC,        ES_PLUS,        ES_LESS,        KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                 ES_BSLS,        ES_QUES,        ES_LPRN,        ES_RPRN,        ES_AMPR,        ES_PIPE,        ES_TILD,        
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 ES_IEXL,        ES_LCBR,        ES_RCBR,        ES_MINS,        ES_GRTR,        KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_EXLM,        KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [EXTRA_LAYER] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_PSCREEN,                                     KC_TRANSPARENT, KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,         
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_WH_LEFT,  KC_MS_WH_DOWN,  KC_MS_WH_UP,    KC_MS_WH_RIGHT, KC_F12,         
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, TO(0),                                                                          KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_UP,       KC_MS_RIGHT,    KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MEDIA_PLAY_PAUSE,                                                                                                KC_AUDIO_MUTE,  KC_MEDIA_PREV_TRACK,KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,KC_MEDIA_NEXT_TRACK,KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_MS_BTN3,     KC_MS_BTN2,     KC_MS_BTN1
  ),
  [OTHER_LAYER] = LAYOUT_moonlander(
    RESET,          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, AU_TOG,                                         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, MU_TOG,                                         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, MU_MOD,                                                                         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
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

enum hold_behavior {
    HOLD_TAP = 0,
    HOLD_KEEP,
    HOLD_LAYER,
};

typedef struct {
    const uint16_t kc_tap;
    const uint16_t kc_hold;
    const enum hold_behavior hold_behavior;
    enum tap_hold_state state;
    uint16_t time;
} tap_hold_action_t;

static tap_hold_action_t tap_hold_actions[TAP_HOLD_END-TAP_HOLD_START-1] = {
    TH_KEY(TH_VIMWINDOW_RALT) = TKH_ACTION(LCTL(KC_W), KC_RALT), // vim window  &  keep right alt
    TH_KEY(TH_O_LCTL)         = TKH_ACTION(KC_O, KC_LCTL), // o  &  keep right ctrl
    TH_KEY(TH_E_LALT)         = TKH_ACTION(KC_E, KC_LALT), // e  &  keep right alt
    TH_KEY(TH_I_SYMBOLS)      = TLH_ACTION(KC_I, SYMBOLS_LAYER), // i  &  symbols layer
};

void tap_hold_handle(tap_hold_action_t* action, keyrecord_t *record);

float shift_blocked_song[][2] = SONG(CAPS_LOCK_OFF_SOUND);

bool check_valid_shift_key(uint16_t keycode, keyrecord_t *record, bool play_sound);

bool check_valid_shift_key(uint16_t keycode, keyrecord_t *record, bool play_sound) {
  if (IS_KEY(keycode) && (get_mods() != 0) && ((get_mods() & MOD_MASK_SHIFT) == get_mods())) {
    bool is_left_keyboard = record->event.key.row < 6;
    bool pressed_lshift = (get_mods() & MOD_BIT(KC_LSHIFT)) == MOD_BIT(KC_LSHIFT);
    bool pressed_rshift = (get_mods() & MOD_BIT(KC_RSHIFT)) == MOD_BIT(KC_RSHIFT);
    if ((is_left_keyboard && pressed_lshift) || (!is_left_keyboard && pressed_rshift)) {
      if (play_sound) {
        PLAY_SONG(shift_blocked_song);
      }
      return false;
    }
  }
  return true;
}

void check_timers(uint16_t term);

void check_timers(uint16_t term) {
    if (tmux_ctx.state == TMUX_TIMER_RUNNING) {
        if (timer_elapsed(tmux_ctx.time) > term) {
            tmux_ctx.state = TMUX_WAITING_KEY;
            layer_on(TMUX_LAYER);
        }
    }

    for (uint8_t i = 0; i < TAP_HOLD_END-TAP_HOLD_START-1; ++i) {
        tap_hold_action_t* action = &tap_hold_actions[i];
        if ((action->state == TH_TAPPING) && (timer_elapsed(action->time) > term)) {
            action->state = TH_HOLDING;
            switch (action->hold_behavior) {
                case HOLD_TAP:
                    tap_code16(action->kc_hold);
                    break;
                case HOLD_KEEP:
                    register_code(action->kc_hold);
                    break;
                case HOLD_LAYER:
                    layer_on(action->kc_hold);
                    break;
            }
        }
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // Block the shift usage for the keys in the same hand
  if (!check_valid_shift_key(keycode, record, record->event.pressed)) return false;

  // If some tap hold is on hold and another key is pressed we change his state to held
  if (record->event.pressed) check_timers(0);

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
            if (check_valid_shift_key(keycode, record, true)) {
                tap_code(keycode);
            }
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
            if (check_valid_shift_key(action->kc_tap, record, true)) {
                tap_code16(action->kc_tap);
            }
        } else if (action->state == TH_HOLDING) {
            switch (action->hold_behavior) {
                case HOLD_TAP:
                    break;
                case HOLD_KEEP:
                    unregister_code(action->kc_hold);
                    break;
                case HOLD_LAYER:
                    layer_off(action->kc_hold);
                    break;
            }
        }
        action->state = TH_DISABLED;
    }
}

void matrix_scan_user(void) {
    check_timers(TAPPING_TERM);
}

layer_state_t layer_state_set_user(layer_state_t state) {
    // 29 - 30 - 31 --- 65 - 66 - 67
    // 22 - 27 - 31 - 4
    if (layer_state_cmp(state, TMUX_LAYER)) {
        rgb_matrix_set_color(29, 0x00, 0x00, 0xff);
    } else {
        rgb_matrix_set_color(29, 0x00, 0x00, 0x00);
    }

    if (layer_state_cmp(state, SYMBOLS_LAYER)) {
        rgb_matrix_set_color(30, 0x00, 0xff, 0x00);
    } else {
        rgb_matrix_set_color(30, 0x00, 0x00, 0x00);
    }

    if (layer_state_cmp(state, EXTRA_LAYER)) {
        rgb_matrix_set_color(31, 0xff, 0x00, 0x00);
    } else {
        rgb_matrix_set_color(31, 0x00, 0x00, 0x00);
    }

    if (layer_state_cmp(state, OTHER_LAYER)) {
        rgb_matrix_set_color(65, 0xff, 0xb8, 0x00);
    } else {
        rgb_matrix_set_color(65, 0x00, 0x00, 0x00);
    }

    return state;
}
