#pragma once
#ifndef HEADER_CLASS
#define HEADER_CLASS


class Complex {
public:
	int r;
	int i;

	Complex gumar(Complex x, Complex y);
	Complex hanum(Complex x, Complex y);
	Complex bazmapatkum(Complex x, int y);
	unsigned int result(Complex x);
};
#endif