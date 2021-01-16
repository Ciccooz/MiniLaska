#pragma once

#include "../Headers/playableBoard.h"

#define NOT_OVER 0
#define PLAYER_0_WON 1
#define PLAYER_1_WON 2

typedef char GameOverCode;

GameOverCode isGameOver(PlayableBoard board);
