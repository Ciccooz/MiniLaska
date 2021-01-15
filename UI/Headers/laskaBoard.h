#pragma once

#include "../../BACKEND/Headers/laskaTypes.h"

/******************************DEFINITIONS*********************************/
/**
*@details 				Cella non giocabile
**/
#define UNPLAYABLE_PAWN     (char)0xb0   /*░*/

/**
*@details 				Angolo in alto a sinistra
**/
#define TOP_LEFT_CORNER     (char)0xc9   /*╔*/

/**
*@details 				Intersezione in alto
**/
#define TOP_INTERSECTION    (char)0xcb   /*╦*/

/**
*@details 				Angolo in alto a destra
**/
#define TOP_RIGHT_CORNER    (char)0xbb   /*╗*/

/**
*@details 				Lato sinistro
**/
#define MID_LEFT_SIDE       (char)0xcc   /*╠*/

/**
*@details 				Intersezione in mezzo
**/
#define MID_INTERSECTION    (char)0xce   /*╬*/

/**
*@details 				Lato destro
**/
#define MID_RIGHT_SIDE      (char)0xb9   /*╣*/

/**
*@details 				Angolo in basso a sinistra
**/
#define BOTTOM_LEFT_CORNER  (char)0xc8   /*╚*/

/**
*@details 				Intersezione in basso
**/
#define BOTTOM_INTERSECTION (char)0xca   /*╩*/

/**
*@details 				Angolo in basso a destra
**/
#define BOTTOM_RIGHT_CORNER (char)0xbc   /*╝*/

/**
*@details 				Bordo orizzontale delle celle interne
**/
#define HORIZONTAL_SIDE     (char)0xcd   /*═*/

/**
*@details 				Bordo verticale delle celle interne
**/
#define VERTICAL_SIDE       (char)0xba   /*║*/

/**
*@details 				Colonna più a sinistra
**/
#define FIRST_COLUMN 		'a'

/**
*@details 				Riga più in alto
**/
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
/**
*@brief 		 		Stampa a video tutta la griglia
*@details 		 		Questo metodo utilizza tutti gli altri metodi per stampare
*						per intero la griglia.
*
*@param board			La griglia da stampare
**/
void printBoard(PlayableBoard board);

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
*@param input	 		Input dell'utente
*@param UICoords 		Array nella quale caricare le coordinate
**/
void UserInputToUICoords(UserInput input, int UICoords[2]);

/**
*@brief 		 		Stampa i separatori in base ai parametri passati
*@details 		 		Stampa per primo, e per una sola volta, il parametro 'left'.
*				 		Poi per ogni cella viene stampato il carattere #HORIZONTAL_SIDE
*				 		e alla fine della cella il parametro 'intersection', questo
*				 		processo è ripetuto per tutta la lunghezza della griglia.
*				 		Una volta finita la griglia verrà stampato il parametro 'right'.
*
*@param cellSide		Dimensioni della singola cella
*@param left	 		Carattere da stampare per primo
*@param intersection	Carattere che viene stampato in mezzo
*@param right 			Carattere stampato alla fine della griglia
**/

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
Tower getTowerInBetween(PlayableBoard board, int UIPos1[2], int UIPos2[2]);

static void printHorizontalSeparator(int cellSide, char left, char intersection, char right);

/**
*@brief 		 		Stampa i separatori superiori
*@details 		 		Chiama il metodo printHorizontalSeparator(), passando come
*				 		argomenti #TOP_LEFT_CORNER, #TOP_INTERSECTION, #TOP_RIGHT_CORNER.
*
*@param cellSide		Dimensioni della singola cella
**/
static void printUpperSeparator(int cellSide);

/**
*@brief 		 		Stampa i separatori intermedi
*@details 		 		Chiama il metodo printHorizontalSeparator(), passando come
*				 		argomenti #MID_LEFT_SIDE, #MID_INTERSECTION, #MID_RIGHT_SIDE.
*
*@param cellSide		Dimensioni della singola cella
**/
static void printMidSeparator(int cellSide);

/**
*@brief 		 		Stampa i separatori inferiori
*@details 		 		Chiama il metodo printHorizontalSeparator(), passando come
*				 		argomenti #BOTTOM_LEFT_CORNER, #BOTTOM_INTERSECTION, #BOTTOM_RIGHT_CORNER.
*
*@param cellSide		Dimensioni della singola cella
**/
static void printLowerSeparator(int cellSide);

/**
*@brief 		 		Stampa il contenuto di una cella
*
*@param content			Carattere da stampare all'interno
*@param cellSide		Dimensioni della singola cella
**/
static void printCellContent(char content, int cellSide);

/**
*@brief 		 		Stampa le coordinate delle colonne
*
*@param cellSide		Dimensioni della singola cella
**/
static void printColumnCoordinates(int cellSide);

/**
*@brief 		 		Stampa le coordinate delle righe
*@details				La coordinata viene stampata solo se terminalRow è
*						pari a cellSide/2.
*
*@param cellSide		Dimensioni della singola cella
*@param terminalRow		Rappresenta a che altezza della cella ci si trova
*@param boardRow		Indice della riga
**/
static void printRowCoordinates(int cellSide, int terminalRow, int boardRow);
