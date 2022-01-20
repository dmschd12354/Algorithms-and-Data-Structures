/* BINARY SEARCHING ALGORITHM */

#include <iostream>

using namespace std;

template <typename T>
int Binary_Searching(T* arr, int begin, int end, T target) {
	if (begin <= end) {
		int mid = (begin + end) / 2;
		if (arr[mid] == target)
			return mid;
		else if (target < arr[mid])
			return Binary_Searching(arr, begin, mid - 1, target);
		else if (target > arr[mid])
			return Binary_Searching(arr, mid + 1, end, target);
	}
	else
		return -1;
}

int main()
{
	int arr[5] = { 1,2,5,3,7 };
	cout << "Index: " << Binary_Searching(arr, 0, 4, 2) << endl;

	double arr1[5] = { 1.1,2.2,3.3,4.4,5.5 };
	cout << "Index: " << Binary_Searching(arr1, 0, 5, 5.5) << endl;

	char arr2[5] = { 'a','b','c','d','e' };
	cout << "Index: " << Binary_Searching(arr2, 0, 5, 'b') << endl;

	char arr3[5] = "abcd";
	cout << "Index: " << Binary_Searching(arr3, 0, 5, 'b') << endl;
}