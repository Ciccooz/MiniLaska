#pragma once

#include <stdlib.h>
#include "../../includer.h"

void move(PlayableBoard board, int UIFrom[2], int UITo[2]);

static void conquer(Tower conquered, Tower conquerer);
static void deepCopy(Tower destination, Tower source);
static void clearCell(Tower tower);
