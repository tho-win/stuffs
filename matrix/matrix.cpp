#include "matrix.h"

DenseMatrix::DenseMatrix(int r, int c) : rows(r), cols(c) {
    allocSpace();
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = 0;
        }
    }
}

DenseMatrix::~DenseMatrix() {
    for (int i = 0; i < rows; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

void DenseMatrix::allocSpace() {
    matrix = new double*[rows];
    for (int i=0; i<rows; i++){
        matrix[i] = new double[cols];
    }
}

double DenseMatrix::get(int row, int column) {
    return matrix[row][column];
}

void DenseMatrix::set(int row, int column, int value) {
    matrix[row][column] = value;
}

void DenseMatrix::resize(int newRow, int newColumn) {
    newMatrix = new double*[rows];
    for (int i=0; i<newRow; i++){
        newMatrix[i] = new double[newColumn];
    }
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            newMatrix[i][j] = matrix[i][j];
        }
    }
}