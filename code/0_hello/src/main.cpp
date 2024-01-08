// This program prints some text to the console output (TXD0 => P0.2) and blinks an LED (P1.18)
// Default console baudrate: 9600

#include "mbed.h"

#define WAIT_TIME_MS 1000

DigitalOut led1(LED1); // LED1 => P1.18

int main()
{
  printf("Hello, World!\n");
  printf("This is the blinky example running on Mbed OS %d.%d.%d.\n", MBED_MAJOR_VERSION, MBED_MINOR_VERSION, MBED_PATCH_VERSION);
  
  while (true)
  {
    led1 = !led1;                                             // Toggle LED1
    printf("LED Status: %s\n", (led1.read() ? "OFF" : "ON")); // As LED is active-low, it is ON when led1 = 0
    thread_sleep_for(WAIT_TIME_MS);                           // Delay in miliseconds
  }
}