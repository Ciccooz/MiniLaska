#pragma once
#include "laskaTypes.h"

/**
*@file 			validation.h
*@brief			File nella quale si trovano tutti i controlli da effettuare su un input
**/

/********************************METHODS***********************************/
/**
*@brief 				Chiama il metodo errorFill()
*
*@param	from[2]			Un array con le coordinate della pedina da muovere
*@param	to[2]			Un array contenente le coordinate di destinazione
*@param	board			La matrice contenente tutte le pedine
*@param	oTurn			Indica di chi è il turno
*
*@return				errors, ottenuto dal metodo errorFill()
**/
int isValidMove(int from[2], int to[2], PlayableBoard board, int oTurn);
/**
*@brief 				Controlla se le coordinate sono interne alla griglia
*
*@param	from[2]			Un array con le coordinate della pedina da muovere
*@param	to[2]			Un array contenente le coordinate di destinazione
**/
int coordinatesWithinBounds(int from[2], int to[2]);
/**
*@brief 				Controlla che la posizione di partenza sia giocabile
*@details				Si fa questo controllo perchè ci sono delle celle
*						che non verranno mai utilizzate.
*
*@param	from[2]			Un array con le coordinate della pedina da muovere
**/
int movesFromPlayableCell(int from[2]);
/**
*@brief 				Controlla che il movimento sia effettuato in diagonale
*@details				Viene effettuato questo controllo dato che ci si può
*						muovere solo in diagonale.
*
*@param	from[2]			Un array con le coordinate della pedina da muovere
*@param	to[2]			Un array contenente le coordinate di destinazione
**/
int movesDiagonally(int from[2], int to[2]);
/**
*@brief 				Controlla se ci si vuole spostare verso l'alto
*
*@param	from[2]			Un array con le coordinate della pedina da muovere
*@param	to[2]			Un array contenente le coordinate di destinazione
**/
int isGoingUp(int from[2], int to[2]);
/**
*@brief 				Controlla se ci si vuole spostare verso il basso
*
*@param	from[2]			Un array con le coordinate della pedina da muovere
*@param	to[2]			Un array contenente le coordinate di destinazione
**/
int isGoingDown(int from[2], int to[2]);
/**
*@brief 				Controlla se la torre si può spostare in alto
*@details				Ricava la pedina che comanda la torre utilizzando il
*						metodo getTop(), e controlla se è diversa da SOLDIER0,
*						dato che è l'unica pedina che non si può muovere verso l'alto.
*
*@param	tower			La torre da controllare
**/
int canGoUp(Tower tower);
/**
*@brief 				Controlla se la torre si può spostare in basso
*@details				Ricava la pedina che comanda la torre utilizzando il
*						metodo getTop(), e controlla se è diversa da SOLDIER1,
*						perchè è l'unica pedina che non si può muovere verso il basso.
*
*@param tower			La torre da controllare
**/
int canGoDown(Tower tower);
/**
*@brief 				Controlla se si vuole far rimanere ferma la torre
*
*@param	from[2]			Un array con le coordinate della pedina da muovere
*@param	to[2]			Un array contenente le coordinate di destinazione
**/
int isInSamePosition(int from[2], int to[2]);
/**
*@brief 				Controlla se si cerca di muovere di troppo una torre
*
*@param	from[2]			Un array con le coordinate della pedina da muovere
*@param	to[2]			Un array contenente le coordinate di destinazione
**/
int isMovingTooMuch(int from[2], int to[2]);
/**
*@brief 				Controlla che ci si vuole muovere di esattamente una posizione
*
*@param	from[2]			Un array con le coordinate della pedina da muovere
*@param	to[2]			Un array contenente le coordinate di destinazione
**/
int isSingleMove(int from[2], int to[2]);
/**
*@brief 				Controlla che ci si vuole muovere di esattamente due posizioni
*
*@param	from[2]			Un array con le coordinate della pedina da muovere
*@param	to[2]			Un array contenente le coordinate di destinazione
**/
int isDoubleMove(int from[2], int to[2]);
/**
*@brief 				Controlla che la cella selezionata sia vuota
*@details				Ricava la pedina che controlla la torre utilizzando il
*						metodo getTop() e controlla se è uguale a #NULL_PAWN.
*
*@param tower			La torre da controllare
**/
int topIsNull(Tower tower);
/**
*@brief 				Controlla se si può conquistare la pedina che comanda una torre
*@details				Nello specifico controlla se la cella precedente, ricavata tramite
*						il metodo getTowerInBetween(), è diversa da quella con la quale si vuole
*						conquistare.
*
*@param	from[2]			Un array con le coordinate della pedina da muovere
*@param	to[2]			Un array contenente le coordinate di destinazione
*@param board			La matrice contenente tutte le pedine
**/
int canConquer(int from[2], int to[2], PlayableBoard board);
/**
*@brief 				Controlla che la torre appartenga al giocatore
*@details				Questo controllo è necessario per evitare che l'avversario
*						possa controllare le pedine dell'utente.
*
*@param	from[2]			Un array con le coordinate della pedina da muovere
*@param board			La matrice contenente tutte le pedine
*@param oTurn			Il turno del giocatore
**/
int isYourPawn(int from[2], PlayableBoard board, int oTurn);
/**
*@brief 				Controlla se l'utente è costretto a conquistare
*
*@param	board			La matrice che contiene le pedine
**/
int mustConquer(PlayableBoard board, int oTurn);
