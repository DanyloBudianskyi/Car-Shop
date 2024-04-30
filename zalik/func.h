#pragma once

#include <cstdio>
#include <iostream>
#include <cstring>
#include "Cars.h"
#include "Employees.h"
#include "Certificate.h"

void showAdminPanel() {
	cout << "-----------------------------------------\n";
	cout << "|              Show Info:               |\n";
	cout << "-----------------------------------------\n";
	cout << "| 1. Show all cars.                     |\n";
	cout << "| 2. Show all employees.                |\n";
	cout << "| 3. Show all certificates.             |\n";
	cout << "| 4. Show number of cars and emp.       |\n";
	cout << "-----------------------------------------\n";
	cout << "|                 Menu:                 |\n";
	cout << "-----------------------------------------\n";
	cout << "| 5. Add new car                        |\n";
	cout << "| 6. Delete car by index                |\n";
	cout << "| 7. Add new Employee                   |\n";
	cout << "| 8. Delete Employee                    |\n";
	cout << "| 9. Update files                       |\n";
	cout << "-----------------------------------------\n";
	cout << "| 0. Exit.                              |\n";
	cout << "-----------------------------------------\n";
	cout << ">>> ";
}

void showEmployeePanel() {
	cout << "-----------------------------------------\n";
	cout << "|              Show Info:               |\n";
	cout << "-----------------------------------------\n";
	cout << "| 1. Show all cars.                     |\n";
	cout << "| 2. Show actual number of cars.        |\n";
	cout << "| 3. Show all certificates.             |\n";
	cout << "-----------------------------------------\n";
	cout << "|                 Menu:                 |\n";
	cout << "-----------------------------------------\n";
	cout << "| 4. Register a car sale                |\n";
	cout << "-----------------------------------------\n";
	cout << "| 0. Exit.                              |\n";
	cout << "-----------------------------------------\n";
	cout << ">>> ";
}

void showUserPanel() {
	cout << "-----------------------------------------\n";
	cout << "|                 Info:                 |\n";
	cout << "-----------------------------------------\n";
	cout << "| 1. Show all cars.                     |\n";
	cout << "| 2. Sort by...                         |\n";
	cout << "| 3. Find car by...                     |\n";
	cout << "| 4. Find certificate by number.        |\n";
	cout << "-----------------------------------------\n";
	cout << "| 0. Exit.                              |\n";
	cout << "-----------------------------------------\n";
	cout << ">>> ";
}

void showSortPanel() {
	cout << "\n1. Sort by name." << endl;
	cout << "2. Sort by price." << endl;
	cout << "3. Sort by year." << endl;
}

void showAllCar(Cars* cars, int numberOfCars) {
	if (numberOfCars == 0) {
		cout << "\nWe don't have any cars :(\n\n";
		return;
	}
	cout << "All cars:\n";
	for (int i = 0; i < numberOfCars; i++) {
		cout << "\nCar #" << i + 1 << ":";
		cars[i].showCarInfo();
		cout << endl;
	}
}

void showAllCertificates(Certificate* certificates, int numberOfCertificates) {
	if (numberOfCertificates == 0) {
		cout << "\nWe don't have any certificates :(\n\n";
		return;
	}
	cout << "All certificates:\n";
	for (int i = 0; i < numberOfCertificates; i++) {
		cout << "\nCertificate #" << i + 1 << ":";
		certificates[i].showCertificate();
		cout << endl;
	}
}


void showAllEmployees(Employees* employees, int numberOfEmployees) {
	if (numberOfEmployees == 0) {
		cout << "\nWe don't have any employees :(\n\n";
		return;
	}
	cout << "\nAll employees:\n ";
	for (int i = 0; i < numberOfEmployees; i++) {
		cout << "\nEmployee #" << i + 1 << ":";
		employees[i].showEmployeesInfo();
		cout << endl;
	}
}

void addCar(Cars*& cars, int& numberOfCars, int& capacity) {
	if (numberOfCars >= capacity) {
		capacity += 1;
		Cars* temp = new Cars[capacity];
		for (int i = 0; i < numberOfCars; i++) {
			temp[i] = cars[i];
		}
		delete[] cars;
		cars = temp;
	}
	cout << "Adding a new car:\n" << endl;
	cars[numberOfCars].fillCarInfo();
	numberOfCars++;
	cout << "You've successfully added a new car.\n";
}

