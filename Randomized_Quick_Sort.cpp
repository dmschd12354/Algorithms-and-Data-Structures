#include <iostream>
#include <ctime>

using namespace std;

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int* arr, int p, int q) { // Aim is to partition based on a pivot. (left = smaller, right = larger)
	int x = arr[p]; // pivot
	int i = p; // i = first / i: index for putting elements smaller then the pivot

	for (int j = p + 1; j <= q; j++) {
		if (arr[j] <= x) { // if arr[j] <= pivot
			++i;
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[p], arr[i]); // move pivot to the middle to make (left = smaller, middle = pivot, right = larger)

	return i; // return an index of pivot
}

int Randomized_partition(int* arr, int begin, int end) {
	srand(static_cast<unsigned int>(time(0)));
	int i = rand() % (begin - end); // choose pivot randomly
	swap(arr[begin], arr[i]); // swap a pivot and the first element in order to move the pivot to the beginning
	return partition(arr, begin, end);
}

void QuickSort(int* arr, int begin, int end) {
	if (begin < end) {
		int q = Randomized_partition(arr, begin, end);
		QuickSort(arr, begin, q - 1);
		QuickSort(arr, q + 1, end);
	}
}

int main()
{
	int arr[5] = { 1,2,3,4,0 };
	QuickSort(arr, 0, 4);
	for (int i = 0; i < 5; i++) {
		cout << arr[i] << " ";
	}cout << endl;
}