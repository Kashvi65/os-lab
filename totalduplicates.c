#include <stdio.h>

int countDuplicates(int arr[], int n) {
    int count = 0;
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] == -1) continue; // Skip already counted elements
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                count++;
                arr[j] = -1; // Mark the duplicate element
                break;
            }
        }
    }
    return count;
}

int main() {
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int duplicates = countDuplicates(arr, n);
    printf("Total number of duplicate elements: %d\n", duplicates);

    return 0;
}



