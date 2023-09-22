#include <iostream>
#include <cmath>

class Complex {
public:
	int r;
	int i;

	~Complex() {}

	Complex(int x, int y) {
		r = x;
		i = y;
	}


	Complex gumar(Complex x, Complex y) {
		x.r += y.r;
		x.i += x.i;
		return x;
	};

	Complex hanum(Complex x, Complex y) {
		x.r -= y.r;
		x.i -= x.i;
		return x;
	};

	Complex bazmapatkum(Complex x, int y) {
		x.r *= y;
		x.i *= y;
		return x;
	};

	unsigned int Bajanum(Complex x) {
		unsigned int result = sqrt((x.r * x.r) + (x.i * x.i));
		return result;
	};
};