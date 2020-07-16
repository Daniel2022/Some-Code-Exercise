#include <stdlib.h>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>

//Important: Do not remove the following two lines
//           This is called a forward declaration, and
//           let's you use HyperVector before its actual declaration
//           has been provided.
template<class T>
class HyperVector;

template<class T>
class HyperVectorIterator : public std::iterator< std::random_access_iterator_tag, T >{
public:
  HyperVectorIterator(typename std::vector<std::vector<T> *>::iterator iter1, typename std::vector<T>::iterator iter2, std::vector<std::vector<T> *> * link);

  T & operator*();
  T & operator->();
  T & operator[](int n);

  HyperVectorIterator<T> & operator++();
  HyperVectorIterator<T> operator++(int);
  HyperVectorIterator<T> & operator--();
  HyperVectorIterator<T> operator--(int);
  HyperVectorIterator<T> & operator+=( int n );
  HyperVectorIterator<T> & operator-=( int n );

  HyperVectorIterator<T> operator+( int n ) const;
  HyperVectorIterator<T> operator-( int n ) const;
  int operator-( const HyperVectorIterator<T> & that ) const;

  bool operator== ( const HyperVectorIterator<T> & that ) const;
  bool operator!= ( const HyperVectorIterator<T> & that ) const;
  bool operator< ( const HyperVectorIterator<T> & that ) const;
  bool operator> ( const HyperVectorIterator<T> & that ) const;
  bool operator<= ( const HyperVectorIterator<T> & that ) const;
  bool operator>= ( const HyperVectorIterator<T> & that ) const;
private:
  typename std::vector<std::vector<T> *>::iterator mainiterator;
  typename std::vector<T>::iterator subiterator;
  std::vector<std::vector<T> *> * m_link;
  //HyperVector<T> & m_vector;
};

template<class T>
HyperVectorIterator<T>::HyperVectorIterator(typename std::vector<std::vector<T> *>::iterator iter1, typename std::vector<T>::iterator iter2, std::vector<std::vector<T> *> * link){
  mainiterator = iter1;
  subiterator = iter2;
  m_link = link;
}

template<class T>
T & HyperVectorIterator<T>::operator*(){
  return *subiterator;
}

template<class T>
T & HyperVectorIterator<T>::operator->(){
  return subiterator;
}

template<class T>
T & HyperVectorIterator<T>::operator[](int n){
  return 0;
}

template<class T>
HyperVectorIterator<T> & HyperVectorIterator<T>::operator++(){
  if((!(subiterator==(*mainiterator)->end()-1))||(mainiterator==m_link->end()-1)){
    subiterator++;   
  }
  else{
    mainiterator++;
    subiterator = (*mainiterator)->begin();
  }
  return *this;
}

template<class T>
HyperVectorIterator<T> HyperVectorIterator<T>::operator++(int){
  HyperVectorIterator<T> tmp = *this;
  if((!(subiterator==(*mainiterator)->end()-1))||(mainiterator==m_link->end()-1)){
    subiterator++;
  }
  else{
    mainiterator++;
    subiterator=(*mainiterator)->begin();
  }
  return tmp;
}

template<class T>
HyperVectorIterator<T> & HyperVectorIterator<T>::operator--(){
  if(subiterator!=(*mainiterator)->begin()){
    subiterator--;
  }
  else{
    mainiterator--;
    subiterator = (*mainiterator)->end()-1;
  }
      return *this;
}

template<class T>
HyperVectorIterator<T> HyperVectorIterator<T>::operator--(int){
  HyperVectorIterator<T> tmp = *this;
  if(subiterator!=(*mainiterator)->begin()){
    subiterator--;
  }
  else{
    mainiterator--;
    subiterator = (*mainiterator)->end()-1;
  }
  return tmp;
}

template<class T>
HyperVectorIterator<T> & HyperVectorIterator<T>::operator+=(int n) {
  for(int i=0;i<n;i++){
    (*this)++;
  }
  return *this;
}

template<class T>
HyperVectorIterator<T> & HyperVectorIterator<T>::operator-=(int n) {
  for(int i=0;i<n;i++){
    (*this)--;
  }
  return *this;
}
/*
template<class T>
HyperVectorIterator<T> & HyperVectorIterator<T>::operator+=(const HyperVectorIterator<T> & that){

}*/

template<class T>
HyperVectorIterator<T> HyperVectorIterator<T>::operator+( int n ) const {
  HyperVectorIterator<T> tmp = *this;
  tmp += n;
  return tmp;
}

template<class T>
HyperVectorIterator<T> HyperVectorIterator<T>::operator-( int n ) const {
  HyperVectorIterator<T> tmp = *this;
  tmp -= n;
  return tmp;
}

template<class T>
int HyperVectorIterator<T>::operator-( const HyperVectorIterator<T> & that ) const {
  HyperVectorIterator<T> tmp = *this;
  int i=0;
  while(tmp!=that){
    tmp--;
    i++;
  }
  return i;
}

template<class T>
bool HyperVectorIterator<T>::operator== ( const HyperVectorIterator<T> & that ) const {
  return subiterator == that.subiterator;
}

