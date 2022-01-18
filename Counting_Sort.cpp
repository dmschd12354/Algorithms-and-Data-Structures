/* COUNTING SORTING ALGORITHM */

#include <iostream>
#include <ctime>

using namespace std;

int minVal;
int addMin;

void min(int* arr, int n) {
	// finding min value in array
	minVal = arr[0];
	for (int i = 1; i < n; i++) {
		if (arr[i] < minVal)
			minVal = arr[i];
	}
}

void make_positive(int* arr, int n) {
	addMin = abs(minVal) + 1; // + 1 to avoid 0 when add it up
	for (int i = 0; i < n; i++) {
		arr[i] += addMin; // make it positive for a while
	}
}

int max(int* arr, int n) {
	int max = arr[0];
	for (int i = 1; i < n; i++) {
		if (arr[i] > max) {
			max = arr[i];
		}
	}
	return max;
}

void Counting_Sort(int* arr, int n) {
	// Check if there is 0 or negative value in array
	min(arr, n);
	if (minVal <= 0)
		make_positive(arr, n);

	// Find a max value in arr
	int maxVal = max(arr, n);
	int* C = new int[maxVal]; // generate C
	if (C == nullptr)
		exit(1);

	int* B = new int[n]; // output array
	if (B == nullptr)
		exit(1);

	// Loop 1
	for (int i = 0; i < maxVal; i++) {
		C[i] = 0;
	}

	// Loop 2
	for (int i = 0; i < n; i++) {
		++C[arr[i] - 1];
	}

	// Loop 3
	for (int i = 1; i < maxVal; i++) {
		C[i] += C[i - 1];
	}

	// Loop 4
	for (int i = n - 1; i >= 0; i--) {
		B[C[arr[i] - 1] - 1] = arr[i];
		--C[arr[i] - 1];
	}

	// copying
	for (int i = 0; i < n; i++) {
		arr[i] = B[i];
	}

	// if there was a 0 or negative integer in array
	if (minVal <= 0) {
		for (int i = 0; i < n; i++) {
			arr[i] -= addMin; // convert it back
		}
	}

	delete[] C;
	delete[] B;
}

int main()
{
	// ----- only positive integers in array -----
	int n = 10;
	int* arr = new int[n];
	if (arr == nullptr)
		exit(1);

	srand(static_cast<unsigned int>(time(0)));
	for (int i = 0; i < n; i++) {
		arr[i] = rand() % n + 1;
	}

	cout << "Randomly generated array: ";
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}cout << endl;

	Counting_Sort(arr, n);
	cout << "After sorting: ";
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}cout << endl;

	// ----- 0 or negative integers in array -----
	int arr1[4] = { -1,6,3,0 };

	Counting_Sort(arr1, 4);

	for (int i = 0; i < 4; i++) {
		cout << arr1[i] << " ";
	}cout << endl;
}