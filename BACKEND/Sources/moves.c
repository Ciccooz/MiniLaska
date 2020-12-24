#include "../Headers/moves.h"

#include <string.h>
#include "../../UI/Headers/laskaBoard.h"
#include "../Headers/playableBoard.h"
#include "../Headers/rules.h"
#include "../Headers/tower.h"

void move(PlayableBoard board, int UIFrom[2], int UITo[2])
{
    Tower fromTower = UICoordinatesToTower(board, UIFrom);

    if(isDoubleMove(UIFrom, UITo))
        conquer(getTowerInBetween(board, UIFrom, UITo), fromTower);

    deepCopy(UICoordinatesToTower(board, UITo), fromTower);
    clearCell(fromTower);
}



static void conquer(Tower conquered, Tower conquerer)
{
    Pawn conqueredTop = getTop(conquered);

    if(conquerer[TOWER_HEIGHT - 1] == NULL_PAWN) /*conquerer non pieno*/
    {
        int i;
        for(i = TOWER_HEIGHT - 1; i > 0; i--) /*shifto tutte le pawn in su di una posizione*/
            conquerer[i] = conquerer[i - 1];
        conquerer[0] = conqueredTop; /*aggiungo il top conquistato alla base*/
    }
    changeTop(conquered, NULL_PAWN); /*rimuovo il top conquistato*/
}

static void deepCopy(Tower destination, Tower source)
{
    int i;
    for(i = 0; i < TOWER_HEIGHT; i++)
        destination[i] = source[i];
}
static void clearCell(Tower tower)
{
    memset(tower, NULL_PAWN, TOWER_HEIGHT * sizeof(char));
}
