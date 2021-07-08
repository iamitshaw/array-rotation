
/* Include Guard */

#ifndef _SINGLY_LINKED_LIST_H_
#define _SINGLY_LINKED_LIST_H_

#include "node.h"

template <typename T>
class SinglyLinkedList {
private:
    Node<T>* head;
    size_t size_of_list;
public:
    SinglyLinkedList();
    Node<T>* getHead();
    size_t getListSize();
    void addElementAtHead(Node<T>* nodePointer);
    void addElementAtHead(T data);
    void addElementAtTail(Node<T>* nodePointer);
    void addElementAtTail(T data);
    void insertElementAt(Node<T>* nodePointer, size_t position);
    void printList();
    void deleteNodeFromHead();
    void deleteNodeFromTail();
    void deleteNodeAt(size_t position);
    void deleteList();
    void reverseListDisplay();
    void deleteElement(T keyValue);
    Node<T>* searchList(T keyValue);
    void leftRotateList(size_t number_of_rotation);
    ~SinglyLinkedList();
private:
    void displayListInReverse(Node<T>* nodePointer);
};



/* constructor */
template<typename T>
SinglyLinkedList<T>::SinglyLinkedList()
        :head{nullptr}, size_of_list{0}{

}

/* getter */
template<typename T>
Node<T> *SinglyLinkedList<T>::getHead() {
    return SinglyLinkedList::head;
}

template<typename T>
size_t SinglyLinkedList<T>::getListSize() {
    return SinglyLinkedList::size_of_list;
}

/* insert an element to the list */
template<typename T>
void SinglyLinkedList<T>::addElementAtHead(Node<T>* nodePointer) {
    insertElementAt(nodePointer, 1);
}

template<typename T>
void SinglyLinkedList<T>::addElementAtHead(T data) {
    /* node creation from the given data */
    auto* node = new Node<T>(data);

    addElementAtHead(node);
}

template<typename T>
void SinglyLinkedList<T>::addElementAtTail(Node<T>* nodePointer) {
    insertElementAt(nodePointer, this->size_of_list + 1);
}

template<typename T>
void SinglyLinkedList<T>::addElementAtTail(T data) {
    /* node creation from the given data */
    auto* node = new Node<T>(data);

    addElementAtTail(node);
}

template<typename T>
void SinglyLinkedList<T>::insertElementAt(Node<T>* nodePointer, size_t position) {
    if(position >= 1 && position <= (this->size_of_list + 1)){
        /* increase the size_of_list */
        this->size_of_list += 1;

        /* create a temporary node pointer
         * for navigating through the list */
        Node<T>* tempNodePointer {this->head};

        if(position == 1){
            /* head pointer variable will get modified
             * if insertion get performed at first node */
            nodePointer -> next = tempNodePointer ;
            this->head = nodePointer;
        } else {
            size_t countOfNode = 1;

            /* navigate through the required position */
            while(countOfNode < (position - 1)){
                tempNodePointer = tempNodePointer -> next;
                countOfNode++;
            }

            nodePointer -> next = tempNodePointer -> next;
            tempNodePointer -> next = nodePointer;
        }
    } else {
        std::cout << "insertion can't be performed!" << std::endl;
    }
}

/* display the list */
template<typename T>
void SinglyLinkedList<T>::printList() {
    Node<T>* tempNodePointer{this->head};
    while(tempNodePointer){
        std::cout << tempNodePointer->getData() << " ";
        tempNodePointer = tempNodePointer -> next;
    }std::cout << std::endl;
}

/* delete an element from the list */
template<typename T>
void SinglyLinkedList<T>::deleteNodeFromHead() {
    deleteNodeAt(1);
}

template<typename T>
void SinglyLinkedList<T>::deleteNodeFromTail() {
    deleteNodeAt(this->size_of_list);
}

template<typename T>
void SinglyLinkedList<T>::deleteNodeAt(size_t position) {
    /*Deletion can be performed only when their exist node at that position */
    if(position >= 1 && position <= this->size_of_list){
        /* create a temporary node pointer
         * for navigating through the list */
        Node<T>* tempNodePointer {this->head};

        /* decrease the size_of_list */
        this->size_of_list -= 1 ;

        if(position == 1){
            /* head pointer variable will get modified if
             * first node of linked list is being deleted */
            this->head = tempNodePointer -> next;
            tempNodePointer -> next = nullptr;

            /* de-allocate the heap memory */
            delete tempNodePointer;
        } else {
            size_t countOfNode = 1;

            /* for deleting position-th node, access to
             * (position - 1)-th node has to obtained */
            while(countOfNode < (position - 1)){
                tempNodePointer = tempNodePointer -> next;
                countOfNode++;
            }

            /* declare a node pointer that will point to deleted node */
            Node<T>* nodeToBeDeleted{tempNodePointer -> next};

            /* detach the node to be deleted from list */
            tempNodePointer -> next = nodeToBeDeleted -> next ;
            nodeToBeDeleted -> next = nullptr;

            /* de-allocate the heap memory */
            delete nodeToBeDeleted;
        }
    } else {
        std::cout << "deletion can't be performed!" << std::endl;
    }
}

