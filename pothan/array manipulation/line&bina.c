#include <stdio.h>

// Linear Search
void linearSearch(int arr[], int n, int key) {
    int i, found = 0;
    for(i = 0; i < n; i++) {
        if(arr[i] == key) {
            printf("Linear Search: Element found at index %d\n", i);
            found = 1;
            break;
        }
    }
    if(!found)
        printf("Linear Search: Element not found\n");
}

// Binary Search (array must be sorted)
void binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1, mid, found = 0;
    
    while(low <= high) {
        mid = (low + high) / 2;
        if(arr[mid] == key) {
            printf("Binary Search: Element found at index %d\n", mid);
            found = 1;
            break;
        } else if(arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    if(!found)
        printf("Binary Search: Element not found\n");
}

int main() {
    int arr[100], n, i, key;

    // Input array size
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Input sorted array elements
    printf("Enter %d sorted elements:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Input key to search
    printf("Enter element to search: ");
    scanf("%d", &key);

    linearSearch(arr, n, key);
    binarySearch(arr, n, key);

    return 0;
}
