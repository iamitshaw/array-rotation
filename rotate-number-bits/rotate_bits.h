
/* include guard */
#ifndef _ROTATE_BITS_H_
#define _ROTATE_BITS_H_

#include <bits/stdc++.h>

/* a function to left rotate bits of number by rotate_bits */
template <typename T>
T left_rotate(T number, size_t rotate_bits) {

    /* how many bits consist of the data_type T */
    const size_t bits_count{ sizeof(T)*8};

    /* perform the left circular shift */
    return (number << rotate_bits) | (number >> (bits_count - rotate_bits));
}

/* a function to right rotate bits of number by rotate_bits */
template <typename T>
T right_rotate(T number, size_t rotate_bits) {

    /* how many bits consist of the data_type T */
    const size_t bits_count{ sizeof(T)*8};

    /* perform the right circular shift */
    return (number >> rotate_bits) | (number << (bits_count - rotate_bits));
}

#endif
