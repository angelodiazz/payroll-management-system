#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "payrollsystem.h"
#include "employee.h"
#include "exceptions.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    PayrollSystem m_system;   // your backend object

    // setup / helpers
    void setupTable();
    void wireSignals();
    void syncTypeControls();
    void refreshTable();

    // actions
    void addEmployee();
    void removeSelected();
    void showTotals();
};

#endif // MAINWINDOW_H
