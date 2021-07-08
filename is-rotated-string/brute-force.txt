#include <bits/stdc++.h>

/* function prototype */
bool is_rotated_string(const std::string& first_string, const std::string& second_string);

/* brute-force approach */
int main(int argc, char* argv[]) {
    std::string first_string{"azonam"};
    std::string second_string{"amazon"};

    bool is_rotated = {is_rotated_string(first_string, second_string)};

    if (is_rotated) {
        /* if first_string and second_string are rotation of each other */
        std::cout << "\"" << first_string << "\" and \"" << second_string ;
        std::cout << "\" are rotation of each other!" << std::endl;
    } else {
        /* if first_string and second_string are not rotation of each other */
        std::cout << "\"" << first_string << "\" and \""<< second_string ;
        std::cout << "\" aren't rotation of each other!" << std::endl;
    }
    return 0;
}

/* a function to check whether or not first_string
 * and second_string are rotation of each other */
bool is_rotated_string(const std::string& first_string, const std::string& second_string) {

    /* compute the length of first_string and second_string */
    size_t first_length{first_string.length()};
    size_t second_length{second_string.length()};

    /* check whether or not size of first_string and second_string are same*/
    if (first_length != second_length) {
        return false;
    } else {
        /* if size of first_string and second string are same */
        for (size_t i{0};i < first_length;i++) {

            /* in trivial situation both string are rotation of each other.
             * hence, is_rotated is true in the beginning of each iteration */
            bool is_rotated{true};

            for (size_t j{0};j < second_length;j++) {
                if (first_string[(i + j)%first_length] != second_string[j]) {
                    /* if first_string and second_string don't have same
                     * character at a specific position then first_string
                     * and second_string can't be rotation of each other */
                    is_rotated = {false};
                    break;
                }
            }
            if (is_rotated) {
                /* if first_string and second_string
                 * are exact rotation of each other */
                return true;
            }
        }

        /* if first_string and second_string
         * aren't rotation of each other */
        return false;
    }
}