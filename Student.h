#ifndef STUDENT_H
#define STUDENT_H
#include<string>

class Student {

    private:
        int studentID;
        string studentName;
    public:
	// Class constructors
    Student(); // empty constructor
	Student(int id, string name); //initializes the student id and initializes name of the student
	void setStudentId(int id); // sets id to the student's id
	void setStudentName(string name); // sets name to the student's name
	int getStudentId(); // gets student's id
    std::string getStudentName(); // gets student's name
	bool operator==(const Student &other) const; // overload the operator ==
                                                 // to compare two Student objects
};

#endif
