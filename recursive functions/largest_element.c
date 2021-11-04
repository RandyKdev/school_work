/**
 * @file
 * @brief A recursive function to find the position of the largest element in an array of integers
 */

#include <assert.h> // for assert function (for tests)

/**
 * @brief Finds the index of the first largest element in an array
 * @param array The list of elements 
 * @param arrSize The length of the `array`
 * @param index the current index of the `array`
 * @param indexOfFirstLargest the index of the current first largest element found
 * @returns The index of the first largest element in `array`
 */
int indexOfFirstLargestElem(int array[], int arraySize, int index, int indexOfFirstLargest) {
    // Base case
    if(index == arraySize - 1) {
        return indexOfFirstLargest;
    }

    // Recursive case
    if(array[++index] > array[indexOfFirstLargest]) {
        indexOfFirstLargest = index;
    }

    return indexOfFirstLargestElem(array, arraySize, index, indexOfFirstLargest);
}

/**
 * @brief Self-test Implementations
 * @returns void
 */
void test(void) {
    int arrSize = 5;

    int arr[] = {0, 9, 8, 4, 3};
    int indexLargest = indexOfFirstLargestElem(arr, arrSize, 0, 0);
    assert(indexLargest == 1);

    arrSize = 5;
    int arr1[] = {0, 9, 10, 10, 3};
    indexLargest = indexOfFirstLargestElem(arr1, arrSize, 0, 0);
    assert(indexLargest == 2);

    arrSize = 1;
    int arr2[] = {0};
    indexLargest = indexOfFirstLargestElem(arr2, arrSize, 0, 0);
    assert(indexLargest == 0);
}

/**
 * @brief Main function
 * @returns 0 on exit
 */
int main(void) {
    test(); // runs self-test implementation of the program
    return 0;
}
