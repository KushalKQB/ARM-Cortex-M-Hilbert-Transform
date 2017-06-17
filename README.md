# ARM-Cortex-M-Hilbert-Transform
DSP functions to compute Hilbert Transform of a set of real or complex data samples. Crucial in signal processing applications requiring analytic representation of the signal.
<h2> Note: </h2>
This function will only work in CMSIS based projects.
<h2> Usage </h2>
You only need to add the files "arm_chilbert.c" and "arm_hilbert.h" to your source group. The naming conventions are similar to functions provided by CMSIS-DSP software library. For further details on how to use the function, execute "test.c" provided in the "Examples" folder. Supports lengths of [16,32,64...4096] only.
<h2> Algorithm </h2>
<ol>
<li> Compute FFT of the vector.</li>
<li> Consider the no. of elements to be N. Then, multiply
			<ul>
      <li> 1 with elements at indices 0 and (N/2)
			<li> 2 with elements at indices from 1 to ((N/2)-1)
			<li> 0 with elements at indices from ((N/2)+1) to N-1
      </ul>
</li>
<li> Finally, compute IFFT of the vector obtained.</li>
</ol>
<h2> License </h2>
This project is licensed under the MIT License - see the LICENSE.md file for more details.
<h2> Acknowledgments </h2>
The algorithm is based on MATLAB's implementation of "hilbert()" function.
