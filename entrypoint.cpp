#include <iostream>
#include <memory>
#include "entrypoint.h"

int main() {

	constexpr size_t n = 128;

	auto output = std::make_unique<complex<float>[]>(n);
	auto input  = std::make_unique<complex<float>[]>(n);

	for (size_t i = 0; i < n / 2; i++) {
		input[i]     = 1.5 * i;
		input[n-1-i] = 1.5 * i;
	}

	fft_(input, output, n);

	for (size_t i = 0; i < n; i++)
		std::cout << el.real() << "," << el.imag() << "\n";

	return 0;

}
