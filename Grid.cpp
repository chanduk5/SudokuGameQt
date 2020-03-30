#include <QPair>
#include "Grid.h"

// Function set the operational grid
void Grid::setGridInput(QVector<QVector<int>> inputGrid)
{
	//copy the input grid into the operational grid
	this->grid = inputGrid;
}

// Function get the operational grid
QVector<QVector<int>> Grid::getGrid(void)
{
	//copy the input grid into the operational grid
	return this->grid;
}

//Function to set the operational grid size
void Grid::setGridSize(size_t ipGridSize)
{
	// copy the input grid size to operational grid size
	this->gridSize = ipGridSize;
}

//Function to get the grid size
size_t Grid::getGridSize(void)
{
	return gridSize;
}

bool Grid::elementInRow(Grid * gridObj, int eleRow, int key)
{
    // Extract a specified row from the grid.
    QVector<int> gridCurRow(gridObj->grid[eleRow].begin(), grid[eleRow].end());

    // Retrun the matching element status
    return (std::find(gridCurRow.begin(), gridCurRow.end(), key) != gridCurRow.end());
}

// Returns a boolean which indicates whether any assigned entry
// in the specified column matches the given number. 
bool Grid::elementInCol(Grid * gridObj, int eleCol, int key)
{
    for (int row = 0; row < sqrt(gridObj->gridSize); row++)
        if (grid[row][eleCol] == key)
        {
            return true;
        }
    return false;
}

// Returns a boolean which indicates whether any assigned entry
// within the specified 3x3 box matches the given number. 
bool Grid::elementInBox(Grid * gridObj, int box_start_row, int box_start_col, int key)
{
    for (int row = 0; row < 3; row++)
        for (int col = 0; col < 3; col++)
            if (gridObj->grid[row + box_start_row][col + box_start_col] == key)
            {
                return true;
            }
    return false;
}

// Returns a boolean which indicates whether it will be legal to assign
// num to the given row,col location.
bool Grid::placeElementInRowColBox(Grid * gridObj, int eleRow, int eleCol, int element)
{
    // Check if 'num' is not already placed in current row,
    // current column and current 3x3 box 
    return !elementInRow(gridObj, eleRow, element) &&
        !elementInCol(gridObj, eleCol, element) &&
        !elementInBox(gridObj, eleRow - eleRow % 3, eleCol - eleCol % 3, element);
}


// Searches the grid to find an entry that is still unassigned. If
// found, the reference parameters row, col will be set the location
// that is unassigned, and true is returned. If no unassigned entries
// remain, false is returned. 
QPair<size_t, size_t> Grid::get_unassigned_location(Grid * gridObj)
{
    for (size_t row = 0; row < sqrt(gridObj->gridSize); row++)
        for (size_t col = 0; col < sqrt(gridObj->gridSize); col++)
            if (gridObj->grid.at(row).at(col) == gridObj->BLANK)
            {
                return qMakePair(row, col);
            }
    return qMakePair(sqrt(gridObj->gridSize), sqrt(gridObj->gridSize));
}

bool Grid::solve_soduko(void)
{
    size_t size = sqrt(this->getGridSize());

    // Get an unassigned Soduko grid location
    QPair<size_t, size_t> row_and_col = get_unassigned_location(this);

    // If the Soduko grid has been filled, we are done
    if (qMakePair(size, size) == row_and_col)
    {
        return true;
    }

    int eleRow = row_and_col.first;
    int eleCol = row_and_col.second;

    // Consider digits 1 to 9
    for (int element = 1; element <= 9; element++)
    {
        // If placing the current number in the current
        // unassigned location is valid, go ahead
        if (placeElementInRowColBox(this, eleRow, eleCol, element))
        {
            // Make tentative assignment
            this->grid[eleRow][eleCol] = element;

            // Do the same thing again recursively. If we go 
            // through all of the recursions, and in the end 
            // return true, then all of our number placements 
            // on the Soduko grid are valid and we have fully
            // solved it
            if (this->solve_soduko())
            {
                return true;
            }

            // As we were not able to validly go through all 
            // of the recursions, we must have an invalid number
            // placement somewhere. Lets go back and try a 
            // different number for this particular unassigned location
            this->grid[eleRow][eleCol] = BLANK;
        }
    }

    // If we have gone through all possible numbers for the current unassigned
    // location, then we probably assigned a bad number early. Lets backtrack 
    // and try a different number for the previous unassigned locations.
    return false;
}

