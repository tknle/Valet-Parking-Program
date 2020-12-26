/* ------------------------------------------------------
I have done all the coding by myself and only copied the
code that my professor provided to complete my workshops
and assignments.
-----------------------------------------------------------
Milestone 6
Class: OOP144NFF
Filename: Parking.h
Student name: Mia Le
Student ID: 131101198
Email: tknle1@myseneca.ca
-----------------------------------------------------------
Date       Reason
August 08, 2020  This file has been modified and resubmit to
satisfiy the requirements of milestone 6.
-----------------------------------------------------------*/
#ifndef SDDS_PARKING_H
#define SDDS_PARKING_H
#include <iostream>
#include <fstream>
#include "Menu.h"
#include "Vehicle.h"
#include "Car.h"
#include "Motorcycle.h"

namespace sdds {

	const int MAX_NO_OF_SPOTS= 100;

	class Parking {
		char* m_fileName;
		//MODIFY FOR MILESTONE 6
		int m_noOfSpots; //available spots
		Vehicle* m_parkingspots[MAX_NO_OF_SPOTS];
		int m_noOfSpotsParked; //tracking the array, 	
		
		Menu* m_parkMenu; //The Parking Menu
		Menu* m_selectMenu; //Selection menu
		
		void createParkingMenu();
		void createSelectionSubMenu();
		void status() const;
		void setEmpty();
		//Private Member function implementa1ons
		bool isEmpty() const;
		void parkVehicle() ;
		void returnVehicle() ;
		void parkedVehicles();
		bool closeParking() ;
		bool exitApp() ;
		bool loadData() ;
		void saveData() ;
		int getEmptySpot();
		void clearData();

	public:
		Parking();
		~Parking();
		Parking(const Parking&) = delete;
		Parking& operator= (const Parking&) = delete;
		Parking(const char*, int);
		Parking(const char*);
		int run();
		
	};
}

#endif 