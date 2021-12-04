/**
 * @file 
 * @brief A program to sort an array of elements using the merge sort algorithm
 */

#include <assert.h> // for assert function (for tests)

/**
 * @brief Merges sub sorted arrays in to main array
 * @param arr the pointer to the array of elements
 * @param start the start index of the left sub array [inclusive]
 * @param end the end index of the right sub array [exclusive]
 * @param middle the mid index between start and end
 */
void merge(int arr[], int start, int end, int middle) {
    int tempLeft[middle - start]; // creates temp array to hold left sub array
    int tempRight[end - middle]; // creates temp array to hold right sub array

    // copies elements from left sub array to temp array
    for(int i = start, j = 0; i < middle; i++, j++) {
        tempLeft[j] = arr[i];
    }

    // copies elements from right sub array to temp array
    for(int i = middle, j = 0; i < end; i++, j++) {
        tempRight[j] = arr[i];
    }

    // merges elements in to main array
    for(int i = start, j = 0, k = 0; i < end; i++) {
        if(j == middle - start) arr[i] = tempRight[k++];
        else if(k == end - middle) arr[i] = tempLeft[j++];
        else if(tempLeft[j] <= tempRight[k]) arr[i] = tempLeft[j++];
        else arr[i] = tempRight[k++];
    }
}

/**
 * @brief Sorts an array of integers using the merge sort algo
 * @param arr the pointer to the array of elements
 * @param start the start index of the sort [inclusive]
 * @param end the end index of the sort [exclusive]
 * @returns void
 */
void mergeSort(int arr[], int start, int end) {
    if(start == end - 1) return;

    int middle = (start + end) /2;

    // divides main array in to sub arrays
    mergeSort(arr, start, middle);
    mergeSort(arr, middle, end);

    // merges sub sorted arrays in to main array
    merge(arr, start, end, middle);
}

/**
 * @brief Self-test Implementations
 * @returns void
 */
void test(void) {
    // The following lines tests the program for correct behaviour
    int test1[] = {1,2,3, 5,4}; // first test array
    int test2[] = {1,3,2,4,5}; // second test array
    int test3[] = {-3,-5,0,2,1,-4}; // third test array
    int test4[] = {2}; // fourth test array

    int solution1_2[] = {1,2,3,4,5}; // solution for test array 1 and 2
    int solution3[] = {-5,-4,-3,0,1,2}; // solution for test array 3
    
    mergeSort(test1, 0, 5); // sorts test array 1
    mergeSort(test2, 0, 5); // sorts test array 2
    mergeSort(test3, 0, 6); // sorts test array 3
    mergeSort(test4, 0, 1); // sorts test array 4

    // Checks if test array 1 and 2 has been correctly sorted
    for(int i = 0; i < 5; i++) {
        assert(test1[i] == solution1_2[i]);
        assert(test2[i] == solution1_2[i]);
    }

    // Checks if test array 3 has been correctly sorted
    for(int i = 0; i < 6; i++) {
        assert(test3[i] == solution3[i]);
    }

    // // Checks if test array 4 has been correctly sorted
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