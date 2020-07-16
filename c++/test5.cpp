#include <vector>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <iterator>
using namespace std;

int main(){
    vector<string> vec = {"Hello ", ",", "World", "."};
    vector<string>::iterator it,it2;
    it = vec.begin(); it2 = vec.end()-1;
    //it2+=it;
    cout << it2-it << endl;
    cout << *it << *it2 << endl;
}