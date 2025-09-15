enum layer_names {
    _Layer1,
    _Layer2
};

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
   
    
    [0] = LAYOUT_ortho_4x4(
     KC_TAB,   KC_Q,    KC_W,    KC_E,  KC_R,    KC_T,    KC_DEL,                  KC_PSCR,   KC_Y,    KC_U,    KC_I,     KC_O,      KC_P,       KC_BSPC,
     KC_LCTL,  KC_A,    KC_S,    KC_D,  KC_F,    KC_G,    MO(1),                   KC_LGUI,   KC_H,    KC_J,    KC_K,     KC_L,      KC_M,       KC_ENT,
     KC_ESC,   KC_Z,    KC_X,    KC_C,  KC_V,    KC_B,    KC_LSFT,                 KC_SPC,    KC_N,    KC_M,    KC_COMM,  KC_DOT,    KC_SLSH,    KC_QUOT
    ),
    
    [1] = LAYOUT_ortho_4x4(
     KC_CAPS,   KC_TRNS,    KC_TRNS,    KC_TRNS,  KC_UP,      KC_TRNS,  KC_DEL,                  KC_PSCR,   KC_7,    KC_8,    KC_9,  KC_MINS,    KC_EQL,     KC_TRNS,
     KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_LEFT,  KC_DOWN,    KC_RGHT,  MO(1),                   KC_LGUI,   KC_4,    KC_5,    KC_6,  KC_0,       KC_TRNS,    KC_TRNS,
     KC_ESC,    KC_TRNS,    KC_TRNS,    KC_TRNS,  KC_TRNS,    KC_TRNS,  KC_LSFT,                 KC_SPC,    KC_1,    KC_2,    KC_3,  KC_MUTE,    KC_VOLD,    KC_VOLU
    ),
};


#ifdef OLED_ENABLE
bool oled_task_user(void) {

    if (is_keyboard_master()) {

    oled_set_cursor(0, 1);

    switch (get_highest_layer(layer_state)) {
        case 0:
            oled_write_ln_P(PSTR("Layer 1"), false);
            break;
        case 1:
            oled_write_ln_P(PSTR("Layer 2"), false);
            break;
    }

    oled_set_cursor(1, 1);
    oled_write_P(PSTR("WPM: "), false);
    oled_write(get_u8_str(get_current_wpm(), ' '), false);
}
            

     if (!is_keyboard_master()) {

     oled_set_cursor(0, 0);
              
        led_t led_state = host_keyboard_led_state();
        oled_write_P(led_state.caps_lock ? PSTR("CAPS") : PSTR("    "), false);
} 
            
     return false;             
    }
#endif