#pragma once
#include "laskaTypes.h"

/**
*@file 			playableBoard.h
*@brief			In questo file si trovano i metodi legati alla griglia di gioco
**/

/********************************METHODS***********************************/
/*
Alloca la memoria per il campo da gioco tramite la chiamata ad allocBoard e posiziona le pedine
nella posizione di inizio partita tramite la chiamata a spawnPawns
Restituisce il puntatore base (PlayableBoard) o NULL in caso si verificasse un'eccezione durante
l'allocazione di memoria
*/

/**
*@brief 		Crea una nuova griglia ed inserisce le pedine
*@details 		Chiama il metodo allocBoard() e, se l'allocazione è 
*				andata a buon fine, chiama il metodo spawnPawns(),
*				altrimenti restituisce NULL.
**/
PlayableBoard newBoard();

/*
Alloca dinamicamente la memoria per il campo da gioco (limitato alle caselle giocabili) e
restituisce il puntatore base (PlayableBoard)
Se la calloc non riesce ad allocare memoria la funzione ripulisce tutto ciò che eventualmente
era già stato allocato prima che si verificasse l'eccezione chiamando freeBoard e restituisce
NULL
*/

/**
*@brief 		Alloca dinamicamente la memoria del campo da gioco
*@details 		Prima alloca l'array che conterrà le righe della griglia,
*				poi alloca le righe della griglia utilizzando dimesioni 
*				diverse, ottenute tramite il metodo getRowSize().
*				Nel caso in cui una delle allocazioni non vada a buon fine,
*				chiama il metodo freeBoard().
*
*@note			Abbiamo deciso di allocare array di dimensioni diverse per
*				risparmiare spazio, dato che molte celle non vengono
*				utilizzate.
**/
static PlayableBoard allocBoard();

/**
*@brief 		Posiziona le pedine sulla griglia
*@details 		Per prima cosa riempe la griglia di #NULL_PAWN. Poi
*				nella prima metà della griglia posiziona le pedine #SOLDIER1 e 
*				nella seconda metà #SOLDIER2, la riga in mezzo non viene riempita.
*				Il numero di pedine posizionate in ogni riga dipende dal valore
*				restituito da getRowSize().
*
*@param grid	Griglia nella quale posizionare le pedine
**/
static void spawnPawns(PlayableBoard grid);

/**
*@brief 		Restituisce la grandezza di una riga
*@details 		Se l'indice della riga è dispari, restituisce 3,
*				altrimenti 4. Questo perchè nelle righe pari sono
*				presenti 4 celle disponibili, mentre in quelle dispari 3.
*
*@param	row		L'indice della riga
**/
int getRowSize(int row);

/*
Libera la memoria allocata per il campo da gioco. Nel caso dovesse trovare un puntatore NULL
procede direttamente con la free del buffer in cui tale puntatore è memorizzato.
*/

/**
*@brief 		Libera la memoria allocata per il campo da gioco
*@details 		Libera la memoria delle singole torri, poi della riga
*				nella quale si trovano le torri. Infine fa la free del 
*				puntatore dell'intera griglia.
*
*@param	grid	Griglia dalla quale liberare la memoria
**/
void freeBoard(PlayableBoard grid);

/**
*@brief 		Restituisce la torre compresa tra due celle
*@details 		Ricava le coordinate della torre facendo la media,
*				tra le coordinate della cella di partenza e quella di
*				destinazione. Ottiene la torre chiamando il metodo 
*				UICoordinatesToTower(), passando come parametri la griglia 
*				e le coordinate appena trovate
*
*@param from[2] Coordinate di partenza
*@param to[2]	Coordinate di destinazione
*@param	grid	Griglia contenente le torri
**/
Tower getPrevious(int from[2], int to[2], PlayableBoard board);