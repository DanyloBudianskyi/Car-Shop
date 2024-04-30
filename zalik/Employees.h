#pragma once
#include <iostream>
#include <cstring>
#include "Date.h"
using namespace std;

struct Employees {
	char lastName[60] = "";
	char firstName[60] = "";
	Date birthday;
	int experience = 0;
	char phoneNumber[15] = "";
	char status[60] = "";

	void showEmployeesInfo() {
		cout << "\n\tName: " << lastName << " " << firstName << endl;
		cout << "\tPhone number: " << phoneNumber << endl;
		cout << "\tBirthday: " << birthday.toString() << endl;
		cout << "\tExperience: " << experience << " years" << endl;
		cout << "\tStatus: " << status << endl;
	}

	void fillEmployeesInfo() {
		cout << "Input last name: "; cin.getline(lastName, 60);
		cout << "Input first name: "; cin.getline(firstName, 60);
		cout << "Input birthday(dd/mm/yyyy): "; cin >> birthday.day >> birthday.month >> birthday.year;
		cout << "Input experience: "; cin >> experience;
		cin.ignore();
		cout << "Input phone number: "; cin.getline(phoneNumber, 15);
		cout << "Input status: "; cin.getline(status, 60);
	}
};