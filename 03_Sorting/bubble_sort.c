#include <stdio.h>
#include <stdbool.h>

void bubble_sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

void print_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[100];
    int n;
    printf("Enter the dimension the array: ");
    scanf("%d",&n);
    printf("Enter the array: ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    printf("Original: ");
    print_array(arr, n);

    bubble_sort(arr, n);

    printf("Sorted:   ");
    print_array(arr, n);

    return 0;
}