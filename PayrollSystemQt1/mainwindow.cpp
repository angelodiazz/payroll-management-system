#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>
#include <QTableWidgetItem>
#include <QLocale>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow) {
    ui->setupUi(this);

    // Make sure the combo has our two types
    if (ui->cmbType->count() == 0) {
        ui->cmbType->addItem("Hourly");
        ui->cmbType->addItem("Salaried");
    }

    setupTable();
    wireSignals();
    syncTypeControls();
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::setupTable() {
    ui->tableEmployees->setColumnCount(6);
    ui->tableEmployees->setHorizontalHeaderLabels(
        {"Type", "ID", "Name", "Gross", "Tax", "Net"}
        );

    ui->tableEmployees->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableEmployees->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableEmployees->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableEmployees->horizontalHeader()->setStretchLastSection(true);
}

void MainWindow::wireSignals() {
    connect(ui->btnAdd,    &QPushButton::clicked, this, &MainWindow::addEmployee);
    connect(ui->btnRemove, &QPushButton::clicked, this, &MainWindow::removeSelected);
    connect(ui->btnTotals, &QPushButton::clicked, this, &MainWindow::showTotals);
    connect(ui->cmbType,   &QComboBox::currentTextChanged,
            this, &MainWindow::syncTypeControls);
}

void MainWindow::syncTypeControls() {
    const bool isHourly = (ui->cmbType->currentText() == "Hourly");
    ui->spnHours->setVisible(isHourly);
    // If you created labels for hours, you could show/hide them here too.
}

void MainWindow::refreshTable() {
    const auto &list = m_system.employees();     // std::vector<AbstractEmployee*>
    ui->tableEmployees->setRowCount(static_cast<int>(list.size()));

    QLocale loc;

    for (int row = 0; row < static_cast<int>(list.size()); ++row) {
        const AbstractEmployee* e = list[static_cast<size_t>(row)];

        QString type  = QString::fromStdString(e->typeName());
        QString id    = QString::fromStdString(e->id());
        QString name  = QString::fromStdString(e->name());
        QString gross = loc.toString(e->grossPay(),  'f', 2);
        QString tax   = loc.toString(e->taxAmount(), 'f', 2);
        QString net   = loc.toString(e->netPay(),    'f', 2);

        ui->tableEmployees->setItem(row, 0, new QTableWidgetItem(type));
        ui->tableEmployees->setItem(row, 1, new QTableWidgetItem(id));
        ui->tableEmployees->setItem(row, 2, new QTableWidgetItem(name));
        ui->tableEmployees->setItem(row, 3, new QTableWidgetItem(gross));
        ui->tableEmployees->setItem(row, 4, new QTableWidgetItem(tax));
        ui->tableEmployees->setItem(row, 5, new QTableWidgetItem(net));
    }
}

void MainWindow::addEmployee() {
    const QString typeText = ui->cmbType->currentText();
    const std::string id   = ui->txtId->text().trimmed().toStdString();
    const std::string name = ui->txtName->text().trimmed().toStdString();
    const double taxRate   = ui->spnTax->value();

    if (id.empty()) {
        QMessageBox::warning(this, "Input Error", "Employee ID cannot be empty.");
        return;
    }
    if (name.empty()) {
        QMessageBox::warning(this, "Input Error", "Employee name cannot be empty.");
        return;
    }

    try {
        if (typeText == "Hourly") {
            double hourlyRate = ui->spnRate->value();
            double hours      = ui->spnHours->value();

            // HourlyEmployee(id, name, hourlyRate, hoursWorked, taxPercent)
            m_system.addEmployee(
                new HourlyEmployee(id, name, hourlyRate, hours, taxRate)
                );
        } else {
            double annualSalary = ui->spnRate->value();

            // SalariedEmployee(id, name, annualSalary, taxPercent)
            m_system.addEmployee(
                new SalariedEmployee(id, name, annualSalary, taxRate)
                );
        }
    } catch (const InvalidEmployeeException &ex) {
        QMessageBox::warning(this, "Invalid Employee", ex.what());
        return;
    }

    // Clear inputs after successful add
    ui->txtId->clear();
    ui->txtName->clear();
    ui->spnRate->setValue(0.0);
    ui->spnHours->setValue(0.0);
    ui->spnTax->setValue(0.0);

    refreshTable();
}

void MainWindow::removeSelected() {
    int row = ui->tableEmployees->currentRow();
    if (row < 0) {
        QMessageBox::information(this, "Remove", "Select a row to remove.");
        return;
    }

    QTableWidgetItem* idItem = ui->tableEmployees->item(row, 1);
    if (!idItem) {
        QMessageBox::warning(this, "Remove", "Could not read employee ID from table.");
        return;
    }

    const std::string id = idItem->text().toStdString();
    if (!m_system.removeEmployee(id)) {
        QMessageBox::warning(this, "Remove", "Could not remove employee (ID not found).");
        return;
    }

    refreshTable();
}

void MainWindow::showTotals() {
    QLocale loc;
    double gross = m_system.totalGross();
    double net   = m_system.totalNet();

    QString message = QString("Total Gross: $%1\nTotal Net:   $%2")
                          .arg(loc.toString(gross, 'f', 2))
                          .arg(loc.toString(net,   'f', 2));

    QMessageBox::information(this, "Payroll Totals", message);
}
