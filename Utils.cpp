/* ------------------------------------------------------
I have done all the coding by myself and only copied the
code that my professor provided to complete my workshops
and assignments.
-----------------------------------------------------------
Milestone 6
Class: OOP144NFF
Filename: Utils.cpp
Student name: Mia Le
Student ID: 131101198
Email: tknle1@myseneca.ca
-----------------------------------------------------------
Date       Reason
August 08, 2020  This file has been modified and resubmit to
satisfiy the requirements of milestone 6.
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include "Utils.h"
#include <cstring>
#include <string.h>

using namespace std;

namespace sdds {
	//check user input is y/Y/n/N
	bool yes(){
		bool exit = true;
		string ans;
		bool invalid = true;

		while (invalid == true) {
			cin >> ans;

			if (ans.compare("Y") == 0 || ans.compare("y") == 0) {
				exit = true;
				invalid = false;
			}
			else if (ans.compare("N") == 0 || ans.compare("n") == 0) {
				exit = false;
				invalid = false;
			}
			else {
				cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
			}
		}

		return exit;
	}
}