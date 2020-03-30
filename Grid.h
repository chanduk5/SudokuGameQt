#pragma once
#include <QVector>

//class to declare the member and methods of the grid.
class Grid
{
private:
	QVector<QVector<int>> grid;	//member to hold the entire grid
	size_t gridSize;
	const short BLANK;
	bool elementInRow(Grid * gridObj, int eleRow, int key);
	bool elementInCol(Grid * gridObj, int col, int num);
	bool elementInBox(Grid * gridObj, int box_start_row, int box_start_col, int key);
	QPair<size_t, size_t> get_unassigned_location(Grid * gridObj);
	bool placeElementInRowColBox(Grid * gridObj, int row, int col, int num);

public:
	//Grid default constructor
	Grid() : grid(0), gridSize(0), BLANK(0){}

	void setGridInput(QVector<QVector<int>> inputGrid);
	QVector<QVector<int>> getGrid(void);
	void setGridSize(size_t ipGridSize);
	size_t getGridSize(void);
	bool solve_soduko(void);
};

