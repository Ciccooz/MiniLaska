#include <stdio.h>

#include "BACKEND/Headers/board.h"
#include "UI/Headers/UIBoard.h"
#include "BACKEND/Headers/moves.h"
#include "BACKEND/Headers/validation.h"


static void refreshTerminal();

/*
Prende l'user input e lo converte a coordinate UI (matrice 7x7 con indici da 0 a 6)
Il risultato viene storato direttamente in UICoords
*/
static void getUserInput(const char* title, int UICoords[2]);
