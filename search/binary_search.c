/**
 * @file 
 * @brief A program to search for an element in a sorted array using the binary search method
 */

#include <assert.h> // for assert function (for tests)

/**
 * @brief Searches for an element in an array of elements
 * @param arr the pointer to the array of elements
 * @param searchElem the element searched for
 * @param start the start index of the search [inclusive]
 * @param end the end index of the search [exclusive]
 * @returns the index of the search element if it is in the array
 * @returns -1 if the element is not found
 */
int binarySearch(int arr[], int searchElem, int start, int end) {
    // base case
    if(start >= end) return -1;

    int middle = (start + end) / 2;
    
    // element found
    if(arr[middle] == searchElem) return middle;

    // recursive case
    if(arr[middle] > searchElem) return binarySearch(arr, searchElem, start, middle);
    return binarySearch(arr, searchElem, middle + 1, end);
}

/**
 * @brief Self-test Implementations
 * @returns void
 */
void test(void) {
    // The following lines tests the program for correct behaviour
    int test[] = {1, 2, 3, 4, 5, 6, 7, 9, 34, 56, 79, 999}; // test array

    // good cases
    assert(binarySearch(test, 2, 0, 12) == 1); // Checks if 2 is in array
    assert(binarySearch(test, 7, 0, 12) == 6); // Checks if 7 is in array
    assert(binarySearch(test, 4, 0, 12) == 3); // Checks if 4 is in array
    assert(binarySearch(test, 999, 0, 12) == 11); // Checks if 999 is in array
    assert(binarySearch(test, 56, 0, 12) == 9); // Checks if 56 is in array

    // bad cases
    assert(binarySearch(test, 0, 0, 12) == -1); // Checks if 0 is in array
    assert(binarySearch(test, 100, 0, 12) == -1); // Checks if 100 is in array
    assert(binarySearch(test, 8, 0, 12) == -1); // Checks if 8 is in array
}

/**
 * @brief Main function
 * @returns 0 on exit
 */
int main(void) {
    test(); // runs self-test implementation of the program
    return 0;
}