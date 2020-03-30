#pragma once
/*******************************************************************************/
/*	InputFile.h															       */
/*******************************************************************************/
#ifndef _INPUTFILE_H
#define _INPUTFILE_H

#include <QMessageBox>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QString>

#include "Grid.h"
#include "SudokuQt_GUI.h"

/*******************************************************************************/
/*	Declaration section	*/
/*******************************************************************************/

class InputFile
{
	QString inputFileName;
public:
	bool importInputFile(SudokuQt_GUI solver, Grid &ipGrid);
	bool checkInputFileValidity(QVector<QVector<int>> input);
	QString getInputFileName(void);
};

#endif

/*******************************************************************************/
/*	End of the Inputfile.h	                                                   */
/*******************************************************************************/

