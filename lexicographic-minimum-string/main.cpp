#include <bits/stdc++.h>

/* function prototype */
void string_generator(char* input_string, size_t size_of_string);
size_t lexicographic_minimum_string(const char* input_string, size_t size_of_string);
bool is_minimum_string(const char* input_string, size_t X, size_t Y, size_t size_of_string);

int main(int argc, char* argv[]) {

    /* get the size of random string */
    size_t size_of_string{7};

    /* declare character array to store random_string */
    char* input_string = new char[size_of_string + 1];

    /* generate a random character array */
    string_generator(input_string, size_of_string);
    std::cout << "input string: " << input_string << std::endl;

    size_t min_index{lexicographic_minimum_string(input_string, size_of_string)};

    /* print the lexicographic minimum string */
    std::cout << "lexicographic minimum string: ";
    for (size_t i{0};i < size_of_string;i++) {
        std::cout << input_string[(i+min_index)%size_of_string];
    }
    /* traverse the cursor to the next line */
    std::cout << std::endl;

    /* de-allocate the heap memory */
    delete [] input_string;

    return 0;
}

bool is_minimum_string(const char* input_string, size_t X, size_t Y, size_t size_of_string) {
    for (size_t i{0}; i < size_of_string; i++) {
        if (input_string[X] < input_string[Y]) {
            /* if the current string that being
             * considered isn't minimum string */
            return false;
        } else if (input_string[X] > input_string[Y]) {
            /* if the current string that being
             * considered is minimum string */
            return true;
        } else {
            X = (X + 1)%size_of_string;
            Y = (Y + 1)%size_of_string;
        }
    }
    /* if minimum string is exactly identical
     * to the current string being considered */
    return true;
}

/* a function to compute the index of lexicographic minimum string */
size_t lexicographic_minimum_string(const char* input_string, size_t size_of_string) {
    size_t min_index{0};
    for (size_t current_index{1}; current_index < size_of_string; current_index++) {
        if (is_minimum_string(input_string, min_index, current_index, size_of_string)) {
            /* update the lexicographic minimum string */
            min_index = current_index;
        }
    }
    return min_index;
}

/* generate a random character array consist of
 * only uppercase letters and lowercase letters */
void string_generator(char* input_string, size_t size_of_string) {

    /* define a seed value for random_number_generator */
    auto seed{std::chrono::system_clock::now().time_since_epoch().count()};

    /* declare a random_generator with a seeded value */
    std::mt19937 random_generator(seed);

    std::uniform_int_distribution<size_t> distinct_upper_case('A', 'Z');
    std::uniform_int_distribution<size_t> distinct_lower_case('a', 'z');

    /* define an range for random numbers */
    std::uniform_int_distribution<size_t> distinct_type(1, 2);

    size_t current_character_type; char character;

    for (size_t i{0};i < size_of_string;i++) {

        /* generate a random character type */
        current_character_type = {distinct_type(random_generator)};

        switch(current_character_type){
            /* upper-case letters */
            case 1: {
                character = distinct_upper_case(random_generator);break;
            }
            /* lower-case letters */
            case 2: {
                character = distinct_lower_case(random_generator);break;
            }
            default: {
                std::cout << "Invalid CAPTCHA!\n" << std::endl;break;
            }
        }

        /* assign the current generated character */
        input_string[i] = character;
    }

    /* null terminated array of characters */
    input_string[size_of_string] = '\0';
}