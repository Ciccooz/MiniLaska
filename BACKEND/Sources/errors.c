#include "../Headers/errors.h"

int errorFill(int from[2], int to[2], PlayableBoard board)
{
    int errors = 0;
	
	Tower fromTower = UICoordinatesToTower(board, from);
	Tower toTower   = UICoordinatesToTower(board, to);

    if(!coordinatesWithinBounds(from, to)) {
        errors |= OUT_OF_BOUNDS;
        return errors;
    }

    if(!movesFromPlayableCell(from))
        errors |= NOT_PLAYABLE_CELL;

    if(isGoingUp(from, to) && !canGoUp(fromTower))
        errors |= CANT_GO_UP;

    if(isGoingDown(from, to) && !canGoDown(fromTower))
        errors |= CANT_GO_DOWN;

    if(isInSamePosition(from, to))
        errors |= NOT_MOVING;

    if(isMovingTooMuch(from, to))
        errors |= MOVING_TOO_MUCH;

    if(isDoubleMove(from, to) && !canConquer(from, to, board))
        errors |= CANT_CONQUER;

    if(!topIsNull(toTower))
        errors |= TOP_NOT_NULL;

    return errors;
}

void errorCheck(int errors)
{
    if(errors & OUT_OF_BOUNDS)
        printf("out of bounds\n");

    if(errors & NOT_PLAYABLE_CELL)
        printf("not playable cell\n");

    if(errors & CANT_GO_UP)
        printf("cant go up\n");

    if(errors & CANT_GO_DOWN)
        printf("cant go down\n");

    if(errors & NOT_MOVING)
        printf("not moving\n");

    if(errors & MOVING_TOO_MUCH)
        printf("moving too much\n");

    if(errors & CANT_CONQUER)
        printf("cant conquer\n");

    if(errors & TOP_NOT_NULL)
        printf("top not null\n");
}