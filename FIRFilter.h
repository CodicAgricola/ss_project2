#define FIR_FILTER_LENGTH 16

typedef struct {
  float buf[FIR_FILTER_LENGTH];
  int bufIndex;

  float out;
} FIRFilter;

void FIRFilter_Init(FIRFilter *fir);
float FIRFilter_Update(FIRFilter *fir, float input);
