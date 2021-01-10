#pragma once

#include "BACKEND/Headers/laskaTypes.h"
#include "BACKEND/Headers/input.h"
#include "BACKEND/Headers/rules.h"
#include "BACKEND/Headers/errors.h"
#include "BACKEND/Headers/tower.h"
#include "BACKEND/Headers/playableBoard.h"

/********************************METHODS***********************************/
/**
*@brief 		Esegue il comando per la pulizia dello schermo del terminale
*@details 		Viene eseguito un comando diverso in base a quale sistema 
*				operativo sta utilizzando l'utente.	
**/
void refreshTerminal();

/**
@brief			Controlla se è necessario promuovere una pedina
@details		Se una torre raggiunge il lato opposto del campo, 
*				allora deve essere promossa. Quindi viene chiamato 
*				il metodo promote(), passando come parametro la 
*				torre da promuovere.
*
*@param board 	La matrice contenente tutte le pedine
*@param UITo[2] Un array contenente le coordinate di destinazione
**/
static void checkPromotion(PlayableBoard board, int UITo[2]);

/**
@brief			Controlla se un giocatore ha vinto
@details		Controlla quante pedine di ogni giocatore sono rimaste,
*				se non ce ne sono, allora l'altro giocatore ha vinto la 
*				partita.
*
*@param board 	La matrice contenente tutte le pedine
*@param names 	Un array che contiene i nomi dei giocatori
**/
int hasWon(PlayableBoard board, Names names);

int countPawns(PlayableBoard board, char soldierTop, char officerTop);

int countMoves(PlayableBoard board, char soldierTop, char officerTop);