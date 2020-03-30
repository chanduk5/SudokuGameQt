#pragma once

#include <QtWidgets/QMainWindow>
#include <QPainter>
#include <QPushButton>
#include <QString>
#include <QMessageBox>

#include <QtWidgets/QMainWindow>
#include "ui_SudokuQt_GUI.h"

class SudokuQt_GUI : public QMainWindow
{
	Q_OBJECT

public:
	SudokuQt_GUI(QWidget *parent = Q_NULLPTR);

private:
	Ui::SudokoSolverClass ui;
private slots:
	void on_pushButton_clicked(void);
	void on_pushButton_2_clicked(void);
	void on_pushButton_3_clicked(void);
protected:
	//define the method of base class
	void paintEvent(QPaintEvent* event);
};
