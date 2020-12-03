#pragma once

#include "board.h"
#include "math.h"

void move(PlayableBoard board, unsigned int from[2], unsigned int to[2]);

static void conquer(Tower conquered, Tower conquerer);
static void deepCopy(Tower destination, Tower source);
static void clearCell(Tower tower);
