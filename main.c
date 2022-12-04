#include <stdio.h>
#include "AudioFile.h"
#include "FIRFilter.h"

// low pass filter
FIRFilter lp_fir;

int main() {
  FIRFilter_Init(&lp_fir);

  int i = 0;
  while (i < 100) {
    float input = i++;
    FIRFilter_Update(&lp_fir, input);
    float out = lp_fir.out;
    printf("%f ", lp_fir.out);
  }
  printf("\n");

  return 0;
}
