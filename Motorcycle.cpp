/* ------------------------------------------------------
I have done all the coding by myself and only copied the
code that my professor provided to complete my workshops
and assignments.
-----------------------------------------------------------
Milestone 6
Class: OOP144NFF
Filename: Motorcycle.cpp
Student name: Mia Le
Student ID: 131101198
Email: tknle1@myseneca.ca
-----------------------------------------------------------
Date       Reason
August 08, 2020  This file has been modified and resubmit to
satisfiy the requirements of milestone 6.
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS

#include "Motorcycle.h"
#include "Utils.h"
#include <cstring>
#include <string.h>

using namespace std;

namespace sdds {

	Motorcycle::Motorcycle() {
		setEmpty();
		sidecar = false;
	}

	Motorcycle::Motorcycle(const char* licensePlate, const char* model, int sidecar) : Vehicle(licensePlate, model), sidecar(false) {
		if (model == nullptr || model[0] == '\0' || licensePlate == nullptr || licensePlate[0] == '\0' || strlen(licensePlate) > 8 || strlen(model) <= 1) {
			setEmpty();
			sidecar = false;
		}
		else {
			sidecar = true;
			setLicensePlate(licensePlate);
			setMakeModel(model);
		}
	}
	
	std::istream& Motorcycle::read(std::istream& cin) {
		if (isCsv()) {
			//call the base class
			Vehicle::read(cin);
			bool hassidecar;
			cin >> hassidecar;
			cin.ignore(50,'\n');
			sidecar = hassidecar;
		}
		else {
			cout << "\nMotorcycle information entry" << endl;
			Vehicle::read(cin);
			cout << "Does the Motorcycle have a side car? (Y)es/(N)o: ";
			sidecar = yes();
		}
		return cin;
	}

	std::ostream& Motorcycle::write(std::ostream& os) const {
		if (isEmpty()) {
			os << "Invalid Motorcycle Object" << endl;

		}
		else {
			if (isCsv()) {
				os << "M,";
			}
			else {
				os << "Vehicle type: Motorcycle" << endl;
			}
			Vehicle::write(os);			
			if (isCsv()) {
				os << sidecar << endl;
			}
			else {
				if (sidecar) {
					os << "With Sidecar" << endl;
				}
			}
		}
		return os;
	}

}