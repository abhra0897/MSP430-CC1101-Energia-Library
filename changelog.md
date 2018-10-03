### Changes by me (abhra0897)

#### Oct 03, 2018

- Removed a bug that was sometimes causing infinite loop while writing to CC1101 registers through SPI bus.
- Bug details: "while(SO_IS_HIGH());" is causing infinite loop sometimes, hence they are commented out some places. Maybe adding pull down resistor to SO (MISO) will solve it? 
- Added debug print option. It's enabled by default. Do DEBUG_TRUE 0 at cc1101.h to disable. DEBUG_PRINT helps to identify problem if program crashes anywhere.

#### Sep 20, 2018

- Added support for 868 MHz ISM band.
- Added frequency change method in API
- Modified examples
- Modified readme with recent changes
#### Sep 16, 2018

- Changed GDO0 and GDO2 pins to free up Analog input pins and the on-board switch of MSP430G2 launchpad

#### Sep 14, 2018

- Added support to MSP430G2553 MCU

### Previous changes by jhester (2015 ?) 

- Added sleep, idle, and other functions supported by MRFI to match functionality
- Now uses class to organize and hide private methods
- Lists all Tx powers in table
- Made tool for determining data rates from registers and registers from target data rates

