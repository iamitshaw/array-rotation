
/* Include Guard */

#ifndef _IMPROVED_SOLUTION_H_
#define _IMPROVED_SOLUTION_H_

#include <bits/stdc++.h>

/* a function to search an element in an ascending-order sorted and rotated array */
ssize_t pivoted_search(const size_t* array, ssize_t left, ssize_t right, size_t key_value) {

    while (left <= right) {
        ssize_t mid{left + (right - left)/2};
        if (array[mid] == key_value) {
            /* evaluate whether or not the key_value to be searched
             * is present at the middle of the current sub-array */
            return mid;
        } else if (array[left] <= array[mid]) {
            /* if pivot isn't available in array[left...mid] i.e.
             * the part of array under consideration is sorted */

            if (key_value >= array[left] && key_value <= array[mid]) {
                /* since, sub-array array[left...mid] is sorted so
                 * that check whether or not key_value is situated
                 * inside the part of array under consideration */
                right = mid - 1;
            } else {
                /* since, key doesn't lie in sub-array array[left...mid-1], so
                 * that divide sub-array array[mid+1...right] into two parts such
                 * that it can be checked quickly that in which part key lies */
                left = mid + 1;
            }
        } else {
            /* if pivot isn't available in array[mid+1...right] i.e.
             * the part of the array under consideration is sorted */

            if (key_value >= array[mid + 1] && key_value <= array[right]) {
                /* since, sub-array array[mid+1...right] is sorted so
                 * that check whether or not key_value is situated
                 * inside the part of array under consideration */
                left = mid + 1;
            } else {
                /* since, key doesn't lie in sub-array array[mid+1...right], so
                 * that divide sub-array array[left...mid-1] into two parts such
                 * that it can be checked quickly that in which part key lies */
                right = mid - 1;
            }
        }
    }

    /* -1 sentinel is used to indicate that
     * key_value is not present in the array */
    return -1;
}

#endif