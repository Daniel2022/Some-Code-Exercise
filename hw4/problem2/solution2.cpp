#include <stdlib.h>
#include <vector>
#include <iostream>

template<class T>
class Matrix {
public:
  Matrix( int rs, int cs, T val = 0 );
  virtual ~Matrix();
  
  Matrix<T> & resize( int rs, int cs, T val=0 );

  T & operator() ( int r, int c );
  const T & operator() (int r, int c ) const;
  size_t rows() const;
  size_t cols() const;

  Matrix<T> block( int r, int c, int h, int w ) const;
  Matrix<T> & setBlock( int r, int c, int h, int w, T & val );
  Matrix<T> & setBlock( int r, int c, const Matrix<T> & val );
  Matrix<T> & setIdentity();
  Matrix<T> & setConstant( const T & val );
  Matrix<T> & setZero();

  Matrix<T> transpose() const;
  Matrix<T> & transposeInPlace();

  Matrix<T> operator+ ( const Matrix<T> & op ) const;
  Matrix<T> & operator+=( const Matrix<T> & op );
  Matrix<T> operator- ( const Matrix<T> & op ) const;
  Matrix<T> & operator-= ( const Matrix<T> & op);

  Matrix<T> operator*( const T & op ) const;
  Matrix<T> operator*( const Matrix<T> & op ) const;
  Matrix<T> & operator*=( const T & op );

  Matrix<T> hadamard ( const Matrix<T> & op ) const;
  T sum() const;
private:
  size_t m_row;
  size_t m_col;
  std::vector<std::vector<T> *> m_data;
};

template<class T>
Matrix<T>::Matrix( int rs, int cs, T val) {
  m_row = rs; m_col = cs;
  m_data.reserve(rs);
  for(int i=0;i<rs;i++) {
    m_data.push_back( new std::vector<T>() );
    m_data.back()->reserve(cs);
    for(int j=0;j<cs;j++) {
      m_data.back()->push_back(val);
    }
  }
}

template<class T>
Matrix<T>::~Matrix() {}

template<class T>
Matrix<T> & Matrix<T>::resize( int rs, int cs, T val) {
  m_row = rs; m_col = cs;
  Matrix<T> temp(rs,cs,val);
  m_data = temp.m_data;
  return *this;
}

template<class T>
T & Matrix<T>::operator() ( int r, int c ) {
  return (*m_data[r])[c];
}

template<class T>
const T & Matrix<T>::operator() ( int r, int c ) const {
  return (*m_data[r])[c];
}

template<class T>
size_t Matrix<T>::rows() const {
  return m_row;
}
template<class T>
size_t Matrix<T>::cols() const {
  return m_col;
}

template<class T>
Matrix<T> Matrix<T>::block( int r, int c, int h, int w ) const {
  Matrix<T> out(h, w);
  for(int i=0;i<h;i++) {
    for(int j=0;j<w;j++) 
      out(i, j) = (*m_data[i+r])[j+c];
  }
  return out;
}

template<class T>
Matrix<T> & Matrix<T>::setBlock( int r, int c, int h, int w, T & val ) {
  for(int i=0;i<h;i++) {
    for(int j=0;j<w;j++)
      (*m_data[i+r])[j+c] = val;
  }
  return *this;
}

template<class T>
Matrix<T> & Matrix<T>::setBlock( int r, int c, const Matrix<T> & val ) {
  for(int i=0;i<val.m_row;i++) {
    for(int j=0;j<val.m_col;j++)
      (*m_data[i+r])[j+c] = val(i, j);
  }
}

template<class T>
Matrix<T> & Matrix<T>::setIdentity() {
  for(int i=0;i<m_row;i++) {
    for(int j=0;j<m_col;j++) {
      if(i==j)
        (*m_data[i])[j] = 1;
      else
        (*m_data[i])[j] = 0;
    }
  }
  return *this;
}

