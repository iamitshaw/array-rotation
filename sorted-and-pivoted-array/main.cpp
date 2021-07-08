#include "improved.h"

/* reversal algorithm */
template <typename T>
void reversal_algorithm(T* array, size_t start_index, size_t end_index) {
    /* reverse the array from start_index to end_index */
    for (size_t i{0};i < (end_index - start_index)/2;i++) {
        std::swap(array[start_index + i], array [end_index - i - 1]);
    }
}

template <typename T>
void rotate_array(T* array, size_t number_of_rotation, size_t array_size) {

    /* remove redundant rotations */
    number_of_rotation %= array_size;

    /* if array has been rotated at least once */
    if (number_of_rotation != 0) {
        reversal_algorithm(array, 0, number_of_rotation);
        reversal_algorithm(array, number_of_rotation, array_size);
        reversal_algorithm(array, 0, array_size);
    }
}

template <typename T>
ssize_t partition(T* array, ssize_t left, ssize_t right) {

    /* initialize the seed value for the random engine generator */
    auto seed{std::chrono::system_clock::now().time_since_epoch().count()};

    /* declare a random_number_generator with a seeded value */
    std::mt19937 random_engine_generator(seed);

    std::uniform_int_distribution<size_t> distinct_number(left, right);
    size_t index{distinct_number(random_engine_generator)};

    /* place the randomly selected element at end of the current list */
    std::swap(*(array + index), *(array + right));

    /* initialize i to store the count of elements less than
     * the element array[right] in the current list */
    ssize_t i = left - 1;
    for (auto j{left};j < right;j++) {
        if (*(array + j) < *(array + right)) {
            i += 1;
            std::swap(*(array + i), *(array + j));
        }
    }
    std::swap(*(array + i + 1), *(array + right));
    return (i + 1);
}

template <typename T>
void quick_sort(T* array, ssize_t left, ssize_t right) {
    if (left < right) {
        /* get a pivot value */
        ssize_t pivot = partition(array, left, right);

        /* decompose the array around pivot value */
        quick_sort(array, left, pivot - 1);
        quick_sort(array, pivot + 1, right);
    }
}

template <typename T>
void shuffle_array(T* array, size_t array_size) {
    /* define a seed value for random_number_generator */
    auto seed{std::chrono::system_clock::now().time_since_epoch().count()};

    /* declare a random_number_generator with a seeded value */
    std::mt19937 random_number_generator(seed);

    /* define an range for random numbers */
    size_t left_bound{0}, right_bound{array_size - 1};
    std::uniform_int_distribution<size_t> distinct_element(left_bound, right_bound);

    size_t random_index;
    for (int i = 0; i < array_size;i++) {
        random_index = distinct_element(random_number_generator) % (array_size - i) + i;
        std::swap(array[i], array[random_index]);
    }
}

/* driver program */
int main(int argc, char* argv[]) {
    /* define a seed value for random_number_generator */
    auto seed{std::chrono::system_clock::now().time_since_epoch().count()};

    /* declare a random_number_generator with a seeded value */
    std::mt19937 random_number_generator(seed);

    /* define an range for random numbers */
    size_t left_bound{1}, right_bound{17};
    std::uniform_int_distribution<size_t> distinct_element(left_bound, right_bound);


    /* define the  array_size */
    ssize_t array_size{13};

    /* allocate memory to store heap memory */
    auto* array = new size_t[array_size];

    /* read the array elements */
    for (size_t i{0};i < array_size;i+=1) {
        array[i] = (i + 1);
    }

    /* shuffle the array elements */
    shuffle_array(array, array_size);

    /* print the array elements */
    std::cout << "Array elements:" << std::endl;
    for (size_t i{0};i < array_size;i++) {
        std::cout << array[i] << " ";
    }

    size_t number_of_rotation{distinct_element(random_number_generator)};
    std::cout << "\nNumber of rotation: " << number_of_rotation << std::endl;

    double start{static_cast<double>(clock())};
    /* sort the array elements */
    quick_sort(array, 0, array_size - 1);
    double end{static_cast<double>(clock())};

    /* print the sorted array */
    std::cout << "\nSorted array:" << std::endl;
    for (size_t i{0};i < array_size;i++) {
        std::cout << array[i] << " ";
    }

    /* calculate the time required */
    double time_required{(end - start)/CLOCKS_PER_SEC};
    std::cout << "\nSorting time: " << time_required << "sec" << std::endl;

    start = static_cast<double>(clock());
    rotate_array(array, number_of_rotation, array_size);
    end = static_cast<double>(clock());

    /* time required for rotation */
    time_required = (end - start)/CLOCKS_PER_SEC;
    std::cout << "\nArray rotation time: " << time_required << "sec" << std::endl;

    /* print the sorted and rotated array */
    std::cout << "\nSorted and rotated array:" << std::endl;
    for (size_t i{0};i < array_size;i++) {
        std::cout << array[i] << " ";
    }

    /* get the key_value */
    size_t key_value{distinct_element(random_number_generator)};
    std::cout << "\nKey value: " << key_value << std::endl;

    start = {static_cast<double>(clock())};
    /* search the key_value */
    ssize_t index {pivoted_search(array, 0, array_size - 1, key_value)};
    end = {static_cast<double>(clock())};

    /* calculate the time required */
    time_required = {(end - start)/CLOCKS_PER_SEC};
    std::cout << "\nSearching time: " << time_required << "sec";

    if (index != -1) {
        printf("\n%d has been found at position %d.\n", key_value, (index + 1));
    } else {
        printf("\nkey value %d has not been found!\n", key_value);
    }

    /* de-allocate the heap memory */
    delete [] array;

    return 0;
}