#pragma once
#include "laskaTypes.h"

/**
*@file 				tower.h
*@brief				File nella quale si trovano i metodi relativi alle torri
**/

/******************************DEFINITIONS*********************************/
/**
*@brief 		Soldier x
**/
#define SOLDIER1  'x'

/**
*@brief 		Soldier o
**/
#define SOLDIER2  'o'

/**
*@brief 		Officer X
**/
#define OFFICER1  'X'

/**
*@brief 		Officer O
**/
#define OFFICER2  'O'

/**
*@brief 		Cella vuota
**/
#define NULL_PAWN ' '

/********************************METHODS***********************************/
/**
*@brief 			Restituisce la pedina che comanda la torre
*@details			Viene restituito #NULL_PAWN nel caso in cui la cella
*					sia vuota.
*
*@param	tower		La torre da cui prendere la pedina	
**/
char getTop(Tower tower);

/**
*@brief 			Restituisce l'indice della pedina che comanda la torre
*@details			Restituisce -1 nel caso in cui la cella sia vuota.
*
*@param	tower		La torre dalla quale prendere l'indice della pedina
**/
int getTopIndex(Tower tower);

/**
*@brief 			Sostituisce la pedina che comanda la torre, con una nuova
*
*@param	tower 		La torre la cui pedina che la comanda verrà sostituita
*@param	newTop 		La pedina che sostituirà quella selezionata
**/
void changeTop(Tower tower, char newTop);

/**
*@brief 			Promuove la pedina che comanda la torre
*@details 			Effettua la promozione di una pedina da #SOLDIER1 ad #OFFICER1,
*					oppure da #SOLDIER2 ad #OFFICER2 chiamando il metodo changeTop() 
*					ed inserendo come parametri la torre da sostituire e la nuova pedina,
*					ovvero un #OFFICER1 o un #OFFICER2.
*
*@param	tower 		La torre la cui pedina che la comanda verrà promossa
**/
void promote(Tower tower);