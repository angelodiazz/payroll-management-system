#pragma once
#include <stdexcept>
#include <string>

class InvalidEmployeeException : public std::runtime_error {
public:
    explicit InvalidEmployeeException(const std::string& msg)
        : std::runtime_error(msg) {}
};
