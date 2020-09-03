#pragma once
#include <string>
#include "Degree.h"
using namespace std;

class Student {



private:
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int numDays[3];
	Degree degreeProgram;

public:
	const static int daySizeArray = 3;

	Student();
	Student(string studentID, string firstName, string lastName, string emailAddress, int age, int numDays[], Degree degreeProgram);

	string getID();
	string getFirst();
	string getLast();
	string getEmail();
	int getAge();
	int* getDays();
	Degree getDegree();

	void setID(string studentID);
	void setFirst(string firstName);
	void setLast(string lastName);
	void setEmail(string emailAddress);
	void setAge(int age);
	void setDays(int numDays[]);
	void setDegree(Degree degree);
	void print();

	~Student();

};