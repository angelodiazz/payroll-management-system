#include "ui_console.h"
#include <iostream>
#include <limits>

using std::cin;
using std::cout;
using std::string;

ConsoleUI::ConsoleUI(PayrollSystem& system) : m_system(system) {}

void ConsoleUI::run() {
    bool running = true;
    while (running) {
        switch (menu()) {
            case 1: addHourly(); break;
            case 2: addSalaried(); break;
            case 3: removeById(); break;
            case 4: findById(); break;
            case 5: printAll(); break;
            case 6: showTotals(); break;
            case 0: running = false; break;
            default: cout << "Invalid choice.\n"; break;
        }
    }
    cout << "Goodbye!\n";
}

int ConsoleUI::menu() const {
    cout << "\n===== Payroll Menu =====\n"
         << "1) Add Hourly Employee\n"
         << "2) Add Salaried Employee\n"
         << "3) Remove Employee\n"
         << "4) Find Employee\n"
         << "5) Print All\n"
         << "6) Show Totals\n"
         << "0) Exit\n"
         << "Choose: ";

    int choice;
    if (!(cin >> choice)) {
        clearCinLine();
        return -1;
    }
    return choice;
}

void ConsoleUI::addHourly() {
    string id, name;
    double rate, hours, tax;

    cout << "Enter Employee ID: ";
    cin >> id;
    cout << "Enter Employee Name: ";
    cin >> name;
    cout << "Enter Hourly Rate: ";
    cin >> rate;
    cout << "Enter Hours Worked: ";
    cin >> hours;
    cout << "Enter Tax Rate (%): ";
    cin >> tax;

    try {
        m_system.addEmployee(new HourlyEmployee(id, name, rate, hours, tax));
        cout << "Hourly employee added successfully.\n";
    } catch (const InvalidEmployeeException& ex) {
        cout << "Error: " << ex.what() << "\n";
    }
}

void ConsoleUI::addSalaried() {
    string id, name;
    double annual, tax;

    cout << "Enter Employee ID: ";
    cin >> id;
    cout << "Enter Employee Name: ";
    cin >> name;
    cout << "Enter Annual Salary: ";
    cin >> annual;
    cout << "Enter Tax Rate (%): ";
    cin >> tax;

    try {
        m_system.addEmployee(new SalariedEmployee(id, name, annual, tax));
        cout << "✅ Salaried employee added successfully.\n";
    } catch (const InvalidEmployeeException& ex) {
        cout << "Error: " << ex.what() << "\n";
    }
}

void ConsoleUI::removeById() {
    string id;
    cout << "Enter Employee ID to remove: ";
    cin >> id;

    if (m_system.removeEmployee(id))
        cout << "Employee removed successfully.\n";
    else
        cout << "Employee not found.\n";
}

void ConsoleUI::findById() const {
    string id;
    cout << "Enter Employee ID to find: ";
    cin >> id;

    if (auto* e = m_system.findEmployee(id)) {
        cout << "\nEmployee found:\n"
             << "Type: " << e->typeName() << "\n"
             << "ID: " << e->id() << "\n"
             << "Name: " << e->name() << "\n"
             << "Gross Pay: $" << e->grossPay() << "\n"
             << "Tax: $" << e->taxAmount() << "\n"
             << "Net Pay: $" << e->netPay() << "\n";
    } else {
        cout << "Employee not found.\n";
    }
}

void ConsoleUI::printAll() const {
    if (m_system.employees().empty()) {
        cout << "No employees in the system.\n";
        return;
    }
    m_system.printAll();
}

void ConsoleUI::showTotals() const {
    cout << "Total Gross Pay: $" << m_system.totalGross() << "\n";
    cout << "Total Net Pay:   $" << m_system.totalNet() << "\n";
}

void ConsoleUI::clearCinLine() {
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}