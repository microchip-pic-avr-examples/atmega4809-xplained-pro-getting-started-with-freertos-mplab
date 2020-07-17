<a href="https://www.microchip.com" rel="nofollow"><img src="images/microchip.png" alt="MCHP" width="300"/></a>

![Freertos](images/freeRTOS.png)

# ATMEGA4809 Xplained Pro Getting Started With FreeRTOS™

This is an example of how to get started with FreeRTOS™ on the AVR architecture with ATMEGA4809 Xplained Pro. FreeRTOS™ is a real-time operative system kernel which allows the MCU to operate with different tasks simultaneously. This is accomplished with mutexes, semaphores and software timers. [AN3007](https://www.microchip.com/wwwAppNotes/AppNotes.aspx?appnote=en610121) describes in detail how the FreeRTOS™ is being used to control the AVR.

## Related Documentation

- [AN3007 - Getting Started with FreeRTOS on megaAVR® 0-series](https://www.microchip.com/wwwAppNotes/AppNotes.aspx?appnote=en610121)
- [ATmega4809 Device Page](https://www.microchip.com/wwwproducts/en/ATMEGA4809)
- [FreeRTOS™ Homepage](https://www.freertos.org/index.html)

## Software Used

- [MPLAB® X IDE v5.40 or later](https://www.microchip.com/mplab/mplab-x-ide)
- [XC8 (v2.20)](https://www.microchip.com/mplab/compilers) alternatively [AVR/GNU C Compiler 5.4.0](https://www.microchip.com/mplab/avr-support/avr-and-arm-toolchains-c-compilers) can be used
- Data Visualizer
    - [MPLAB Data Visualizer](https://gallery.microchip.com/packages/MPLAB-Data-Visualizer-Standalone(Windows)/)
    - [Studio Data visualizer](https://www.microchip.com/mplab/avr-support/data-visualizer)
- ATmega_DFP 2.2.108 or later

## Hardware Used

- [ATmega4809 Xplained Pro](https://www.microchip.com/developmenttools/ProductDetails/ATMEGA4809-XPRO)
- [OLED1 Xplained Pro Extension Kit](https://www.microchip.com/developmenttools/ProductDetails/ATOLED1-XPRO)

## Setup

* Connect the OLED1 Xplained Pro Extension Kit into the **EXT3** port on your Xplained Pro

## Operation

1. Download the zip file or clone the example to get the source code.
2. Connect the ATmega4809 Xplained Pro to your computer with a micro usb cable.
3. Open `ATmega4809FreeRTOSExample.X` in MPLAB.
4. Make sure the kit is selected as the tool to be programmed under project settings.
5. Press the make and program button to program the device.
6. Open your favorite terminal application or Data visualizer and open the serial port associated with the Xplained Pro.
## Conclusion

We have here shown that it is possible to run FreeRTOS™ on an ATmega4809 and what advantages this might bring to your project. As mentioned in the appnote [AN3007](https://www.microchip.com/wwwAppNotes/AppNotes.aspx?appnote=en610121) you can see the different tasks running and interact with them using the virtual com port on your ATmega4809 Xplained Pro or using the on board buttons. 