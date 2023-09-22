#include <iostream>
#include "complex_sort.h"

int main() {
	int c = 5;
	Complex* arr = new Complex[c];

	for (int i = 0; i < length; i++) {
		arr[i].r = c - i;
		arr[i].i = i;
	}

	print(arr, c);


	bubbleSortComplex(arr, c);
	print(arr, c);

	return 0;
}