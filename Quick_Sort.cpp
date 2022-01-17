/* Quick SORTING ALGORITHM */

#include <iostream>

using namespace std;

template <typename T>
void swap(T* a, T* b) {
	T temp = *a;
	*a = *b;
	*b = temp;
}

// Aim is to partition based on a pivot. (left = smaller, right = larger)
template <typename T>
int partition(T* arr, int p, int q) {
	T x = arr[p]; // pivot
	int i = p; // i = 0 / i: index for putting elements smaller then the pivot

	for (int j = p + 1; j <= q; j++) {
		if (arr[j] <= x) { // if arr[j] <= pivot
			++i;
			swap(arr[i], arr[j]);
		}
	}
	// move pivot to the middle to make (left = smaller, middle = pivot, right = larger)
	swap(arr[p], arr[i]);

	return i; // return an index of pivot
}

template <typename T>
void QuickSort(T* arr, int begin, int end) {
	if (begin < end) {
		int q = partition(arr, begin, end);
		QuickSort(arr, begin, q - 1);
		QuickSort(arr, q + 1, end);
	}
}

int main()
{
	// Inputs (ints)
	int arr[5] = { 1,2,3,4,0 };
	QuickSort(arr, 0, 4);
	for (int i = 0; i < 5; i++) {
		cout << arr[i] << " ";
	}cout << endl;

	// Inputs (doubles)
	double arr1[5] = { 4.1, 3.3, 2.2, 4.4, 4.2 };
	QuickSort(arr1, 0, 4);

	for (int i = 0; i < 5; i++) {
		cout << arr1[i] << " ";
	} cout << endl;

	// Inputs (strings)
	string arr2[5] = { "Apple", "Mango", "Banana", "Juice", "Ant" };
	QuickSort(arr2, 0, 4);

	for (int i = 0; i < 5; i++) {
		cout << arr2[i] << " ";
	} cout << endl;
}