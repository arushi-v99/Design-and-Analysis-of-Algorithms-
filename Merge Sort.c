#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int left, int mid, int right) {
	int i = left, j = mid+1,k=0,temp[right-left+1];
	while (i<=mid && j<=right) {
		if (arr[i]<arr[j]) {
			temp[k]=arr[i];
			i++;
		}
		else {
			temp[k]=arr[j];
			j++;
		}
		k++;
	}
	while (i<=mid){
		temp[k]=arr[i];
		i++;
		k++;
	}
	while (j<=right) {
		temp[k]=arr[j];
		j++;
		k++;
	}
	k=0;
	for (i=left;i<=right;i++) {
		arr[i]=temp[k];
		k++;
	}
}

void mergeSort(int arr[], int left, int right ) {
	if (left<right) {
		int mid=(left+right)/2;
		mergeSort(arr,left,mid);
		mergeSort(arr,mid+1,right);
		merge(arr,left,mid,right);
	}
}

int main() {
    int n;
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    mergeSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    free(arr);
    return 0;
}