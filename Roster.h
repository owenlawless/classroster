#pragma once
#include <string>
#include "degree.h"
#include "student.h"
using std::string;

class Roster {

public:
	int index;

	int rosterSize;

	Student** classRosterArray; 

	Roster();

	Roster(int rosterSize);

	void parseAndAdd(string row);

	void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree degreeProgram);

	bool remove(string studentID);

	void printAll();

	void printAverageDaysInCourse(string studentID);

	void printInvalidEmails();

	void printDegree(Degree degree);

	Student* getStudentAt(int index);

	~Roster(); 
};
