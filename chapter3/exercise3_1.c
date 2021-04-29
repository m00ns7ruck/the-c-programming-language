#include <stdio.h>

/*
  Using Linux's time utility:
    Sorted array of 10 elements.
    Searching for non existent item, larger than the largest item:

      real 0m0.003s
      user 0m0.001s
      sys  0m0.002s

    Searching for existent item, smaller than the middle of the array
      real 0m0.003s
      user 0m0.003s
      sys  0m0.000s

    Searching for existent item, larger than the middle of the array
      real	0m0.002s
      user	0m0.001s
      sys	0m0.001s
 */
int BinarySearch(int x, int arr[], int n) {
    int low = 0;
    int hight = n - 1;
    int mid;

    while(low <= hight) {
        mid = (low + hight) / 2;
        if(x < arr[mid]) {
            hight = mid - 1;
        }
        else if( x > arr[mid]) {
            low = mid + 1;
        }
        else {
            return mid;
        }
    }

    return -1;
}

/*
  Using Linux's time utility:
    Sorted array of 10 elements.
    Searching for non existent item, larger than the largest item:

      real 0m0.002s
      user 0m0.002s
      sys  0m0.000s

    Searching for existent item, smaller than the middle of the array

      real	0m0.003s
      user	0m0.001s
      sys	0m0.002s

    Searching for existent item, larger than the middle of the array

      real 0m0.002s
      user 0m0.002s
      sys  0m0.000s
 */
int BinarySearchFewerConditions(int x, int arr[], int n) {
    int low = 0;
    int hight = n - 1;
    int mid;

    while((low <= hight) && (x != arr[mid])) {
        mid = (low + hight) / 2;
        if(x < arr[mid]) {
            hight = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    return (arr[mid] == x) ? mid : -1;
}

int main() {
    int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int indx = BinarySearchFewerConditions(7, arr, 10);
    printf("Index: %d, Number: %d\n", indx, arr[indx]);

    return 0;
}
