
/* include guard */

#ifndef _BLOCK_SWAP_ALGORITHM_H_
#define _BLOCK_SWAP_ALGORITHM_H_

#include <bits/stdc++.h>

/* a function to swap two blocks of the array having equal size */
template <typename T>
void block_swap(T* array,size_t left_block_index,size_t right_block_index,size_t size_of_block) {
    for (size_t i{0};i < size_of_block;i++) {
        std::swap(array[left_block_index + i],array[right_block_index + i]);
    }
}

/* block swap algorithm */
template <typename T>
void rotate_array(T* array, size_t number_of_rotation, size_t array_size) {

    /* remove redundant rotations */
    number_of_rotation %= array_size;

    if (number_of_rotation > 0) {
        const size_t division_index{array_size - number_of_rotation};

        /* compute the size of left and right side of
         * the array relative to point of division */
        size_t left_size{array_size - number_of_rotation};
        size_t right_size{number_of_rotation};

        while (left_size != right_size) {
            if (left_size < right_size) {
                /* if left side sub-array is shorter than right side sub-array */
                block_swap(array, division_index - left_size,
                           division_index + right_size - left_size, left_size);
                right_size -= left_size;
            } else {
                /* if right side subarray is shorter than left side sub-array */
                block_swap(array, division_index - left_size,
                           division_index, right_size);
                left_size -= right_size;
            }
        }
        /* left_size of subarray is equal to right_size of subarray */
        block_swap(array, division_index - left_size, division_index, left_size);
    }
}

#endif