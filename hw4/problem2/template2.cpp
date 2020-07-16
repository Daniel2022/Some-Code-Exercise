/*******************************************************
 *
 * Problem 2 consists of implementing a template Matrix class.
 * The class should heavily rely on operators to enable convenient
 * encoding of arithmetic operations (see main function below for examples).
 * The exact interface is indicated below, and please also consider
 * the homework instructions for detailed background information.
 *
 * You are to modify lines
 *
 * -19 to 59: Add your implementation of the template Matrix class
 * 
 *******************************************************/

#include <stdlib.h>
#include <vector>
#include <iostream>

/****************
 *
 * Add your code for the (template) class Matrix here.
 * Matrix needs to correctly implement the interface declared by the below member functions.
 * The interface of the matrix is then used in the main function at the bottom.
 * It reads in a rectangular matrix from the console, and then performs a certain number of
 * operations on it to exploit the interface of Matrix.
 *
 * Matrix( int rs, int cs, T val = 0 );
 * virtual ~Matrix();
 *
 * Matrix<T> & resize( int rs, int cs, T val = 0 );
 *
 * T         & operator()( int r, int c );
 * const T   & operator()( int r, int c ) const;
 * size_t      rows() const;
 * size_t      cols() const;
 *
 * Matrix<T>   block( int r, int c, int h, int w ) const;
 * Matrix<T> & setBlock( int r, int c, int h, int w, T & val );
 * Matrix<T> & setBlock( int r, int c, const Matrix<T> & val );
 * Matrix<T> & setIdentity();
 * Matrix<T> & setConstant( const T & val );
 * Matrix<T> & setZero();
 *
 * Matrix<T>   transpose() const;
 * Matrix<T> & transposeInPlace();
 *
 * Matrix<T>   operator+ ( const Matrix<T> & op ) const;
 * Matrix<T> & operator+=( const Matrix<T> & op );
 * Matrix<T>   operator- ( const Matrix<T> & op ) const;
 * Matrix<T> & operator-=( const Matrix<T> & op );
 *
 * Matrix<T>   operator* ( const T & op ) const;
 * Matrix<T>   operator* ( const Matrix<T> & op ) const;
 * Matrix<T> & operator*=( const T & op );
 *
 * Matrix<T>   hadamard  ( const Matrix<T> & op ) const;
 * T           sum() const;
 *
 ***************/

/*************** Do not change any code below this line!! *************/

void printMatrix( const Matrix<float> & A ) {
  for( int r = 0; r < A.rows(); r++ ) {
    for( int c = 0; c < A.cols(); c++ ) {
      std::cout << A(r,c) << " ";
    }
    std::cout << "\n";
  }
}

int main() {
  //get the rows and cols
  int rows, cols;
  std::cin >> rows >> cols;

  //initialize the matrix
  Matrix<float> A(rows,cols);
  for( int r = 0; r < rows; r++ ) {
    for( int c = 0; c < cols; c++ ) {
      std::cin >> A(r,c);
    }
  }

  //do the operations
  Matrix<float> A1 = A.block(0,0,rows,rows);
  Matrix<float> A2 = A.block(0,cols-rows,rows,rows);
  Matrix<float> A3 = A1 + A2.transpose();
  Matrix<float> A4 = A1 - A2.transpose();
  Matrix<float> A5 = A1 * A2 * 2.0f; A5 *= 3.33f;
  Matrix<float> A6 = A1.hadamard(A2);
  A3 += A5;
  A4 -= A6;
  A1.setIdentity();
  A2.setConstant(4.44f);
  A.setBlock(0,0,A1);
  A.setBlock(0,cols-rows,A2);
  A.transposeInPlace();

  //print the result to the console
  printMatrix(A3);
  printMatrix(A4);
  printMatrix(A5);
  printMatrix(A6);
  printMatrix(A);

  return 0;
}