#include <bits/stdc++.h>

/* function prototype */
bool is_rotated_string(const std::string& first_string, const std::string& second_string);
void rotate_string(std::string& string, int string_length);

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

    /* time-complexity --- O(n^2)
     * space-complexity --- O(n) */

    /* compute the length of first_string and second_string */
    size_t first_length{first_string.length()};
    size_t second_length{second_string.length()};

    /* check whether or not size of first_string and second_string are same*/
    if (first_length != second_length) {
        return false;
    } else {
        /* if size of first_string and second string are same */
        std::string temp_string{second_string};

        for (int i{0}; i < first_length; i++) {

            /* in trivial situation both string are rotation of each other.
             * hence, is_rotated is true in the beginning of each iteration */
            bool is_rotated{true};

            for (int j{0}; j < second_length; j++) {
                /* if first_string and second_string don't have same
                 * character at a corresponding position then first_string
                 * and second_string can't be rotation of each other */
                if (first_string.at(j) != temp_string.at(j)) {
                    is_rotated = false;
                    break;
                }
            }
            if (is_rotated) {
                /* if first_string and second_string
                 * are exact rotation of each other */
                return true;
            }

            /* if current version of second_string hasn't
             * exactly matched with the first_string */
            rotate_string(temp_string, first_length);
        }
        return false;
    }
}

/* rotate one character of the string towards left */
void rotate_string(std::string& string, int string_length) {
    char temp{string.at(0)};
    for (int i {1};i < string_length;i++) {
        string.at(i - 1) = string.at(i);
    }
    string.at(string_length - 1) = temp;
}