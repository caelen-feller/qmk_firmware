#include QMK_KEYBOARD_H

#define LAYOUT_c(k5B, k6B, k7B, k9B, kAB, kBB, kCB, kDB, k0A, k1A, k2A, k3A, k4A, k5A, kEB, kFB, k6A, k7A, k8A, k9A, kAA, kBA, kCA, kDA, kEA, kFA) { \
         {k0A, KC_NO}, \
         {k1A, KC_NO}, \
         {k2A, KC_NO}, \
         {k3A, KC_NO}, \
         {k4A, KC_NO}, \
         {k5A, k5B}, \
         {k6A, k6B}, \
         {k7A, k7B}, \
         {k8A, KC_NO}, \
         {k9A, k9B}, \
         {kAA, kAB}, \
         {kBA, kBB}, \
         {kCA, kCB}, \
         {kDA, kDB}, \
         {kEA, kEB}, \
         {kFA, kFB} \
}

enum layer_names {
    _BL, // Base layer
    _LFL, // Left function layer
    _MFL, // Middle Function layer
    _RFL, // Right function layer
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BL] = LAYOUT_c(
        KC_Y,   KC_U,   KC_I,   KC_O,       KC_P,       KC_LBRC,    KC_RBRC,    KC_BSPC,
        KC_H,   KC_J,   KC_K,   KC_L,       KC_SCLN,    KC_QUOT,    KC_NUHS,    KC_ENT,
        KC_B,   KC_N,   KC_M,   KC_COMM,    KC_DOT,     KC_SLSH,    KC_ALGR,
        MO(_LFL),   TT(_MFL),   MO(_RFL)
    ),
    [_LFL] = LAYOUT_c(
        _______,   _______,   _______,   _______,    _______,     _______,    _______,    _______,
        _______,   _______,   _______,   _______,    _______,     _______,    _______,    _______,
        _______,   _______,   _______,   _______,    _______,     _______,    _______,
        _______,   _______,   _______
    ),
    [_MFL] = LAYOUT_c(
        TG(_MFL),   TG(_MFL),   KC_UP,   TG(_MFL),    TG(_MFL),     TG(_MFL),    TG(_MFL),    _______,
        TG(_MFL),   KC_LEFT,   KC_DOWN,   KC_RGHT,    TG(_MFL),     TG(_MFL),    TG(_MFL),    _______,
        TG(_MFL),   TG(_MFL),   TG(_MFL),   TG(_MFL),    TG(_MFL),     TG(_MFL),    _______,
        _______,   TG(_MFL),   _______
    ),
    [_RFL] = LAYOUT_c(
        KC_6,   KC_7,   KC_8,   KC_9,    KC_0,     KC_MINUS,    KC_EQUAL,    _______,
        _______,   _______,   _______,   _______,    _______,     _______,    _______,    _______,
        _______,   _______,   _______,   _______,    _______,     _______,    _______,
        _______,   _______,   _______
    ),
};

#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {

};
#endif // defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)


const rgblight_segment_t PROGMEM bl_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, HSV_GREEN}
);
const rgblight_segment_t PROGMEM lfl_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, HSV_RED}
);
const rgblight_segment_t PROGMEM mfl_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, HSV_PINK}
);
const rgblight_segment_t PROGMEM rfl_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, HSV_BLUE}
);

const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    bl_layer,
    // fl_layer,
    // bfl_layer,
    lfl_layer,
    mfl_layer,
    rfl_layer
);

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, _BL));
    return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(1, layer_state_cmp(state, _LFL));
    rgblight_set_layer_state(2, layer_state_cmp(state, _MFL));
    rgblight_set_layer_state(3, layer_state_cmp(state, _RFL));
    return state;
}