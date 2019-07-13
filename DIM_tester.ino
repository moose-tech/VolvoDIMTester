/****************************************************************************
  CAN Write Demo for the SparkFun CAN Bus Shield.

  Written by Stephen McCoy.
  Original tutorial available here: http://www.instructables.com/id/CAN-Bus-Sniffing-and-Broadcasting-with-Arduino
  Used with permission 2016. License CC By SA.

  Distributed as-is; no warranty is given.
*************************************************************************/

#include <Canbus.h>
#include <defaults.h>
#include <global.h>
#include <mcp2515.h>
#include <mcp2515_defs.h>

//********************************Setup Loop*********************************//

void setup() {
  Serial.begin(9600);
  Canbus.init(CANSPEED_125);
}

//********************************Main Loop*********************************//

void loop() {
  tCAN message;
  tCAN message2;
  char receiveVal;

  if (Serial.available() > 0)
  {
    receiveVal = Serial.read();

    switch (receiveVal) {
      //IGN ON P2 + set brightness
      case '0':
        message.id = 0x07E; //formatted in HEX
        message.header.rtr = 0;
        message.header.length = 8; //formatted in DEC
        message.data[0] = 0x00;
        message.data[1] = 0x93;
        message.data[2] = 0x9A;
        message.data[3] = 0x00; //formatted in HEX
        message.data[4] = 0x00;
        message.data[5] = 0x00;
        message.data[6] = 0x00;
        message.data[7] = 0x24;
        mcp2515_bit_modify(CANCTRL, (1 << REQOP2) | (1 << REQOP1) | (1 << REQOP0), 0);
        mcp2515_send_message(&message);
        message2.id = 0x2A0;
        message2.header.rtr = 0;
        message2.header.length = 8;
        message2.data[0] = 0x20;
        message2.data[1] = 0x0F;
        mcp2515_bit_modify(CANCTRL, (1 << REQOP2) | (1 << REQOP1) | (1 << REQOP0), 0);
        mcp2515_send_message(&message2);
        break;

      //Test P2
      case '1':
        message.id = 0x720;
        message.header.rtr = 0;
        message.header.length = 8;
        message.data[0] = 0x04;
        message.data[1] = 0x31;
        message.data[2] = 0x01;
        message.data[3] = 0x02;
        message.data[4] = 0x02;
        mcp2515_bit_modify(CANCTRL, (1 << REQOP2) | (1 << REQOP1) | (1 << REQOP0), 0);
        mcp2515_send_message(&message);
        break;

      //IGN ON P3 + set brightness
      case '2':
        message.id = 0x07E; //formatted in HEX
        message.header.rtr = 0;
        message.header.length = 8; //formatted in DEC
        message.data[0] = 0x00;
        message.data[1] = 0xFB;
        message.data[2] = 0x9B;
        message.data[3] = 0x20; //formatted in HEX
        message.data[4] = 0x00;
        message.data[5] = 0x1F;
        message.data[6] = 0xE0;
        message.data[7] = 0x20;
        mcp2515_bit_modify(CANCTRL, (1 << REQOP2) | (1 << REQOP1) | (1 << REQOP0), 0);
        mcp2515_send_message(&message);
        message2.id = 0x2A0;
        message2.header.rtr = 0;
        message2.header.length = 8;
        message2.data[0] = 0x20;
        message2.data[1] = 0x0F;
        mcp2515_bit_modify(CANCTRL, (1 << REQOP2) | (1 << REQOP1) | (1 << REQOP0), 0);
        mcp2515_send_message(&message2);
        break;

      //Test P3
      case '3':
        message.id = 0x720;
        message.header.rtr = 0;
        message.header.length = 8;
        message.data[0] = 0x04;
        message.data[1] = 0x31;
        message.data[2] = 0x01;
        message.data[3] = 0x02;
        message.data[4] = 0x02;
        mcp2515_bit_modify(CANCTRL, (1 << REQOP2) | (1 << REQOP1) | (1 << REQOP0), 0);
        mcp2515_send_message(&message);
        break;

      //IGN OFF P3
      case '4':
        message.id = 0x07E; //formatted in HEX
        message.header.rtr = 0;
        message.header.length = 8; //formatted in DEC
        message.data[0] = 0x00;
        message.data[1] = 0xFB;
        message.data[2] = 0x86;
        message.data[3] = 0x20; //formatted in HEX
        message.data[4] = 0x00;
        message.data[5] = 0x1F;
        message.data[6] = 0xE0;
        message.data[7] = 0x20;
        mcp2515_bit_modify(CANCTRL, (1 << REQOP2) | (1 << REQOP1) | (1 << REQOP0), 0);
        mcp2515_send_message(&message);
        break;

      //IGN OFF P2
      /*case '5':
        
        break;*/
    }
  }
}
