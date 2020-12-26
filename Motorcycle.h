/* ------------------------------------------------------
I have done all the coding by myself and only copied the
code that my professor provided to complete my workshops
and assignments.
-----------------------------------------------------------
Milestone 6
Class: OOP144NFF
Filename: Motorcycle.h
Student name: Mia Le
Student ID: 131101198
Email: tknle1@myseneca.ca
-----------------------------------------------------------
Date       Reason
August 08, 2020  This file has been modified and resubmit to
satisfiy the requirements of milestone 6.
-----------------------------------------------------------*/

#ifndef SDDS_MOTORCYCLE_H
#define SDDS_MOTORCYCLE_H
#include "Vehicle.h"
namespace sdds {

	class Motorcycle : public Vehicle {
		bool sidecar;
	public:
		Motorcycle();
		Motorcycle(const char*, const char*, int = 0);
		Motorcycle(const Motorcycle&) = delete;
		Motorcycle& operator=(const Motorcycle&) = delete;
		std::istream& read(std::istream & = std::cin);
		std::ostream& write(std::ostream & = std::cout) const;
	};

}

#endif 