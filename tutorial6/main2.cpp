#include <iostream>

using namespace std;
template <typename T>
class Matrix2{
private:
    T content[2][2];
public:
    T & at(int row, int col);
    void transpose();
    void add(Matrix2<T> & matrix);
    void remove(Matrix2<T> & matrix);
    T determinant();
    void print();
};
template <typename T>
T & Matrix2<T>::at(int row, int col){
    return content[row][col];
}
template <typename T>
void Matrix2<T>::transpose(){
    T temp[2][2];
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            temp[j][i] = content[i][j];
        }
    }
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            content[i][j] = temp[i][j];
        }
    }
}
template <typename T>
void Matrix2<T>::add(Matrix2<T> & matrix){
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            content[i][j] += matrix.content[i][j];
        }
    }
}
template <typename T>
void Matrix2<T>::remove(Matrix2<T> & matrix){
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            content[i][j] -= matrix.content[i][j];
        }
    }
}
template <typename T>
T Matrix2<T>::determinant(){
    return content[0][0]*content[1][1]-content[0][1]*content[1][0];
}
template <typename T>
void Matrix2<T>::print(){
    cout << content[0][0] << "\t" << content[0][1] << "\t" << endl;
    cout << content[1][0] << "\t" << content[1][1] << "\t" << endl;
}

int main() {
    Matrix2<float> matrix;
    matrix.at(0,0) = 0.1f;
    matrix.at(1,0) = 1.2f;
    matrix.at(0,1) = 2.3f;
    matrix.at(1,1) = 3.4f;
    std::cout << "The original matrix is:\n";
    matrix.print();
    std::cout << "Transposing the matrix returns:\n";
    matrix.transpose();
    matrix.print();
    std::cout << "The determinant is: ";
    std::cout << matrix.determinant() << "\n";
    std::cout << "The matrix times 2 is:\n";
    matrix.add(matrix);
    matrix.print();
    std::cout << "Subtracting the matrix from itself returns:\n";
    matrix.remove(matrix);
    matrix.print();
    return 0;
}