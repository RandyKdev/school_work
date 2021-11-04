#include<assert.h>

int indexOfFirstLargestElem(int arr[], int arrSize, int index, int indexOfLargest) {

    // Base case
    if(index == arrSize - 1) {
        return indexOfLargest;
    }

    // Recursive case
    if(arr[++index] > arr[indexOfLargest]) {
        indexOfLargest = index;
    }

    return indexOfFirstLargestElem(arr, arrSize, index, indexOfLargest);
}

void test() {
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

int main(void) {
    test();
    return 0;
}