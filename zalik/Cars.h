#pragma once
#include <iostream>
#include <cstring>
using namespace std;

struct Cars {
	char brand[100] = "";
	char model[100] = "";
	char fuelType [20] = "";
	float liters = 0;
	char bodyType[100] = "";
	int year = 0;
	float price = 0;

	void showCarInfo() {
		cout << "\n\tBrand: " << brand << endl;
		cout << "\tModel: " << model << endl;
		cout << "\tFuel type: " << fuelType << endl;
		cout << "\tLiters: " << liters << endl;
		cout << "\tBody: " << bodyType << endl;
		cout << "\tYear: " << year << endl;
		cout << "\tPrice: " << price << endl;
	}

	void fillCarInfo() {
		cout << "\tInput brand: "; cin.getline(brand, 100);
		cout << "\tInput model: "; cin.getline(model, 100);
		cout << "\tInput fuel type: "; cin.getline(fuelType, 20);
		cout << "\tInput liters: "; cin >> liters;
		cout << "\tInput body type: "; cin.ignore(); cin.getline(bodyType, 100);
		cout << "\tInput year: "; cin >> year;
		cout << "\tInput price: "; cin >> price;
		cout << endl;
	}
};