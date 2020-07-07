<a href="https://www.microchip.com" rel="nofollow"><img src="images/microchip.png" alt="MCHP" width="300"/></a>

![Freertos](images/freeRTOS.png)

# ATMEGA4809 Xplained Pro Getting Started With FreeRTOS™

This is an example of how to get started with FreeRTOS™ on the AVR architecture with ATMEGA4809 Xplained Pro. FreeRTOS™ is a real-time operative system kernel which allows the MCU to operate with different tasks simultaneously. This is accomplished with mutexes, semaphores and software timers.

## Related Documentation

- [AN3007 - Getting Started with FreeRTOS on megaAVR® 0-series](https://www.microchip.com/wwwAppNotes/AppNotes.aspx?appnote=en610121)
- [ATmega4809 Family Product Page](https://www.microchip.com/design-centers/8-bit/avr-mcus/device-selection/atmega4809)
- [FreeRTOS™ Homepage](https://www.freertos.org/index.html)

## Software Used

- [MPLAB X IDE  or v5.40 newer](https://www.microchip.com/mplab/mplab-x-ide)
- [Data Visualizer](https://www.microchip.com/mplab/avr-support/data-visualizer)
- ATmega_DFP 1.4.351 or newer

## Hardware Used

- ATmega4809 Xplained Pro [(ATMEGA4809-XPRO)](https://www.microchip.com/developmenttools/ProductDetails/ATMEGA4809-XPRO)
- OLED1 Xplained Pro Extension Kit [(ATOLED1-XPRO)](https://www.microchip.com/developmenttools/ProductDetails/ATOLED1-XPRO)

## Setup

1. Open `ATmega4809FreeRTOSExample.X` in MPLAB
2. Connect the OLED1 Xplained Pro Extension Kit into the **EXT3** port on your ATmega4809 Xplained Pro.
3. Connect the ATmega4809 Xplained Pro to your computer with a micro usb cable.
4. Make sure the kit is selected as the tool to be programmed under project settings
5. Press the make and program button to program the device.
6. Open data visualizer under to interact with the virtual comport on the devkit

## Operation

As mentioned in the appnote [AN3007](#Related-Documentation) you can see the different tasks running and interact with them using the virtual com port on your ATmega4809 Xplained Pro or using the on board buttons. 

## Summary

We have here shown that it is possible to run FreeRTOS™ on an ATmega4809 and what advantages this might bring to your project.