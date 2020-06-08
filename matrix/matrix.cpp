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
    double *newMatrix = new double*[rows];
    for (int i=0; i<newRow; i++){
        newMatrix[i] = new double[newColumn];
    }
    int copyRow = rows <= newRow ? rows : newRow;
    int copyCol = cols <= newColumn ? cols : newColumn;
    for (int i = 0; i < copyRow; ++i) {
        for (int j = 0; j < copyCol; ++j) {
            newMatrix[i][j] = matrix[i][j];
        }
    }
    rows = newRow;
    cols = newColumn;
    matrix = newMatrix; //need to look at this again cause old matrix might not be deallocate here
}

Matrix DenseMatrix::add(const Matrix& other) {
    double *newMatrix = new double*[rows];
    for (int i=0; i<rows; i++){
        newMatrix[i] = new double[cols];
    }
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            newMatrix[i][j] = matrix[i][j] + other->matrix[i][j];
        }
    }
    return newMatrix;
}

Matrix DenseMatrix::subtract(const Matrix& other) {
    double *newMatrix = new double*[rows];
    for (int i=0; i<rows; i++){
        newMatrix[i] = new double[cols];
    }
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            newMatrix[i][j] = matrix[i][j] - other->matrix[i][j];
        }
    }
    return newMatrix;
}

Matrix DenseMatrix::multiply(const Matrix& other) {
    //no error catching assuming matrices are multipliable
    double *newMatrix = new double*[rows];
    for (int i=0; i<rows; i++){
        newMatrix[i] = new double[other->cols];
    }
    for (int i = 0; i < rows; ++i) {
        double r[] = matrix[i];
        double c[cols];
        for (int j = 0; j < cols; ++j) {
            c[i] = other->matrix[i][j];
        }
        double temp = 0;
        for (int k=0; k < rows; k++) {
            temp += r[k]*c[k];
        }
        newMatrix[i][j] = temp;
        }
    }
    return newMatrix;
}
