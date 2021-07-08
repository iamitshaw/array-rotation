#include "singly_linked_list.h"

int main(int argc, char* argv[]) {
    /* define a seed value for random_number_generator */
    auto seed{std::chrono::system_clock::now().time_since_epoch().count()};

    /* declare a random_number_generator with a seeded value */
    std::mt19937 random_generator(seed);

    /* define an range for random numbers */
    size_t left_bound{11}, right_bound{37};
    std::uniform_int_distribution<size_t> distinct(left_bound, right_bound);

    /* define the list size */
    size_t list_size{13};

    SinglyLinkedList<size_t> singly_list;

    /* create a linked list */
    for (size_t i{0};i < list_size;i++) {
        singly_list.addElementAtHead(distinct(random_generator));
    }

    /* display the list */
    std::cout << "\nOriginal Linked List: " << std::endl;
    singly_list.printList();

    /* get the value of number_of_rotation */
    size_t number_of_rotation{distinct(random_generator)};
    std::cout << "\nNumber of rotation: " << number_of_rotation << std::endl;

    /* left rotate the list */
    singly_list.leftRotateList(number_of_rotation);

    /* display the list */
    std::cout << "\nRotated Linked List: " << std::endl;
    singly_list.printList();

    return 0;
}
