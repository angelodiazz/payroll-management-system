#pragma once
#include <string>
#include "taxable.h"

// =========================
// Abstract base class
// =========================
class AbstractEmployee {
protected:
    std::string m_id;
    std::string m_name;

public:
    AbstractEmployee(const std::string& id, const std::string& name);
    virtual ~AbstractEmployee() = default;

    std::string id() const;
    std::string name() const;

    void setId(const std::string& id);
    void setName(const std::string& name);

    // Pure virtuals → runtime polymorphism
    virtual double grossPay() const = 0;
    virtual double taxAmount() const = 0;
    virtual double netPay() const = 0;
    virtual std::string typeName() const = 0;
};

// =========================
// Multi-level base (single inheritance)
// =========================
class PaidEmployee : public AbstractEmployee {
protected:
    double m_baseRate; // hourly or monthly base

public:
    PaidEmployee(const std::string& id, const std::string& name, double baseRate);
    void setBaseRate(double rate);
    double baseRate() const;
};

// =========================
// HourlyEmployee (multiple inheritance with Taxable)
// =========================
class HourlyEmployee : public PaidEmployee, public Taxable {
private:
    double m_hoursWorked;
    double m_taxRatePercent;

public:
    HourlyEmployee(const std::string& id,
                   const std::string& name,
                   double hourlyRate,
                   double hoursWorked,
                   double taxRatePercent);

    // Compile-time polymorphism (overloading)
    void setHours(double hours);
    void setHours(int hours);

    void setTaxRate(double taxPercent);
    double hoursWorked() const;

    // Taxable
    double taxRate() const override;

    // AbstractEmployee
    double grossPay() const override;
    double taxAmount() const override;
    double netPay() const override;
    std::string typeName() const override;
};

// =========================
// SalariedEmployee (hierarchical + multiple inheritance)
// =========================
class SalariedEmployee : public PaidEmployee, public Taxable {
private:
    double m_annualSalary;
    double m_taxRatePercent;

public:
    SalariedEmployee(const std::string& id,
                     const std::string& name,
                     double annualSalary,
                     double taxRatePercent);

    double taxRate() const override;

    double grossPay() const override;     // monthly
    double taxAmount() const override;
    double netPay() const override;
    std::string typeName() const override;
};
