#include <REGX52.H>
#include "MatrixLED.h"

int offset,col;
unsigned char Animation[] = {0x40, 0xD8, 0xFD, 0x0E, 0x1D, 0x1E, 0x1C, 0x38};

void main() {
  _74HC595_Init();
  while (1) {
    for (offset = 0; offset <= sizeof(Animation) - 8; offset++) {
      for (col = 0; col < 8; col++) {
        MatrixLED(col, Animation[col+offset]);
      }
    }
  }
}