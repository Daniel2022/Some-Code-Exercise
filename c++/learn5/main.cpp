#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <string>
#include "Class.hpp"

using namespace std;
bool lessthan(Student *p1, Student *p2);

int main(){
    ifstream Student_info;
    ifstream University_info;
    vector<Student *> students;
    map<string, University *> univerisities;
    Student_info.open("Students.txt");
    University_info.open("Universities.txt");
    if(!Student_info){
        cout << "Cannot open file 'Student.txt'" << endl;
        return 0;
    }
    if(!University_info){
        cout << "Cannot open file 'University.txt'" << endl;
        return 0;
    }
    while(Student_info.good()){
        string oneline;
        string twoline;
        string name;
        int score;
        vector<string> ambition;
        getline(Student_info, oneline);
        getline(Student_info, twoline);
        stringstream lineStm1(oneline);
        stringstream lineStm2(twoline);
        lineStm1 >> name >> score;
        while(lineStm2.good()){
            string copy;
            lineStm2 >> copy;
            ambition.push_back(copy);
        }
        students.push_back(new Student(name, score, ambition));
    }
    while(University_info.good()){
        string oneline;
        string name2;
        string code2;
        int total;
        getline(University_info, oneline);
        stringstream lineStm(oneline);
        lineStm >> name2 >> code2 >> total; //cout << total <<endl;
        univerisities[code2] = new University(name2, code2, total);
    }
    sort(students.begin(), students.end(), lessthan);
    vector<Student *>::iterator it;
    for(it=students.begin(); it!=students.end();it++){
        vector<string>::iterator its;
        vector<string> vect = (*it)->get_ambition();
        bool flag = false;
        for(its=vect.begin();its!=vect.end();++its){
            if(univerisities[*its]->m_total!=0){
                cout << (*it)->get_name() << " to " << univerisities[*its]->get_name() << " score: " << (*it)->get_score() << endl;
                univerisities[*its]->m_total -= 1;
                flag = true;
                break;
            }
        }
        if(!flag){
            cout << (*it)->get_name() << " is not accpeted by a university." << " score: " << (*it)->get_score() << endl;
        }
    }
    return 0;
}

bool lessthan(Student *p1, Student *p2){
    return p1->get_score() > p2->get_score();
}
