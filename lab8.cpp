#include <iostream>
#include "lab8.h"


void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int median(int arr[], int low, int high) {

	int mid = (low + high) / 2;

	if (arr[low] > arr[mid]) {
		swap(&arr[low], &arr[mid]);
	}
	if (arr[mid] > arr[high]) {
		swap(&arr[mid], &arr[high]);
	}
	if (arr[low] > arr[mid]) {
		swap(&arr[low], &arr[mid]);
	}

	return mid;
}

int splitting(int arr[], int low, int high) {
	int pivot = median(arr, low, high);
	int pivot_val = arr[pivot];

	swap(&arr[pivot], &arr[high]);

	int i = low;

	for (int j = low; j < high; j++) {
		if (arr[j] < pivot_val) {
			swap(&arr[i], &arr[j]);
			i++;
		}
	}

	swap(&arr[i], &arr[high]);
	return i;
}


void quicksort(int arr[], int low, int high) {
	if (low < high) {

		int pivot_index = splitting(arr, low, high);
		quicksort(arr, low, pivot_index);
		quicksort(arr, pivot_index + 1, high);
	}
}

void merge(int arr[], int left, int mid, int right) {

	int i, j, k;
	
	int n1 = mid - left + 1;
	int n2 = right - mid;

	int* L = (int*)malloc(n1 * sizeof(int));
	int* R = (int*)malloc(n2 * sizeof(int));

	for (i = 0; i < n1; i++) {
		L[i] = arr[left + i];
	}
	for (j = 0; j < n2; j++) {
		R[j] = arr[mid + 1 + j];
	}

	i = 0;
	j = 0;
	k = left;

	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}

		k++;
	}

	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}

	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}
}

void mergesort(int arr[], int left, int right) {
	
	if (left < right) {
		int mid = left + (right - left) / 2;
		mergesort(arr, 1, mid);
		mergesort(arr, mid + 1, right);

		merge(arr, 1, mid, right);
	}
}