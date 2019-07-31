#include <mcp_can.h>
#include <SPI.h>

const int SPI_CS_PIN = 10;

MCP_CAN CAN(SPI_CS_PIN); // Set CS pin

void setup()
{
  Serial.begin(9600);
  CAN.begin(CAN_125KBPS);
}

//P2_IGN_ON
unsigned char stmp[8] = {0x8E, 0x00, 0x1C, 0x36, 0x70, 0x1F, 0x08, 0x00};
unsigned char stmp2[8] = {0xCB, 0x51, 0xB9, 0xF0, 0x00, 0x00, 0x00, 0x00};

//P2_TEST
unsigned char stmp3[8] = {0xCC, 0x51, 0xB2, 0x02, 0x80, 0x00, 0x00, 0x00};

//P3_IGN_ON + BRIGHTNESS
unsigned char stmp4[8] = {0x00, 0xFB, 0x9B, 0x20, 0x00, 0x1F, 0xE0, 0x20};
unsigned char stmp5[8] = {0x20, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

//P3_TEST
unsigned char stmp6[8] = {0x04, 0x31, 0x01, 0x02, 0x02, 0x00, 0x00, 0x00};

//P3_IGN_OFF
unsigned char stmp7[8] = {0x00, 0xFB, 0x86, 0x20, 0x00, 0x1F, 0xE0, 0x20};

void loop()
{
  byte receiveVal;

  if (Serial.available() > 0)
  {
    receiveVal = Serial.read();

    switch (receiveVal) {
      //IGN ON P2
      case 0x01:
        CAN.sendMsgBuf(0x00513FFC, 1, 8, stmp);
        while (true) {
          CAN.sendMsgBuf(0x000FFFFE, 1, 8, stmp2);
        }
        break;

      //Test P2
      case 0x02:
        CAN.sendMsgBuf(0x000FFFFE, 1, 8, stmp3);
        break;

      //IGN ON P3 + set brightness
      case 0x03:
        CAN.sendMsgBuf(0x07E, 0, 8, stmp4);
        CAN.sendMsgBuf(0x2A0, 0, 8, stmp5);
        break;

      //Test P3
      case 0x04:
        CAN.sendMsgBuf(0x720, 0, 8, stmp6);
        break;

      //IGN OFF P3
      case 0x05:
        CAN.sendMsgBuf(0x07E, 0, 8, stmp7);
        break;
    }
  }
}
