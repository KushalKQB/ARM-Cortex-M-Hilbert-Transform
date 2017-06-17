/* Algorithm to compute hilbert transform:
1) Compute FFT of the vector.
2) Consider the no. of elements to be N. Then, multiply
			-> 1 with elements at indices 0 and (N/2)
			-> 2 with elements at indices from 1 to ((N/2)-1)
			-> 0 with elements at indices from ((N/2)+1) to N-1
3) Finally, compute IFFT of the vector obtained.

* The vector must follow the same interleaved format as used in CMSIS-DSP software library.

* The function performs in-place computation the same way all other transform functions do
in CMSIS-DSP software library.*/

#include "arm_math.h"
#include "arm_const_structs.h"
#include "arm_hilbert.h"

void arm_chilbert_f32(
	const arm_cfft_instance_f32* S,
	float32_t* p1) 
{
	uint32_t i, L;
	
	L = (S->fftLen);
	
	arm_cfft_f32(S, p1, 0, 1);
	for(i = 0; i <= (L*2)-1; i += 2){
		if(i == 0 || i == L) {}
		else if(i <= L-2) {
			p1[i] = 2 * p1[i];
			p1[i+1] = 2 * p1[i+1];
		}
		else {
			p1[i] = 0;
			p1[i+1] = 0;
		}
	}
	
	arm_cfft_f32(S, p1, 1, 1);
}