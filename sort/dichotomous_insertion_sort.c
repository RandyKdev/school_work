/**
 * @file 
 * @brief A program to sort an array of elements using the dichotomous insertion sort algorithm
 */

#include <assert.h> // for assert function (for tests)

/**
 * @brief Dichotomously finds the index at which the element should be inserted
 * @param arr the pointer to the array of elements
 * @param element the value of the element to be inserted
 * @param start the start index of the array [inclusive]
 * @param end the end index of the array [exclusive]
 * @returns the index at which to insert the element
 */
int findInsertionIndex(int arr[], int element, int start, int end) {
   int middle = (start + end) / 2;
   if(middle == start) return arr[middle] >= element ? middle : middle + 1;
   if(arr[middle] >= element && arr[middle - 1] <= element) return middle;
   if(arr[middle] < element) return findInsertionIndex(arr, element, middle + 1, end);
   return findInsertionIndex(arr, element, start, middle); 
}

/**
 * @brief Sorts an array of integers using the dichotomous insertion sort algo
 * @param arr the pointer to the array of elements
 * @param length the number of elements in the array
 * @returns void
 */
void dichotomousInsertionSort(int arr[], int length) {
    int element;
    for(int i = 1; i < length; i++) {
        element = arr[i];
        
        // find the index at which to insert `element`
        int pos = findInsertionIndex(arr, element, 0, i);

        // shifts the elements at the right of the index one step to the right
        for(int j = i - 1; j >= pos; j--) {
            arr[j + 1] = arr[j];
        }

        // inserts `element` at the index `pos`
        arr[pos] = element;
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
    
    dichotomousInsertionSort(test1, 5); // sorts test array 1
    dichotomousInsertionSort(test2, 5); // sorts test array 2
    dichotomousInsertionSort(test3, 6); // sorts test array 3
    dichotomousInsertionSort(test4, 1); // sorts test array 4

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