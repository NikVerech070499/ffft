#include <complex>
#include <numbers>

void fft_(const complex<float>* input, complex<float>* output, std::size_t n, std::size_t step = 1) {
	
	if (n == 1) {
		output[0] = input[0];
		return;
	}
	
	// Vectorization is there
	#pragma omp task
	{
	fft_(input, output, n / 2, step * 2);
	fft_(input + step, output + n / 2, n / 2, step * 2);
	}
	#pragma omp taskwait

	for (std::size_t t = 0; t < n / 2; t++) {
		auto E = output[t];
		auto O = output[t + n / 2];
		auto W = std::polar(1.0f, -2.0f * std::pi_v<float> * t / n);
		output[t] = E + W * O;
		output[t + n / 2] = E - W * O;
	}
	
}
