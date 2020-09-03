#include <string>
#include "degree.h"
#include "student.h"
#include <iostream>

using namespace std;

Student::Student() {
	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->emailAddress = "";
	this->age = 0;
	for (int i = 0; i < daySizeArray; ++i) {
		this->numDays[i] = 0;
	}
	this->degreeProgram = Degree::UNDECIDED;

}

Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int numDays[], Degree degreeProgram) {
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->age = age;
	for (int i = 0; i < daySizeArray; ++i) {
		this->numDays[i] = numDays[i];
	}
	this->degreeProgram = degreeProgram;
}

string Student::getID() {
	return studentID;
}

string Student::getFirst() {
	return firstName;
}

string Student::getLast() {
	return lastName;
}

string Student::getEmail() {
	return emailAddress;
}

int Student::getAge() {
	return age;
}


int* Student::getDays() {
	return numDays;
}

Degree Student::getDegree() {
	return degreeProgram;
}

void Student::setID(string studentID) {
	this->studentID = studentID;
}

void Student::setFirst(string firstName) {
	this->firstName = firstName;
}

void Student::setLast(string lastName) {
	this->lastName = lastName;
}

void Student::setEmail(string emailAddress) {
	this->emailAddress = emailAddress;
}

void Student::setAge(int age) {
	this->age = age;
}

void Student::setDays(int daysInCourse[]) {
	for (int i = 0; i < daySizeArray; i++) {
		this->numDays[i] = daysInCourse[i];
	}
}

void Student::setDegree(Degree degreeProgram) {
	this->degreeProgram = degreeProgram;
}

void Student::print() {
	std::cout << getID() << "\t" << getFirst() << "\t" << getLast() << "\t" << getEmail() << "\t" << getAge() << "\t";
	int* day = getDays();
	cout << day[0] << "\t" << day[1] << "\t" << day[2] << "\t";
	cout << degreeStrings[(int)getDegree()] << endl;
}

Student::~Student() {

}