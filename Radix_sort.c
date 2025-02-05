#include <stdio.h>

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
    }
    int output[n];
    for (int i = 1; max / i > 0; i *= 10) { // Using i instead of exp
        int count[10] = {0}; // Count array for digits 0-9
        for (int j = 0; j < n; j++)
            count[(arr[j] / i) % 10]++;
        for (int j = 1; j < 10; j++)
            count[j] += count[j - 1];
        for (int j = n - 1; j >= 0; j--) {
            output[count[(arr[j] / i) % 10] - 1] = arr[j];
            count[(arr[j] / i) % 10]--;
        }
        for (int j = 0; j < n; j++)
            arr[j] = output[j];
    }
    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}
