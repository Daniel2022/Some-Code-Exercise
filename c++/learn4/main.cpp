#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

int main()
{
    string str;
    ifstream inStream;
    ofstream outStream;
    stringstream lineStm;
    outStream.open("test.txt");
    inStream.open("testFile.txt");
    while(inStream.good()){
        string oneline;
        string twoline;
        getline(inStream, oneline);
        getline(inStream, twoline);
        cout << oneline << twoline << endl;
        //outStream << oneline << endl;
    }
    //outStream << str;
    outStream.close();
    return 0;
}