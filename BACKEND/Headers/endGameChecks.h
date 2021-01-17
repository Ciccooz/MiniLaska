#pragma once
#include "../Headers/playableBoard.h"

/**
*@file 					endGameChecks.h
*@brief 				File nella quale si trovano i controlli per determinare la vittoria di un giocatore
**/

/******************************DEFINITIONS*********************************/
/**
*@details				Valore per la quale nessuno ha vinto.
**/
#define NOT_OVER 0

/**
*@details				Variabile che rappresenta la vittoria del Player0.
**/
#define PLAYER_0_WON 1

/**
*@details				Variabile che determina la vittoria del Player1.
**/
#define PLAYER_1_WON 2

/**
*@details				Definizione del tipo GameOverCode, come carattere.
**/
typedef char GameOverCode;

/********************************METHODS***********************************/
/**
*@brief 				Controlla se un giocatore ha vinto
*@details 				Per ogni giocatore controlla se ha mosse disponibili
*						e se è ancora in possesso di pedine, chiamando i metodi
*						hasAvailableMoves() e hasPawnsLeft(). In base a chi ha 
*						vinto returna #PLAYER_0_WON o #PLAYER_1_WON, se nessuno
*						ha vinto returna #NOT_OVER.
*
*@param	board   		La griglia contentente le pedine
**/
GameOverCode isGameOver(PlayableBoard board);