template<class T>
bool HyperVectorIterator<T>::operator!= ( const HyperVectorIterator<T> & that ) const {
  return subiterator != that.subiterator;
}

template<class T>
bool HyperVectorIterator<T>::operator< ( const HyperVectorIterator<T> & that ) const {
  return (subiterator < that.subiterator)||(mainiterator < that.mainiterator);
}

template<class T>
bool HyperVectorIterator<T>::operator> ( const HyperVectorIterator<T> & that ) const {
  return (subiterator > that.subiterator)||(mainiterator > that.mainiterator);
}

template<class T>
bool HyperVectorIterator<T>::operator<= ( const HyperVectorIterator<T> & that ) const {
  return (subiterator <= that.subiterator)||(mainiterator < that.mainiterator);
}

template<class T>
bool HyperVectorIterator<T>::operator>= ( const HyperVectorIterator<T> & that ) const {
  return (subiterator >= that.subiterator)||(mainiterator > that.mainiterator);
}


#define VALUES_PER_BUCKET  50

template<class T>
class HyperVector {
public:
  typedef HyperVectorIterator<T> iterator;

  HyperVector();
  HyperVector( size_t size, T val = T() );
  virtual ~HyperVector();

  T & operator[]( int index );
  T & at( int index );

  // The following two functions are to be implemented by yourself
  iterator begin();
  iterator end();
  size_t size();
  bool empty();
  
  void push_back( const T & elem );
  void clear();

private:
  std::vector< std::vector<T> * > m_data;
  size_t m_size;
};

template<class T>
HyperVector<T>::HyperVector() {
  m_size = 0;
}

template<class T>
HyperVector<T>::HyperVector( size_t size, T val ) {
  size_t nbrBuckets = size / VALUES_PER_BUCKET;
  m_data.reserve(nbrBuckets+1);
  for( int i = 0; i < nbrBuckets; i++ )
    m_data.push_back( new std::vector<T>(VALUES_PER_BUCKET,val) );
  if( size % VALUES_PER_BUCKET != 0 )
    m_data.push_back( new std::vector<T>(size % VALUES_PER_BUCKET,val) );
  m_size = size;
}

template<class T>
HyperVector<T>::~HyperVector() {
  for( int i = 0; i < m_data.size(); i++ )
    delete m_data[i];
}

template<class T>
T &
HyperVector<T>::operator[]( int index ) {
  return this->at(index);
}

template<class T>
T &
HyperVector<T>::at( int index ) {
  size_t mainIndex = index / VALUES_PER_BUCKET;
  size_t subIndex = index % VALUES_PER_BUCKET;

  if( !(mainIndex < m_data.size() ) ) {
    std::cout << "Error: you attempted to access an element beyond the size of the container\n";
    return (*(m_data[0]))[0];
  }

  if( !(subIndex < (*(m_data[mainIndex])).size()) ) {
    std::cout << "Error: you attempted to access an element beyond the size of the container\n";
    return (*(m_data[0]))[0];
  }

  return (*(m_data[mainIndex]))[subIndex];
}

template<class T>
typename HyperVector<T>::iterator
HyperVector<T>::begin() {
  iterator itr(m_data.begin(), (*(m_data.begin()))->begin(), &m_data);
  return itr;
  // Todo: Implement this function to return an iterator as defined by you
}

template<class T>
typename HyperVector<T>::iterator
HyperVector<T>::end() {
  iterator itr(m_data.end()-1, (*(m_data.end()-1))->end(), &m_data);
  return itr;
  // Todo: Implement this function to return an iterator as defined by you
}

template<class T>
size_t
HyperVector<T>::size() {
  return m_size;
}

template<class T>
bool
HyperVector<T>::empty() {
  return m_size == 0;
}

template<class T>
void
HyperVector<T>::push_back( const T & elem ) {
  if( m_size == 0 ) {
    m_data.push_back( new std::vector<T>() );
    m_data.back()->reserve( VALUES_PER_BUCKET );
  }

  if( m_data.back()->size() >= VALUES_PER_BUCKET ) {
    m_data.push_back( new std::vector<T>() );
    m_data.back()->reserve( VALUES_PER_BUCKET );
  }

  m_data.back()->push_back( elem );
  m_size++;
  return;
}

template<class T>
void
HyperVector<T>::clear() {
  for( int i = 0; i < m_data.size(); i++ )
    delete m_data[i];
  m_data.clear();
  m_size = 0;
}

/*************** Do not change any code below this line!! *************/

int main() {
  
  //read one line with random numbers from the console
  std::string oneLine;
  std::getline( std::cin, oneLine );
  std::stringstream lineStm(oneLine);

  //store the individual numbers of this line in a HyperVector
  HyperVector<float> vec;
  float temp;
  while( lineStm >> temp ) {
    vec.push_back( temp );
  }

  //sort the elements using the random-access iterators
  std::sort( vec.begin(), vec.end() );

  //print the result to the console
  for( int i = 0; i < vec.size(); i++ )
    std::cout << vec[i] << " ";
  std::cout << "\n";

  return 0;
}