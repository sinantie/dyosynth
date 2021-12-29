#ifndef __HARDWARE_CONFIG_H__
#define __HARDWARE_CONFIG_H__

//
// Hardware config
//
#define POT_NUMBER    5
#define BUTTON_NUMBER 5
#define LED_NUMBER 16

// Hardware config
// Pin configuration(double check your schematic before configure those pins)
// Pots
#define GENERIC_POT_1_PIN     A0
#define GENERIC_POT_2_PIN     A1
#define GENERIC_POT_3_PIN     A2
#define GENERIC_POT_4_PIN     A3
#define GENERIC_POT_5_PIN     A4
// Buttons
#define GENERIC_SWITCH_1_PIN  6
#define GENERIC_SWITCH_2_PIN  7
#define GENERIC_SWITCH_3_PIN  8
#define GENERIC_SWITCH_4_PIN  9
#define GENERIC_SWITCH_5_PIN  10
// Led Encoders
#define ENCODER_LED_CLK_PIN       4
#define ENCODER_LED_LATCH_PIN     2
#define ENCODER_LED_DATA_PIN      5
// PWM
#define PWM_1_PIN             3
#define PWM_2_PIN             11

typedef enum {
  GENERIC_POT_1,
  GENERIC_POT_2,
  GENERIC_POT_3,
  GENERIC_POT_4,
  GENERIC_POT_5  
} POT_HARDWARE_INTERFACE;

typedef enum {
  GENERIC_BUTTON_1,
  GENERIC_BUTTON_2,
  GENERIC_BUTTON_3,
  GENERIC_BUTTON_4,
  GENERIC_BUTTON_5  
} BUTTON_HARDWARE_INTERFACE;

#endif