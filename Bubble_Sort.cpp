/* BUBBLE SORTING ALGORITHM */

#include <iostream>

using namespace std;

template <typename T>
void swap(T* a, T* b) {
	T temp = *a;
	*a = *b;
	*b = temp;
}

template <typename T>
void Bubble_Sort(T* arr, int n) {
	int i = 0, change = 1;

	while (change && i < n - 1) {
		change = 0;
		for (int j = 0; j < n - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				swap(&arr[j], &arr[j + 1]);
				change = 1;
			}
		}
		++i;
	}
}

int main()
{
	// Inputs (ints)
	int arr[7] = { 2,7,4,5,2,6,1 };
	Bubble_Sort(arr, 7);

	for (int i = 0; i < 7; i++) {
		cout << arr[i] << " ";
	}cout << endl;

	// Inputs (doubles)
	double arr1[5] = { 4.1, 3.3, 2.2, 4.4, 4.2 };
	Bubble_Sort(arr1, 5);

	for (int i = 0; i < 5; i++) {
		cout << arr1[i] << " ";
	} cout << endl;

	// Inputs (strings)
	string arr2[5] = { "Apple", "Mango", "Banana", "Juice", "Ant" };
	Bubble_Sort(arr2, 5);

	for (int i = 0; i < 5; i++) {
		cout << arr2[i] << " ";
	} cout << endl;
}