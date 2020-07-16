#include <stdlib.h>
#include <vector>
#include <functional>
#ifndef ONLINE_JUDGE
#include <thread>
#endif
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
  else{
    std::cout << "The two Matrixes' sizes is not matched." << "\n";
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
  else{
    std::cout << "The two Matrixes' sizes is not matched." << "\n";
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
  else{
    std::cout << "The two Matrixes' sizes is not matched." << "\n";
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
  else{
    std::cout << "The two Matrixes' sizes is not matched." << "\n";
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
  else{
    std::cout << "The two Matrixes' sizes is not matched." << "\n";
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
/****************************
 * 
 * Add a template implementation of a matrix class
 * It should support the operations of accessing an element of the matrix,
 * taking a sub-block, element-wise multiplication, and summation over all elements
 * of the matrix.
 *
 * NOTE: you may reuse the matrix implementation from Problem 2!! It has all you need
 *
 *
 * template<class T>
 * class Matrix
 *
 ****************************/

// Use this struct to pass the required information to each thread
// (this includes the input matrix, the output matrix, the kernel,
// the number of threads, and the thread-index)
struct KernelApplicationJob {
  Matrix<float> * src;
  Matrix<float> * K;
  Matrix<float> * dst;
  size_t threadIndex;
  size_t numberThreads;
};

/****************************
 * 
 * Implement the following function which will run in a thread.
 * The function is supposed to run the kernel convolution over
 * a sub-part of the image. If employing 4 threads (as we do),
 * the function should process 25% of the output matrix. The
 * threadIndex variable is used to decide which one of sub-parts
 * this thread is working on
 *
 *
 * void kernelApplicationThread( KernelApplicationJob & my_job );
 *
 ****************************/
//template<class T>
void kernelApplicationThread( KernelApplicationJob & my_job ) {
  int wide = (my_job.src->rows()*my_job.src->cols()) / my_job.numberThreads;
  int start_index = my_job.threadIndex * wide;
  int h = (my_job.K->rows()-1) / 2;
  int w = (my_job.K->cols()-1) / 2;
  for(int i=start_index;i<(my_job.threadIndex+1)*wide;i++) {
    int rs = i/my_job.src->cols(), cs = i%my_job.src->cols();
    if(((rs-h)>=0 && (rs+h)<my_job.src->rows()) && ((cs-w)>=0 && (cs+w)<my_job.src->cols())) {
      int rs = i/my_job.src->cols(), cs = i%my_job.src->cols();
      (*my_job.dst)(rs,cs) = ((my_job.src->block(rs-h,cs-w,my_job.K->rows(),my_job.K->cols())).hadamard(*my_job.K)).sum();
    }
  }
}
/*************** Do not change any code below this line!! *************/

int main() {
  size_t numberThreads = 4;

  //read in some matrix
  size_t rows;
  size_t cols;
  size_t kernelType;
  std::cin >> rows >> cols >> kernelType;
  Matrix<float> input(rows,cols);
  for( size_t r = 0; r < rows; r++ ) {
    for( size_t c = 0; c < cols; c++ ) {
      std::cin >> input(r,c);
    }
  }

  //define the kernel
  Matrix<float> * Kptr;
  if( kernelType == 0 ) { //gaussian blur kernel 3x3
    Kptr = new Matrix<float>(3,3);
    Matrix<float> & K = *Kptr;
    K(0,0) = (1.0f/16.0f); K(0,1) = (2.0f/16.0f); K(0,2) = (1.0f/16.0f);
    K(1,0) = (2.0f/16.0f); K(1,1) = (4.0f/16.0f); K(1,2) = (2.0f/16.0f);
    K(2,0) = (1.0f/16.0f); K(2,1) = (2.0f/16.0f); K(2,2) = (1.0f/16.0f);
  }
  if( kernelType == 1) { //gaussian blur kernel 5x5
    Kptr = new Matrix<float>(5,5);
    Matrix<float> & K = *Kptr;
    K(0,0) = (2.0f/159.0f); K(0,1) = ( 4.0f/159.0f); K(0,2) = ( 5.0f/159.0f); K(0,3) = ( 4.0f/159.0f); K(0,4) = (2.0f/159.0f);
    K(1,0) = (4.0f/159.0f); K(1,1) = ( 9.0f/159.0f); K(1,2) = (12.0f/159.0f); K(1,3) = ( 9.0f/159.0f); K(1,4) = (4.0f/159.0f);
    K(2,0) = (5.0f/159.0f); K(2,1) = (12.0f/159.0f); K(2,2) = (15.0f/159.0f); K(2,3) = (12.0f/159.0f); K(2,4) = (5.0f/159.0f);
    K(3,0) = (4.0f/159.0f); K(3,1) = ( 9.0f/159.0f); K(3,2) = (12.0f/159.0f); K(3,3) = ( 9.0f/159.0f); K(3,4) = (4.0f/159.0f);
    K(4,0) = (2.0f/159.0f); K(4,1) = ( 4.0f/159.0f); K(4,2) = ( 5.0f/159.0f); K(4,3) = ( 4.0f/159.0f); K(4,4) = (2.0f/159.0f);
  }
  if( kernelType == 2 ) { //average kernel 3x3
    Kptr = new Matrix<float>(3,3,1.0f/9.0f);
  }
  if( kernelType == 3 ) { //average kernel 5x5
    Kptr = new Matrix<float>(5,5,1.0f/25.0f);
  }
  if( kernelType == 4 ) { //horizontal sobel kernel
    Kptr = new Matrix<float>(1,3);
    Matrix<float> & K = *Kptr;
    K(0,0) = -1.0f;
    K(0,2) =  1.0f;
  }
  if( kernelType == 5 ) { //vertical sobel kernel
    Kptr = new Matrix<float>(3,1);
    Matrix<float> & K = *Kptr;
    K(0,0) = -1.0f;
    K(2,0) =  1.0f;
  }
  
  //define the output
  Matrix<float> output(rows,cols);
  
  std::vector<KernelApplicationJob> jobs(numberThreads);
  for( size_t i = 0; i < numberThreads; i++ ) {
    jobs[i].src = &input;
    jobs[i].K = Kptr;
    jobs[i].dst = &output;
    jobs[i].threadIndex = i;
    jobs[i].numberThreads = numberThreads;
  }

#ifndef ONLINE_JUDGE
  //start the threads that apply the kernel
  std::vector<std::thread> kernelApplicators;
  kernelApplicators.reserve(numberThreads);
  for( size_t i = 0; i < numberThreads; i++ ) {
    KernelApplicationJob & ref = jobs[i];
    kernelApplicators.push_back( std::thread(kernelApplicationThread,std::ref(jobs[i]) ) );
  }
  for( auto& thread : kernelApplicators ) {
    if( thread.joinable() )
      thread.join();
  }
#else
  for( size_t i = 0; i < numberThreads; i++ )
    kernelApplicationThread(jobs[i]);
#endif

  //output the result
  for( size_t r = 0; r < rows; r++ ) {
    for( size_t c = 0; c < cols; c++ ) {
      std::cout << output(r,c) << " ";
    }
    std::cout << "\n";
  }

  return 0;
}