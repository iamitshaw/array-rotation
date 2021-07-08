
/* include guard */

#ifndef _TEMP_ARRAY_USAGE_H_
#define _TEMP_ARRAY_USAGE_H_

#include <bits/stdc++.h>

/* a function to left rotate an array by value
 * specified in variable number_of_rotation */
template <typename T>
void rotate_array(T* array, size_t number_of_rotation, size_t array_size) {

    /* remove redundant rotations */
    number_of_rotation %= array_size;

    if (number_of_rotation > 0) {
        /* allocate memory to store elements which
     * are present at the beginning of the array */
        auto* rotated_array = new T[number_of_rotation];

        /* store the first number_of_rotation elements in rotated array */
        for (size_t i{0};i < number_of_rotation;i++) {
            rotated_array[i] = array[i];
        }

        /* shift rest of the array elements which has not been
         * stored in rotated array to left by number_of_rotation */
        for (size_t i{number_of_rotation};i < array_size;i++) {
            array[i - number_of_rotation] = array[i];
        }

        /* store back the elements from rotated array */
        for (size_t i{0};i < number_of_rotation;i++) {
            array[array_size - number_of_rotation + i] = rotated_array[i];
        }

        /* de-allocate the heap memory */
        delete [] rotated_array;
    }
}

#endif