/**
 * @file 
 * @brief A program to sort an array of elements using the quick sort algorithm
 */

#include <assert.h> // for assert function (for tests)

/**
 * @brief Rearranges the array such that all elements before pivot is less than pivot 
 * and all elements after pivot is greater that pivot
 * @param arr the pointer to the array of elements
 * @param start the start index [inclusive]
 * @param end the end index [exclusive]
 * @returns the index of the pivot
 */
int partition(int arr[], int start, int end) {
    int pivot = arr[start];
    int i = start;

    // rearranges the array
    for(int j = start + 1; j < end; j++) {
        if(arr[j] <= pivot) {
            int temp = arr[j];
            arr[j] = arr[++i];
            arr[i] = temp;
        }
    }

    // swap pivot and element at index i
    arr[start] = arr[i];
    arr[i] = pivot;
    
    return i;
}

/**
 * @brief Sorts an array of integers using the quick sort algo
 * @param arr the pointer to the array of elements
 * @param start the start index [inclusive]
 * @param end the end index [exclusive]
 * @returns void
 */
void quickSort(int arr[], int start, int end) {
    if(start >= end - 1) return;

    int pivot = partition(arr, start, end);

    quickSort(arr, start, pivot);
    quickSort(arr, pivot + 1, end);
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
    
    quickSort(test1, 0, 5); // sorts test array 1
    quickSort(test2, 0, 5); // sorts test array 2
    quickSort(test3, 0, 6); // sorts test array 3
    quickSort(test4, 0, 1); // sorts test array 4

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