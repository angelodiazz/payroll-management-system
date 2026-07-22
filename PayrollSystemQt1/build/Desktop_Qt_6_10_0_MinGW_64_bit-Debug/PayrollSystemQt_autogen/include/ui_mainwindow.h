/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QComboBox *cmbType;
    QLineEdit *txtId;
    QLineEdit *txtName;
    QDoubleSpinBox *spnRate;
    QDoubleSpinBox *spnHours;
    QDoubleSpinBox *spnTax;
    QPushButton *btnAdd;
    QPushButton *btnRemove;
    QPushButton *btnTotals;
    QTableWidget *tableEmployees;
    QTextBrowser *textBrowser_2;
    QTextBrowser *textBrowser;
    QMenuBar *menubar;
    QMenu *menuPayroll_Management_System;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->setEnabled(true);
        MainWindow->resize(1920, 1123);
        MainWindow->setMinimumSize(QSize(800, 600));
        MainWindow->setMaximumSize(QSize(1920, 1123));
        MainWindow->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        MainWindow->setAutoFillBackground(false);
        MainWindow->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonIconOnly);
        MainWindow->setDocumentMode(false);
        MainWindow->setTabShape(QTabWidget::TabShape::Rounded);
        MainWindow->setDockNestingEnabled(false);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setMinimumSize(QSize(1920, 1080));
        centralwidget->setMaximumSize(QSize(1920, 1080));
        centralwidget->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        cmbType = new QComboBox(centralwidget);
        cmbType->addItem(QString());
        cmbType->addItem(QString());
        cmbType->setObjectName("cmbType");
        cmbType->setGeometry(QRect(890, 290, 91, 41));
        txtId = new QLineEdit(centralwidget);
        txtId->setObjectName("txtId");
        txtId->setGeometry(QRect(230, 260, 113, 20));
        txtName = new QLineEdit(centralwidget);
        txtName->setObjectName("txtName");
        txtName->setGeometry(QRect(230, 280, 113, 20));
        spnRate = new QDoubleSpinBox(centralwidget);
        spnRate->setObjectName("spnRate");
        spnRate->setGeometry(QRect(890, 460, 91, 41));
        spnRate->setMaximum(1000000.000000000000000);
        spnHours = new QDoubleSpinBox(centralwidget);
        spnHours->setObjectName("spnHours");
        spnHours->setGeometry(QRect(890, 360, 91, 31));
        spnHours->setMaximum(500.000000000000000);
        spnTax = new QDoubleSpinBox(centralwidget);
        spnTax->setObjectName("spnTax");
        spnTax->setGeometry(QRect(890, 410, 91, 31));
        spnTax->setMaximum(100.000000000000000);
        btnAdd = new QPushButton(centralwidget);
        btnAdd->setObjectName("btnAdd");
        btnAdd->setGeometry(QRect(60, 260, 141, 41));
        btnRemove = new QPushButton(centralwidget);
        btnRemove->setObjectName("btnRemove");
        btnRemove->setGeometry(QRect(390, 260, 141, 41));
        btnTotals = new QPushButton(centralwidget);
        btnTotals->setObjectName("btnTotals");
        btnTotals->setGeometry(QRect(660, 260, 141, 41));
        tableEmployees = new QTableWidget(centralwidget);
        if (tableEmployees->columnCount() < 6)
            tableEmployees->setColumnCount(6);
        tableEmployees->setObjectName("tableEmployees");
        tableEmployees->setGeometry(QRect(40, 320, 781, 201));
        tableEmployees->setColumnCount(6);
        tableEmployees->horizontalHeader()->setDefaultSectionSize(120);
        textBrowser_2 = new QTextBrowser(centralwidget);
        textBrowser_2->setObjectName("textBrowser_2");
        textBrowser_2->setGeometry(QRect(840, 340, 181, 181));
        textBrowser = new QTextBrowser(centralwidget);
        textBrowser->setObjectName("textBrowser");
        textBrowser->setGeometry(QRect(10, 10, 1261, 231));
        textBrowser->setFrameShape(QFrame::Shape::Box);
        MainWindow->setCentralWidget(centralwidget);
        textBrowser_2->raise();
        cmbType->raise();
        txtId->raise();
        txtName->raise();
        spnRate->raise();
        spnHours->raise();
        spnTax->raise();
        btnAdd->raise();
        btnRemove->raise();
        btnTotals->raise();
        tableEmployees->raise();
        textBrowser->raise();
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1920, 21));
        menubar->setMaximumSize(QSize(1920, 1080));
        menubar->setBaseSize(QSize(500, 600));
        menuPayroll_Management_System = new QMenu(menubar);
        menuPayroll_Management_System->setObjectName("menuPayroll_Management_System");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuPayroll_Management_System->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Payroll Management System", nullptr));
        cmbType->setItemText(0, QCoreApplication::translate("MainWindow", "Hourly", nullptr));
        cmbType->setItemText(1, QCoreApplication::translate("MainWindow", "Salaried", nullptr));

        txtId->setText(QString());
        txtId->setPlaceholderText(QCoreApplication::translate("MainWindow", "Employee ID", nullptr));
        txtName->setPlaceholderText(QCoreApplication::translate("MainWindow", "Employee Name", nullptr));
        btnAdd->setText(QCoreApplication::translate("MainWindow", "Add Employee", nullptr));
        btnRemove->setText(QCoreApplication::translate("MainWindow", "Remove Selected", nullptr));
        btnTotals->setText(QCoreApplication::translate("MainWindow", "Show Totals", nullptr));
        textBrowser_2->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:700;\">Hours:</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-weight:700;\"><br /></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /><"
                        "/p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:700;\">Tax Rate(%):</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-weight:700;\"><br /></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:700;\">Hours Worked:</span></p></body></html>", nullptr));
        textBrowser->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:24pt; font-style:italic;\">PAYROLL MANAGEMENT SYSTEM</span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt; font-style:italic;\">By: Angelo Diaz, Juan Diego Llinas, Alexander Brodie</span></p></body></html>", nullptr));
        menuPayroll_Management_System->setTitle(QCoreApplication::translate("MainWindow", "Payroll Management System", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
