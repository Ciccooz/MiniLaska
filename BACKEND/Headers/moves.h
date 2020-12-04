#pragma once

#include "../../UI/Headers/UIBoard.h"
#include "validation.h"
#include "rules.h"
#include "board.h"
#include "pawn.h"
#include "math.h"
#include <stdlib.h>

void move(PlayableBoard board, int UIFrom[2], int UITo[2]);

static void conquer(Tower conquered, Tower conquerer);
static void deepCopy(Tower destination, Tower source);
static void clearCell(Tower tower);
