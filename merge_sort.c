#include <stdio.h>

int main() {
    int arr[100], arrSize;
    printf("Enter the number of elements: ");
    scanf("%d", &arrSize);
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < arrSize; i++) {
        scanf("%d", &arr[i]);
    }
    for (int curr_size = 1; curr_size < arrSize; curr_size *= 2) {
        for (int left_start = 0; left_start < arrSize - 1; left_start += 2 * curr_size) {
            // Find the middle and the right end of the subarray
            int mid = left_start + curr_size - 1;
            int right_end = left_start + 2 * curr_size - 1 < arrSize - 1 ? left_start + 2 * curr_size - 1 : arrSize - 1;
            int n1 = mid - left_start + 1; // Size of left subarray
            int n2 = right_end - mid;      // Size of right subarray
            int leftArr[n1], rightArr[n2];
            for (int i = 0; i < n1; i++)
                leftArr[i] = arr[left_start + i];
            for (int j = 0; j < n2; j++)
                rightArr[j] = arr[mid + 1 + j];
            int i = 0, j = 0, k = left_start;
            while (i < n1 && j < n2) {
                if (leftArr[i] <= rightArr[j]) {
                    arr[k] = leftArr[i];
                    i++;
                } else {
                    arr[k] = rightArr[j];
                    j++;
                }
                k++;
            }
            while (i < n1) {
                arr[k] = leftArr[i];
                i++;
                k++;
            }
            while (j < n2) {
                arr[k] = rightArr[j];
                j++;
                k++;
            }
        }
    }
    printf("Sorted array: \n");
    for (int i = 0; i < arrSize; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}    


//Recursive
#include <stdio.h>

// Function to merge two subarrays
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary arrays
    int leftArr[n1], rightArr[n2];

    // Copy data to temp arrays
    for (int i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        rightArr[j] = arr[mid + 1 + j];

    // Merge the temp arrays back into arr[left...right]
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements of leftArr[]
    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    // Copy remaining elements of rightArr[]
    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

// Function to implement Merge Sort recursively
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2; // Find the middle point

        // Recursively sort the first and second halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}

// Main function
int main() {
    int arr[100], n;

    // Taking input for array size
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Taking input for array elements
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Calling mergeSort function
    mergeSort(arr, 0, n - 1);

    // Printing the sorted array
    printf("Sorted array: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
