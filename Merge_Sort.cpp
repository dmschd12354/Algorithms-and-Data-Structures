/* MERGE SORTING ALGORITHM */

#include <iostream>

using namespace std;

template <typename T>
void merge(T* arr, int left, int mid, int right) {
	int i = left;
	int m = mid + 1;
	T* sorted = new T[right - left + 1];
	int idx = 0;

	while (i <= mid && m <= right) {
		if (arr[i] <= arr[m])
			sorted[idx++] = arr[i++];
		else
			sorted[idx++] = arr[m++];
	}

	// copying remaining elements
	if (i <= mid) {
		for (i; i <= mid; i++) {
			sorted[idx++] = arr[i];
		}
	}
	else if (m <= right) {
		for (m; m <= right; m++) {
			sorted[idx++] = arr[m];
		}
	}

	// copying sorted array to arr array
	idx = 0;
	for (int t = left; t <= right; t++) {
		arr[t] = sorted[idx++];
	}

	delete[] sorted;
}

template <typename T>
void merge_sort(T* arr, int left, int right) {
	if (left < right) {
		int mid = (left + right) / 2;
		merge_sort(arr, left, mid);
		merge_sort(arr, mid + 1, right);
		merge(arr, left, mid, right);
	}
}

int main()
{
	// Inputs (ints)
	int arr[6] = { 3,2,5,1,10,1 };
	merge_sort(arr, 0, 5);
	for (int i = 0; i < 6; i++) {
		cout << arr[i] << " ";
	}cout << endl;

	// Inputs (doubles)
	double arr1[5] = { 4.1, 3.3, 2.2, 4.4, 4.2 };
	merge_sort(arr1, 0, 4);

	for (int i = 0; i < 5; i++) {
		cout << arr1[i] << " ";
	} cout << endl;

	// Inputs (strings)
	string arr2[5] = { "Apple", "Mango", "Banana", "Juice", "Ant" };
	merge_sort(arr2, 0, 4);

	for (int i = 0; i < 5; i++) {
		cout << arr2[i] << " ";
	} cout << endl;
}