/* destructor */
template<typename T>
SinglyLinkedList<T>::~SinglyLinkedList() {
    Node<T>* tempNodePointer{nullptr};
    while (this->head){
        tempNodePointer = this->head;
        this->head = tempNodePointer -> next;
        tempNodePointer -> next = nullptr;

        /* de-allocate the heap memory */
        delete tempNodePointer;
    }
}

/* delete the list */
template<typename T>
void SinglyLinkedList<T>::deleteList() {
    Node<T>* tempNodePointer{nullptr};
    while (this->head){
        tempNodePointer = this->head;
        this->head = tempNodePointer -> next;
        tempNodePointer -> next = nullptr;

        /* de-allocate the heap memory */
        delete tempNodePointer;
    }
    this->size_of_list = 0;
}

template<typename T>
void SinglyLinkedList<T>::reverseListDisplay() {
    displayListInReverse(this->head);

    /* traverse the cursor to the next line */
    std::cout << std::endl;
}

template<typename T>
void SinglyLinkedList<T>::displayListInReverse(Node<T> *nodePointer) {
    if(nodePointer) {
        displayListInReverse(nodePointer->next);
        std::cout << nodePointer->getData() << " ";
    }
}

template<typename T>
void SinglyLinkedList<T>::deleteElement(T keyValue) {
    if(this->size_of_list >= 1){
        Node<T>* tempNodePointer{this->head};
        Node<T>* previousNode{tempNodePointer} ;

        /* navigate through the list */
        while (tempNodePointer){

            /* if keyValue is found then further
             * traversal of list isn't required */
            if(tempNodePointer->getData() == keyValue){
                break;
            } else {
                previousNode = tempNodePointer;
                tempNodePointer = tempNodePointer -> next ;
            }
        }

        if(tempNodePointer){

            /* detach the node to be deleted from list */
            previousNode->next = tempNodePointer->next;
            tempNodePointer->next = nullptr;

            /* decrease the list size */
            this->size_of_list -= 1;

            /* de-allocate the heap-memory */
            delete tempNodePointer;
        } else {
            /* if element isn't found in the list */
            std::cout << "element not found!" << std::endl;
        }
    }
}

template<typename T>
Node<T> *SinglyLinkedList<T>::searchList(T keyValue) {
    Node<T>* tempNodePointer{this->head};

    /* search operation can be performed
     * only if linked list contain nodes */
    if(this->size_of_list >= 1){

        /* navigate through the list nodes */
        while (tempNodePointer){
            /* if keyValue is found inside the list
             * then no further traversal is required */
            if(tempNodePointer->getData() == keyValue){
                return tempNodePointer;
            } else {
                tempNodePointer = tempNodePointer -> next;
            }
        }
    } else {

        /* nullptr is a sentinel used to indicate
         * that keyValue isn't found in the list */
        return nullptr;
    }

    /* nullptr is a sentinel used to indicate
     * that keyValue isn't found in the list */
    return nullptr;
}

template<typename T>
void SinglyLinkedList<T>::leftRotateList(size_t number_of_rotation) {
    /* remove the redundant rotation */
    number_of_rotation %= this->size_of_list;

    /* if list has to be rotated */
    if (number_of_rotation >= 1) {
        Node<T>* tempNodePointer{this->head};
        size_t count_of_node{1};

        /* navigate through the list */
        while (count_of_node < number_of_rotation) {
            tempNodePointer = tempNodePointer->next;
            count_of_node++;
        }

        /* define a node pointer for k-th node */
        Node<T>* kthNode{tempNodePointer};

        /* get a node pointer for the end list node */
        while (tempNodePointer->next) {
            tempNodePointer = tempNodePointer->next;
        }

        /* perform the pointer manipulation */
        tempNodePointer->next = this->head;
        this->head = kthNode->next;
        kthNode->next = nullptr;
    }
}

#endif