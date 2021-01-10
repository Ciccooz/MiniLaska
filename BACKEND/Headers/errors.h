#pragma once
#include "laskaTypes.h"

/**
*@file 			errors.h
*@brief			All'interno di questo file si trovano i metodi relativi agli errori di input
**/

/******************************DEFINITIONS*********************************/
#define OUT_OF_BOUNDS           0x01
#define NOT_PLAYABLE_CELL       0x02
#define NOT_DIAGONAL            0x04
#define CANT_GO_UP              0x08
#define CANT_GO_DOWN            0x10
#define NOT_MOVING              0x20
#define MOVING_TOO_MUCH         0x40
#define CANT_CONQUER            0x80
#define TOP_NOT_NULL            0x100
#define NOT_YOUR_PAWN			0x200
#define MUST_CONQUER			0x400

/********************************METHODS***********************************/
/**
*@brief 			Effettua tutti i controlli dell'input dell'utente
*@details			Nel caso in cui l'utente inserisca un input che genera 
*					errori, in base all'errore generato, si mette in OR un 
*					intero chiamato 'errors', con tutti i bit posti 
*					inizialmente a 0, con la variabile corrispondente 
*					all'errore.
*
*@param	from[2]		Un array con le coordinate della pedina da muovere
*@param	to[2]		Un array contenente le coordinate di destinazione
*@param	board		La matrice contenente tutte le pedine
*@param	oTurn		Indica di chi è il turno 
*
*@return				L'intero 'errors' dichiarato all'inizio del metodo
**/
int errorFill(int from[2], int to[2], PlayableBoard board, int oTurn);

/**
*@brief 				Stampa a video l'errore che si è generato
*@details				La variabile 'errors' viene messa in AND con le variabili che
*						corrispondono ad un certo errore. Se l'AND da come risultato 1,
*						significa che è presente quell'errore e viene stampato a video.
*
*@param	errors			Intero che contiene gli errori
**/
void errorCheck(int errors);