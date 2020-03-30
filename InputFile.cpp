/*******************************************************************************/
/*	InputFile.cpp															   */
/*******************************************************************************/

/*******************************************************************************/
/*	Includes section	*/
/*******************************************************************************/

#include "InputFile.h"

/*******************************************************************************/
/*	Declaration section	*/
/*******************************************************************************/

/*******************************************************************************/
/*	Defination section	*/
/*******************************************************************************/

/*******************************************************************************/
/*	Function to check input file validity	*/
/*******************************************************************************/

bool InputFile::checkInputFileValidity(QVector<QVector<int>> input)
{
	//check for the rows and coloums are equal in size
	if (input.size() != input[0].size())
	{
		return false;
	}

	//Check for the input validity
	for (auto& eleVec : input)
	{
		for (auto& ele : eleVec)
		{
			if (!((ele >= 0) && (ele <= input.size())))
			{
				return false;
			}
		}
	}
	return true;
}

/*******************************************************************************/
/*	Function to import input file and extract the data,											   */
/*  check for the validity and forward to the grid							   */
/*******************************************************************************/

bool InputFile::importInputFile(SudokuQt_GUI solver, Grid &ipGrid)
{
	// data variable to fill input grid
	QVector<QVector<int>> fillInputGrid;
	size_t row = 0, col = 0, lastCycleCol = 0;

	// filter the file fomats
	QString filter = "CSV(*.csv);; All File(*.*)";

	//fill the default input file path
	static QString filePath = "C://";

	//Get the file name
	QString fileName = QFileDialog::getOpenFileName(&solver, "Open Input File", filePath, filter);
	
	//Get the directory name
	QDir dir = QFileInfo(fileName).absoluteDir();

	//Get the file path
	filePath = dir.absolutePath();

	//Get the file name
	inputFileName = QFileInfo(fileName).fileName();

	//Assign the file name
	QFile file(fileName);

	// open the file
	if (file.open(QFile::ReadOnly | QFile::Text))
	{
		//Assgin the file to get the text stream
		QTextStream in(&file);

		//Check for the end
		while (!in.atEnd())
		{
			//Read the each line in the file
			QString line = in.readLine();

			//Reset the column 
			col = 0;

			//Resize the Input Grid
			fillInputGrid.resize(row + 1);

			// Traverse across the index from 0 to line size
			for (auto index = 0; index < line.size(); index++)
			{
				//Elementating the ',' and ' '
				if ((line.at(index) != ',') && (line.at(index) != ' '))
				{
					//Resize the Input Grid vector according to coloumn size
					fillInputGrid[row].resize(col + 1);

					//Fill the Input Grid vector
					fillInputGrid[row][col] = line[index].digitValue();
					// Increase the column 
					col++;
				}
			}

			// Check for the input file validity
			//Last cycle line columns not equal to '0'
			//Present cycle line columns not equal to '0'
			//Last cycle line columns not equal to present cycle columns.
			if (((lastCycleCol != 0)  && (col != 0)) && (lastCycleCol != col))
			{
				return false;
			}

			//Assign the present cycle col to last cycle col
			lastCycleCol = col;

			//Increse the no of rows
			row += (col != 0) ? 1 : 0;
		}
		
		//Check for the input grid validity
		if (!checkInputFileValidity(fillInputGrid))
		{
			return false;
		}

		//Set the input grid
		ipGrid.setGridInput(fillInputGrid);

		//set the input grid size
		ipGrid.setGridSize(row * col);
	}
	else
	{
		// Pop up with the warning, if input file cannot open
		QMessageBox::warning(&solver, "Sudoku Solver++", "file cannot open");
	}
	return true;
}

/*******************************************************************************/
/*	Function to get the input file name										   */
/*******************************************************************************/

QString InputFile::getInputFileName(void)
{
	return inputFileName;
}

/*******************************************************************************/
/*	End of the Inputfile.cpp	                                               */
/*******************************************************************************/