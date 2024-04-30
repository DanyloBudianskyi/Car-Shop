#include <iostream>
#include "Cars.h"
#include "Employees.h"
#include "func.h"
#include "Certificate.h"

int main()
{
	int menu = 0;
	int numberOfCars = 0;
	int numberOfEmployees = 0;
	int numberOfCertificates = 0;
	int capacity = 1;
	int person = 0;
	int index = 0;
	long cerNum = 0;
	char name[20] = "";
	Cars* cars = new Cars[capacity];
	Employees* employees = new Employees[capacity];
	Certificate* certificate = new Certificate[capacity];


	cout << "Who are you?(1-Admin, 2-Employee, 3-Customer): "; cin >> person;

	loadCarsFromFile(cars, numberOfCars, capacity);
	loadEmployeesFromFile(employees, numberOfEmployees, capacity);
	loadCertificates(certificate, numberOfCertificates, capacity);

	switch (person)
	{
	//Admin
	case 1:
		do
		{
			showAdminPanel();
			cin >> menu;
			cin.ignore();
			switch (menu)
			{
			case 1:
				showAllCar(cars, numberOfCars);
				break;
			case 2:
				showAllEmployees(employees, numberOfEmployees);
				break;
			case 3:
				showAllCertificates(certificate, numberOfCertificates);
				break;
			case 4:
				cout << "Number of cars: " << numberOfCars << endl;
				cout << "Number of employees: " << numberOfEmployees << endl << endl;
				break;
			case 5:
				addCar(cars, numberOfCars, capacity);
				break;
			case 6:
				cout << "Enter index "; cin >> index;
				deleteCarByIndex(cars, numberOfCars, index);
				break;
			case 7:
				addEmployee(employees, numberOfEmployees);
				break;
			case 8:
				cout << "Enter employee name: "; cin.getline(name, 20);
				deleteEmployeesByName(employees, numberOfEmployees, name);
				break;
			case 9:
				cout << "Which file you want to update?(1.cars.txt, 2.employees.txt):" << endl; cin >> menu;
				if (menu == 1) {
					saveCarsToFile(cars, numberOfCars);
					break;
				}
				else if (menu == 2) {
					saveEmployeesToFile(employees, numberOfEmployees);
					break;
				}
				break;
			case 0:
				return 0;
			default:
				cout << "Invalid option\n";
				break;
			}
		} while (true);
	
	//Employee
	case 2:
		do
		{
			showEmployeePanel();
			cin >> menu;
			cin.ignore();
			switch (menu)
			{
			case 1:
				showAllCar(cars, numberOfCars);
				break;
			case 2:
				cout << "Number of cars: " << numberOfCars << endl;
				break;
			case 3:
				showAllCertificates(certificate, numberOfCertificates);
				break;
			case 4:
				addCertificate(certificate, numberOfCertificates, employees, numberOfEmployees, cars, numberOfCars);
				saveCertificatesToFile(certificate, numberOfCertificates);
				break;
			case 0:
				return 0;
			default:
				cout << "Invalid option\n";
				break;
			}
		} while (true);
	
	//User
	case 3:
		do
		{
			showUserPanel();
			cin >> menu;
			cin.ignore();
			switch (menu)
			{
			case 1:
				showAllCar(cars, numberOfCars);
				break;
			case 2:
				showSortPanel();
				cin >> menu;
				switch (menu)
				{
				//По названию
				case 1:
					cout << "1. Sort from A to Z\n";
					cout << "2. Sort from Z to A\n";
					cout << "Input your choice:"; cin >> menu;
					if (menu == 1) {
						sort<Cars>(cars, numberOfCars, [](Cars a, Cars b) -> bool {
							return a.brand > b.brand;
							});
					}
					else if (menu == 2) {
						sort<Cars>(cars, numberOfCars, [](Cars a, Cars b) -> bool {
							return a.brand < b.brand;
							});
					}
					else cout << "Wrong input";
					break;
				//По цене
				case 2:
					cout << "1. From lowest to highest\n";
					cout << "2. From highest to lowest\n";
					cout << "Input your choice:"; cin >> menu;
					if (menu == 1) {
						sort<Cars>(cars, numberOfCars, [](Cars a, Cars b) -> bool {
							return a.price < b.price;
							});
					}
					else if (menu == 2) {
						sort<Cars>(cars, numberOfCars, [](Cars a, Cars b) -> bool {
							return a.price > b.price;
							});
					}
					else cout << "Wrong input";
					break;
				//По году
				case 3:
					cout << "1. By newest\n";
					cout << "2. By oldest\n";
					cout << "Input your choice:"; cin >> menu;
					if (menu == 1) {
						sort<Cars>(cars, numberOfCars, [](Cars a, Cars b) -> bool {
							return a.year < b.year;
							});
					}
					else if (menu == 2) {
						sort<Cars>(cars, numberOfCars, [](Cars a, Cars b) -> bool {
							return a.year > b.year;
							});
					}
					else cout << "Wrong input";
					break;
				default:
					break;
				}
				break;
			case 3:
				cout << "\n1. Find by brand\n";
				cout << "2. Find by model\n";
				cout << "3. Find by fuel\n";
				cout << "4. Find by body type:";
				cin >> menu;
				if (menu == 1) {
					cout << "Input brand name:\n"; cin.ignore(); cin.getline(name, 20);
					find(cars, numberOfCars, name);
					break;
				}
				else if (menu == 2) {
					cout << "Input model:\n"; cin.ignore(); cin.getline(name, 20);
					find(cars, numberOfCars, name);
					break;
				}
				else if (menu == 3) {
					cout << "Input fuel type:\n"; cin.ignore(); cin.getline(name, 20);
					find(cars, numberOfCars, name);
					break;
				}
				else if (menu == 4) {
					cout << "Input body type:\n"; cin.ignore(); cin.getline(name, 20);
					find(cars, numberOfCars, name);
					break;
				}
				else {
					cout << "Wrong input" << endl;
				}
			case 4:
				cout << "Input certificate number: "; cin >> cerNum;
				findCertificate(certificate, numberOfCertificates, cerNum);
				break;
			case 0:
				return 0;
			default:
				cout << "Invalid option\n";
				break;
			}
		} while (true);
	default:
		break;
	}
	delete[] cars;
	delete[] certificate;
	delete[] employees;
}