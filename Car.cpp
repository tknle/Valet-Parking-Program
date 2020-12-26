/* ------------------------------------------------------
I have done all the coding by myself and only copied the
code that my professor provided to complete my workshops
and assignments.
-----------------------------------------------------------
Milestone 6
Class: OOP144NFF
Filename: Car.cpp
Student name: Mia Le
Student ID: 131101198
Email: tknle1@myseneca.ca
-----------------------------------------------------------
Date       Reason
August 08, 2020  This file has been modified and resubmit to
satisfiy the requirements of milestone 6.
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS

#include "Car.h"
#include "Utils.h"
#include <cstring>
#include <string.h>

using namespace std;

namespace sdds {

	Car::Car() {
		setEmpty();
		carwash = false;
	}

	Car::Car(const char* licensePlate, const char* model, int carwash) : Vehicle(licensePlate,model), carwash(false){
		if (model == nullptr || model[0] == '\0' || licensePlate == nullptr || licensePlate[0] == '\0' || strlen(licensePlate) > 8 || strlen(model) <= 1) {
			setEmpty();
			carwash = false;
		}
		else {
			carwash = true;
			setLicensePlate(licensePlate);
			setMakeModel(model);
		}		
	}

	std::istream& Car::read(std::istream & cin) {
		if (isCsv()) {
			Vehicle::read(cin);
			bool hascarwash;
			cin >> hascarwash;
			cin.ignore(50, '\n');
			carwash = hascarwash;
		}
		else {
			cout << "\nCar information entry" << endl;
			Vehicle::read(cin);
			cout << "Carwash while parked? (Y)es/(N)o: ";
			carwash=yes();

		}
		return cin;
	}

	std::ostream& Car::write(std::ostream & os) const {
		if (isEmpty()) {
			os << "Invalid Car Object" << endl;

		}
		else {
			if (isCsv()) {
				os << "C,";
			}
			else {
				os << "Vehicle type: Car" << endl;
			}
			Vehicle::write(os);
			if (isCsv()) {
				os << carwash << endl;
			}
			else {
				if (carwash) {
					os << "With Carwash" << endl;
				}
				else {
					os << "Without Carwash" << endl;
				}
			}
		}
		return os;
	}

}