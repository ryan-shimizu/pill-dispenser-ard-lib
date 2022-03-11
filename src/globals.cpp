#include "globals.h"

// initial value at startup
volatile uint8_t g_pill_count = 0;


// isr function call when beam break occurs
void increment_g_pill_count(){
    g_pill_count++;
}