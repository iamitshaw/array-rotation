
/* Include Guard */
#ifndef _BASIC_APPROACH_H_
#define _BASIC_APPROACH_H_

#include <bits/stdc++.h>

/* binary search algorithm */
template <typename T>
ssize_t binary_search(const T* array, ssize_t left, ssize_t right, T key_value) {
    while (left <= right) {
        ssize_t mid{left + (right - left)/2};
        if (*(array + mid) == key_value) {
            /* evaluate whether or not the key_value to be searched
             * is present at the middle of the current sub-array */
            return mid;
        } else if (*(array + mid) > key_value) {
            /* if key_value is less than array[mid] then key_value can be present
             * only in the left of the current sub-array before the middle element */
            right = mid - 1;
        } else {
            /* if key_value is greater than array[mid] then key_value can be present
             * only in the right of the current sub-array after the middle element */
            left = mid + 1;
        }
    }
    /* -1 sentinel is used to indicate that key_value is not found */
    return -1;
}

ssize_t find_pivot(const size_t* array, ssize_t left, ssize_t right) {

    while (left <= right) {
        ssize_t mid{left + (right - left)/2};
        if (mid < right && array[mid] > array[mid + 1]) {
            /* if abrupt decrease in value has been
             * observed at the index position mid */
            return mid;
        } else if (left < mid && array[mid - 1] > array[mid]) {
            /* if abrupt decrease in value has been
             * observed at index position (mid - 1) */
            return mid - 1;
        } else if (array[left] <= array[mid]) {
            /* if array[left] is less than array[mid] then required
             * index position can be present only in the right of
             * the current sub-array after the middle element */
            left = mid + 1;
        } else if (array[left] > array[mid]) {
            /* if array[left] is greater than array[mid] then required
             * index position can be present only in the left of
             * the current sub-array before the middle element */
            right = mid - 1;
        }
    }

    /* -1 sentinel is used to indicate
     * that array hasn't been rotated */
    return -1;

}

/* a function to search an element in an ascending-order sorted and rotated array */
ssize_t pivoted_search(const size_t* array, ssize_t left, ssize_t array_size, size_t key_value) {
    ssize_t pivot{find_pivot(array, left, array_size - 1)};
    std::cout << "Pivot position: " << (pivot + 1) << std::endl;

    if (pivot == -1) {
        /* if array hasn't been rotated */
        return binary_search(array, left, array_size - 1, key_value);
    } else {
        if (array[0] <= key_value) {
            return binary_search(array, left, pivot, key_value);
        } else {
            return binary_search(array, pivot + 1, array_size - 1, key_value);
        }
    }
}

#endif