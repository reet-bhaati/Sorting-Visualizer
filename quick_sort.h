#include <iostream>
using namespace std;

int partition (int* arr, int low, int high)
{
    int pivot = arr[high];  
    int i = (low - 1); 
 
    for (int j = low; j <= high- 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(int* arr, int start, int end) {
	if(start < end) {
		int pivot = partition(arr, start, end);
		mergeSort(arr, start, pivot-1);
		mergeSort(arr, pivot+1, end);
	}
}

int* quick_sort(int* arr, int size) {
	
	int* store = new int[size];
	for(int index = 0 ; index < size ; ++index) {
		store[index] = arr[index];
	}

	quickSort(store, 0, size-1);
	return store;
}
