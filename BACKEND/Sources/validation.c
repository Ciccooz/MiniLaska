#include "..\\Headers\\validation.h"

int isValidMove(int from[], int to[])
{
    return coordinatesWithinBounds(from, to) &&
        movesFromPlayableCell(from) &&
        isSingleMove(from, to);
}

int coordinatesWithinBounds(int from[], int to[])
{
	int validRows = (from[0] >= 0 && from[0] < GRID_SIZE) && (to[0] >= 0 && to[0] < GRID_SIZE);
	int validCols = (from[1] >= 0 && from[1] < GRID_SIZE) && (to[1] >= 0 && to[1] < GRID_SIZE);
	return validRows && validCols;
}

int movesFromPlayableCell(int from[])
{
    return (from[0] % 2) == (from[1] % 2);
}

int isSingleMove(int from[], int to[])
{
    int singleRow = (abs(from[0] - to[0]) == 1);
    int singleCol = (abs(from[1] - to[1]) == 1);
    return singleRow && singleCol;
}
