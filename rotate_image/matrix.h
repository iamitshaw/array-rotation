
/* include guard */

#ifndef _MATRIX_H_
#define _MATRIX_H_

#include <bits/stdc++.h>

template <typename T>
class Matrix {
private:
    size_t row{3};
    size_t column{3};
    T** array;
public:
    Matrix();
    Matrix(size_t row, size_t column);
    ~Matrix();
    void print_matrix();
    void initialize_matrix();
    size_t get_row() const;
    size_t get_column() const;
    void set_value(size_t X, size_t Y, T value);
    T get_value(size_t X, size_t Y);
};

template<typename T>
Matrix<T>::Matrix() {
    Matrix<T>(this->row, this->column);
}

template <typename T>
Matrix<T>::Matrix(size_t row, size_t column) {
    this->array = new T*[row];
    if (!this->array) {
        std::cout <<"Memory Error!\n" << std::endl;
        exit(EXIT_FAILURE);
    } else {
        for (size_t i{0}; i < row; i++) {
            this->array[i] = new T[column];
            if (!this->array[i]) {
                std::cout << "Memory Error!\n";
                exit(EXIT_FAILURE);
            }
        }
        this->row = row;
        this->column = column;
    }
}

template<typename T>
Matrix<T>::~Matrix() {
    for (size_t i{0}; i < this->row;i++) {
        delete [] this->array[i];
    }
    delete [] array;
}

template<typename T>
size_t Matrix<T>::get_row() const {
    return this->row;
}

template<typename T>
size_t Matrix<T>::get_column() const {
    return this->column;
}

template<typename T>
void Matrix<T>::set_value(size_t X, size_t Y, T value) {
    this->array[X][Y] = value;
}

template<typename T>
T Matrix<T>::get_value(size_t X, size_t Y) {
    return this->array[X][Y];
}

template<typename T>
void Matrix<T>::print_matrix() {
    for (size_t i{0};i < this->row;i++) {
        for (size_t j{0};j < this->column; j++) {
            std::cout << std::setw(6) << this->array[i][j];
        }
        std::cout << std::endl;
    }
}

template<typename T>
void Matrix<T>::initialize_matrix() {
    /* define a seed value for random_number_generator */
    auto seed{std::chrono::system_clock::now().time_since_epoch().count()};

    /* declare a random_number_generator with a seeded value */
    std::mt19937 random_number_generator(seed);

    /* define an range for random numbers */
    ssize_t left_bound{0}, right_bound{255};
    std::uniform_int_distribution<T> distinct_element(left_bound, right_bound);

    for (int i{0};i < row;i++) {
        for (int j{0};j < column;j++) {
            this->array[i][j] = distinct_element(random_number_generator);
        }
    }
}

#endif
