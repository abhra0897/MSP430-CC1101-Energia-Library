#include <cc1101.h>
#include <macros.h>
#include <pins.h>
#include <registers.h>

#define sizetx 61

byte TX_buffer[sizetx]={0};
byte i;

void setup()
{
  Serial.begin(9600);
  Radio.Init();
  Radio.SetDataRate(4); // Needs to be the same in Tx and Rx
  Radio.SetLogicalChannel(1); // Needs to be the same as receiver
  Radio.SetTxPower(0);
  for(i=0;i<sizetx;i++)
  {
     TX_buffer[i]=0;
  }
}
unsigned long burstnum=0;
void loop()
{
  // Send 100 packets, then wait 2 seconds
  // Put burst number in first data field
  TX_buffer[0] = burstnum++;
  for(int i=0;i<100;i++) {
    Radio.SendData(TX_buffer,sizetx);
    delay(1);
  }
  Serial.println("Test");
  delay(100);
}


