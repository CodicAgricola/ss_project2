#include <stdio.h>
#include <math.h>

// samples/sec
const int sampleRate = 44100;

typedef struct {
  float frequency;
  float amplitude;
  float angle;
  float offset;
} SineOscillator;

void SineOscillator_Init(SineOscillator *so, float freq, float amp) {
  so->frequency = freq;
  so->amplitude = amp;
  so->offset = 2 * M_PI * so->frequency / sampleRate;
}

double SineOscillator_Sample(SineOscillator *so) {
  double sample = so->amplitude * sin(so->angle);
  so->angle += so->offset;
  return sample;
}

int main() {
  FILE *in_fp;
  FILE *out_fp;
  int duration = 2;
  SineOscillator so;
  SineOscillator_Init(&so, 440, 0.5);

  out_fp = fopen("waveform", "wb");

  for (int i = 0; i < sampleRate * duration; i++) {
    double sample = SineOscillator_Sample(&so);
    fwrite(&sample, sizeof(double), 1, out_fp);
  }

  fclose(out_fp);
}
