#include QMK_KEYBOARD_H

#define LAYOUT_c(k5A, k4A, k3A, k2A, k1A, k0A, k6A, k7A, k8A, k9A, kAA, kBA, k6B, k5B, kFA, kEA, kDA, kCA, k7B, k9B, kAB, kBB, kCB, kDB, kFB, kEB) { \
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
    _FL, // Function layer
    _BFL, // Bottom function/Number layer
    _LFL, // Left function layer
    _RFL, // Right function layer
    _UNL // Uppercase Number layer
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BL] = LAYOUT_c(
        KC_TAB,     KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,
        KC_ESC,     KC_A,       KC_S,       KC_D,       KC_F,       KC_G,
        KC_LSFT,    KC_BSLS,    KC_Z,       KC_X,       KC_C,       KC_V,
        KC_LCTL,    MO(_FL),    KC_LGUI,    KC_LALT,    KC_SPC,
        MO(_LFL),   MO(_RFL),
        MO(_BFL)
    ),

    [_FL] = LAYOUT_c(
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,
        _______, _______,
        _______
    ),
    [_BFL] = LAYOUT_c(
        KC_GRV,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,
        _______,  _______, _______, _______, _______, _______,
        _______,  _______, _______, _______, _______, _______,
        _______,  _______, _______, _______, _______,
        MO(_UNL), _______,
        _______
    ),
    [_LFL] = LAYOUT_c(
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,
        _______, _______,
        MO(_UNL)
    ),
    [_RFL] = LAYOUT_c(
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,
        _______, _______,
        _______
    ),
    [_UNL] = LAYOUT_c(
        KC_TILD, KC_EXLM, KC_AT  , KC_HASH, KC_DLR,  KC_PERC,
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,
        _______, _______,
        _______
    )
};

#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {

};
#endif // defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)


const rgblight_segment_t PROGMEM bl_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, HSV_GREEN}
);
const rgblight_segment_t PROGMEM fl_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, HSV_CYAN}
);
const rgblight_segment_t PROGMEM bfl_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, HSV_MAGENTA}
);
const rgblight_segment_t PROGMEM lfl_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, HSV_RED}
);
const rgblight_segment_t PROGMEM rfl_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, HSV_BLUE}
);
const rgblight_segment_t PROGMEM unl_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, HSV_PINK}
);

const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    bl_layer,
    fl_layer,
    bfl_layer,
    lfl_layer,
    rfl_layer,
    unl_layer
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
    rgblight_set_layer_state(1, layer_state_cmp(state, _FL));
    rgblight_set_layer_state(2, layer_state_cmp(state, _BFL));
    rgblight_set_layer_state(3, layer_state_cmp(state, _LFL));
    rgblight_set_layer_state(4, layer_state_cmp(state, _RFL));
    rgblight_set_layer_state(5, layer_state_cmp(state, _UNL));
    return state;
}