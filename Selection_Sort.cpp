/* SELECTION SORTING ALGORITHM */

#include <iostream>

using namespace std;

template <typename T>
void selection_sort(T* arr, int numelem) {
	int minpos;
	T min;
	// outer loop (depends on the number of elements)
	for (int i = 0; i < numelem; i++) {
		min = arr[i];
		minpos = i;

		// inner loop (finding smallest value and position of it)
		for (int j = i + 1; j < numelem; j++) {
			if (arr[j] < min) {
				min = arr[j];
				minpos = j;
			}
		}
		// swapping
		if (arr[i] != arr[minpos]) {
			arr[minpos] = arr[i];
			arr[i] = min;
		}
	}
}

int main()
{
	// Inputs (ints)
	int arr[7] = { 6,3,8,5,3,5,1 };
	selection_sort(arr, 7);

	for (int i = 0; i < 7; i++) {
		cout << arr[i] << " ";
	}cout << endl;

	// Inputs (doubles)
	double arr1[5] = { 4.1, 3.3, 2.2, 4.4, 4.2 };
	selection_sort(arr1, 5);

	for (int i = 0; i < 5; i++) {
		cout << arr1[i] << " ";
	} cout << endl;

	// Inputs (strings)
	string arr2[5] = { "Apple", "Mango", "Banana", "Juice", "Ant" };
	selection_sort(arr2, 5);

	for (int i = 0; i < 5; i++) {
		cout << arr2[i] << " ";
	} cout << endl;
}