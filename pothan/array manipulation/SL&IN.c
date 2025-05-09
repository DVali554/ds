#include <stdio.h>

// Bubble Sort
void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for(i = 0; i < n - 1; i++) {
        for(j = 0; j < n - i - 1; j++) {
            if(arr[j] > arr[j+1]) {
                // Swap
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    printf("Bubble Sorted Array: ");
    for(i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
}

// Selection Sort
void selectionSort(int arr[], int n) {
    int i, j, min, temp;
    for(i = 0; i < n - 1; i++) {
        min = i;
        for(j = i + 1; j < n; j++) {
            if(arr[j] < arr[min]) min = j;
        }
        // Swap
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
    printf("Selection Sorted Array: ");
    for(i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
}

// Insertion Sort
void insertionSort(int arr[], int n) {
    int i, key, j;
    for(i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while(j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
    printf("Insertion Sorted Array: ");
    for(i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[100], n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    // Copy array for each sort
    int arr1[100], arr2[100], arr3[100];
    for(i = 0; i < n; i++) {
        arr1[i] = arr2[i] = arr3[i] = arr[i];
    }

    bubbleSort(arr1, n);
    selectionSort(arr2, n);
    insertionSort(arr3, n);

    return 0;
}
