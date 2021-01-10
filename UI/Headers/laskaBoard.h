#pragma once

#include "../../BACKEND/Headers/laskaTypes.h"

/******************************DEFINITIONS*********************************/
#define UNPLAYABLE_PAWN     (char)0xb0   /*░*/
#define TOP_LEFT_CORNER     (char)0xc9   /*╔*/
#define TOP_INTERSECTION    (char)0xcb   /*╦*/
#define TOP_RIGHT_CORNER    (char)0xbb   /*╗*/
#define MID_LEFT_SIDE       (char)0xcc   /*╠*/
#define MID_INTERSECTION    (char)0xce   /*╬*/
#define MID_RIGHT_SIDE      (char)0xb9   /*╣*/
#define BOTTOM_LEFT_CORNER  (char)0xc8   /*╚*/
#define BOTTOM_INTERSECTION (char)0xca   /*╩*/
#define BOTTOM_RIGHT_CORNER (char)0xbc   /*╝*/
#define HORIZONTAL_SIDE     (char)0xcd   /*═*/
#define VERTICAL_SIDE       (char)0xba   /*║*/

#define FIRST_COLUMN 		'a'
#define FIRST_ROW 			GRID_SIZE

typedef struct
{
  char column;
  int row;
} UserInput;

/********************************METHODS***********************************/
/*
cellSide indica la dimensione della cella (bordi esclusi) in char
cellSide deve essere un multiplo di TOWER_HEIGHT
*/
void printBoard(PlayableBoard board, int cellSide);

/*Restituisce la torre corrispondente alle UICoords date*/
/**
*@brief 		 		Restituisce la torre che corrisponde alle coordinate date
*@details 		 		Converte le coordinate che rappresentano una cella della
*				 		griglia dell'UI, in una torre della griglia
*				 		utilizzata dal programma.
*
*@note			 		La griglia utilizzata dal programma non utilizza alcune
*				 		celle, quindi le coordinate delle colonne sono diverse.
*				 		Per selezionare la cella corretta, è necessario inserire
*				 		la riga, senza modifiche, e la colonna, divisa per 2. 
*
*@param board	 		La griglia contentente le torri
*@param UICoords 		Le coordinate da cui prendere la torre
**/
Tower UICoordinatesToTower(PlayableBoard board, int UICoords[2]);

/**
*@brief 		 		Converte le coordinate dell'utente in quelle della UI
*
*@note			 		L'utente ha come indice riga da 1 a 7, mentre come indice 
*				 		colonna dalla lettera 'a' alla 'g'. La griglia dell'UI ha 
*				 		righe e colonne con indici che vanno da 0 a 6.
*
*@param input	 
*@param UICoords 
**/
void UserInputToUICoords(UserInput input, int UICoords[2]);

/**
*@brief 		 		Stampa i separatori in base ai parametri passati
*@details 		 		Stampa per primo, e per una sola volta, il parametro 'left'.
*				 		Poi per ogni cella viene stampato il carattere HORIZONTAL_SIDE
*				 		e alla fine della cella il parametro 'intersection', questo 
*				 		processo è ripetuto per tutta la lunghezza della griglia.
*				 		Una volta finita la griglia verrà stampato il parametro 'right'.
*
*@param left	 		Carattere da stampare per primo
*@param intersection	Carattere che viene stampato in mezzo
*@param right 			Carattere stampato alla fine della griglia
**/
static void printHorizontalSeparator(int cellSide, char left, char intersection, char right);

/**
*@brief 		 		Stampa i separatori superiori
*@details 		 		Chiama il metodo printHorizontalSeparator(), passando come
*				 		argomenti TOP_LEFT_CORNER, TOP_INTERSECTION, TOP_RIGHT_CORNER.
**/
static void printUpperSeparator(int cellSide);

/**
*@brief 		 		Stampa i separatori intermedi
*@details 		 		Chiama il metodo printHorizontalSeparator(), passando come
*				 		argomenti MID_LEFT_SIDE, MID_INTERSECTION, MID_RIGHT_SIDE.
**/
static void printMidSeparator(int cellSide);

/**
*@brief 		 		Stampa i separatori inferiori
*@details 		 		Chiama il metodo printHorizontalSeparator(), passando come
*				 		argomenti BOTTOM_LEFT_CORNER, BOTTOM_INTERSECTION, BOTTOM_RIGHT_CORNER.
**/
static void printLowerSeparator(int cellSide);

/**
*@brief 		 		Stampa il contenuto di una cella
**/
static void printCellContent(char content, int cellSide);

/**
*@brief 		 		Stampa le coordinate delle colonne
**/
static void printColumnCoordinates(int cellSide);

/**
*@brief 		 		Stampa le coordinate delle righe
**/
static void printRowCoordinates(int cellSide, int UIRow, int boardRow);