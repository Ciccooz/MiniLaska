#pragma once

#include "rules.h"
#include "board.h"

/*Restituisce la pedina (o la pedina che comanda la torre) che occupa la cella selezionata
Se la cella è vuota, viene restituito il NULL_PAWN (ovvero uno spazio vuoto)............*/
char getTop(Tower tower);

/*Restituisce l'indice nella quale si trova la pedina 
(o la pedina che comanda la torre) nella cella selezionata
Se la cella è vuota, restituisce -1.....................................................*/
int getTopIndex(Tower tower);

/*Cambia la pedina (o la pedina che comanda la torre) della cella selezionata,
con un'altra indicata nei parametri.....................................................*/
void changeTop(Tower tower, char newTop);

/*Promuove la pedina (o la pedina che comanda la torre), da SOLDIER a OFFICIER..........*/
void promote(Tower tower);

/* MANCA IL MOVE */