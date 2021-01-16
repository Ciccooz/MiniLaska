#pragma once
#include "laskaTypes.h"

/**
*@file 			moves.h
*@brief			File contenente i metodi per effettuare una mossa
**/

/********************************METHODS***********************************/
/**
*@brief 				Muove una torre
*@details 				Seleziona la torre nella cella indicata
*						dall'utente e la muove nella cella scelta.
*
*@param	board 			La matrice contenente tutte le pedine
*@param	UIFrom[2] 		Un array con le coordinate da cui muovere la pedina
*@param	UITo[2] 		Un array che contiene le coordinatedi destinazione
**/
void move(PlayableBoard board, int UIFrom[2], int UITo[2]);

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
