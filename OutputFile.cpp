#include <QDateTime>
#include "OutputFile.h"

#if 1
//Export the output file to specified location
bool OutputFile::exportOutputFile(SudokuQt_GUI solver, Grid& ipGrid)
{
	//QString filepath = 
	QString filename = QString("C://Output_SudokuSolver++.csv").arg(QDateTime::currentDateTime().toString("ddMMyyyy-hh_mm_ss"));
	return 0;
}
#endif`																						