/* ------------------------------------------------------
I have done all the coding by myself and only copied the
code that my professor provided to complete my workshops
and assignments.
-----------------------------------------------------------
Milestone 6
Class: OOP144NFF
Filename: Menu.h
Student name: Mia Le
Student ID: 131101198
Email: tknle1@myseneca.ca
-----------------------------------------------------------
Date       Reason
August 08, 2020  This file has been modified and resubmit to
satisfiy the requirements of milestone 6.
-----------------------------------------------------------*/
#ifndef SDDS_MENU_h
#define SDDS_MENU_h
#include <iostream>
using namespace std;
namespace sdds {

    const int MAX_NO_OF_ITEMS = 10;

    class MenuItem {
        friend class Menu;
        char* m_itemname;
        MenuItem(const char*);
        ~MenuItem();
        MenuItem(const MenuItem&) = delete;
        void operator=(const MenuItem& item) = delete;
        ostream& display(ostream& stream = cout) const;

    };

    class Menu {
        char* m_title;
        MenuItem* m_menuitems[MAX_NO_OF_ITEMS];
        int m_sizeof;
        int m_inden;
    public:
        Menu();
        Menu(const char*, int itemno = 0);
        ~Menu();
        void setItem(const char*);
        Menu(const Menu&);
        bool isEmpty() const;
        void setEmpty();
        void operator=(const char* name);
        void add(const char* name);
        operator int() const;
        operator bool() const;
        std::ostream& display(std::ostream & = std::cout) const;
        void operator=(const Menu&);
        Menu& operator<<(const char*);
        int run() const;

    };

}

#endif
