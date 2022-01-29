#include <iostream>
#include <chrono>

#include "./bubble_sort.h"
#include "./insertion_sort.h"
#include "./merge_sort.h"
#include "./quick_sort.h"

using namespace std;

template <typename T>
inline void print(T* arr, int size) {
	for(int index = 0 ; index < size ; ++index) {
		cout << arr[index] << ' ';
	}
	cout << '\n';
}

int main()
{
	int size;
	cin >> size;

	int* arr = new int[size];
	for(int i = 0 ; i < size ; ++i) {
		cin >> arr[i];
	}

	enum algo_code {
		_bubble_sort,
		_insertion_sort,
		_merge_sort,
		_quick_sort,
	};

	string algos[] = {"bubble_sort", "insertion_sort", "merge_sort", "quick_sort"};

	for(int curr = 0 ; curr < 4 ; ++curr) {

		auto start = chrono::high_resolution_clock::now();

		switch(curr) {
			case _bubble_sort:
				print<int>(bubble_sort(arr, size), size);
				break;

			case _insertion_sort:
				print<int>(insertion_sort(arr, size), size);
				break;

			case _merge_sort:
				print<int>(merge_sort(arr, size), size);
				break;

			case _quick_sort:
				print<int>(quick_sort(arr, size), size);
				break;

			default:
				break;
		}

		auto stop = chrono::high_resolution_clock::now();
		auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);

		cout << algos[curr] << " took: " << duration.count() << " microseconds" << '\n';
	}

	return 0;
}
