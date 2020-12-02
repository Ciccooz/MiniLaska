#include "..\\Headers\\validation.h"


int isValidMove(int from[], int to[], PlayableBoard board)
{  
    int errors = errorFill(from, to, board);
    errorCheck(errors);

    return  coordinatesWithinBounds(from, to) &&
            movesFromPlayableCell(from) &&

            ((isGoingUp(from, to) && canGoUp(from, to, board)) ||
            (isGoingDown(from, to) && canGoDown(from, to, board)))  &&

            (isSingleMove(from, to) ||
            (isDoubleMove(from, to) && canConquer(from, to, board))) &&

            topIsNull(to, board);
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

int isGoingUp(int from[], int to[])
{
    return from[0] > to[0];
}

int isGoingDown(int from[], int to[])
{
    return from[0] < to[0];
}

int canGoUp(int from[], int to[], PlayableBoard board)
{
    /*
    int isGoingUp = from[0] > to[0];

    if(isGoingUp)
    */
    return getTop(from, board) != SOLDIER1;
}

int canGoDown(int from[], int to[], PlayableBoard board)
{
    /*
    int isGoingDown = from[0] > to[0];

    if(isGoingDown)
    */
    return getTop(from, board) != SOLDIER2;
}

int isInSamePosition(int from[], int to[])
{
    int row = abs(from[0] - to[0]);
    int col = abs(from[1] - to[1]);

    int movingRow = row == 0;
    int movingCol = col == 0;

    return movingRow && movingCol;
}

int isMovingTooMuch(int from[], int to[])
{
    int row = abs(from[0] - to[0]);
    int col = abs(from[1] - to[1]);

    int movingRow = (row > 2);
    int movingCol = (col > 2);

    return movingRow || movingCol;
}

int isSingleMove(int from[], int to[])
{
    int singleRow = (abs(from[0] - to[0]) == 1);
    int singleCol = (abs(from[1] - to[1]) == 1);
    return singleRow && singleCol;
}

int isDoubleMove(int from[], int to[])
{
    int doubleRow = (abs(from[0] - to[0]) == 2);
    int doubleCol = (abs(from[1] - to[1]) == 2);
    return doubleRow && doubleCol;
}

int topIsNull(int from[], PlayableBoard board)
{
    return getTop(from, board) == NULL_PAWN;
}

int canConquer(int from[], int to[], PlayableBoard board)
{
    int row = to[0];
    int col = to[1];
    int previous[2];
    
    char fromTop = getTop(from, board);
    char previousTop;

    if(from[0] > to[0])
        row--;
    else
        row++;

    if(from[1] > to[1])
        col--;
    else
        col++;

    previous[0] = row;
    previous[1] = col;
    previousTop = getTop(previous, board);

    return (fromTop == SOLDIER1 || fromTop == OFFICER1) &&
           (previousTop == SOLDIER2 || previousTop == OFFICER2) ||
           (fromTop == SOLDIER2 || fromTop == OFFICER2) &&
           (previousTop == SOLDIER1 || previousTop == OFFICER1);
}