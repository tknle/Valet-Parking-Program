/* ------------------------------------------------------
I have done all the coding by myself and only copied the
code that my professor provided to complete my workshops
and assignments.
-----------------------------------------------------------
Milestone 6
Class: OOP144NFF
Filename: Car.h
Student name: Mia Le
Student ID: 131101198
Email: tknle1@myseneca.ca
-----------------------------------------------------------
Date       Reason
August 08, 2020  This file has been modified and resubmit to
satisfiy the requirements of milestone 6.
-----------------------------------------------------------*/

#ifndef SDDS_CAR_H
#define SDDS_CAR_H
#include <iostream>
#include"Vehicle.h"
namespace sdds {

	class Car : public Vehicle {
		bool carwash;

	public:
		Car();
		Car(const char*, const char*, int =0);
		//copy prohibited
		Car(const Car&) = delete;
		Car& operator=(const Car&) = delete;
		//Read
		std::istream& read(std::istream & = std::cin);
		//Write
		std::ostream& write(std::ostream & = std::cout) const;
	};

}

#endif 