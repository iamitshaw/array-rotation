
/* include guard */

#ifndef _ROTATE_INDIVIDUAL_H_
#define _ROTATE_INDIVIDUAL_H_

#include <bits/stdc++.h>

/* a function to left rotate an array by single element */
template<typename T>
void left_rotate(T* array, size_t array_size) {
    /* store the first element of the array */
    T key{array[0]};

    /* shift the remaining elements of the array to the left */
    for (size_t i{1};i < array_size;i++) {
        array[i - 1] = array[i];
    }

    /* put the first element as the last element of the array */
    array[array_size - 1] = key;
}

/* a function to rotate an array by value
 * specified in variable number_of_rotation */
template <typename T>
void rotate_array(T* array, size_t number_of_rotation, size_t array_size) {

    /* remove redundant rotations */
    number_of_rotation %= array_size;

    for (size_t i{0};i < number_of_rotation;i++) {
        left_rotate(array, array_size);
    }
}

#endif
