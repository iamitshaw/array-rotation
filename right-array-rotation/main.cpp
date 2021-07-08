#include "block_swap_algorithm.h"

int main(int argc, char* argv[]) {
    /* define a seed value for random_number_generator */
    auto seed{std::chrono::system_clock::now().time_since_epoch().count()};

    /* declare a random_number_generator with a seeded value */
    std::mt19937 random_number_generator(seed);

    /* define an range for random numbers */
    size_t left_bound{17}, right_bound{37};
    std::uniform_int_distribution<size_t> distinct_element(left_bound, right_bound);


    /* define the  array_size */
    size_t array_size{13};

    /* allocate memory to store heap memory */
    auto* array = new size_t[array_size];

    /* read the array elements */
    for (size_t i{0};i < array_size;i+=1) {
        array[i] = distinct_element(random_number_generator);
    }

    /* print the array elements */
    std::cout << "Array elements:" << std::endl;
    for (size_t i{0};i < array_size;i++) {
        std::cout << array[i] << " ";
    }

    size_t number_of_rotation{distinct_element(random_number_generator)};
    std::cout << "\nNumber of rotation: " << number_of_rotation << std::endl;

    double start{static_cast<double>(clock())};
    rotate_array(array, number_of_rotation, array_size);
    double end{static_cast<double>(clock())};

    /* print the array elements */
    std::cout << "\nRotated elements:" << std::endl;
    for (size_t i{0};i < array_size;i++) {
        std::cout << array[i] << " ";
    }

    /* print the required time for array rotation */
    auto time_required{(end - start)/CLOCKS_PER_SEC};
    std::cout << "\nTime required: " << time_required << "sec" << std::endl;

    /* de-allocate the heap memory */
    delete [] array;

    return 0;
}