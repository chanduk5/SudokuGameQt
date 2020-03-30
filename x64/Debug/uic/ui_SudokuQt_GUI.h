/********************************************************************************
** Form generated from reading UI file 'SudokuQt_GUI.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUDOKUQT_GUI_H
#define UI_SUDOKUQT_GUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SudokoSolverClass
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLineEdit *lineEdit;
    QLabel *label;
    QPushButton *pushButton_3;
    QLineEdit *lineEdit_2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *SudokoSolverClass)
    {
        if (SudokoSolverClass->objectName().isEmpty())
            SudokoSolverClass->setObjectName(QString::fromUtf8("SudokoSolverClass"));
        SudokoSolverClass->resize(628, 799);
        SudokoSolverClass->setCursor(QCursor(Qt::ArrowCursor));
        SudokoSolverClass->setFocusPolicy(Qt::ClickFocus);
        centralWidget = new QWidget(SudokoSolverClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(40, 610, 93, 51));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial Black"));
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        pushButton->setFont(font);
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(230, 610, 93, 51));
        pushButton_2->setFont(font);
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(410, 610, 151, 51));
        lineEdit->setFont(font);
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 530, 141, 61));
        label->setFont(font);
        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(470, 540, 93, 41));
        pushButton_3->setFont(font);
        lineEdit_2 = new QLineEdit(centralWidget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(150, 540, 301, 41));
        lineEdit_2->setFont(font);
        SudokoSolverClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(SudokoSolverClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 628, 21));
        SudokoSolverClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(SudokoSolverClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        SudokoSolverClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(SudokoSolverClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        SudokoSolverClass->setStatusBar(statusBar);

        retranslateUi(SudokoSolverClass);

        QMetaObject::connectSlotsByName(SudokoSolverClass);
    } // setupUi

    void retranslateUi(QMainWindow *SudokoSolverClass)
    {
        SudokoSolverClass->setWindowTitle(QCoreApplication::translate("SudokoSolverClass", "SudokoSolver", nullptr));
        pushButton->setText(QCoreApplication::translate("SudokoSolverClass", "Input", nullptr));
        pushButton_2->setText(QCoreApplication::translate("SudokoSolverClass", "Start", nullptr));
        lineEdit->setText(QCoreApplication::translate("SudokoSolverClass", "Run Time: 0 MS", nullptr));
        label->setText(QCoreApplication::translate("SudokoSolverClass", "Out Directory:", nullptr));
        pushButton_3->setText(QCoreApplication::translate("SudokoSolverClass", "Browse", nullptr));
        lineEdit_2->setText(QCoreApplication::translate("SudokoSolverClass", "C://", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SudokoSolverClass: public Ui_SudokoSolverClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUDOKUQT_GUI_H
