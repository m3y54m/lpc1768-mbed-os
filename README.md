# Mbed OS on LPC1768

This repository documents my previous efforts to develop programs for an LPC1768 microcontroller using the Mbed OS. The reason I chose this MCU is that the original board which Mbed OS was first developed for was the following board that was based on LPC1768 and is the most documented hardware for Mbed OS:

![image](https://github.com/m3y54m/lpc1768-mbed-os/assets/1549028/02d2d427-bba0-486d-bfa4-3cbc52e36671)

![image](https://github.com/m3y54m/lpc1768-mbed-os/assets/1549028/9aa34292-c36d-4f9a-b141-abd781329f6e)

## Hardware

I did not have access to the "mbed LPC1768" board. Instead, I used another board based on LPC1768 produced by [ECA](https://eshop.eca.ir/ساخت-ایران/876-هدربرد-برد-راه-انداز-lpc1768-cortex-m3.html) which you can see in the following image. It lacks some of the components of the original Mbed board such as Ethernet PHY and FLASH memory chips, but in return exposes all the I/O pins of the MCU:

![ECA_Header_Board](https://github.com/m3y54m/lpc1768-mbed-os/assets/1549028/324de3e7-0241-458e-97ca-972437755e0b)

![ECA_Schematic](https://github.com/m3y54m/lpc1768-mbed-os/assets/1549028/b9c13995-e066-4b26-a9f4-b551114665b4)

## Project Initialization

There are several ways to initialize your Mbed OS project. I personally prefer using PlatformIO which is easier and faster.

For this hardware you should create a new project in PlatformIO with the following configuartions:

- Board: **NXP mbed LPC1768**
- Framework: **Mbed**

## First Program

This is the [first program](code/0_hello/src/main.cpp) which prints some text to the console output (TXD0 => P0.2) and blinks an LED (P1.18). Default console baudrate is 9600.


```cpp
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
```

## Resources

- [mbed LPC1768](https://os.mbed.com/platforms/mbed-LPC1768/)
- [mbed NXP LPC1768 Schematic](http://mbed.org/media/uploads/chris/mbed-005.1.pdf)
- [mbed NXP LPC1768 Microcontroller Brochure](https://www.nxp.com/docs/en/brochure/LPC1768.pdf)
- [ECA LPC1768 Header Board](https://eshop.eca.ir/ساخت-ایران/876-هدربرد-برد-راه-انداز-lpc1768-cortex-m3.html)
- [Mbed OS Documentation](https://os.mbed.com/docs/mbed-os/)
- [NXP mbed LPC1768 - PlatformIO documentation](https://docs.platformio.org/en/stable/boards/nxplpc/lpc1768.html)
- [PlatformIO Mbed OS for NXP LPC Examples](https://github.com/platformio/platform-nxplpc/tree/master/examples)
