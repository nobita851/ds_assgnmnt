#include<stdio.h> 
void swap(int* a, int* b) 
{ 
	int t = *a; 
	*a = *b; 
	*b = t; 
} 
int partition (int arr[], int low, int high) 
{ 
	int pivot = arr[high],j; 
	int i = (low - 1); 

	for (j = low; j <= high- 1; j++) 
	{ 
		if (arr[j] < pivot) 
		{ 
			i++; 
			swap(&arr[i], &arr[j]); 
		} 
	} 
	swap(&arr[i + 1], &arr[high]); 
	return (i + 1); 
} 
void quickSort(int arr[], int low, int high) 
{ 
	if (low < high) 
	{ 
		int pi = partition(arr, low, high); 
		quickSort(arr, low, pi - 1); 
		quickSort(arr, pi + 1, high); 
	} 
} 
void selectionSort(int arr[], int n) 
{ 
    int i, j, min_idx; 
    for (i = 0; i < n-1; i++) 
    {  
        min_idx = i; 
        for (j = i+1; j < n; j++) 
          if (arr[j] < arr[min_idx]) 
            min_idx = j; 
        swap(&arr[min_idx], &arr[i]); 
    } 
} 
void printArray(int arr[], int size) 
{ 
	int i; 
	for (i=0; i < size; i++) 
		printf("%d ", arr[i]); 
	printf("\n"); 
} 
int main() 
{ 
	int arr[] = {10, 7, 8, 9, 1, 5}; 
	int n = sizeof(arr)/sizeof(arr[0]); 
	printf("Given Array : "); 
	printArray(arr, n);
	printf("\nSorted array by Quick sort : "); 
	quickSort(arr, 0, n-1); 
    printArray(arr, n); 
    printf("\nSorted array by Selection sort : "); 
    selectionSort(arr, n); 
    printArray(arr, n);
	return 0; 
} 

