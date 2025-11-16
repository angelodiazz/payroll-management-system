#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <iomanip>
#include <functional>
#include "employee.h"
#include "exceptions.h"

class PayrollSystem {
public:
    PayrollSystem() = default;
    ~PayrollSystem();

    // Takes ownership (dynamic allocation)
    void addEmployee(AbstractEmployee* emp); // throws InvalidEmployeeException

    bool removeEmployee(const std::string& id);
    AbstractEmployee* findEmployee(const std::string& id) const;

    const std::vector<AbstractEmployee*>& employees() const;

    // Templates: generic totalizer
    template <typename Func>
    double total(Func f) const {
        double sum = 0.0;
        for (auto* e : m_employees) sum += f(*e);
        return sum;
    }

    double totalGross() const;
    double totalNet() const;

    void printAll() const;

private:
    std::vector<AbstractEmployee*> m_employees; // raw pointers (for learning)

    void clear();
};
