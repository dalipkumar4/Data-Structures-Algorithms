#include <stdio.h>

// Linear search function
int linearSearch(int arr[], int length, int key) {
    for (int i = 0; i < length; i++) {
        if (arr[i] == key)
            return i;  // return index where found
    }
    return -1; // return -1 if not found
}

int main() {
    int arr[] = {82, 35, 22, 57, 25};
    int length = sizeof(arr) / sizeof(arr[0]);
    int n;

    printf("Enter the search value: ");
    scanf("%d", &n);

    int result = linearSearch(arr, length, n);

    if (result != -1)
        printf("Value found at index %d", result);
    else
        printf("Not Found!");

    return 0;
}
