#include <string>
#include "Degree.h"
#include "Student.h"
#include "Roster.h"
#include <iostream>
using namespace std;

Roster::Roster() {
	this->index = -1;
	this->rosterSize = 0;
	this->classRosterArray = nullptr;
}

Roster::Roster(int rosterSize) {
	this->rosterSize = rosterSize;
	this->index = -1;
	this->classRosterArray = new Student * [rosterSize];
}

void Roster::parseAndAdd(string row) {

	if (index < rosterSize) {
		index++;
	}

	int rhs = row.find(",");
	string studentID = row.substr(0, rhs);

	int lhs = rhs + 1;
	rhs = row.find(",", lhs);
	string firstName = row.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = row.find(",", lhs);
	string lastName = row.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = row.find(",", lhs);
	string emailAddress = row.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = row.find(",", lhs);
	string tempAge = row.substr(lhs, rhs - lhs);
	int age = stoi(tempAge);

	lhs = rhs + 1;
	rhs = row.find(",", lhs);
	int daysInCourse1 = stoi(row.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = row.find(",", lhs);
	int daysInCourse2 = stoi(row.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = row.find(",", lhs);
	int daysInCourse3 = stoi(row.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = row.find(",", lhs);
	Degree degreeProgram;
	string degreeStr = row.substr(lhs, rhs - lhs);

	if (row.back() == 'K') degreeProgram = Degree::NETWORK;
	else if (row.back() == 'Y') degreeProgram = Degree::SECURITY;
	else if (row.back() == 'E') degreeProgram = Degree::SOFTWARE;
	else {
		cerr << "Invalid Student\n";
		exit(-1);
	}

	add(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);

}

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree degreeProgram) {
	int darr[Student::daySizeArray];

	darr[0] = daysInCourse1;
	darr[1] = daysInCourse2;
	darr[2] = daysInCourse3;

	classRosterArray[index] = new Student(studentID, firstName, lastName, emailAddress, age, darr, degreeProgram);
}

bool Roster::remove(string studentID) {

	bool found = false;
	for (int i = 0; i < index; ++i) {
		if (classRosterArray[i]->getID() == studentID) {
			found = true;
			delete this->classRosterArray[i];
			cout << "Student removed." << endl;
			classRosterArray[i] = classRosterArray[index];
			index--;
		}
	}
	if (!found) {
		cout << "Student not found." << endl;
	}
	return found;
}

void Roster::printAll() {
	for (int i = 0; i <= index; ++i) {
		classRosterArray[i]->print();
	}
}

void Roster::printAverageDaysInCourse(string studentID) {

	int average = 0;

	for (int i = 0; i < 5; ++i) {
		string tempID = classRosterArray[i]->getID();
		if (tempID == studentID) {
			average = ((classRosterArray[i]->getDays()[0] + classRosterArray[i]->getDays()[1] + classRosterArray[i]->getDays()[2]) / 3);
			cout << "Student " << studentID << " averages " << average << " days per course." << endl;
		}
	}
}

void Roster::printInvalidEmails() {
	for (int i = 0; i < index; i++) {
		bool foundCharAt = false;
		bool foundCharPeriod = false;
		bool foundCharSpace = false;
		string email = "";
		email = (*classRosterArray[i]).getEmail();
		for (char& c : email) {
			if (c == '@') {
				foundCharAt = true;
			}
			if (c == '.') {
				foundCharPeriod = true;
			}
			if (c == ' ') {
				foundCharSpace = true;
			}
		}
		if (foundCharAt == false || foundCharPeriod == false || foundCharSpace == true) {
			cout << (*classRosterArray[i]).getEmail() << '\n';
		}
	}
	cout << '\n';
}

void Roster::printDegree(Degree degree) {
	for (int i = 0; i < 5; ++i) {
		Degree tempDegree = classRosterArray[i]->getDegree();
		if (tempDegree == degree) {
			classRosterArray[i]->print();
		}
	}
}


Student* Roster::getStudentAt(int index) {
	return classRosterArray[index];
}

Roster::~Roster() {
	for (int i = 0; i < 5; ++i) {
		delete classRosterArray[i];
	}
	delete classRosterArray;
}