/* ------------------------------------------------------
I have done all the coding by myself and only copied the
code that my professor provided to complete my workshops
and assignments.
-----------------------------------------------------------
Milestone 6
Class: OOP144NFF
Filename: Parking.cpp
Student name: Mia Le
Student ID: 131101198
Email: tknle1@myseneca.ca
-----------------------------------------------------------
Date       Reason
August 08, 2020  This file has been modified and resubmit to
satisfiy the requirements of milestone 6.
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include <fstream>
#include "Parking.h"
#include "Utils.h"
#include <cstring>
#include <string.h>
#include <string>
using namespace std;

namespace sdds {

	Parking::Parking() {
		setEmpty();
	}

	Parking::~Parking() {
		saveData();
		clearData();
	}

	//set data members to empty state
	void Parking::setEmpty() {
		m_fileName = nullptr;
		m_noOfSpots = 0;

		for (int i = 0; i < MAX_NO_OF_SPOTS; i++) {
			m_parkingspots[i] = nullptr;
		}
		m_noOfSpotsParked = 0;
		m_parkMenu = nullptr;
		m_selectMenu = nullptr;
	}

	//delete the DMA
	void Parking::clearData() {
		delete[] m_fileName;
		m_fileName = nullptr;
		delete m_parkMenu;
		m_parkMenu = nullptr;

		delete m_selectMenu;
		m_selectMenu = nullptr;

		for (int i = 0; i < MAX_NO_OF_SPOTS; i++) {
			if (m_parkingspots[i] != nullptr) {
				delete m_parkingspots[i];
				m_parkingspots[i] = nullptr;
			}
		}
	}


	bool Parking::isEmpty() const {
		return (m_fileName == nullptr && m_parkMenu == nullptr &&
			m_selectMenu == nullptr);
	}


	void Parking::createParkingMenu() {
		if (m_parkMenu != nullptr) {
			if (m_parkMenu) {
				delete[] m_parkMenu;
				m_parkMenu = nullptr;
			}
		}
		m_parkMenu = new Menu("Parking Menu, select an action:");
		m_parkMenu->add("Park Vehicle");
		m_parkMenu->add("Return Vehicle");
		m_parkMenu->add("List Parked Vehicles");
		m_parkMenu->add("Close Parking (End of day)");
		m_parkMenu->add("Exit Program");
	}

	void Parking::createSelectionSubMenu() {
		if (m_selectMenu != nullptr) {
			if (m_selectMenu) {
				delete[] m_selectMenu;
				m_selectMenu = nullptr;
			}
		}
		m_selectMenu = new Menu("Select type of the vehicle:", 1);
		m_selectMenu->add("Car");
		m_selectMenu->add("Motorcycle");
		m_selectMenu->add("Cancel");
	}

	//constructor with 1 argument
	Parking::Parking(const char* inputFileName) {
		if (inputFileName != nullptr && strlen(inputFileName) > 0) {
			m_fileName = new char[strlen(inputFileName) + 1];
			strcpy(m_fileName, inputFileName);
		}
		else {
			m_fileName = nullptr;
		}
		m_parkMenu = nullptr;
		m_selectMenu = nullptr;

		if (loadData()) {
			createParkingMenu();
			createSelectionSubMenu();
		}
		else {
			cout << "Error loading file " << endl;
			exit(0);
		}
	}

	//constructor 2 args
	Parking::Parking(const char* datafile, int noOfSpots) {
		setEmpty();
		if (datafile != nullptr && strlen(datafile) != 0) {
			if (noOfSpots >= 10 && noOfSpots <= MAX_NO_OF_SPOTS) {
				m_fileName = new char[strlen(datafile) + 1];
				strcpy(m_fileName, datafile);
				m_noOfSpots = noOfSpots;
			}
		}

		if (loadData()) {
			createParkingMenu();
			createSelectionSubMenu();
		}
		else {
			cout << "Error loading file " << endl;
			exit(0);
		}
	}

	//user give input for car and motorcycle submenu
	void Parking::parkVehicle() {
		if (m_noOfSpotsParked == m_noOfSpots || m_noOfSpots == 0) {
			cout << "Parking is full" << endl;
		}
		else {
			//display sub menu
			cout << "    " << "Select type of the vehicle:" << endl;
			cout << "    " << "1- Car" << endl;
			cout << "    " << "2- Motorcycle" << endl;
			cout << "    " << "3- Cancel" << endl;
			cout << "    " << "> ";

			int num;
			cin >> num;

			if (num == 3) {
				cout << "Parking cancelled" << endl;
			}
			else {
				int emptySpot = getEmptySpot();

				if (num == 1)
				{
					m_parkingspots[emptySpot] = new Car();
					m_parkingspots[emptySpot]->setCsv(false);
					cin >> *m_parkingspots[emptySpot];
				}
				else if (num == 2)
				{
					m_parkingspots[emptySpot] = new Motorcycle();
					m_parkingspots[emptySpot]->setCsv(false);
					cin >> *m_parkingspots[emptySpot];
				}
				//print the ticket, set to the array
				cout << endl;
				cout << "Parking Ticket" << endl;
				m_noOfSpots--;
				m_noOfSpotsParked++;
				m_parkingspots[emptySpot]->setParkingSpot(emptySpot + 1);
				cout << *m_parkingspots[emptySpot];
				cout << endl;
			}
		}
	}

	//return the matching license then delete it if the licenses are matched, otherwise print Not found
	void Parking::returnVehicle() {
		cout << "Return Vehicle" << endl;

		cout << "Enter Licence Plate Number: ";
		char licensePlate[12] = "";

		cin.ignore();
		cin.getline(licensePlate, 12, '\n');
		size_t len = strlen(licensePlate) + 1;
		while (len > 8) {
			cout << "Invalid Licence Plate, try again: ";
			cin.getline(licensePlate, 30, '\n');
			len = strlen(licensePlate) + 1;
		}
		//search for matching license plate
		bool notfound = true;

		for (int i = 0; i < m_noOfSpotsParked && notfound; i++) {
			if (*m_parkingspots[i] == licensePlate) {
				cout << endl;
				cout << "Returning: " << endl;
				cout << *m_parkingspots[i] << endl;
				delete m_parkingspots[i];
				m_parkingspots[i] = nullptr;
				notfound = false;
			}
			else {
				notfound = true;
			}
		}
		if (notfound) {
			cout << endl;
			cout << "License plate " << licensePlate << " Not found" << endl;
			cout << endl;
		}
		else {
			m_noOfSpots++;
		}
	}

	//print all the vehicle
	void Parking::parkedVehicles() {
		cout << "*** List of parked vehicles ***" << endl;
		for (int i = 0; i < m_noOfSpotsParked; i++) {
			if (m_parkingspots[i] != nullptr) {
				cout << *m_parkingspots[i];
				cout << "-------------------------------" << endl;
			}
		}
	}

	//option 4, close parking then delete everything in the array that not null
	bool Parking::closeParking() {
		bool close = true;
		if (isEmpty()) {
			cout << "Closing Parking" << endl;
		}
		else {
			cout << "This will Remove and tow all remaining vehicles from the parking!" << endl;
			cout << "Are you sure? (Y)es/(N)o: ";
			if (!yes()) {
				close = false;
				cout << "Aborted!" << endl;
			}
			else {
				cout << "Closing Parking" << endl;

				for (int i = 0; i < m_noOfSpotsParked; i++) {
					if (m_parkingspots[i] != nullptr) {
						cout << endl;
						cout << "Towing request" << endl;
						cout << "*********************" << endl;
						cout << *m_parkingspots[i];

						delete m_parkingspots[i];
						m_parkingspots[i] = nullptr;
					}
				}
			}
		}

		return close;
	}

	//exit the app, option 5
	bool Parking::exitApp() {
		bool exit = true;
		cout << "This will terminate the program!" << endl;
		cout << "Are you sure? (Y)es/(N)o: ";
		string ans;
		bool isyes = yes();
		if (isyes) {
			exit = true;
		}
		return exit;
	}

	//loop from 0 t o MAX to find the FIRST empty spot and return the index of that empty spot
	int Parking::getEmptySpot() {
		for (int i = 0; i < MAX_NO_OF_SPOTS; i++) {
			if (m_noOfSpots != 0) {
				if (m_parkingspots[i] == nullptr) {
					return i;
				}
			}
		}
		return -1;
	}

	//load Data from file
	bool Parking::loadData() {
		if (!isEmpty()) {
			ifstream fin(m_fileName);
			int emptySpot;
			if (fin.is_open()) {
				while (!fin.eof()) {
					char type;
					fin >> type;

					fin.ignore();
					if (fin.fail()) {
						return true;
					}
					if (fin.bad()) {
						fin.clear();
						fin.ignore(200, '\n');
						clearData();
						return false;
					}
					if (m_noOfSpots != 0) {
						emptySpot = getEmptySpot();
						//create Car and then read from file
						if (toupper(type) == 'C') {
							m_parkingspots[emptySpot] = new Car();
							m_parkingspots[emptySpot]->setCsv(true);
							fin >> *m_parkingspots[emptySpot];
							m_parkingspots[emptySpot]->setCsv(false);
							m_noOfSpots--;
							m_noOfSpotsParked++;
						}
						//create Motorcycle and then read from file
						else if (toupper(type) == 'M') {
							m_parkingspots[emptySpot] = new Motorcycle();
							m_parkingspots[emptySpot]->setCsv(true);
							fin >> *m_parkingspots[emptySpot];
							m_parkingspots[emptySpot]->setCsv(false);
							m_noOfSpots--;
							m_noOfSpotsParked++;
						}
					}
				}
			}			
		}
		return true;
	}

	//save data to the file
	void Parking::saveData() {
		if (!isEmpty()) {
			ofstream fout;
			fout.open(m_fileName, ios::trunc);
			if (fout.is_open()) {				
				for (int counter = 0; counter < MAX_NO_OF_SPOTS; ++counter) {
					if (m_parkingspots[counter] != nullptr) {
						m_parkingspots[counter]->setCsv(true);		
						fout << *m_parkingspots[counter];
					}									
				}
			}			
			cin.ignore(500, '\n');
		}		
	}

	//the start of the program
	int Parking::run() {
		int valid = 1;
		int num;
		bool exit = false;
		if (!isEmpty()) {
			//status();
			while (!exit) {
				status();
				//display parking menu
				cout << "Parking Menu, select an action:" << endl;
				cout << "1- Park Vehicle" << endl;
				cout << "2- Return Vehicle" << endl;
				cout << "3- List Parked Vehicles" << endl;
				cout << "4- Close Parking (End of day)" << endl;
				cout << "5- Exit Program" << endl;
				cout << "> ";
				cin >> num;
				switch (num) {
				case 1:
					parkVehicle();
					break;
				case 2:
					returnVehicle();
					break;
				case 3:
					parkedVehicles();
					break;
				case 4:
					exit = closeParking();
					break;
				case 5:
					exit = exitApp();
					valid = 0;
					if (exit) {
						cout << "Exiting program!" << endl;
					}
					break;
				}
			}
		}
		return valid;
	}

	void Parking::status() const {
		cout << "****** Seneca Valet Parking ******" << endl;
		cout << "*****  Available spots: ";
		cout.width(4);
		cout.setf(ios::left);
		cout << m_noOfSpots;
		cout.unsetf(ios::left);
		cout << " *****" << endl;
	}
}