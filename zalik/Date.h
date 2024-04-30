#pragma once
#include <iostream>
#include <ctime>
using namespace std;

struct Date {
	int day = 0;
	int month = 0;
	int year = 0;
	char str[50] = "";

	const char* toString(const char* format = "%d %B %Y") {
		tm dateInfo = { 0, 0, 0, day, month - 1, year - 1900 };
		strftime(str, 50, format, &dateInfo);
		return str;
	}
};