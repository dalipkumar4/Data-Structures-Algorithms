#include <stdio.h>

int binarySearch(int a[], int n, int target) {
    int start = 0, end = n - 1, mid;

    while (start <= end) {
        mid = (start + end) / 2;

        if (target > a[mid])
            start = mid + 1;
        else if (target < a[mid])
            end = mid - 1;
        else
            return mid;  // return index if found
    }

    return -1; // return -1 if not found
}

int main() {
    int a[] = {0, 3, 4, 5, 9, 12};
    int n = sizeof(a) / sizeof(a[0]);
    int target;

    printf("Enter the value to search: ");
    scanf("%d", &target);

    int index = binarySearch(a, n, target);

    if (index != -1)
        printf("Element %d found at index %d\n", target, index);
    else
        printf("Element %d not found\n", target);

    return 0;
}
