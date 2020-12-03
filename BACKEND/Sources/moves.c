#include "../Headers/moves.h"


void move(PlayableBoard board, unsigned int from[2], unsigned int to[2])
{
    Tower fromTower = UICoordinatesToTower(board, from);

    if(isDoubleMove(from, to))
        conquer(getMidTower(from, to), fromTower); /*nome della funzione?*/

    deepCopy(toTower, fromTower);
    clearCell(fromTower);
}



static void conquer(Tower conquered, Tower conquerer)
{
    Pawn conqueredTop = getTop(conquered);

    if(conquerer[TOWER_HEIGHT - 1] == NULL_PAWN) /*non piena*/
    {
        int i;
        for(i = TOWER_HEIGHT - 1; i > 0; i--)
            conquerer[i] = conquerer[i - 1];
        conquerer[0] = conqueredTop;
    }
    changeTop(conquered, NULL_PAWN);
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