void addEmployee(Employees*& employees, int& numberOfEmployees) {
	cout << "Adding a new employee:\n" << endl;
	employees[numberOfEmployees].fillEmployeesInfo();
	numberOfEmployees++;
	cout << "You've successfully added a new employee.\n";
}

void addCertificate(Certificate*& certificates, int& numberOfCertificates, Employees* employees, int numberOfEmployees, Cars* cars, int numberOfCars) {
	cout << "Creating a new certificate:\n" << endl;
	certificates[numberOfCertificates].fillCertificate(employees, numberOfEmployees, cars, numberOfCars);
	numberOfCertificates++;
	cout << "You've successfully created a certificate.\n";
}

void deleteCarByIndex(Cars*& cars, int& numberOfCars, int& index) {
	index -= 1;
	if (index >= 0 && index < numberOfCars) {
		Cars* newCars = new Cars[numberOfCars - 1];
		for (int i = 0; i < index; i++) {
			newCars[i] = cars[i];
		}
		for (int i = index + 1; i < numberOfCars; i++) {
			newCars[i - 1] = cars[i];
		}
		delete cars;
		cars = newCars;
		--numberOfCars;
		cout << "Car with index " << index + 1 << " was deleted\n";
	}
	else {
		cout << "Wrong index\n";
	}
}

void findCertificate(Certificate* certificate, int& numberOfCertificates, long name) {
	int index = -1;
	for (int i = 0; i < numberOfCertificates; i++) {
		if (certificate[i].identificationNumber == name) {
			index = i;
			break;
		}
	}
	if (index != -1) {
		cout << "Certificate was found: " << endl;
		certificate[index].showCertificate();
	}
	else (cout << "Certificate wasn't found") << endl;
}

void deleteEmployeesByName(Employees*& employees, int& numberOfEmployees, char* name) {
	int index = -1;
	int answer = 0;
	for (int i = 0; i < numberOfEmployees; i++) {
		if (strcmp(employees[i].firstName, name) == 0 || strcmp(employees[i].lastName, name) == 0) {
			index = i;
			break;
		}
	}

	if (index != -1) {
		cout << "Are you sure you want to remove this employee?\n(Input 1 - if yes)"; cin >> answer;
		if (answer == 1) {
			for (int i = index; i < numberOfEmployees - 1; i++) {
				employees[i] = employees[i + 1];
			}
			numberOfEmployees--;
			cout << "Employee with name " << employees[index].lastName << " " << employees[index].firstName << " was deleted\n";
		}
		else {
			cout << "\nCommand was canceled\n";
			return;
		}

	}
	else {
		cout << "\nEmployee wasn't found\n";
	}
}

void loadCarsFromFile(Cars*& cars, int& numberOfCars, int& capacity) {
	FILE* file = nullptr;
	fopen_s(&file, "cars.txt", "r");
	if (file != nullptr) {
		delete[] cars;
		cars = new Cars[capacity];
		numberOfCars = 0;
		while (!feof(file)) {
			fscanf_s(file, "%s %s %f %s %s %d %f\n", cars[numberOfCars].brand, 100, cars[numberOfCars].model, 100, &cars[numberOfCars].liters, cars[numberOfCars].fuelType, 20, cars[numberOfCars].bodyType, 100, &cars[numberOfCars].year, &cars[numberOfCars].price);
			numberOfCars++;
			if (numberOfCars >= capacity) {
				capacity *= 2;
				Cars* temp = new Cars[capacity];
				for (int i = 0; i < numberOfCars; i++) {
					temp[i] = cars[i];
				}
				delete[] cars;
				cars = temp;
			}
		}
		fclose(file);
		cout << "Cars were loaded.\n";
	}
}

