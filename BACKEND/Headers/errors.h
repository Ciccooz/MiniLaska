#pragma once
#include "laskaTypes.h"

/**
*@file 			errors.h
*@brief			All'interno di questo file si trovano i metodi relativi agli errori di input
**/

/******************************DEFINITIONS*********************************/
/**
*@brief 		Errore OUT_OF_BOUNDS
*
*@details		Errore generato dopo aver messo in input delle coordinate
*				al di fuori della griglia.
**/
#define OUT_OF_BOUNDS           0x01

/**
*@brief 		Errore NOT_PLAYABLE_CELL
*
*@details		Errore che si verifica quando le coordinate
*				portano ad una cella che non può mai essere
*				utilizzata.
**/
#define NOT_PLAYABLE_CELL       0x02

/**
*@brief 		Errore NOT_DIAGONAL
*
*@details		Errore che si riscontra quando si prova a muoversi
*				in orizzontale o in verticale.
**/
#define NOT_DIAGONAL            0x04

/**
*@brief 		Errore CANT_GO_UP
*
*@details		Si genera questo errore dopo che l'utente ha provato
*				a muovere verso l'alto una pedina che non può spostarsi in
*				quella direzione.
**/
#define CANT_GO_UP              0x08

/**
*@brief 		Errore CANT_GO_DOWN
*
*@details		Si genera questo errore dopo che l'utente ha provato
*				a muovere verso il basso una pedina che non può spostarsi in
*				quella direzione.
**/
#define CANT_GO_DOWN            0x10

/**
*@brief 		Errore NOT_MOVING
*
*@details		Errore generato quando si cerca di far rimanere ferma una torre.
**/
#define NOT_MOVING              0x20

/**
*@brief 		Errore MOVING_TOO_MUCH
*
*@details		Errore che si verifica quando ci si vuole muovere di più
*				di due posizioni.
**/
#define MOVING_TOO_MUCH         0x40

/**
*@brief 		Errore CANT_CONQUER
*
*@details		Errore che si riscontra quando si cerca di conquistare
*				una torre, ma non è possibile.
**/
#define CANT_CONQUER            0x80

/**
*@brief 		Errore TOP_NOT_NULL
*
*@details		Si genera questo errore quando ci si vuole spostare in una cella
*				non vuota.
**/
#define TOP_NOT_NULL            0x100

/**
*@brief 		Errore NOT_YOUR_PAWN
*
*@details		Errore generato quando l'utente prova a muovere una pedina non sua.
**/
#define NOT_YOUR_PAWN			0x200

/**
*@brief 		Errore MUST_CONQUER
*
*@details		Errore che si verifica quando l'utente cerca di fare un'altra mossa
*				al posto di conquistare una torre.
**/
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
void promptErrors(int errors);
