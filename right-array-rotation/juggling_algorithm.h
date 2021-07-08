
/* include guard */

#ifndef _JUGGLING_ALGORITHM_H_
#define _JUGGLING_ALGORITHM_H_

#include <bits/stdc++.h>

/* juggling algorithm */
template <typename T>
void rotate_array(T* array, size_t number_of_rotation, size_t array_size) {

    /* remove redundant rotations */
    number_of_rotation %= array_size;

    if (number_of_rotation > 0) {
        /* compute set_size to divide array into different sets */
        size_t set_size{std::__gcd(array_size,number_of_rotation)};

        /* position i-th element of each set at its right place */
        for (size_t i{0};i < set_size;i++) {

            /* store initial_value in a temporary variable */
            T initial_value{array[i]};
            size_t j{i}, k;

            while(true) {

                /* get the next position to process */
                if (static_cast<ssize_t>(j - number_of_rotation) < 0) {
                    k = (array_size + j - number_of_rotation);
                } else {
                    k = (j - number_of_rotation);
                }

                if (k == i) {
                    /* if starting position has been reached */
                    break;
                }

                /* position subsequent set's corresponding element
                 * to the preceding set's corresponding element */
                array[j] = array[k];
                j = k;
            }

            /* finally store initial_value at right position */
            array[j] = initial_value;
        }
    }
}

#endif
