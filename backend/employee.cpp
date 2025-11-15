#include "employee.h"

// ---------- AbstractEmployee ----------
AbstractEmployee::AbstractEmployee(const std::string& id,
                                   const std::string& name)
    : m_id(id), m_name(name) {}

std::string AbstractEmployee::id() const { return m_id; }
std::string AbstractEmployee::name() const { return m_name; }
void AbstractEmployee::setId(const std::string& id) { m_id = id; }
void AbstractEmployee::setName(const std::string& name) { m_name = name; }

// ---------- PaidEmployee ----------
PaidEmployee::PaidEmployee(const std::string& id,
                           const std::string& name,
                           double baseRate)
    : AbstractEmployee(id, name), m_baseRate(baseRate > 0 ? baseRate : 0) {}

void PaidEmployee::setBaseRate(double rate) { m_baseRate = (rate > 0) ? rate : 0; }
double PaidEmployee::baseRate() const { return m_baseRate; }

// ---------- HourlyEmployee ----------
HourlyEmployee::HourlyEmployee(const std::string& id,
                               const std::string& name,
                               double hourlyRate,
                               double hoursWorked,
                               double taxRatePercent)
    : PaidEmployee(id, name, hourlyRate),
      m_hoursWorked(hoursWorked),
      m_taxRatePercent(taxRatePercent) {
    if (m_hoursWorked < 0) m_hoursWorked = 0;
    if (m_taxRatePercent < 0) m_taxRatePercent = 0;
    if (m_taxRatePercent > 100) m_taxRatePercent = 100;
}

void HourlyEmployee::setHours(double hours) { m_hoursWorked = (hours >= 0) ? hours : 0; }
void HourlyEmployee::setHours(int hours) { m_hoursWorked = (hours >= 0) ? hours : 0; }
void HourlyEmployee::setTaxRate(double taxPercent) {
    if (taxPercent < 0) taxPercent = 0;
    if (taxPercent > 100) taxPercent = 100;
    m_taxRatePercent = taxPercent;
}
double HourlyEmployee::hoursWorked() const { return m_hoursWorked; }
double HourlyEmployee::taxRate() const { return m_taxRatePercent; }

double HourlyEmployee::grossPay() const {
    // Array requirement: split hours into regular and overtime
    double hours[2];
    if (m_hoursWorked <= 40.0) { hours[0] = m_hoursWorked; hours[1] = 0.0; }
    else { hours[0] = 40.0; hours[1] = m_hoursWorked - 40.0; }

    double regularPay = hours[0] * m_baseRate;
    double overtimePay = hours[1] * m_baseRate * 1.5;
    return regularPay + overtimePay;
}
double HourlyEmployee::taxAmount() const { return grossPay() * (m_taxRatePercent / 100.0); }
double HourlyEmployee::netPay() const { return grossPay() - taxAmount(); }
std::string HourlyEmployee::typeName() const { return "Hourly"; }

// ---------- SalariedEmployee ----------
SalariedEmployee::SalariedEmployee(const std::string& id,
                                   const std::string& name,
                                   double annualSalary,
                                   double taxRatePercent)
    : PaidEmployee(id, name, annualSalary / 12.0),
      m_annualSalary(annualSalary),
      m_taxRatePercent(taxRatePercent) {
    if (m_annualSalary < 0) m_annualSalary = 0;
    if (m_taxRatePercent < 0) m_taxRatePercent = 0;
    if (m_taxRatePercent > 100) m_taxRatePercent = 100;
}
double SalariedEmployee::taxRate() const { return m_taxRatePercent; }
double SalariedEmployee::grossPay() const { return m_annualSalary / 12.0; } // monthly
double SalariedEmployee::taxAmount() const { return grossPay() * (m_taxRatePercent / 100.0); }
double SalariedEmployee::netPay() const { return grossPay() - taxAmount(); }
std::string SalariedEmployee::typeName() const { return "Salaried"; }
