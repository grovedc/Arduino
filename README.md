# Arduino
Code for the little devices, and some not so little.

## ATTiny85

Code for the little devices, and some not so little.

ATTiny85

What's not to like about these little guys?  In an 8 pin DIP, you get:

    1) a microprocessor
    2) clock - no external components needed
    3) 8k ROM
    4) 512 bytes RAM
    5) 512 bytes EEPROM - can be written to in circuit
    6) counter/timers
    7) 6 very configurable I/O pins
    8) Analog to digital converters (ADC)
    9) an analog comparator

And the drive current for the pins is 40 ma, with a sleep mode current draw of
0.24 ua.  For a buck and a half, you can get the Digispark that runs at 16.5 mHz
and has a USB adapter and a programmable LED.

The operational voltage range is also good - you can use 3.3 or 5 volts.  This
means that you can use 18650 batteries for power.

You don't get console by default, so debug print statements aren't useful.  (I
know that it is possibe to configure a soft serial port).  You are also going to
be programing in C/C++ as this device is way to small to host Python.

## XIAO

The XIOA has an ARM Cortex 32bit 48MHz microcontroller(SAMD21G18) with 256KB Flash,
32KB SRAM.  The XIAO has interfaces: 1 I2C interface,1 UART interface, 1 SPI interface.

The XIOA does have very powerful counter/timers.

While the XIOA does support Python, there isn't all that much space left on the device
after installation.  If you are looking at CircuitPython, note the limited module
support.  For example, the `displayio` and `terminalio` modules are not available.

FreeRTOS is available for the XIOA.  This is my preferred environment for the XIAO.

As much as I like the XIAO, I think that the $5 microcontroller space is very crowded.

