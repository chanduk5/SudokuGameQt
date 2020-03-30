#include "SudokuQt_GUI.h"
#include <QtWidgets/QApplication>
#include <QFileDialog>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	SudokuQt_GUI w;
	w.show();
	return a.exec();
}
