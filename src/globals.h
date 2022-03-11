// globals.h
#include "Arduino.h"

// global pill count necessary since ISR won't have the scope necessary to edit this val
extern volatile uint8_t g_pill_count;

// isr function call
void increment_g_pill_count();