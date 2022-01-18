/* HEAP SORTING ALGORITHM */

#include <iostream>

using namespace std;

int parent(int i) { return (--i) / 2; }
int left(int i) { return (++i) * 2 - 1; }
int right(int i) { return (++i) * 2; }

template <typename T>
void swap(T* a, T* b) {
	T temp = *b;
	*a = *b;
	*b = temp;
}

template <typename T>
void Max_Heapify(T* arr, int i, int n) { // Heapifying a tree that is spread from i
	int l = left(i);
	int r = right(i);
	int largest;

	if (l < n && arr[l] > arr[i]) // when left-child > parent
		largest = l;
	else
		largest = i; // when parent > left-child

	if (r < n && arr[r] > arr[largest]) // when right-child > arr[largest]
		largest = r;

	if (largest != i) { // when parent is smaller than left or right child
		swap(arr[i], arr[largest]);
		Max_Heapify(arr, largest, n); // recursive call - heapifying tree in the next level
	}
}

template <typename T>
void Build_Max_Heap(T* arr, int n) {
	/*
	Beginning from i equals to an index of parent of a last node, hepify respect to i.
	Then, hepify the heap until i becomes 0.
	*/
	for (int i = parent(n - 1); i >= 0; i--) {
		Max_Heapify(arr, i, n);
	}
}

template <typename T>
void Heap_Sort(T* arr, int n) {
	Build_Max_Heap(arr, n);
	for (int i = n - 1; i >= 1; i--) { // begin from the last element to the second element
		swap(arr[0], arr[i]); // swapping the last node with the first node
		--n; // decrementing the heap size (implicitly removing the last node(maximum))
		Max_Heapify(arr, 0, n); // heapifying arr b/c arr doesn't satisfy the max-heap property now 
	}
}

int main()
{
	// Inputs (ints)
	int arr[7] = { 6,6,7,4,8,5,2 };
	Heap_Sort(arr, 7);

	for (int i = 0; i < 7; i++) {
		cout << arr[i] << " ";
	}cout << endl;

	// Inputs (doubles)
	double arr1[5] = { 4.1, 3.3, 2.2, 4.4, 4.2 };
	Heap_Sort(arr1, 5);

	for (int i = 0; i < 5; i++) {
		cout << arr1[i] << " ";
	} cout << endl;

	// Inputs (strings)
	string arr2[5] = { "Apple", "Mango", "Banana", "Juice", "Ant" };
	Heap_Sort(arr2, 5);

	for (int i = 0; i < 5; i++) {
		cout << arr2[i] << " ";
	} cout << endl;
}