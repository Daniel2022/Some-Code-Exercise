#include <fstream>
#include <iostream>
#include <sstream>
using namespace std;

int main(){
    ifstream stm;
    stm.open("test.txt");
    while(stm.good()){
        int n;
        stm >> n;
        cout << n << endl;
    }
}