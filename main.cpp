#include "payrollsystem.h"
#include "ui_console.h"

int main() {
    PayrollSystem system;
    ConsoleUI ui(system);
    ui.run();
    return 0;
}
