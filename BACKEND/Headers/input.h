#pragma once
#include "laskaTypes.h"

/**
*@file 			input.h
*@brief			In questo file sono presenti metodi per l'input dell'utente
**/

/******************************DEFINITIONS*********************************/
/**
*@details 		Definizione del tipo Name, come array di caratteri
**/
typedef char* Name;

/**
*@details 		Definizione del tipo Names, come array di Name
**/
typedef Name* Names;

/********************************METHODS***********************************/
/**
*@brief 			Chiede all'utente di inserire la modalità di gioco
*@details 			L'utente può scegliere tra la modalità Player contro Player
*					oppure Player contro IA.
**/
int getGameMode();

/**
*@brief 			Chiede i nomi dei giocatori
*@details 			In base alla modalità scelta, chiede i nomi dei giocatori.
*					Se l'utente ha scelto Player contro Player, allora chiede 
*					i due nomi dei giocatori. Se ha scelto Player contro IA, 
*					allora il metodo chiederà solo il nome dell'utente.
*
*@param gameMode	Modalità scelta dall'utente
**/
Names getNames(int gameMode);

/*
Prende l'user input e lo converte a coordinate UI (matrice 7x7 con indici da 0 a 6)
Il risultato viene storato direttamente in UICoords
*/

/**
*@brief 			Chiede all'utente le coordinate della mossa
*@details 			Dopo che l'utente ha inserito le coordinate,
*					controlla che i valori siano giusti, se sono giusti
*					li salva in UICoords e returna 1, altrimenti returna 0.
*
*@param title		Spiega se si inseriscono coordinate della cella di partenza o destinazione.
*
*@param UICoords[2] Array nella quale vengono salvate le coordinate.
*
*@param board 		Griglia contente tutte le torri.
**/
int getCoordinates(const char* title, int UICoords[2], PlayableBoard board);