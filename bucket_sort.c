#include <stdio.h>
#define BUCKET_SIZE 10
int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int buckets[BUCKET_SIZE][n];  // Each bucket can hold up to n elements
    int count[BUCKET_SIZE] = {0};  // Array to track number of elements in each bucket
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    for (int i = 0; i < n; i++) {
        int index = (arr[i] * BUCKET_SIZE) / (max + 1); // Normalize bucket index
        buckets[index][count[index]++] = arr[i];  // Place element in the correct bucket
    }
    for (int i = 0; i < BUCKET_SIZE; i++) {
        for (int j = 0; j < count[i] - 1; j++) {
            for (int k = j + 1; k < count[i]; k++) {
                if (buckets[i][j] > buckets[i][k]) {
                    int temp = buckets[i][j];
                    buckets[i][j] = buckets[i][k];
                    buckets[i][k] = temp;
                }
            }
        }
    }
    int index = 0;
    for (int i = 0; i < BUCKET_SIZE; i++) {
        for (int j = 0; j < count[i]; j++) {
            arr[index++] = buckets[i][j];
        }
    }
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
