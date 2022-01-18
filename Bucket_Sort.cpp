/* BUCKET SORTING ALGORITHM */

#include <iostream>	
#include <deque>

using namespace std;

template <typename T>
void InsertionSort(deque<T>& dq) {
	int i, j;
	T current;
	for (i = 1; i < dq.size(); i++) { // moving forward
		current = dq[i];

		for (j = i - 1; j >= 0 && dq[j] > current; j--) { // comparing
			dq[j + 1] = dq[j]; // moving to next position
		}
		dq[j + 1] = current; // insert current element
	}
}

template <typename T>
void BucketSort(T* arr, int n) {
	// Buckets (using deque since push_back and pop_front need to be used)
	deque<T>* B = new deque<T>[n];
	if (B == nullptr)
		exit(1);

	// put elements in a corresponding bucket
	for (int i = 0; i < n; i++) {
		int idx = n * arr[i];
		B[idx].push_back(arr[i]);
	}

	// sorting each bucket
	for (int i = 0; i < n; i++) {
		InsertionSort(B[i]);
	}

	// put elements from a bucket to an original array
	int j = 0;
	for (int i = 0; i < n; i++) {
		while (!B[i].empty()) {
			arr[j] = B[i].front();
			B[i].pop_front();
			++j;
			if (j == n)
				break;
		}
	}
}

int main()
{
	double arr1[7] = { 0.9, 0.1, 0.6, 0.7, 0.6, 0.3, 0.1 };
	BucketSort(arr1, 7);

	for (int i = 0; i < 7; i++) {
		cout << arr1[i] << " ";
	} cout << endl;
}