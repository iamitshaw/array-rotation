#include "rotate_bits.h"

int main(int argc, char* argv[]) {
    /* declare two variable number and rotate_bits */
    size_t number{1024};
    size_t rotate_bits{5};

    /* print the appropriate message */
    std::cout << "Left rotation of " << number << " by " << rotate_bits ;
    std::cout << " is " << left_rotate(number, rotate_bits) << std::endl;

    std::cout << "Right rotation of " << number << " by " << rotate_bits ;
    std::cout << " is " << right_rotate(number, rotate_bits) << std::endl;

    return 0;
}
