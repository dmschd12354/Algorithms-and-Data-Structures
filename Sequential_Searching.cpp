/* SEQUENTIAL SEARCHING ALGORITHM */


#include <iostream>

using namespace std;

template <typename T>
int Sequential_Searching(T* arr, int n, T target) {
	for (int i = 0; i < n; i++) {
		if (arr[i] == target)
			return i;
	}

	return -1;
}

int main() {
	int arr[5] = { 1,2,3,4,5 };
	cout << "Index: " << Sequential_Searching(arr, 5, 3) << endl;

	double arr1[5] = { 1.1,2.2,3.3,4.4,5.5 };
	cout << "Index: " << Sequential_Searching(arr1, 5, 5.5) << endl;

	char arr2[5] = { 'a','b','c','d','e' };
	cout << "Index: " << Sequential_Searching(arr2, 5, 'b') << endl;

	char arr3[5] = "abcd";
	cout << "Index: " << Sequential_Searching(arr3, 5, 'b') << endl;
}