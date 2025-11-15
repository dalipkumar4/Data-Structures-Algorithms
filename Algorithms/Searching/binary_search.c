#include <stdio.h>

int main()
{
    // Declare and initialize a sorted array
    int a[] = {0, 3, 4, 5, 9, 12};

    // Calculate the number of elements in the array
    int n = sizeof(a) / sizeof(a[0]);

    // Target value to search in the array
    int target = 3;

    // Define the start and end index for binary search
    int start = 0, end = n - 1;

    // Declare variables for middle index and flag to track if element is found
    int mid;
    int found = 0;

    // Binary Search Loop: runs as long as the search space is valid
    while (start <= end)
    {
        // Calculate the middle index
        mid = (start + end) / 2;

        // If target is greater than middle element, search in the right half
        if (target > a[mid])
            start = mid + 1;

        // If target is smaller than middle element, search in the left half
        else if (target < a[mid])
            end = mid - 1;

        // If target is equal to the middle element, element is found
        else {
            found = 1;  // Set found flag
            break;      // Exit the loop
        }
    }

    // Output the result
    if (found)
        printf("Element %d found at index %d\n", target, mid);
    else
        printf("Element %d not found\n", target);

    return 0;  // End of program
}
