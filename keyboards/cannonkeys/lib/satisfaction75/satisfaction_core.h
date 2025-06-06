// Copyright 2023 Andrew Kannan
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include <stdint.h>
#include <stdbool.h>

#include <hal.h>

#include "via.h" // only for EEPROM address
#include "satisfaction_keycodes.h"

#define EEPROM_ENABLED_ENCODER_MODES_OFFSET 0
#define EEPROM_DEFAULT_OLED_OFFSET 1
#define EEPROM_CUSTOM_ENCODER_OFFSET 2

enum s75_keyboard_value_id {
  id_encoder_modes = 1,
  id_oled_default_mode,
  id_encoder_custom,
  id_oled_mode
};

enum encoder_modes {
  ENC_MODE_VOLUME,
  ENC_MODE_MEDIA,
  ENC_MODE_SCROLL,
  ENC_MODE_BRIGHTNESS,
  ENC_MODE_BACKLIGHT,
  ENC_MODE_CUSTOM0,
  ENC_MODE_CUSTOM1,
  ENC_MODE_CUSTOM2,
  _NUM_ENCODER_MODES,
  ENC_MODE_CLOCK_SET // This shouldn't be included in the default modes, so we put it after NUM_ENCODER_MODES
};

enum custom_encoder_behavior {
    ENC_CUSTOM_CW,
    ENC_CUSTOM_CCW,
    ENC_CUSTOM_PRESS
};

enum oled_modes {
  OLED_DEFAULT,
  OLED_TIME,
  OLED_OFF,
  _NUM_OLED_MODES
};


// Keyboard Information
extern volatile uint8_t led_numlock;
extern volatile uint8_t led_capslock;
extern volatile uint8_t led_scrolllock;
extern uint8_t layer;

// OLED Behavior
extern uint8_t oled_mode;
extern bool oled_repaint_requested;
extern bool oled_wakeup_requested;
extern uint32_t oled_sleep_timer;

// Encoder Behavior
extern uint8_t encoder_value;
extern uint8_t encoder_mode;
extern uint8_t enabled_encoder_modes;

// RTC
extern RTCDateTime last_timespec;
extern uint16_t last_minute;

// RTC Configuration
extern bool clock_set_mode;
extern uint8_t time_config_idx;
extern int8_t hour_config;
extern int16_t minute_config;
extern int8_t year_config;
extern int8_t month_config;
extern int8_t day_config;
extern uint8_t previous_encoder_mode;

void pre_encoder_mode_change(void);
void post_encoder_mode_change(void);
void change_encoder_mode(bool negative);
uint16_t handle_encoder_clockwise(void);
uint16_t handle_encoder_ccw(void);
uint16_t handle_encoder_press(void);
uint16_t retrieve_custom_encoder_config(uint8_t encoder_idx, uint8_t behavior);
void set_custom_encoder_config(uint8_t encoder_idx, uint8_t behavior, uint16_t new_code);

void update_time_config(int8_t increment);

void oled_request_wakeup(void);
void oled_request_repaint(void);
bool oled_task_needs_to_repaint(void);

void custom_config_load(void);

uint32_t read_custom_config(void *data, uint32_t offset, uint32_t length);
uint32_t write_custom_config(const void *data, uint32_t offset, uint32_t length);
