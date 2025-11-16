#include "payrollsystem.h"

PayrollSystem::~PayrollSystem() { clear(); }

void PayrollSystem::clear() {
    for (auto* e : m_employees) delete e;
    m_employees.clear();
}

void PayrollSystem::addEmployee(AbstractEmployee* emp) {
    if (!emp) throw InvalidEmployeeException("Null employee pointer.");
    if (emp->id().empty()) throw InvalidEmployeeException("Employee ID cannot be empty.");

    for (auto* existing : m_employees) {
        if (existing->id() == emp->id())
            throw InvalidEmployeeException("Duplicate employee ID: " + emp->id());
    }
    m_employees.push_back(emp);
}

bool PayrollSystem::removeEmployee(const std::string& id) {
    for (size_t i = 0; i < m_employees.size(); ++i) {
        if (m_employees[i]->id() == id) {
            delete m_employees[i];
            m_employees.erase(m_employees.begin() + static_cast<long>(i));
            return true;
        }
    }
    return false;
}

AbstractEmployee* PayrollSystem::findEmployee(const std::string& id) const {
    for (auto* e : m_employees) if (e->id() == id) return e;
    return nullptr;
}

const std::vector<AbstractEmployee*>& PayrollSystem::employees() const {
    return m_employees;
}

double PayrollSystem::totalGross() const {
    return total([](const AbstractEmployee& e){ return e.grossPay(); });
}
double PayrollSystem::totalNet() const {
    return total([](const AbstractEmployee& e){ return e.netPay(); });
}

void PayrollSystem::printAll() const {
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "---------------- Payroll ----------------\n";
    std::cout << std::left
              << std::setw(10) << "Type"
              << std::setw(10) << "ID"
              << std::setw(18) << "Name"
              << std::setw(12) << "Gross"
              << std::setw(12) << "Tax"
              << std::setw(12) << "Net" << "\n";

    for (auto* e : m_employees) {
        std::cout << std::left
                  << std::setw(10) << e->typeName()
                  << std::setw(10) << e->id()
                  << std::setw(18) << e->name()
                  << std::setw(12) << e->grossPay()
                  << std::setw(12) << e->taxAmount()
                  << std::setw(12) << e->netPay()
                  << "\n";
    }
    std::cout << "-----------------------------------------\n";
    std::cout << "Total Gross: " << totalGross() << "\n";
    std::cout << "Total Net:   " << totalNet() << "\n";
    std::cout << "-----------------------------------------\n";
}
