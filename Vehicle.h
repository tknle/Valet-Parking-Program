/* ------------------------------------------------------
I have done all the coding by myself and only copied the
code that my professor provided to complete my workshops
and assignments.
-----------------------------------------------------------
Milestone 6
Class: OOP144NFF
Filename: Vehicle.h
Student name: Mia Le
Student ID: 131101198
Email: tknle1@myseneca.ca
-----------------------------------------------------------
Date       Reason
August 08, 2020  This file has been modified and resubmit to
satisfiy the requirements of milestone 6.
-----------------------------------------------------------*/
#ifndef SDDS_VEHICLE_H
#define SDDS_VEHICLE_H
#include <iostream>
#include "ReadWritable.h"

namespace sdds {

	class Vehicle : public ReadWritable {

		char m_licensePlate[9];
		char* m_model; //DMA
		size_t m_strlen;
		int m_parkingSpot; // can be 0, if 0 = not parked
		char* fileInput;

	protected:
		void clearMemory();
		void setEmpty();
		bool isEmpty() const;
		const char* getLicensePlate() const;
		const char* getMakeModel() const;
		void setMakeModel(const char* model);
		void setLicensePlate(const char*);		

	public:
		Vehicle(); //default constructor
		~Vehicle(); //destructor
		Vehicle(const char*, const char*); //constructor overloading w 3 args
		//copy prohibited
		Vehicle(const Vehicle&) = delete;
		Vehicle& operator=(const Vehicle&) = delete;
		int getParkingSpot() const;
		void setParkingSpot(int);
		bool operator==(const char*) const;
		bool operator==(const Vehicle&) const;
		std::istream& read(std::istream & = std::cin);
		std::ostream& write(std::ostream & = std::cout) const;
	};
	
	
}

#endif 