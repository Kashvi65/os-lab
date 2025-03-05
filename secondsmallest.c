#include <stdio.h>

void findSecondSmallest(int arr[], int n) {
    if (n < 2) {
        printf("Array must contain at least two elements.\n");
        return;
    }

    int first = arr[0], second = arr[1];

    if (first > second) {
        int temp = first;
        first = second;
        second = temp;
    }

    for (int i = 2; i < n; i++) {
        if (arr[i] < first) {
            second = first;
            first = arr[i];
        } else if (arr[i] < second && arr[i] != first) {
            second = arr[i];
        }
    }

    if (second == first) {
        printf("No second smallest element found.\n");
    } else {
        printf("Second smallest element: %d\n", second);
    }
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    findSecondSmallest(arr, n);
    return 0;
}
