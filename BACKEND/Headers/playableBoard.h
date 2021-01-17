#pragma once
#include "laskaTypes.h"

/**
*@file 			playableBoard.h
*@brief			In questo file si trovano i metodi legati alla griglia di gioco
**/
/********************************METHODS***********************************/
/**
*@brief 		Crea una nuova griglia ed inserisce le pedine
*@details 		Chiama il metodo allocBoard() e, se l'allocazione è
*				andata a buon fine, chiama il metodo spawnPawns(),
*				altrimenti restituisce NULL.
**/
PlayableBoard newBoard();
/**
*@brief 		Restituisce la grandezza di una riga
*@details 		Se l'indice della riga è dispari, restituisce 3,
*				altrimenti 4. Questo perchè nelle righe pari sono
*				presenti 4 celle disponibili, mentre in quelle dispari 3.
*
*@param	row		L'indice della riga
**/
int getRowSize(int row);
/**
*@brief 		Libera la memoria allocata per il campo da gioco
*@details 		Libera la memoria delle singole torri, poi della riga
*				nella quale si trovano le torri. Infine fa la free del
*				puntatore dell'intera griglia.
*
*@param	grid	Griglia dalla quale liberare la memoria
**/
void freeBoard(PlayableBoard grid);
