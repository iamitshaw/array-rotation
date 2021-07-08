
/* include guard */

#ifndef _ROTATE_INDIVIDUAL_H_
#define _ROTATE_INDIVIDUAL_H_

#include <bits/stdc++.h>

/* a function to right rotate an array by single element */
template<typename T>
void right_rotate(T* array, size_t array_size) {

    /* declare a variable for end_index */
    size_t end_index{array_size - 1};

    /* store the last element of the array */
    T key{array[end_index]};

    /* shift the remaining elements of the array to the left */
    for (size_t i{end_index};i > 0;i--) {
        array[i] = array[i - 1];
    }

    /* put the last element as the first element of the array */
    array[0] = key;
}

/* a function to right rotate an array by value
 * specified in variable number_of_rotation */
template <typename T>
void rotate_array(T* array, size_t number_of_rotation, size_t array_size) {

    /* remove redundant rotations */
    number_of_rotation %= array_size;

    for (size_t i{0};i < number_of_rotation;i++) {
        right_rotate(array, array_size);
    }
}

#endif
