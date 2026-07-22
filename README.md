[![OpenSSF Best Practices](https://www.bestpractices.dev/projects/12399/badge)](https://www.bestpractices.dev/projects/12399)
[![OpenSSF Scorecard](https://api.securityscorecards.dev/projects/github.com/angelodiazz/payroll-management-system/badge)](https://securityscorecards.dev/viewer/?uri=github.com/angelodiazz/payroll-management-system)

# Payroll Management System

A C++17 payroll application with a shared business-logic design used by both a Qt graphical interface and a console interface.

The project was created to practice object-oriented programming, runtime polymorphism, templates, lambda expressions, validation, exception handling, and separation between application logic and presentation.

## Features

- Add and remove hourly and salaried employees
- Prevent duplicate employee IDs
- Calculate regular and overtime pay for hourly employees
- Calculate monthly gross pay for salaried employees
- Calculate tax and net pay
- Display individual payroll records
- Calculate total gross and net payroll values
- Use the same employee and payroll concepts from graphical and console interfaces

## Object Model

```text
AbstractEmployee
└── PaidEmployee
    ├── HourlyEmployee
    └── SalariedEmployee

Taxable
├── HourlyEmployee
└── SalariedEmployee
```

`AbstractEmployee` defines the common payroll interface through pure virtual functions.

`HourlyEmployee` and `SalariedEmployee` implement their own gross-pay, tax, net-pay, and employee-type behavior.

The `Taxable` interface provides a separate contract for employee types that expose a tax rate.

## Payroll Calculations

Hourly employees receive:

- Regular pay for up to 40 hours
- Overtime pay at 1.5 times the hourly rate for hours above 40

Salaried employees receive monthly gross pay calculated from their annual salary.

Tax and net-pay values are calculated separately for each employee type.

## Generic Aggregation

`PayrollSystem` includes a generic `total` function template that accepts a callable object.

Gross-pay and net-pay totals reuse the same traversal logic through lambda expressions.

## Interfaces

### Qt Interface

The Qt application provides a graphical desktop interface for interacting with the payroll models.

### Console Interface

The console application provides a text-based interface using the same employee and payroll concepts.

## Technologies

- C++17
- Qt 6 Widgets
- Standard Template Library
- CMake
- Object-oriented programming
- Templates and lambda expressions
- Exception handling

## Project Structure

```text
payroll-management-system/
├── backend/
│   ├── main.cpp
│   ├── employee.h
│   ├── employee.cpp
│   ├── payrollsystem.h
│   ├── payrollsystem.cpp
│   ├── taxable.h
│   ├── exceptions.h
│   ├── ui_console.h
│   ├── ui_console.cpp
│   └── CMakeLists.txt
├── PayrollSystemQt1/
│   ├── main.cpp
│   ├── mainwindow.h
│   ├── mainwindow.cpp
│   ├── mainwindow.ui
│   ├── employee.h
│   ├── employee.cpp
│   ├── payrollsystem.h
│   ├── payrollsystem.cpp
│   └── CMakeLists.txt
└── README.md
```

## Build the Qt Application

Requirements:

- CMake 3.20 or newer
- A C++17-compatible compiler
- Qt 6 Widgets

```bash
cmake -S PayrollSystemQt1 -B build/qt
cmake --build build/qt
./build/qt/PayrollSystemQt
```

## Build the Console Application

```bash
cmake -S backend -B build/cli
cmake --build build/cli
./build/cli/payroll_cli
```
