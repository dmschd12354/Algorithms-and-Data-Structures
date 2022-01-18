/* RADIX SORTING ALGORITHM */

#include <iostream>

using namespace std;

int max(int* arr, int n) {
	int max = arr[0];
	for (int i = 1; i < n; i++) {
		if (arr[i] > max) {
			max = arr[i];
		}
	}
	return max;
}

void CountingSort(int* arr, int n, int div) {
	// Generate C
	int* C = new int[10];
	if (C == nullptr)
		exit(1);

	// Generate output array
	int* B = new int[n];
	if (B == nullptr)
		exit(1);

	// Loop 1
	for (int i = 0; i < 10; i++) {
		C[i] = 0;
	}

	// Loop 2 (from the least significant digit)
	for (int i = 0; i < n; i++) {
		++C[(arr[i] / div) % 10];
	}

	// Loop 3
	for (int i = 1; i < 10; i++) {
		C[i] += C[i - 1];
	}

	// Loop 4
	for (int i = n - 1; i >= 0; i--) {
		B[C[(arr[i] / div) % 10] - 1] = arr[i];
		--C[(arr[i] / div) % 10];
	}

	// copying
	for (int i = 0; i < n; i++) {
		arr[i] = B[i];
	}

	delete[] C;
	delete[] B;
}

void RadixSort(int* arr, int n) {
	int maxval = max(arr, n);
	int digit = 1;
	// finding a digit of the largest number
	while (maxval / 10 != 0) {
		++digit;
		maxval /= 10;
	}

	// sorting by digits
	int div = 1;
	for (int i = 1; i <= digit; i++) {
		CountingSort(arr, n, div);
		div *= 10;
	}
}

int main()
{
	int arr[7] = { 1329,45227,6557,888839,38896555,0,355 };
	RadixSort(arr, 7);
	for (int i = 0; i < 7; i++) {
		cout << arr[i] << " ";
	} cout << endl;
}