cmake_minimum_required(VERSION 3.20)

project(PayrollSystemCLI LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(payroll_cli
        main.cpp
        employee.cpp
        payrollsystem.cpp
        ui_console.cpp
)

target_include_directories(payroll_cli
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
)