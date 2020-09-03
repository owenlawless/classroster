#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include "Roster.h"
#include "Student.h"
#include "Degree.h"

using namespace std;


int main() {

	const string studentData[] = {
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Owen,Lawless,olawles@wgu.edu,29,28,40,30,SOFTWARE"
	};

	int numStudents = 5;

	Roster* classRoster = new Roster(numStudents);


	cout << "Scripting and Programming - Applications C867" << endl;
	cout << "C++" << endl;
	cout << "Student ID#: 001180350" << endl;
	cout << "Owen Lawless" << endl;
	cout << endl;

	cout << endl;

	for (int i = 0; i < numStudents; i++) {
		classRoster->parseAndAdd(studentData[i]);
	}

	cout << "Displaying All Students..." << endl;
	classRoster->printAll();


	cout << endl;

	cout << "Displaying Invalid Emails..." << endl;
	classRoster->printInvalidEmails();

	cout << endl;

	cout << "Average Days per Course..." << endl;
	for (int i = 0; i < numStudents; i++) {
		classRoster->printAverageDaysInCourse(classRoster->getStudentAt(i)->getID());
	}

	cout << endl;

	cout << "Diplaying All Software Students... " << endl;
	classRoster->printDegree(Degree::SOFTWARE);

	cout << endl;

	classRoster->remove("A3");

	cout << endl;

	classRoster->printAll();

	cout << endl;

	classRoster->remove("A3");

	system("pause");

	return 0;
}