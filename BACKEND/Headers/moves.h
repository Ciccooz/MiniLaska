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