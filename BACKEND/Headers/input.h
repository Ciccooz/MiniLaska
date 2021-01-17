#pragma once
#include "laskaTypes.h"

/**
*@file 			      input.h
*@brief			      In questo file sono presenti metodi per l'input dell'utente
**/

/******************************DEFINITIONS*********************************/
/**
*@details 		      Definizione del tipo Name, come array di caratteri
**/
typedef char* Name;

/**
*@details 		      Definizione del tipo Names, come array di Name
**/
typedef Name* Names;

/**
*@details			  Struttura che rappresenta l'input della mossa dell'
*					  utente.
**/
typedef struct
{
  /**
  *@brief 			  La colonna inserita
  **/
  char column;
  
  /**
  *@brief 			  La riga inserita
  **/
  int row;
} UserInput;

/********************************METHODS***********************************/
/**
*@brief 			  Chiede i nomi dei giocatori
*@details 			  Chiede ai giocatori di inserire i propri nomi,
*					  poi li carica in un array.
*					  Nel caso in cui non venga inserito un nome,
*					  viene automaticamente caricato il nome
*					  "Player1" o "Player2" all'interno dell'array.
*					  Infine returna l'array.
**/
Names getNames();

/**
*@brief 			  Libera la memoria dell'array dei nomi
*
*@param	names		  L'array dei nomi
**/
void freeNames(Names names);

/**
*@brief 			  Chiede all'utente le coordinate della mossa
*@details 			  Dopo che l'utente ha inserito le coordinate,
*					  controlla che i valori siano giusti, se sono giusti
*					  li salva in UICoords e returna 1, altrimenti returna 0.
*
*@param title		  Spiega se si inseriscono coordinate della cella di partenza o destinazione.
*@param UICoords[2]   Array nella quale vengono salvate le coordinate.
*@param board 		  Griglia contente tutte le torri.
**/
int getCoordinates(const char* title, int UICoords[2], PlayableBoard board);