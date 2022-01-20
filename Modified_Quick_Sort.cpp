/* MODIFIED QUICK SORTING ALGORITHM */

/*
A modified version of the Quicksort algorithm, 
where the sequence of elements is always split into three subsequences 
by simultaneously using the first two elements as pivots.
*/

#include <iostream>
#include <ctime>

using namespace std;

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void Partition(int* arr, int lo, int hi, int& first_pv, int& second_pv) {
	if (arr[lo] > arr[lo + 1])
		swap(arr[lo], arr[lo + 1]);
	int pivot_1 = arr[lo];
	int pivot_2 = arr[lo + 1];

	// put pivot 2 at the end in order to avoid swapping in the first for loop
	swap(arr[lo + 1], arr[hi]);

	// ----- Partitioning based on pivot 1 ----- (elements <= pivot 1 < elements)
	int i = lo;
	for (int j = lo + 1; j <= hi; j++) {
		if (arr[j] <= pivot_1) { // if arr[j] <= pivot
			++i;
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[lo], arr[i]);
	first_pv = i; // fix an index of pivot 1

	// ----- Preparing for partition based on pivot 2 -----
	second_pv = ++i;
	if (second_pv >= hi) // checking out of range (pivot 1 = largest element)
		return;
	if (arr[hi] != pivot_2) {
		second_pv = first_pv;
		return;
	}
	/* If a pivot 2 has been swapped before, it means that pivot 2 <= pivot 1.
	In this case, after fixing a position of pivot 1, pivot 2 will be in the arr[lo].
	If we assign 'lo' to second, the range is overlapped. So, in this case, make first and second be equal is ideal.
	Swapping pivot 1 and pivot 2 cannot be done since there could be an element that is smaller than pivots in between pivots.
	ex) 2 1 1 2
		f	  s
	--> Elements need to be larger than the pivot 1 and smaller than pivot 2, but in this case it isn't. So it will not sort properly later on. */

	// move pivot 2 to the next position of pivot 1 (swap with last element)
	swap(arr[second_pv], arr[hi]);

	// ----- Partitioning based on pivot 2 ----- (pivot 1 < elements <= pivot 2 < elements)
	for (int j = i + 1; j <= hi; j++) {
		if (arr[j] <= pivot_2) {
			++i;
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[second_pv], arr[i]);
	second_pv = i; // fix an index of pivot 2

	// Result: { elements <= pivot 1 < elements <= pivot 2 < elements }
}

void QuickSort(int* arr, int begin, int end) {
	int first, second;
	if (begin < end) {
		Partition(arr, begin, end, first, second);
		// excluding pivots
		QuickSort(arr, begin, first - 1);
		QuickSort(arr, first + 1, second - 1);
		QuickSort(arr, second + 1, end);
	}
}

void FillArray(int* a, int n) {
	srand(static_cast<unsigned int>(time(0)));
	for (int i = 0; i < n; i++) {
		a[i] = rand() % n;
	}
}

int main()
{
	int arr[40];
	FillArray(arr, 40);

	for (int i = 0; i < 40; i++) {
		cout << arr[i] << " ";
	}cout << endl << endl;

	QuickSort(arr, 0, 39);

	cout << endl;
	for (int i = 0; i < 40; i++) {
		cout << arr[i] << " ";
	}cout << endl;
}