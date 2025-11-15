#pragma once

// Interface for taxable entities (pure abstract type)
class Taxable {
public:
    virtual double taxRate() const = 0;
    virtual ~Taxable() = default;
};
