
#include<string>

using namespace std;

#include <iostream>
#include "Student.h"

Student::Student(){
    studentID = 0;
    studentName = "";
}

Student::Student(int id, string name){
  studentID = id;
  studentName = name;
}

void Student::setStudentId(int id){
  studentID = id;
}

void Student::setStudentName(string name){
  studentName = name;
}

int Student::getStudentId(){
  return studentID;
}

string Student::getStudentName(){
  return studentName;
}

bool Student::operator==(const Student &other) const{
  return (studentID == other.studentID);
}
