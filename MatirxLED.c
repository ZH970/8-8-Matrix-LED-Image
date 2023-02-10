#include <REGX52.H>
#define MATRIX_LED_PORT P0

int i;
sbit SER = 0xB4;
sbit SERCLK = 0xB6;
sbit RCK = 0xB5;

void _74HC595_Init() {
  //There must be these codes to initialization
  SER = 0;
  RCK = 0;
}

/**
 ** @brief Send data to 74HC595
 ** @param When state is 0, it will enable LED 8 * 8 dot matrix to display serial data.If LED is enlighting, this byte is 0
 ** @reval 
 **/
void _74HC595_Send(unsigned char byte, unsigned int state) {
  for (i = 0; i < 8; i++) {
    SER = byte & (0x80 >> i);
    if ((~state) & 0x01) {

      if (i == 0) {
        P2_7 = SER;
      }
      if (i == 1) {
        P2_6 = SER;
      }
      if (i == 2) {
        P2_5 = SER;
      }
      if (i == 3) {
        P2_4 = SER;
      }
      if (i == 4) {
        P2_3 = SER;
      }
      if (i == 5) {
        P2_2 = SER;
      }
      if (i == 6) {
        P2_1 = SER;
      }
      if (i == 7) {
        P2_0 = SER;
      }
    }
    SERCLK = 1;
    SERCLK = 0;
  }
  RCK = 1;
  RCK = 0;
}

/**
 ** @brief Matrix LED show the data that is specified its column
 ** @param Column:{0,7}
 ** @reval
 **/
void MatrixLED(unsigned int column, Data) {
  _74HC595_Send(Data, 1);    //No reference value when multiple columns are displayed
  MATRIX_LED_PORT = ~(0x80 >> column);    //1000 0000
}