void loadEmployeesFromFile(Employees*& employees, int& numberOfEmployees, int& capacity) {
	FILE* file = nullptr;
	fopen_s(&file, "employees.txt", "r");
	if (file != nullptr) {
		delete[] employees;
		employees = new Employees[capacity];
		numberOfEmployees = 0;
		while (!feof(file)) {
			fscanf_s(file, "%s %s %d %d %d %d %s %s\n", employees[numberOfEmployees].lastName, 60, employees[numberOfEmployees].firstName, 60, &employees[numberOfEmployees].birthday.day, &employees[numberOfEmployees].birthday.month, &employees[numberOfEmployees].birthday.year, &employees[numberOfEmployees].experience, employees[numberOfEmployees].phoneNumber, 15, employees[numberOfEmployees].status, 60);
			numberOfEmployees++;
		}
		fclose(file);
		cout << "Employees were loaded\n";
	}
}

void loadCertificates(Certificate*& certificates, int& numberOfCertificates, int& capacity) {
	FILE* file = nullptr;
	fopen_s(&file, "certificates.txt", "r");
	if (file != nullptr) {
		certificates = new Certificate[capacity];
		numberOfCertificates = 0;
		while (!feof(file)) {
			fscanf_s(file, "%s %s %s %d %d %d %s %s %ld %s %s %d\n", certificates[numberOfCertificates].lastName,60, certificates[numberOfCertificates].firstName,60, certificates[numberOfCertificates].phoneNumber,15, &certificates[numberOfCertificates].buyDate.day, &certificates[numberOfCertificates].buyDate.month, &certificates[numberOfCertificates].buyDate.year, certificates[numberOfCertificates].empInfo.lastName,60, certificates[numberOfCertificates].empInfo.firstName,60, &certificates[numberOfCertificates].identificationNumber, certificates[numberOfCertificates].car.brand,100, certificates[numberOfCertificates].car.model,100, &certificates[numberOfCertificates].car.year);
			numberOfCertificates++;
		}
		fclose(file);
		cout << "Certificates were loaded\n";
	}
}

void saveCarsToFile(Cars* cars, int numberOfCars) {
	FILE* file = nullptr;
	fopen_s(&file, "cars.txt", "w");
	if (file != nullptr) {
		for (int i = 0; i < numberOfCars; i++) {
			fprintf(file, "%s %s %.2f %s %s %d %.2f\n", cars[i].brand, cars[i].model, cars[i].liters, cars[i].fuelType, cars[i].bodyType, cars[i].year, cars[i].price);
		}
		fclose(file);
	}
	cout << "Cars were saved\n";
}

void saveEmployeesToFile(Employees* employees, int numberOfEmployees) {
	FILE* file = nullptr;
	fopen_s(&file, "employees.txt", "w");
	if (file != nullptr) {
		for (int i = 0; i < numberOfEmployees; i++) {
			fprintf(file, "%s %s %d %d %d %d %s %s\n", employees[i].lastName, employees[i].firstName, employees[i].birthday.day, employees[i].birthday.month, employees[i].birthday.year, employees[i].experience, employees[i].phoneNumber, employees[i].status);
		}
		fclose(file);
	}
}

void saveCertificatesToFile(Certificate* certificates, int numberOfCertificates) {
	FILE* file = nullptr;
	fopen_s(&file, "certificates.txt", "w");
	if (file != nullptr) {
		for (int i = 0; i < numberOfCertificates; i++) {
			fprintf(file, "%s %s %s %d %d %d %s %s %ld %s %s %d\n", certificates[i].lastName, certificates[i].firstName, certificates[i].phoneNumber, certificates[i].buyDate.day, certificates[i].buyDate.month, certificates[i].buyDate.year, certificates[i].empInfo.lastName, certificates[i].empInfo.firstName, certificates[i].identificationNumber, certificates[i].car.brand, certificates[i].car.model, certificates[i].car.year);

		}
		fclose(file);
	}
}

template <typename T>
void sort(T* arr, int size, bool (*fr)(T, T)) {
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (fr(arr[j], arr[j + 1])) {
				swap(arr[j], arr[j + 1]);
			}
		}
	}
}

void find(Cars* cars, int numberOfCars, char* name) {
	for (int i = 0; i < numberOfCars; i++) {
		if (strcmp(cars[i].brand, name) == 0 || strcmp(cars[i].model, name) == 0 || strcmp(cars[i].fuelType,name) == 0 || strcmp(cars[i].bodyType, name) == 0) {
			cout << "Car #" << i + 1 << endl;
			cars[i].showCarInfo();
		}
	}
}