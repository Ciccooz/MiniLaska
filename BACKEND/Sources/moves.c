#include "../Headers/moves.h"

#include <string.h>
#include "../../UI/Headers/laskaBoard.h"
#include "../Headers/playableBoard.h"
#include "../Headers/rules.h"
#include "../Headers/tower.h"

/**
*@brief 				Conquista una pedina
*@details				Nello specifico prende la pedina che controlla la
*						torre da conquistare e la mette alla base della
*						torre che ha effettuato la conquista.
*
*@param	conquered 		La torre che viene conquistata
*@param	conquerer 		La torre che effettua la conquista.
**/
static void conquer(Tower conquered, Tower conquerer);
/**
*@brief 				Sovrascrive una torre al posto di un'altra
*
*@param	destination 	La torre che viene sovrascritta
*@param	source			La torre che prenderà il posto dell'altra
**/
static void deepCopy(Tower destination, Tower source);
/**
*@brief 				Cancella una torre
*
*@param	tower			La torre da cancellare
**/
static void clearCell(Tower tower);
/**
*@brief			Controlla se è necessario promuovere una pedina
*@details		Se una torre raggiunge il lato opposto del campo,
*				allora deve essere promossa. Quindi viene chiamato
*				il metodo promote(), passando come parametro la
*				torre da promuovere.
*
*@param board 	La matrice contenente tutte le pedine
*@param UITo[2] Un array contenente le coordinate di destinazione
**/
static void checkPromotion(PlayableBoard board, int UITo[2]);



void move(PlayableBoard board, int UIFrom[2], int UITo[2])
{
	Tower fromTower = UICoordinatesToTower(board, UIFrom);

	if(isDoubleMove(UIFrom, UITo))
		conquer(getTowerInBetween(board, UIFrom, UITo), fromTower);

	deepCopy(UICoordinatesToTower(board, UITo), fromTower);
	clearCell(fromTower);
	checkPromotion(board, UITo);
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
static void checkPromotion(PlayableBoard board, int UITo[2])
{
	Tower promoted = UICoordinatesToTower(board, UITo);
	Pawn promotedTop = getTop(promoted);

	if((UITo[0] == 6 && promotedTop == SOLDIER1) || (UITo[0] == 0 && promotedTop == SOLDIER1))
		if(promotedTop != OFFICER0 || promotedTop != OFFICER1)
			promote(promoted);
}
