#include <stdio.h>

#include "BACKEND/Headers/rules.h"
#include "BACKEND/Headers/board.h"
#include "BACKEND/Headers/pawn.h"
#include "BACKEND/Headers/validation.h"
#include "BACKEND/Headers/errors.h"
#include "UI/Headers/UI.h"

static void refreshTerminal();

/*
Prende l'user input e lo converte a coordinate UI (matrice 7x7 con indici da 0 a 6)
Il risultato viene storato direttamente in UICoords
*/
static void getCoordinates(const char* title, int UICoords[2]);
