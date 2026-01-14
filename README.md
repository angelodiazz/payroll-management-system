# Payroll Management System (C++ / Qt6)

An enterprise-grade payroll processing engine featuring a dual-interface architecture (Qt GUI + Console CLI) and a polymorphic calculation core. This project demonstrates advanced Object-Oriented Design patterns, including **Multiple Inheritance**, **Abstract Base Classes**, and **Functional Template Logic**.

---

## 🚀 Key Engineering Features
* **Polymorphic Logic Engine**: Architected a scalable class hierarchy (`AbstractEmployee` → `PaidEmployee` → `Hourly`/`Salaried`) utilizing **pure virtual functions** to enforce contract compliance for pay calculation across disparate employee types.
* **Dual-Head Architecture**: Decoupled the business logic (`PayrollSystem`) from the presentation layer, enabling the same C++ backend to power both a rich **Qt6 Desktop GUI** and a lightweight **Console CLI** without code duplication.
* **Functional Template Integration**: Implemented a generic `total<Func>` template method using **Lambda expressions** to perform arbitrary aggregations (Gross vs. Net pay) dynamically at runtime, reducing boilerplate iteration logic.
* **Robust Error Handling**: Integrated a custom exception hierarchy (`InvalidEmployeeException`) to enforce business rules (e.g., non-negative hours, duplicate ID prevention) before state mutation occurs.

---

## 🛡 Security & Defensive Design
* **Memory Management**: Utilized `std::vector` of pointers for polymorphic storage while implementing strict destructors to prevent memory leaks during employee removal and system shutdown.
* **Input Validation**: Enforced strict bounds checking on tax rates (0-100%) and hours worked within the constructor logic, ensuring the system state remains valid regardless of UI input method.
* **Interface Segregation**: Applied the **Interface Segregation Principle** by creating a pure abstract `Taxable` interface, allowing non-employee entities to potentially interact with the tax calculation module in future expansions.

---

## 🛠 Tech Stack
| Category | Technologies |
| :--- | :--- |
| **Language** | C++17 |
| **Frameworks** | Qt 6 (Widgets Module) |
| **Design Patterns** | Strategy, Template Method, MVC (Model-View-Controller) |
| **Build System** | CMake |

---

## 📂 Project Structure
```text
payroll-system/
├── backend/                # Core Business Logic (Shared Library)
│   ├── employee.h/cpp      # Polymorphic Employee Hierarchy
│   ├── payrollsystem.h/cpp # System Controller & Aggregation Logic
│   ├── taxable.h           # Pure Abstract Interface
│   └── exceptions.h        # Custom Error Handling
├── PayrollSystemQt1/       # Presentation Layer (GUI)
│   ├── mainwindow.h/cpp    # Qt Widget Controller
│   └── mainwindow.ui       # XML Layout Definition
└── ui_console/             # Presentation Layer (CLI)
    └── ui_console.h/cpp    # Text-based Interface
```

## 🚀 Build & Run

### Option 1: Qt GUI (Recommended)
Ensure you have **Qt 6** and **CMake** installed.

```bash
# Configure the Qt project
cmake -S PayrollSystemQt1 -B build_gui

# Build the GUI executable
cmake --build build_gui

# Run
./build_gui/PayrollSystemQt
```

### Option 2: Console Backend
Ensure you have **Qt 6** and **CMake** installed.

```bash
# Configure the Console project
cmake -S backend -B build_console

# Build the CLI executable
cmake --build build_console

# Run
./build_console/Project