template<class T>
Matrix<T> & Matrix<T>::setConstant( const T & val ) {
  for(int i=0;i<m_row;i++) {
    for(int j=0;j<m_col;j++) 
      (*m_data[i])[j] = val;
  }
  return *this;
}

template<class T>
Matrix<T> & Matrix<T>::setZero() {
  setConstant(0);
  return *this;
}

template<class T>
Matrix<T> Matrix<T>::transpose() const {
  Matrix<T> out(m_col, m_row);
  for(int i=0;i<m_row;i++){
    for(int j=0;j<m_col;j++)
      out(j, i) = (*m_data[i])[j];
  }
  return out;
}

template<class T>
Matrix<T> & Matrix<T>::transposeInPlace() {
  Matrix<T> temp = transpose();
  m_row = temp.m_row;
  m_col = temp.m_col;
  m_data = temp.m_data;
  return *this;
}

template<class T>
Matrix<T> Matrix<T>::operator+(const Matrix<T> & op) const {
  Matrix<T> out(m_row, m_col);
  if((m_row==op.m_row) && (m_col==op.m_col)) {
    for(int i=0;i<m_row;i++){
      for(int j=0;j<m_col;j++)
        out(i, j) = (*m_data[i])[j] + op(i, j);
    }  
  }
  return out;
}

template<class T>
Matrix<T> & Matrix<T>::operator+=(const Matrix<T> & op) {
  if((m_row==op.m_row) && (m_col==op.m_col)) {
    for(int i=0;i<m_row;i++){
      for(int j=0;j<m_col;j++)
        (*m_data[i])[j] += op(i, j);
    }
  }
  return *this;
}

template<class T>
Matrix<T> Matrix<T>::operator-(const Matrix<T> & op) const {
  Matrix<T> out(m_row, m_col);
  if((m_row==op.m_row) && (m_col==op.m_col)) {
    for(int i=0;i<m_row;i++){
      for(int j=0;j<m_col;j++)
        out(i, j) = (*m_data[i])[j] - op(i, j);
    }
  }
  return out;
}

template<class T>
Matrix<T> & Matrix<T>::operator-=(const Matrix<T> & op) {
  if((m_row==op.m_row) && (m_col==op.m_col)) {
    for(int i=0;i<m_row;i++){
      for(int j=0;j<m_col;j++)
        (*m_data[i])[j] -= op(i, j);
    }
  }
  return *this;
}

template<class T>
Matrix<T> Matrix<T>::operator*( const T & op ) const {
  Matrix<T> out(m_row, m_col);
  for(int i=0;i<m_row;i++) {
    for(int j=0;j<m_col;j++)
      out(i, j) = (*m_data[i])[j] * op;
  }
  return out;
}

template<class T>
Matrix<T> Matrix<T>::operator*( const Matrix<T> & op ) const {
  Matrix<T> out(m_row, op.m_col);
  for(int i=0;i<out.m_row;i++){
    for(int j=0;j<out.m_col;j++){
      for(int k=0;k<m_col;k++){
        out(i, j) += (*m_data[i])[k]*op(k, j);
      }
    }
  }
  return out;
}

template<class T>
Matrix<T> & Matrix<T>::operator*=( const T & op ) {
  for(int i=0;i<m_row;i++){
    for(int j=0;j<m_col;j++)
      (*m_data[i])[j] *= op;
  }
  return *this;
}

template<class T>
Matrix<T> Matrix<T>::hadamard( const Matrix<T> & op ) const {
  Matrix<T> out(m_row,m_col);
  if((m_row==op.m_row) && (m_col==op.m_col)){
    for(int i=0;i<m_row;i++){
      for(int j=0;j<m_col;j++)
        out(i, j) = (*m_data[i])[j] * op(i, j);
    }
  }
  return out;
}

template<class T>
T Matrix<T>::sum() const {
  T result = 0;
  for(int i=0;i<m_row;i++){
    for(int j=0;j<m_col;j++)
      result += (*m_data[i])[j];
  }
  return result;
}

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