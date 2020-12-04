#include <stdio.h>

#include "BACKEND/Headers/rules.h"
#include "BACKEND/Headers/board.h"
#include "BACKEND/Headers/pawn.h"
#include "BACKEND/Headers/validation.h"
#include "BACKEND/Headers/errors.h"
#include "UI/Headers/UI.h"

static void refreshTerminal();
static void getCoordinates(const char* title, int coords[2]);
