/**
 * @file 
 * @brief A program to sort an array of elements using the selection sort algorithm
 */

#include <assert.h> // for assert function (for tests)

/**
 * @brief Sorts an array of integers using the selection algo
 * @param arr the pointer to the array of elements
 * @param length the number of elements in the array
 * @returns void
 */
void selectionSort(int arr[], int length) {
    int posOfLargest, temp;
    for(int i = 0; i < length; i++) {
        posOfLargest = 0;
        
        for(int j = 0; j < length - i; j++) {
            if(arr[j] > arr[posOfLargest]) posOfLargest = j;
        }
        
        temp = arr[length - i - 1];
        arr[length - i - 1] = arr[posOfLargest];
        arr[posOfLargest] = temp;
    }
}

/**
 * @brief Self-test Implementations
 * @returns void
 */
void test(void) {
    // The following lines tests the program for correct behaviour
    int test1[] = {5,4,3,2,1}; // first test array
    int test2[] = {1,3,2,4,5}; // second test array
    int test3[] = {-3,-5,0,2,1,-4}; // third test array
    int test4[] = {2}; // fourth test array

    int solution1_2[] = {1,2,3,4,5}; // solution for test array 1 and 2
    int solution3[] = {-5,-4,-3,0,1,2}; // solution for test array 3
    
    selectionSort(test1, 5); // sorts test array 1
    selectionSort(test2, 5); // sorts test array 2
    selectionSort(test3, 6); // sorts test array 3
    selectionSort(test4, 1); // sorts test array 4

    // Checks if test array 1 and 2 has been correctly sorted
    for(int i = 0; i < 5; i++) {
        assert(test1[i] == solution1_2[i]);
        assert(test2[i] == solution1_2[i]);
    }

    // Checks if test array 3 has been correctly sorted
    for(int i = 0; i < 6; i++) {
        assert(test3[i] == solution3[i]);
    }

    // Checks if test array 4 has been correctly sorted
    assert(test4[0] == 2);
}

/**
 * @brief Main function
 * @returns 0 on exit
 */
int main(void) {
    test(); // runs self-test implementation of the program
    return 0;
}