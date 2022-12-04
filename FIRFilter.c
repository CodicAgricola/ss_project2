#include "FIRFilter.h"

static float FIR_IMPULSE_RESPONSE[FIR_FILTER_LENGTH] = {
  -0.00329f,
  -0.00525f,
  -0.00688f,
  0.00000f,
  0.02542f,
  0.07247f,
  0.13112f,
  0.18059f,
  0.20000f,
  0.18059f,
  0.13112f,
  0.07247f,
  0.02542f,
  0.00000f,
  -0.00688f,
  -0.00526f
};

//static int FIR_IMPULSE_RESPONSE[];

void FIRFilter_Init(FIRFilter *fir) {
  for (int n = 0; n < FIR_FILTER_LENGTH; n++) {
    fir->buf[n] = 0.0f;
  }

  fir->bufIndex = 0;
  fir->out = 0.0f;
}

float FIRFilter_Update(FIRFilter *fir, float input) {
  fir->buf[fir->bufIndex] = input;
  fir->bufIndex++;
  if (fir->bufIndex == FIR_FILTER_LENGTH) {
    fir->bufIndex = 0;
  }

  fir->out = 0.0f;

  int sumIndex = fir->bufIndex;

  for (int n = 0; n < FIR_FILTER_LENGTH; n++) {
    if (sumIndex > 0) {
      sumIndex--;
    } else {
      sumIndex = FIR_FILTER_LENGTH - 1;
    }

    fir->out += FIR_IMPULSE_RESPONSE[n] * fir->buf[sumIndex];
  }

  return fir->out;
}

/*
float FIRFilter_Update_Int(FIRFilter *fir, float input) {
  fir->buf[fir->bufIndex] = input;
  fir->bufIndex++;
  if (fir->bufIndex == FIR_FILTER_LENGTH) {
    fir->bufIndex = 0;
  }

  fir->out = 0.0f;

  int sumIndex = fir->bufIndex;

  for (int n = 0; n < FIR_FILTER_LENGTH; n++) {
    if (sumIndex > 0) {
      sumIndex--;
    } else {
      sumIndex = FIR_FILTER_LENGTH - 1;
    }

    fir->out += FIR_IMPULSE_RESPONSE[n] * fir->buf[sumIndex];
  }

  return fir->out;
}
*/
