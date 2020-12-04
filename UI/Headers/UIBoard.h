#pragma once

#include <stdio.h>
#include "../../BACKEND/Headers/board.h"
#include "../../BACKEND/Headers/rules.h"

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

/*
cellSide indica la dimensione della cella (bordi esclusi) in char
cellSide deve essere un multiplo di TOWER_HEIGHT
*/
void printBoard(PlayableBoard board, int cellSide);
/*Restituisce la torre corrispondente alle UICoords date*/
Tower UICoordinatesToTower(PlayableBoard board, int UICoords[2]);

static void printHorizontalSeparator(int cellSide, char left, char intersection, char right);
static void printUpperSeparator(int cellSide);
static void printMidSeparator(int cellSide);
static void printLowerSeparator(int cellSide);
static void printCellContent(char content, int cellSide);
static void printColumnCoordinates(int cellSide);
static void printRowCoordinates(int cellSide, int UIRow, int boardRow);
