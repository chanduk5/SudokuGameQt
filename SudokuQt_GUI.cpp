#include <QTimer>
#include <QtCore\qelapsedtimer.h>
#include <QDateTime>

#include "InputFile.h"
#include "SudokuQt_GUI.h"

static Grid sudokuGrid;
static InputFile ipfile;
static QString outputFilePath(Ui::SudokoSolverClass* ui);

SudokuQt_GUI::SudokuQt_GUI(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
}

// function to call when input pushbutton is clicked
void SudokuQt_GUI::on_pushButton_clicked(void)
{
	SudokuQt_GUI solver;
	if (ipfile.importInputFile(&solver, sudokuGrid))
	{
		update();
	}
	else
	{
		QMessageBox::critical(this, "Sudoku Solver++", "Input file is invalid\n");
	}
}

// function to call when input pushbutton is clicked
void SudokuQt_GUI::on_pushButton_2_clicked(void)
{
	QString runTime;
	QElapsedTimer timer;

	// Get output file path and file name
	QString outFilePath = outputFilePath(&ui);

	QMessageBox msgBox;// = QMessageBox(QMessageBox::Information, "Error", "Processing ... ", 0, 0, Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
	msgBox.setIcon(QMessageBox::Information);
	msgBox.setWindowTitle("Sudoku solver++");
	msgBox.setText("Name");
	msgBox.setStandardButtons(0);
	msgBox.setCursor(Qt::WaitCursor);
	msgBox.setStyleSheet("background-color:#444;color:#FFF;outline:none;");
	msgBox.show();

	//msgInfo.setIcon(QMessageBox::Information);
	//msgInfo.setWindowTitle("Sudoku solver++");
	//msgInfo.setText("Name");
	//msgInfo.setInformativeText("Do you want to save your changes?");
	//msgInfo.setStandardButtons(QMessageBox::Ok |
		//QMessageBox::Cancel);
	//msgBox.setDefaultButton(QMessageBox::Save);


	//msgInfo->setWindowTitle("Sudoku solver++");
	
	//msgInfo->setText("Waiting");
	//msgInfo->setWindowModality(Qt::ApplicationModal);
	//msgInfo.show();

	//Sudoku Solver application running window
	//QMessageBox::information(this, "Sudoku Solver++", "Sudoku algorithm running\n");

	// start the timer
	timer.start();

	if (true == sudokuGrid.solve_soduko())
	{
		update();
		runTime.append("Run Time: " + QString::number(timer.elapsed()) + " MS");
		ui.lineEdit->setText(runTime);

		//creating and exporting the output file
		QString outFileName = QString(outFilePath).arg(QDateTime::currentDateTime().toString("ddMMyyyy-hh_mm_ss"));
		QFile outFile(outFileName);

		if (outFile.open(QIODevice::WriteOnly))
		{
			QTextStream stream(&outFile);
			QVector<QVector<int>> outData = sudokuGrid.getGrid();

			for (auto& eleVec : outData)
			{
				for (auto& ele : eleVec)
				{
					stream << ele << ",";
				}
				stream << endl;
			}
		}
		outFile.close();
		msgBox.close();
	}
	else
	{
		//this->close();
		//msgInfo.setIcon(QMessageBox::Critical);
		//msgInfo.setText("Name");
		QMessageBox::critical(this, "Sudoku Solver++", "sudoku is unsolvable\n");
	}
}

// function to call when input pushbutton is clicked
void SudokuQt_GUI::on_pushButton_3_clicked(void)
{
	SudokuQt_GUI solver;
	static QString prevFilePath = "C://";
	QString filePath = ui.lineEdit_2->text();
	filePath = QFileDialog::getExistingDirectory(&solver, "Open Output File", filePath);
	filePath = (filePath != 0) ? filePath : prevFilePath;
	prevFilePath = filePath;
	ui.lineEdit_2->setText(filePath);
}

// function to draw the sudoku grid
void SudokuQt_GUI::paintEvent(QPaintEvent* event)
{
	Q_UNUSED(event);

	//create Qpainter object
	QPainter painter(this);

	//set the pen and brush
	painter.setPen(QPen(Qt::black, 1, Qt::SolidLine, Qt::FlatCap));
	painter.setBrush(QBrush(Qt::cyan, Qt::SolidPattern));
	painter.setFont(QFont("Arial Black", 20, QFont::ExtraBold));

	QVector<QVector<int>> IpGrid = sudokuGrid.getGrid();
	size_t gridSize = sudokuGrid.getGridSize();
	QRectF* rectrangle_Cnt = new QRectF[gridSize];

	for (short row = 0; row < sqrt(gridSize); row++)
	{
		for (short col = 0; col < sqrt(gridSize); col++)
		{
			rectrangle_Cnt[col].setRect((100 + (row * 50)), (50 + (col * 50)), 50, 50);
			painter.drawRect(rectrangle_Cnt[col]);
			if (IpGrid.at(col).at(row) != 0)
			{
				painter.drawText(rectrangle_Cnt[col], Qt::AlignCenter | Qt::AlignVCenter, QVariant(IpGrid.at(col).at(row)).toString());
			}
		}
	}
}

static QString outputFilePath(Ui::SudokoSolverClass* ui)
{
	QString outputFile = ui->lineEdit_2->text();
	QString fileName = ipfile.getInputFileName();

	outputFile = (outputFile + "/Sudoku_Puzzle_output#");
	outputFile.append(fileName.split('#').last());

	return outputFile;

}
