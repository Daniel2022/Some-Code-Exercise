#include <string>
#include <vector>
#include "Class.hpp"
using namespace std;

University::University(string name, string code, int total){
    m_name = name;
    m_code = code;
    m_total = total;
}
string University::get_name(){
    return m_name;
}
string University::get_code(){
    return m_code;
}