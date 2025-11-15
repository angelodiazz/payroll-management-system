#pragma once
#include "payrollsystem.h"

// Console UI / Controller
class ConsoleUI {
public:
    explicit ConsoleUI(PayrollSystem& system);
    void run(); // main loop

private:
    PayrollSystem& m_system;

    void seedSample(); // optional: add sample employees
    int menu() const;
    void addHourly();
    void addSalaried();
    void removeById();
    void findById() const;
    void printAll() const;
    void showTotals() const;

    // Small helpers
    static void clearCinLine();
};
