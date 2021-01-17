#include "../Headers/errors.h"

#include <stdio.h>
#include "../Headers/validation.h"
#include "../../UI/Headers/laskaBoard.h"


int errorFill(int from[2], int to[2], PlayableBoard board, int player)
{
    int errors = 0;

    Tower fromTower;
    Tower toTower;

    if(!coordinatesWithinBounds(from, to)) {
        errors |= OUT_OF_BOUNDS;
        return errors;
    }

    fromTower = UICoordinatesToTower(board, from);
    toTower = UICoordinatesToTower(board, to);

    if(!movesFromPlayableCell(from))
        errors |= NOT_PLAYABLE_CELL;

    if(!movesDiagonally(from, to))
        errors |= NOT_DIAGONAL;

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

	if(!isYourPawn(from, board, player))
		errors |= NOT_YOUR_PAWN;

	if(isSingleMove(from, to) && mustConquer(board, player))
		errors |= MUST_CONQUER;

    return errors;
}
void promptErrors(int errors)
{
    if(!errors)
      return;

    printf("Invalid move:\n");

    if(errors & OUT_OF_BOUNDS)
        printf("\tCoordinates are out of bounds\n");

    if(errors & NOT_PLAYABLE_CELL)
        printf("\tStarting position is not a playable cell\n");

    if(errors & CANT_GO_UP)
        printf("\tThat pawn cannot move up\n");

    if(errors & CANT_GO_DOWN)
        printf("\tThat pawn cannot move down\n");

    if(errors & NOT_MOVING)
        printf("\tYou have to make a move\n");

    if(errors & MOVING_TOO_MUCH)
        printf("\tYou cannot move that far\n");

    if(errors & CANT_CONQUER)
        printf("\tYou cannot conquer that pawn\n");

    if(errors & TOP_NOT_NULL)
        printf("top not null\n");

	if(errors & NOT_YOUR_PAWN)
		printf("not your pawn\n");

	if(errors & MUST_CONQUER)
		printf("must conquer\n");
}
