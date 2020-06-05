
#include "pch.h"
#include <iostream>
#include <string>
using namespace std;


int main()
{
	//Variables that need to be added together at the end are : a, z, x, monthTablenumber, day
	int day, month, year, x, y, z, monthTablenumber;				
	string dayOfweek;
	
	
	cout << "When is your birthday?" << endl << "Example - (01/30/2000)" << endl << endl << "Month: ";

	//Month

	cin >> month;
	if (month > 12 || month < 1)
	{
		cout << "Error! Month must be 1-12" << endl << "Plese try again: ";
		do {
			cout << "When is your birthday: " << endl << "Month: ";
			cin >> month;
			if (month > 12 || month < 1) {
				cout << "Error! Month must be 1-12" << endl << "Please try again: ";
			}
		} while (month > 12 || month < 1);
	}

	//Day 
	cout << endl << "Day: ";
	cin >> day;
	if (day > 31 || day < 1) {
		cout << "Error! Day must be between 1-31" << endl << "Please try again: ";
		do {
			cout << endl << "Day: ";
			cin >> day;
			if (day > 31 || day < 1) {
				cout << "Error! Day must be between 1-31" << endl << "Please try again: ";
			}
		} while (day > 31 || day < 1);
	}

	//Months with 30 days 
	if ((month == 4 || month == 6 || month == 9 || month ==  11) && day > 30) {
		cout << "Error! Day must be between 1-30" << endl << "Please try again: ";
		do {
			cout << endl << "Day: ";
			cin >> day;
			if (day > 31 || day < 1) {
				cout << "Error! Day must be between 1-30" << endl << "Please try again: ";
			}
		} while ((month == 4 || 6 || 9 || 11) && day > 30);
	}

	//Year
	cout << endl << "Year: ";
	cin >> year;
	if (year > 2099 || year < 1752) {
		cout << "Error! Cannot calculate if year greater than 2099 or less than 1752" << endl << "Please try again: ";
		do {
			cout << endl << "Year: ";
			cin >> year;
			if (year > 2099 || year < 1752) {
				cout << "Error! Cannot calculate if year greater than 2099 or less than 1752" << endl << "Please try again: ";
			}
		} while (year > 2099 || year < 1752);
	}

	//Edgecasing leap year
	if (month == 2 && day > 28 && (year % 4) != 0) {
		cout << "Error! Year is not a leap year therefore February cannot have more than 28 days." << endl << "Please try again: ";
		do {
			cout << endl << "When is your birthday: " << endl << "Month: ";
			cin >> month;
			if (month > 12 || month < 1)
			{
				cout << "Error! Month must be 1-12" << endl << "Plese try again: ";
				do {
					cout << "When is your birthday: " << endl << "Month: ";
					cin >> month;
					if (month > 12 || month < 1) {
						cout << "Error! Month must be 1-12" << endl << "Please try again: ";
					}
				} while (month > 12 || month < 1);
			}
			cout << endl << "Day: ";
			cin >> day;
			if (day > 31 || day < 1) {
				cout << "Error! Day must be between 1-31" << endl << "Please try again: ";
				do {
					cout << endl << "Day: ";
					cin >> day;
					if (day > 31 || day < 1) {
						cout << "Error! Day must be between 1-31" << endl << "Please try again: ";
					}
				} while (day > 31 || day < 1);
			}
			if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) {
				cout << "Error! Day must be between 1-30" << endl << "Please try again: ";
				do {
					cout << endl << "Day: ";
					cin >> day;
					if (day > 31 || day < 1) {
						cout << "Error! Day must be between 1-30" << endl << "Please try again: ";
					}
				} while ((month == 4 || 6 || 9 || 11) && day > 30);
			}
			cout << endl << "Year: ";
			cin >> year;
			if (year > 2099 || year < 1752) {
				cout << "Error! Cannot calculate if year greater than 2099 or less than 1752" << endl << "Please try again: ";
				do {
					cout << endl << "Year: ";
					cin >> year;
					if (year > 2099 || year < 1752) {
						cout << "Error! Cannot calculate if year greater than 2099 or less than 1752" << endl << "Please try again: ";
					}
				} while (year > 2099 || year < 1752);
			}

			if (month == 2 && day > 28 && (year % 4) != 0) {
				cout << "Error! Year is not a leap year therefore February cannot have more than 28 days." << endl << "Please try again: ";
			}
		} while (month == 2 && day > 28 && (year % 4) != 0);
	}
	cout << endl << "Your birthday is " << month << " - " << day << " - " << year << endl;

	//Function 1
	x = year % 100;
	y = year - x;
	z = y / 100;
	z = z % 4;
	z = (3 - z);
	z = z * 2;

	//Function 2
	int a = (x / 4);
	

	//Function 3
	monthTablenumber = -1;
	//Assume year is not a leap year then correct if it is								
	switch (month) {
		case 1:
		case 10:
			monthTablenumber = 1;
			break;
		case 2:
		case 3:
		case 11:
			monthTablenumber = 4;
			break;
		case 4:
		case 7:
			monthTablenumber = 0;
			break;
		case 5:
			monthTablenumber = 2;
			break;
		case 6:
			monthTablenumber = 5;
			break;
		case 8:
			monthTablenumber = 3;
			break;
		case 9:
		case 12:
			monthTablenumber = 6;
			break;

		default:															//Default is not necessary because it is impossible for month to not be listed
			break;
	}
	if ((year % 4 == 0) || (year % 400 == 0)) {
		switch (month) {
		case 1:
			monthTablenumber = 0;
			break;
		case 2:
			monthTablenumber = 3;
			break;
		default:
			break;
		}

	}
	

	//Function 4
	//monthTablenumber = 6;
	int sum = a + z + x + monthTablenumber + day;
	int dayTablenumber = (sum % 7);

	//function 5
	switch (dayTablenumber){
		case 1:
			dayOfweek =  "Sunday";
			break;
		case 2:
			dayOfweek = "Monday";
			break;
		case 3: 
			dayOfweek = "Tuesday";
			break;
		case 4:
			dayOfweek = "Wednesday";
			break;
		case 5:
			dayOfweek = "Thursday";
			break;
		case 6:
			dayOfweek = "Friday";
			break;
		case 7:
			dayOfweek = "Saturday";
			break;
		default:
			break;
	}
	cout << endl << "You were born on a " << dayOfweek << endl;












	return 0;
}

