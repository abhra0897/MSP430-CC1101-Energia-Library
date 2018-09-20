### CC1101 MSP430 Energia Library

- (last updated: 20th September, 2018)

- (What's new: Added 868MHz support. see "changelog.md" file)

#### Note
This repository is a fork of Josiah Hester's (Jhester) CC1101 Library for MSP430 on Energia framework. Initially the library only supported the FRAM series MSP430 launchpads: EXP-MSP430FR5739, MSP430FR5969, and MSP430FR6989. Unfortunately it didn't support EXP-MSP430G2 Launchpad that incorporates MSP430G2553 MCU. So, here I have added support to MSP430G2553 MCU  by modifying the pins.h file. It should also work with any MSP430G2x53 and MSP430G2x13 MCU.
( Maybe it will work with MSP430G2452 too? )

##### Credit
Credit for the core library goes to Josiah Hester (jhester) https://github.com/jhester

Original library by jhester: https://buffet.cs.clemson.edu/vcs/u/jhester/cc1101-energia/

#### Supported Frequencies
- 433 MHz  (Supports only 433MHz for now)

#### Supported Launchpads/MCUs
- EXP-MSP430G2 w/ MSP430G2x53 or MSP430G2x13 MCU   (support added: 14th September 2018)
- EXP-MSP430FR5739
- EXP-MSP430FR5969
- EXP-MSP430FR6989

Use the data_rates.py script to determine your data rate register settings.
Or use the provided table and index in the source files.

Check the examples for basic usage.

This library supports low power sleep mode (draw of 200nA).

#### Download
Download this repository to your computer using [git](https://git-scm.com/):

```
git clone https://github.com/abhra0897/MSP430-CC1101-Energia-Library.git
```

#### Install
Put this folder in your Energia libraries folder. Restart Energia. Then load the examples from "File->Examples->CC1101" (note you need two radios to test functionality, a reciever and a transmitter).

#### Pinouts
For each launchpad, reference [this pin description image of the CC1101](http://www.kooing.com/image/cache/data/CC1101_3-500x500.jpg). The proper orientation is with the antenna facing to your right, with the text "RF1100SE" in the correct orientation.

#### MSP430G2553 MCU on EXP-MSP430G2 Launchpad Pinout
Reference the [pinout](https://embeddedcomputing.weebly.com/uploads/1/1/6/2/11624344/4354073_orig.jpeg) for this launchpad, and the [pinout](http://www.kooing.com/image/cache/data/CC1101_3-500x500.jpg) for the CC1101.

    ** MCU Pin numbers (e.g P1.6, P1.7 etc.) are same for all MSP430G2x53 and MSP430G2x13. Launchpad pin numbers (e.g 14, 8 etc.) are only applicable for MSP430G2553 MCU.
	VDD  -> VCC
	SI   -> 14 / P1.6
	SO   -> 15 / P1.7
	CSn  -> 8  / P2.0
	SCK  -> 7  / P1.5
	GDO2 -> 10  / P2.2
	GDO0 -> 9  / P2.1
	GND  -> GND

#### MSP430FR5739 Experimenter Pinout
Reference the [pinout](http://energia.nu/img/LaunchPadMSP430FR5739-v1.1.jpg) for this launchpad, and the [pinout](http://www.kooing.com/image/cache/data/CC1101_3-500x500.jpg) for the CC1101.

	VDD  -> VCC
	SI   -> 11 / P1.6
	SO   -> 12 / P1.7
	CSn  -> 20 / P1.3
	SCK  -> 6  / P2.2
	GDO2 -> 9  / P3.6
	GDO0 -> 3  / P2.5
	GND  -> GND

#### MSP430FR5969 Launchpad Pinout
Reference the [pinout](http://energia.nu/wordpress/wp-content/uploads/2014/10/LaunchPad-with-MSP430FR5969.jpg) for this launchpad, and the [pinout](http://www.kooing.com/image/cache/data/CC1101_3-500x500.jpg) for the CC1101.

	VDD  -> VCC
	SI   -> 15 / P1.6
	SO   -> 14 / P1.7
	CSn  -> 11 / P1.3
	SCK  -> 7  / P2.2
	GDO2 -> 10 / P3.6
	GDO0 -> 8  / P3.4
	GND  -> GND

#### MSP430FR6989 Launchpad Pinout
Reference the [pinout](http://energia.nu/img/LaunchPadMSP430FR5739-v1.1.jpg) for this launchpad, and the [pinout](http://energia.nu/wordpress/wp-content/uploads/2015/07/MSP430FR6989_pinmap.png) for the CC1101.

	VDD  -> 3v3
	SI   -> 15 / P1.6
	SO   -> 14 / P1.7
	CSn  -> 40 / P2.7
	SCK  -> 7  / P1.4
	GDO2 -> 39 / P2.6
	GDO0 -> 38 / P3.3
	GND  -> GND

#### API
All methods below work, and have been tested.

	// Initialize pins, set default registers for CC1101
	void Init(void);

	// Go into receive mode
	void RxOn(void);

	// Go into IDLE mode (draws around 2mA)
	void Idle(void);		

	// Turn off crystal oscillator and go into deep sleep (draws around 200nA)
	void Sleep(void);

	// Wakeup from deep sleep
	void Wakeup(void);

	// Send a data buffer
	void SendData(uint8_t *txBuffer, uint8_t size);

	// Send a data buffer and return without waiting for confirmation
	void SendDataNoWait(uint8_t *txBuffer, uint8_t size);		

	// Set the data rate from one of the builtin choices:
	// rate_ndx=0, 499.590 kBaud
	// rate_ndx=1, 249.795 kBaud
	// rate_ndx=2, 153.252 kBaud
	// rate_ndx=3,  76.626 kBaud /* This setting works well, and any data rates below it */
	// rate_ndx=4,  38.313 kBaud
	// rate_ndx=5,  19.355 kBaud
	// rate_ndx=6,   9.288 kBaud
	// rate_ndx=7,   4.644 kBaud
	// rate_ndx=8,   2.322 kBaud
	// rate_ndx=9,   1.161 kBaud
	// rate_ndx=10,   0.969 kBaud
	void SetDataRate(uint8_t rate_ndx);


	// Set the transmit power from builtin settings
	/* powrset_ndx=0 -- 10 dBm */	 // 29.1 mA
	/* powrset_ndx=1 -- 7 dBm */	 // 24.2 mA
	/* powrset_ndx=2 -- 5 dBm */     // 19.4 mA
	/* powrset_ndx=3 -- 0 dBm */     // 15.9 mA
	/* powrset_ndx=4 -- -10 dBm */	 // 14.4 mA
	/* powrset_ndx=5 -- -15 dBm */	 // 13.1 mA
	/* powrset_ndx=6 -- -20 dBm */	 // 12.4 mA
	/* powrset_ndx=7 -- -30 dBm */	 // 11.9 mA
	void SetTxPower(uint8_t powrset_ndx);

	// Set radio frequency from the available options
	// freq_ndx=0 -- 433 MHz
        // freq_ndx=1 -- 868 MHz
	void SetFrequency(uint8_t freq_ndx);

	// Set the channel to transmit on, RX and TX must be on same channel
	void SetLogicalChannel(uint8_t channel);

	// Sets the maximum size of the packet (upto 61)
	void SetMaxPacketLength(uint8_t pkt_length);

	// Gets MARC state for debugging.
	// Check Figure 25 in CC1101 datasheet to relate the output to the state diagram
	uint8_t GetMARCState();

	// Returns true if packet received
	uint8_t CheckReceiveFlag(void);

	// Receives data into buffer
	uint8_t ReceiveData(uint8_t *rxBuffer);

	// Returns the last SPI state byte
	uint8_t GetState(void);

	// Gets the received signal strength indicator
	int8_t Rssi(void);

#### To do
I am working on this lib to add support for all the frequncies. I hope more updates are coming soon.

#### License
The MIT License (MIT)

Copyright (c) 2018 Avra Mitra
Copyright (c) 2015 Josiah Hester

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
