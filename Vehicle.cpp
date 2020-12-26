/* ------------------------------------------------------
I have done all the coding by myself and only copied the
code that my professor provided to complete my workshops
and assignments.
-----------------------------------------------------------
Milestone 6
Class: OOP144NFF
Filename: Vehicle.cpp
Student name: Mia Le
Student ID: 131101198
Email: tknle1@myseneca.ca
-----------------------------------------------------------
Date       Reason
August 08, 2020  This file has been modified and resubmit to
satisfiy the requirements of milestone 6.
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include "Vehicle.h"
#include <cstring>
#include <string.h>
#include <string>

using namespace std;

namespace sdds {

	Vehicle::Vehicle() {
		setEmpty();
	}

	Vehicle::~Vehicle() {
		delete[] m_model;
		m_model = nullptr;
	}

	//set to empty state
	void Vehicle::setEmpty() {
		m_licensePlate[0] = '\0';
		m_model = nullptr;
		m_parkingSpot = -1; // bcs it can be 0 or positive int
		m_strlen = 0;
	}

	//to delete DMA
	void Vehicle::clearMemory() {
		delete[] m_model;
		setEmpty();
	}
	
	//constructor
	Vehicle::Vehicle(const char* licensePlate, const char* model) {

		if (model == nullptr || model[0] == '\0' || licensePlate == nullptr || licensePlate[0] == '\0' || strlen(licensePlate) > 8 || strlen(model) <= 1) {
			setEmpty();
		}
		else {
			strncpy(m_licensePlate, licensePlate, 9);

			m_strlen = strlen(model) + 1;
			m_model = new char[m_strlen]; // wo +1 cause Invalid write of size 1 for strcpy
			strncpy(m_model, model, m_strlen);

			m_parkingSpot = 0;
		}
	}

	//check if in empty state
	bool Vehicle::isEmpty() const {
		return m_licensePlate[0] == '\0' || m_model == nullptr || m_model[0] == '\0' || m_parkingSpot == -1;
	}

	const char* Vehicle::getLicensePlate() const {
		return m_licensePlate;
	}

	const char* Vehicle::getMakeModel() const {
		return m_model;
	}

	void Vehicle::setLicensePlate(const char* li) {
		if (li[0] == '\0' && li == nullptr) {
			m_licensePlate[0] = '\0';
		}
		else {
			strcpy(m_licensePlate, li);
		}
	}

	void Vehicle::setMakeModel(const char* model) {
		bool valid = model != nullptr && model[0] != '\0';
		if (!valid) {
			m_model = nullptr;
		}
		else {
			if (m_model) {
				delete[] m_model;
				m_model = nullptr;
			}
			m_strlen = strlen(model) + 1;
			m_model = new char[m_strlen];
			strcpy(m_model, model);
		}
	}

	int Vehicle::getParkingSpot() const {
		return m_parkingSpot;
	}

	void Vehicle::setParkingSpot(int parkingNum) {
		
		if (parkingNum > -1) {
			m_parkingSpot = parkingNum;
		}
		else {
			//setEmpty
			clearMemory();
			setEmpty();
		}
	}

	//check if license plate is indentical
	bool Vehicle::operator==(const char* licensePlate) const {
		bool identical = false;

		char licenseDupA[9];
		char licenseDupB[9];
		strcpy(licenseDupA, licensePlate);
		strcpy(licenseDupB, m_licensePlate);
		if (strlen(licenseDupA) != strlen(licenseDupB)) {
			return false;
		}
		else {
			size_t len = strlen(licensePlate) + 1;

			for (size_t i = 0; i < len; i++) {
				licenseDupA[i] = toupper(licensePlate[i]);
				licenseDupB[i] = toupper(m_licensePlate[i]);
				if (licenseDupA[i] != licenseDupB[i]) {
					identical = false;
				}
			}

			if (strcmp(licenseDupA, licenseDupB) == 0) {
				identical = true;
			}
		}
		return identical;
	}

	//check if license plate is indentical, between 2 objects
	bool Vehicle::operator==(const Vehicle& vehicle) const {
		bool validLicense = false;
		char licenseDupA[9] = "";
		char licenseDupB[9] = "";

		strcpy(licenseDupA, vehicle.getLicensePlate());
		size_t len = strlen(vehicle.getLicensePlate()) + 1;

		strcpy(licenseDupB, getLicensePlate());

		for (size_t i = 0; i < len; i++) {
			licenseDupA[i] = toupper(licenseDupA[i]);
			licenseDupB[i] = toupper(licenseDupB[i]);
		}

		if (strcmp(licenseDupB, licenseDupA) == 0) {
			validLicense = true;
		}
		return validLicense;
	}

	//read can work with input from file or from keyboard
	std::istream& Vehicle::read(std::istream& cin) {
		if (ReadWritable::isCsv()) {

			char parkingSpot[10];
			cin.getline(parkingSpot, 10, ',');
			setParkingSpot(std::stoi(parkingSpot));

			char licensePlate[12];			
			cin.getline(licensePlate, 12, ',');
			for (size_t i = 0; i < strlen(licensePlate); i++) {
				licensePlate[i] = toupper(licensePlate[i]);
			}
			setLicensePlate(licensePlate);

			char model[60];
			cin.getline(model, 50, ',');
			setMakeModel(model);
		}
		else {
			char licensePlate[12] = "";
			char* model = new char[60];

			cout << "Enter Licence Plate Number: ";
			cin.ignore();
			cin.getline(licensePlate, 12, '\n');

			size_t len = strlen(licensePlate);
			while (len > 8 || len < 2) {
				cout << "Invalid Licence Plate, try again: ";
				cin.getline(licensePlate, 30, '\n');
				len = strlen(licensePlate);
			}

			if (len < 9) {
				for (unsigned i = 0; i < len; i++) {
					licensePlate[i] = toupper(licensePlate[i]);

				}
			}
			setLicensePlate(licensePlate);

			cout << "Enter Make and Model: ";

			cin.getline(model, 60, '\n');

			size_t len2 = strlen(model);

			while (len2 < 2 || len2 > 60) {
				cout << "Invalid Make and model, try again: ";
				cin.getline(model, 60, '\n');
				len2 = strlen(model);
			}
			setMakeModel(model);

			m_parkingSpot = 0;
			delete[] model;
			model = nullptr;
		}
		if (!cin) {
			setEmpty();
		}
		return cin;
	}

	//write to file or just to the screen
	std::ostream& Vehicle::write(std::ostream& os) const {

		if (isEmpty()) {
			os << "Invalid Vehicle Object" << endl;
			return os;
		}
		else {
			if (isCsv()) {
				os << m_parkingSpot;
				os << ",";
				os << m_licensePlate;
				os << ",";
				os << m_model;
				os<< ",";
			}
			else {
				os << "Parking Spot Number: ";
				if (m_parkingSpot == 0) {
					os << "N/A" << endl;
				}
				else {
					os << m_parkingSpot << endl;
				}
				os << "Licence Plate: " << m_licensePlate << endl;
				os << "Make and Model: " << m_model << endl;
			}
		}
		return os;
	}


	std::ostream& operator<<(std::ostream& os, const Vehicle& rw) {
		rw.write(os);
		return os;
	}

	std::istream& operator>>(std::istream& is, Vehicle& rw) {
		rw.read(is);
		return is;
	}
}