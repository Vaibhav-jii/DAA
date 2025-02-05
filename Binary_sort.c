//Iterative
#include <stdio.h>

int main() {
    int n, key, left, right, mid, found = 0;
    
    printf("Enter number of elements: ");
    scanf("%d", &n);
    
    int arr[n];
    printf("Enter %d sorted elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("Enter element to search: ");
    scanf("%d", &key);

    left = 0;
    right = n - 1;
    
    while (left <= right) {
        mid = left + (right - left) / 2;
        if (arr[mid] == key) {
            found = 1;
            break;
        } else if (arr[mid] < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    if (found) {
        printf("Element found at index %d\n", mid);
    } else {
        printf("Element not found\n");
    }

    return 0;
}

//Recursive
#include <stdio.h>

int binarySearch(int arr[], int left, int right, int key) {
    if (left > right) {
        return -1;
    }

    int mid = left + (right - left) / 2;

    if (arr[mid] == key) {
        return mid;
    } else if (arr[mid] < key) {
        return binarySearch(arr, mid + 1, right, key);
    } else {
        return binarySearch(arr, left, mid - 1, key);
    }
}

int main() {
    int n, key, result;
    
    printf("Enter number of elements: ");
    scanf("%d", &n);
    
    int arr[n];
    printf("Enter %d sorted elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("Enter element to search: ");
    scanf("%d", &key);

    result = binarySearch(arr, 0, n - 1, key);

    if (result != -1) {
        printf("Element found at index %d\n", result);
    } else {
        printf("Element not found\n");
    }

    return 0;
}
