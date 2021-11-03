/**************************************************************
 * main.c
 * rev 1.0 26-Aug-2021 ashle
 * Assignment1_AshMauro
 * ***********************************************************/

#include "pico/stdlib.h"
#include <stdbool.h>
#include <stdio.h>

// Define gpio pins for LEDS
#define RED_LED 11
#define GREEN_LED 13
#define BLUE_LED 12
#define PUSH1 2
#define PUSH2 3
#define PUSH3 4

// Function to set LED pins to boolean variables
void set_pins(bool red, bool green, bool blue) {
  gpio_put(RED_LED, red);
  gpio_put(GREEN_LED, green);
  gpio_put(BLUE_LED, blue);
}

int main(void) {
  
  stdio_init_all();

  // Declare boolean variable
  bool red, green, blue; 

  // Set boolean variables to off
  red = false;
  green = false;
  blue = false;

  // Initialise gpio pins being used
  gpio_init(RED_LED);
  gpio_init(GREEN_LED);
  gpio_init(BLUE_LED);
  gpio_init(PUSH1);
  gpio_init(PUSH2);
  gpio_init(PUSH3);

  // Initialise gpio direction
  gpio_set_dir(RED_LED, true);
  gpio_set_dir(GREEN_LED, true);
  gpio_set_dir(BLUE_LED, true);
  gpio_set_dir(PUSH1, false);
  gpio_set_dir(PUSH2, false);
  gpio_set_dir(PUSH3, false);

  while (true) {
    
    set_pins(red, green, blue); // Call pin boolean function

    red = !gpio_get(PUSH1);
    blue = !gpio_get(PUSH2);
    green = !gpio_get(PUSH3);
  }
}