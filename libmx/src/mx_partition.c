#include "libmx.h"

int mx_partition(char **arr, int left, int right) {
    int midl = mx_strlen(arr[(left + right) >> 1]);
    while (left <= right) {
        while (mx_strlen(arr[left]) < midl)
            left++;
        while (mx_strlen(arr[right]) > midl)
            right--;
        if (left <= right) {
            if (mx_strlen(arr[left]) != mx_strlen(arr[right])) {
                mx_swap_strings(arr, left, right);
            }
            left++;
            right--;
        }
    }
    return left;
}
