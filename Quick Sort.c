#include <stdio.h>

int partition (int arr[], int lb, int ub) {
	int pivot, p=lb, q=ub, temp;
	pivot=arr[lb];
	while (p<q) {
		while (arr[p]<=pivot && p<q) {
			p++;
		}
		while (arr[q]>pivot) {
			q--;
		}
		if (p<q) {
			temp=arr[p];
			arr[p]=arr[q];
			arr[q]=temp;
		}
	}
	arr[lb]=arr[q];
	arr[q]=pivot;
	return q;
}
// Quick Sort function
void quickSort(int arr[], int low, int high) {
    // Complete the code...
    int p;
	if (low<high) {
		p=partition(arr,low,high);
		quickSort(arr,low,p-1);
		quickSort(arr,p+1,high);
	}
}

// Function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;
    // Input the size of the array
    scanf("%d", &n);
    int arr[n];
    
    // Input the elements of the array
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Print the original array
    printArray(arr, n);

    // Sort the array using quick sort
    quickSort(arr, 0, n - 1);
    
    // Print the sorted array
    printArray(arr, n);

    return 0;
}