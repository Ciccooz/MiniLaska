#include "..\\Headers\\errors.h"

int errorFill(int from[], int to[], PlayableBoard board)
{
    int errors = 0;

    if(!coordinatesWithinBounds(from, to)) {
        errors |= OUT_OF_BOUNDS;
        return errors;
    }

    if(!movesFromPlayableCell(from))
        errors |= NOT_PLAYABLE_CELL;

    if(isGoingUp(from, to) && !canGoUp(from, to, board))
        errors |= CANT_GO_UP;

    if(isGoingDown(from, to) && !canGoDown(from, to, board))
        errors |= CANT_GO_DOWN;

    if(isInSamePosition(from, to))
        errors |= NOT_MOVING;

    if(isMovingTooMuch(from, to))
        errors |= MOVING_TOO_MUCH;

    if(isDoubleMove(from, to) && !canConquer(from, to, board))
        errors |= CANT_CONQUER;
    
    if(!topIsNull(to, board))
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