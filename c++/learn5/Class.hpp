#ifndef CLASS_HPP
#define CLASS_HPP

#include <string>
#include <vector>
using namespace std;

class Student{
private:
    string m_name;
    int m_score;
    vector<string> m_ambition;
public:
    Student(string name, int score, vector<string> ambition);
    string get_name();
    int get_score();
    vector<string> get_ambition();
};

class University{
private:
    string m_name;
    string m_code;
public:
    int m_total;
    University(string name, string code, int total);
    string get_name();
    string get_code();
};

#endif