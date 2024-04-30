#pragma once
#include <iostream>
#include <ctime>
#include <cstring>
#include "Date.h"
#include "Employees.h"
#include "Cars.h"

struct Certificate {
    char lastName[60] = "";
    char firstName[60] = "";
    char phoneNumber[15] = "";
    long identificationNumber = 0;
    Employees empInfo;
    Date buyDate;
    Cars car;

    void showCertificate() {
        cout << "\n\tCustomer full name: " << lastName << " " << firstName << endl;
        cout << "\tCar model: " << car.brand << " " << car.model << " " << car.year << endl;
        cout << "\tCustomer phone number: " << phoneNumber << endl;
        cout << "\tSeller: " << empInfo.lastName << " " << empInfo.firstName << endl;
        cout << "\tDate: " << buyDate.toString() << endl;
        cout << "\tIdentification number: " << identificationNumber << endl;
    }

    void fillCertificate(Employees* employees, int numberOfEmployees, Cars* cars, int numberOfCars) {
        srand(time(0));

        cout << "Input customer first name: "; cin.getline(firstName, 60);
        cout << "Input customer last name: "; cin.getline(lastName, 60);
        cout << "Input customer phone number: "; cin.getline(phoneNumber, 60);
        cout << "Input date(dd/mm/yyyy): "; cin >> buyDate.day >> buyDate.month >> buyDate.year;;
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        identificationNumber = rand() % (999999999 - 100000000 + 1) + 100000000;
        int index = 0;
        
        cout << "Choise seller name(input index): " << endl;
        for (int i = 0; i < numberOfEmployees; i++) {
            cout << i + 1 << ". " << employees[i].lastName << " " << employees[i].firstName << endl;
        }
        cin >> index;
        cin.ignore();
        if (index >= 1 && index <= numberOfEmployees) {
            empInfo = employees[index - 1];
        }
        else {
            cout << "Wrong index" << endl;
            return;
        }

        cout << "Choise car(input index): " << endl;
        for (int i = 0; i < numberOfCars; i++) {
            cout << i + 1 << ". " << cars[i].brand << " " << cars[i].model << " " << cars[i].year << endl;
        }
        cin >> index;
        cin.ignore();
        if (index >= 1 && index <= numberOfCars) {
            car = cars[index - 1];
        }
        else {
            cout << "Wrong index" << endl;
            return;
        }
    }
};