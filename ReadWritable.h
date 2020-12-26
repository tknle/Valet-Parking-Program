/* ------------------------------------------------------
I have done all the coding by myself and only copied the
code that my professor provided to complete my workshops
and assignments.
-----------------------------------------------------------
Milestone 6
Class: OOP144NFF
Filename: ReadWritable.h
Student name: Mia Le
Student ID: 131101198
Email: tknle1@myseneca.ca
-----------------------------------------------------------
Date       Reason
August 08, 2020  This file has been modified and resubmit to
satisfiy the requirements of milestone 6.
-----------------------------------------------------------*/
#ifndef SDDS_READWRITABLE_H
#define SDDS_READWRITABLE_H
#include <iostream>
#include <cstring>
#include <string.h>

namespace sdds {

	class ReadWritable {
		bool m_CommaSeparated;

	public:
		ReadWritable();
		virtual ~ReadWritable();
		bool isCsv()const;
		void setCsv(bool value);
		//pure virtual functions to overwrite later
		virtual std::ostream& write(std::ostream & = std::cout) const = 0;
		virtual std::istream& read(std::istream & = std::cin) = 0;
	};
	//operator overload 
	std::ostream& operator<<(std::ostream&, const ReadWritable&);
	std::istream& operator>>(std::istream&, ReadWritable&);
}

#endif 