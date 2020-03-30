#pragma once
#include <QString>
#include "Grid.h"
#include "SudokuQt_GUI.h"

class OutputFile
{
public: 
	bool exportOutputFile(SudokuQt_GUI solver, Grid& ipGrid);
};

