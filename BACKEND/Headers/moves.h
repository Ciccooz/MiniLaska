#pragma once
#include "laskaTypes.h"

/**
*@file 			moves.h
*@brief			File contenente i metodi per effettuare una mossa
**/

/********************************METHODS***********************************/
/**
*@brief 				Muove la pedina (o la torre)
*@details 				Seleziona la pedina (o la torre) nella cella 
*						indicata dall'utente e la muove nella cella scelta.
*
*@param	board 			La matrice contenente tutte le pedine
*@param	UIFrom[2] 		Un array con le coordinate da cui muovere la pedina
*@param	UITo[2] 		Un array che contiene le coordinatedi destinazione.
**/
void move(PlayableBoard board, int UIFrom[2], int UITo[2]);

/**
*@brief 				Conquista una pedina
*@details				Nello specifico prende la pedina che controlla una 
*						torre e la conquista, ovvero la conquista e la 
*						tiene alla base della torre.
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