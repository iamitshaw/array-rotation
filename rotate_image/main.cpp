#include "matrix.h"

/* function prototype */
void rotate_image(Matrix<size_t>& matrix, Matrix<size_t>& result);

int main(int argc, char* argv[]) {

    /* declare row and column variable */
    size_t row{5};
    size_t column{6};

    /* set-up for matrix */
    Matrix<size_t> matrix {row, column};
    matrix.initialize_matrix();
    std::cout << "\nMatrix: " << std::endl;
    matrix.print_matrix();

    /* interchange the content of row and column */
    std::swap(row, column);

    /* rotated matrix */
    Matrix<size_t> result{row, column};
    rotate_image(matrix, result);
    std::cout << "\nRotated matrix: " << std::endl;
    result.print_matrix();

    return 0;
}

/* a function to turn an rectangular image
 * by 90 degrees in clockwise direction */
void rotate_image(Matrix<size_t>& matrix, Matrix<size_t>& result) {
    /* get the row and column of the matrix */
    size_t row {matrix.get_row()};
    size_t column{matrix.get_column()};

    /* loop through each element of the matrix */
    for (size_t i{0};i < row;i++) {
        for (size_t j{0};j < column;j++) {
            size_t element_value{matrix.get_value(row - 1 - i, j)};
            result.set_value(j, i, element_value);
        }
    }
}