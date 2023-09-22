#include <iostream>
#include "complex.h"
#include <cmath>
using namespace std;

int abs(const Complex& z) {
    return sqrt(z.r * z.r + z.i * z.i);
}

bool compareComplexNumbers(Complex a, Complex b) {
    return abs(a) < abs(b);

}


void bubbleSortComplex(Complex* arr, size) {
    int n = size;
    bool swapped;

    do {
        swapped = false;
        for (int i = 0; i < n - 1; i++) {
            if (compareComplexNumbers(arr[i], arr[i + 1])) {
                swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }
    } while (swapped);
}


void print(Complex* arr, int length) {
    for (int i = 0; i < length; i++) {
        cout << i << " " << arr[i].r << " " << arr[i].i << endl;
    }
}