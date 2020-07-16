#include <string>
#include <vector>
#include "Class.hpp"
using namespace std;

Student::Student(string name, int score, vector<string> ambition){
    m_name = name;
    m_score = score;
    m_ambition = ambition;
}
string Student::get_name(){
    return m_name;
}
int Student::get_score(){
    return m_score;
}
vector<string> Student::get_ambition(){
    return m_ambition;
}