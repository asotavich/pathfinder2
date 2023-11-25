#include "libmx.h"

int mx_quicksort(char **arr, int left, int right) {
    if (!arr) return -1;

    int swaps = 0;

    while (left < right) {
        int pivot = mx_partition(arr, left, right);
        swaps += mx_quicksort(arr, left, pivot - 1);
        left = pivot;
    }

    return swaps;
}
