#include "arm_math.h"
#include "arm_const_structs.h"
#include "arm_hilbert.h"

// Below is a set of real data. Note that the real and imaginary parts are interleaved (conforming to CMSIS).
// The results were confirmed in MATLAB using the builtin function 'hilbert()'
static float32_t data_samples[] = {0.957506835434298,0,0.964888535199277,0,
																	 0.157613081677548,0,0.970592781760616,0,
																	 0.957166948242946,0,0.485375648722841,0,
																	 0.800280468888800,0,0.141886338627215,0,
																	 0.421761282626275,0,0.915735525189067,0,
																	 0.792207329559554,0,0.959492426392903,0,
																	 0.655740699156587,0,0.0357116785741896,0,
																	 0.849129305868777,0,0.933993247757551,0};

int32_t main() {
	arm_chilbert_f32(&arm_cfft_sR_f32_len16, data_samples);
	while(1);
}
