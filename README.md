### CC1101 Energia Library

This library interfaces with the CC110X chips (and probably the CC2500). These are commonly found online (check eBay or Amazon) and are very useful low frequency radios. Outdoor range is in excess of one kilometer LOS. This library ahs been tested with, and works on all the FRAM series MSP430 Launchpads, specifically the MSP430FR5739, MSP430FR5969, and MSP430FR6989.

Use the data_rates.py script to determine your data rate register settings.
Or use the provided table and index in the source files.

Check the examples for basic usage.

This library supports low power sleep mode (draw of 200nA).

#### Download
Download this repository to your computer using [git](https://git-scm.com/):

```
git clone anonymous@buffet.cs.clemson.edu:jhester/cc1101-energia cc1101
```

#### Install
Put this folder in your Energia libraries folder. Restart Energia. Then load the examples from "File->Examples->CC1101" (note you need two radios to test functionality, a reciever and a transmitter).

#### Pinouts
For each launchpad, reference [this pin description image of the CC1101](http://www.kooing.com/image/cache/data/CC1101_3-500x500.jpg). The proper orientation is with the antenna facing to your right, with the text "RF1100SE" in the correct orientation.

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
	/* powrset_ndx=0 -- 10 dBm */	0xC0, // 29.1 mA
	/* powrset_ndx=1 -- 7 dBm */		0xC8, // 24.2 mA
	/* powrset_ndx=2 -- 5 dBm */		0x84, // 19.4 mA
	/* powrset_ndx=3 -- 0 dBm */		0x60, // 15.9 mA
	/* powrset_ndx=4 -- -10 dBm */	0x34, // 14.4 mA
	/* powrset_ndx=5 -- -15 dBm */	0x1D, // 13.1 mA
	/* powrset_ndx=6 -- -20 dBm */	0x0E, // 12.4 mA
	/* powrset_ndx=7 -- -30 dBm */	0x12, // 11.9 mA
	void SetTxPower(uint8_t powrset_ndx);

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


#### Changelog
- Added sleep, idle, and other functions supported by MRFI to match functionality
- Now uses class to organize and hide private methods
- Lists all Tx powers in table
- Made tool for determining data rates from registers and registers from target data rates


#### License
The MIT License (MIT)

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
