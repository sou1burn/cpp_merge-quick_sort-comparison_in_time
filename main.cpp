#include <iostream>
#include "lab8.h"
#include <chrono>

//написать еще одну сортировку(слиянием) и сравнить время выполнения двух разных сортировок и посмотреть разницу
int main() {

	int len;
	std::cout << "Enter length of array: \n";
	std::cin >> len;

	if (len == 0 || len < 0) {
		std::cout << "Array entered wrongly, please retry.";
		return 0;
	}

	int* array = (int*)malloc(len * sizeof(int));

	std::cout << "Enter elements of array: \n";
	for (int i = 0; i < len ; i++) {
		std::cin >> array[i];
	}
	
	std::cout << "Entered array is: \n";
	for (int i = 0; i < len; i++) {
		std::cout << array[i] << " ";
	}

	std::cout << std::endl;
	auto start_quick = std::chrono::high_resolution_clock::now();
	quicksort(array, 0, len - 1);
	auto end_quick = std::chrono::high_resolution_clock::now();
	auto duration_quick = std::chrono::duration_cast<std::chrono::microseconds>(end_quick - start_quick);
	std::cout << "Time taken by quicksort is " <<duration_quick.count()  << " microseconds";
	std::cout << "\nSorted using quicksort array is: \n";
	for (int i = 0; i < len; i++) {
		std::cout << array[i] << " ";
	}
	auto start_merge = std::chrono::high_resolution_clock::now();
	mergesort(array, 0, len - 1);
	auto end_merge = std::chrono::high_resolution_clock::now();
	auto duration_merge = std::chrono::duration_cast<std::chrono::microseconds>(end_merge - start_merge);
	std::cout << "\nTime taken by mergesort is " << duration_merge.count() << " microseconds";
	std::cout << "\nSorted using mergesort array is: \n";
	for (int i = 0; i < len; i++) {
		std::cout << array[i] << " ";
	}

	free(array);
	return 0;
}