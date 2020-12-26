/* ------------------------------------------------------
I have done all the coding by myself and only copied the
code that my professor provided to complete my workshops
and assignments.
-----------------------------------------------------------
Milestone 6
Class: OOP144NFF
Filename: Menu.cpp
Student name: Mia Le
Student ID: 131101198
Email: tknle1@myseneca.ca
-----------------------------------------------------------
Date       Reason
August 07, 2020  This file has been modified and resubmit to
satisfiy the requirements of milestone 6.
-----------------------------------------------------------*/

#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include <cstring>
#include "Menu.h"
#include "Utils.h"

using namespace std;

namespace sdds {
    MenuItem::MenuItem(const char* item) {
        if (item[0] != '\0' || item != nullptr) {
            m_itemname = new char[strlen(item) + 1];
            strcpy(m_itemname, item);
        }
        else {
            m_itemname = nullptr;
        }
    }

    MenuItem::~MenuItem()
    {
        delete[] m_itemname;
        m_itemname = nullptr;
    }

    std::ostream& MenuItem::display(std::ostream& os) const
    {
        os << m_itemname << endl;
        return os;
    }

    Menu::Menu() {
        setEmpty();
    }

    Menu::Menu(const char* name, int itemnumber) {
        if (name == nullptr || name[0] == '\0') {
            setEmpty();
        }
        else {
            m_inden = itemnumber;
            m_sizeof = 0;

            m_title = new char[strlen(name) + 1];
            strcpy(m_title, name);

            for (int i = 0; i < MAX_NO_OF_ITEMS; i++) {
                m_menuitems[i] = nullptr;
            }
        }
    }

    Menu::~Menu() {
        delete[] m_title;

        for (int i = 0; i < m_sizeof; i++) {
            delete m_menuitems[i];
            m_menuitems[i] = nullptr;
        }
    }

    Menu::Menu(const Menu& menu)
    {
        m_sizeof = menu.m_sizeof;
        m_inden = menu.m_inden;
        m_title = new char[strlen(menu.m_title) + 1];
        strcpy(m_title, menu.m_title);

        for (int i = 0; i < m_sizeof; i++)
        {
            m_menuitems[i] = new MenuItem(menu.m_menuitems[i]->m_itemname);
        }
    }

    void Menu::setItem(const char* items) {
        if (items == nullptr || items[0] == '\0') {
            setEmpty();
        }
        else {
            if (m_title) {
                delete[] m_title;
                m_title = nullptr;
            }
            m_title = new char[strlen(items) + 1];
            strcpy(m_title, items);
        }
    }

    void Menu::setEmpty() {
        m_sizeof = 0;
        m_inden = 0;
        m_title = nullptr;
        for (int i = 0; i < MAX_NO_OF_ITEMS; i++) {
            m_menuitems[i] = nullptr;
        }
    }

    bool Menu::isEmpty() const {
        return (m_title == nullptr || m_title[0] == '\0');
    }

    Menu::operator bool() const {
        return !isEmpty();
    }

    void Menu::operator=(const Menu& menu) {
        if (menu.isEmpty() || !isEmpty()) {
            for (int i = 0; i < m_sizeof; i++) {
                delete m_menuitems[i];
                m_menuitems[i] = nullptr;
            }
            delete[] m_title;
            m_title = nullptr;
            m_sizeof = 0;
        }
        if (!menu.isEmpty()) {
            m_sizeof = menu.m_sizeof;
            m_inden = menu.m_inden;

            for (int i = 0; i < m_sizeof; i++) {
                m_menuitems[i] = new MenuItem(menu.m_menuitems[i]->m_itemname);
            }
            m_title = new char[strlen(menu.m_title) + 1];
            strcpy(m_title, menu.m_title);
        }
    }


    ostream& Menu::display(ostream& os) const {
        if (isEmpty()) {
            os << "Invalid Menu!" << endl;
        }
        else if (m_sizeof == 0) {
            int inden = m_inden * 4;
            os << setw(inden) << "" << m_title << endl;
            os << "No Items to display!" << endl;
        }
        else {
            int inden = m_inden * 4;
            os << setw(inden) << "" << m_title << endl;
            for (int i = 0; i < m_sizeof; i++) {
                os.width(inden);
                os << setw(inden) << "" << (i + 1) << "- " << m_menuitems[i]->m_itemname << endl;
            }
            os << setw(inden) << "" << "> ";
        }
        return os;
    }

    void Menu::operator=(const char* name) {
        if (m_title) {
            delete[] m_title;
        }
        m_title = new char[strlen(name) + 1];
        strcpy(m_title, name);
    }

    void Menu::add(const char* name) {
        if (m_title && name != nullptr && name[0] != '\0' && m_sizeof < MAX_NO_OF_ITEMS) {
            m_menuitems[m_sizeof] = new MenuItem(name);
            m_sizeof++;
        }
        if (name == nullptr || name[0] == '\0') {
            delete[] m_title;
            m_title = nullptr;
            for (int i = 0; i < m_sizeof; i++) {
                delete m_menuitems[i];
                m_menuitems[i] = nullptr;
            }
            m_sizeof = 0;
        }
    }

    int Menu::run() const {
        int num = -1;
        bool isValid = true;
        display();

        if (m_sizeof == 0) {
            num = 0;
        }
        else {
            isValid = false;
            do {
                cin >> num;
                if (!cin) {
                    cout << "Invalid Integer, try again: ";
                    cin.clear();
                    cin.ignore(5000, '\n');
                }
                else {
                    if (num <= 0 || num > m_sizeof) {
                        cout << "Invalid selection, try again: ";
                    }
                    else {
                        isValid = true;
                        cin.ignore(5000, '\n');
                    }
                }
            } while (!isValid);
        }
        return num;
    }
    Menu& Menu::operator<<(const char* name) {
        add(name);
        return *this;
    }

    Menu::operator int() const {
        return run();
    }


}
