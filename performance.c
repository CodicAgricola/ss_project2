#include <stdint.h>
#include "FIRFilter.h"

int main() {
  FIRFilter fir;
  FIRFilter_Init(&fir);
  int16_t input = 100;
  int16_t output = FIRFilter_Update(&fir, input);

  return 0;
}
