/**
 * @file 
 * @brief A program to search for an element in an array using the linear search method
 */

#include <assert.h> // for assert function (for tests)

/**
 * @brief Searches for an element in an array of elements
 * @param arr the pointer to the array of elements
 * @param length the number of elements in the array
 * @param searchElem the element searched for
 * @returns the index of the search element if it is in the array
 * @returns -1 if the element is not found
 */
int linearSearch(int arr[], int length, int searchElem) {
    for(int i = 0; i < length; i++) {
        if(arr[i] == searchElem) return i;
    }

    return -1;
}

/**
 * @brief Self-test Implementations
 * @returns void
 */
void test(void) {
    // The following lines tests the program for correct behaviour
    int test1[] = {5, 4, 3, 2, 1, 400, 23, 42, 76, 11}; // test array

    // good cases
    assert(linearSearch(test1, 10, 2) == 3); // Checks if 2 is in array
    assert(linearSearch(test1, 10, 23) == 6); // Checks if 23 is in array
    assert(linearSearch(test1, 10, 5) == 0); // Checks if 5 is in array
    assert(linearSearch(test1, 10, 11) == 9); // Checks if 11 is in array
    assert(linearSearch(test1, 10, 42) == 7); // Checks if 42 is in array

    // bad cases
    assert(linearSearch(test1, 10, 0) == -1); // Checks if 0 is in array
    assert(linearSearch(test1, 10, 100) == -1); // Checks if 100 is in array
    assert(linearSearch(test1, 10, 34) == -1); // Checks if 34 is in array
}

/**
 * @brief Main function
 * @returns 0 on exit
 */
int main(void) {
    test(); // runs self-test implementation of the program
    return 0;
}