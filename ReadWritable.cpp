/* ------------------------------------------------------
I have done all the coding by myself and only copied the
code that my professor provided to complete my workshops
and assignments.
-----------------------------------------------------------
Milestone 6
Class: OOP144NFF
Filename: ReadWritable.cpp
Student name: Mia Le
Student ID: 131101198
Email: tknle1@myseneca.ca
-----------------------------------------------------------
Date       Reason
August 08, 2020  This file has been modified and resubmit to
satisfiy the requirements of milestone 6.
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS

#include "ReadWritable.h"

using namespace std;

namespace sdds {

	ReadWritable::ReadWritable() {
		m_CommaSeparated = false;
	}
	
	ReadWritable::~ReadWritable() {

	}

	bool ReadWritable::isCsv()const {
		return m_CommaSeparated;
	}

	void ReadWritable::setCsv(bool value) {
		m_CommaSeparated = value;
	}

	std::ostream& ReadWritable::write(std::ostream& os) const {
		return os;
	}

	std::istream& ReadWritable::read(std::istream& is) {
		return is;
	}

	std::ostream& operator<<(std::ostream& os, const ReadWritable& rw) {

		return rw.write(os);
	}

	std::istream& operator>>(std::istream& is, ReadWritable& rw) {
		return rw.read(is);
	}
}