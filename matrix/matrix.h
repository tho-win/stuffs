#ifndef __MATRIX_H__
#define __MATRIX_H__

#include <iostream>

class Matrix {
    public:
        Matrix(int, int);
        ~Matrix();

        virtual double get(int, int column)= 0;
        virtual void set(int row, int column, int value)= 0;
        virtual void resize(int newRow, int newColumn)= 0;
        
        Matrix add(const Matrix&);
        Matrix subtract(const Matrix&);
        Matrix multiply(const Matrix&);
        Matrix transpose();
        Matrix multiplyConstant(double n);
        Matrix isCommute(const Matrix&);

    private:
        int rows, cols;

        void allocSpace();
};

class DenseMatrix : public Matrix {
    public:
        DenseMatrix(int, int);
        ~DenseMatrix();

    private:
        double** matrix;
}

class SparseMatrix : public Matrix {
    struct index {
        int row;
        int column;
        double value;
    }
    public:
        SparseMatrix(int, int);
        ~SparseMatrix();

    private:
        index* matrix;
}



#endif