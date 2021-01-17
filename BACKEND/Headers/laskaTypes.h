#pragma once

/**
*@file 			laskaTypes.h
*@brief			All'interno di questo file sono presenti
*				i tipi utilizzati all'interno del codice
**/

/******************************DEFINITIONS*********************************/
/**
*@details		Definizione del tipo Pawn, come carattere
**/
typedef char Pawn;
/**
*@details		Definizione del tipo Tower, come array di Pawn
**/
typedef Pawn* Tower;
/**
*@details		Definizione del tipo PlayableBoard, come matrice di Tower
**/
typedef Tower** PlayableBoard;
