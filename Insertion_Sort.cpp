/* INSERTION SORTING ALGORITHM */

#include <iostream>

using namespace std;

template <typename T>
void Insertion_Sort(T* arr, int n) {
	int i, j;
	T current;

	for (i = 1; i < n; i++) { // moving forward
		current = arr[i];

		for (j = i - 1; j >= 0 && arr[j] > current; j--) { // comparing
			arr[j + 1] = arr[j]; // moving to next position
		}
		arr[j + 1] = current; // insert current element
	}
}

int main()
{
	// Inputs (ints)
	int arr[5] = { 4,3,2,4,4 };
	Insertion_Sort(arr, 5);

	for (int i = 0; i < 5; i++) {
		cout << arr[i] << " ";
	} cout << endl;

	// Inputs (doubles)
	double arr1[5] = { 4.1, 3.3, 2.2, 4.4, 4.2 };
	Insertion_Sort(arr1, 5);

	for (int i = 0; i < 5; i++) {
		cout << arr1[i] << " ";
	} cout << endl;

	// Inputs (strings)
	string arr2[5] = { "Apple", "Mango", "Banana", "Juice", "Ant"};
	Insertion_Sort(arr2, 5);

	for (int i = 0; i < 5; i++) {
		cout << arr2[i] << " ";
	}
}