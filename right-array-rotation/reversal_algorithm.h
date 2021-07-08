
/* include guard */

#ifndef _REVERSAL_ALGORITHM_H_
#define _REVERSAL_ALGORITHM_H_

#include <bits/stdc++.h>

template <typename T>
void reversal_algorithm(T* array, size_t start_index, size_t end_index) {
    /* reverse the array from start_index to end_index */
    for (size_t i{0};i < (end_index - start_index)/2;i++) {
        std::swap(array[start_index + i], array [end_index - i - 1]);
    }
}

/* reversal algorithm */
template <typename T>
void rotate_array(T* array, size_t number_of_rotation, size_t array_size) {

    /* remove redundant rotations */
    number_of_rotation %= array_size;

    /* if array has to be rotated at least once */
    if (number_of_rotation > 0) {
        reversal_algorithm(array, 0, array_size);
        reversal_algorithm(array, 0, number_of_rotation);
        reversal_algorithm(array, number_of_rotation, array_size);
    }
}

#endif