#include <stdlib.h>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>

using namespace std;
int main(){
    vector<vector<int>> vec;
    vector<int> order;
    ifstream inStm;
    int line=0;
    int column;
    inStm.open("Example.txt");
    if(!inStm){
        return 0;
    }
    while(inStm.good()){
        vector<int> tmp = {};
        string oneline;
        column = 0;
        getline(inStm, oneline);//cout << oneline;
        stringstream lineStm(oneline);
        while(lineStm.good()){
            int n;
            lineStm >> n;//cout << n << " ";
            tmp.push_back(n);
            column++;//cout << column << endl;
        }
    vec.push_back(tmp);
    line++;//cout<<line<<endl;
    }
    cout << "The number of columns is " << column << endl;
    cout << "Please redefine the order of the columns: " << endl;
    for(int i=0;i<column;i++){
        int ordernum;
        cin >> ordernum;
        order.push_back(ordernum);
    }
    cout << "\n";
    for(int i=0;i<line;i++){
        for(int j=0;j<column;j++){
            cout << vec[i][order[j]] << "\t";
        }
        cout << "\n";
    }
}