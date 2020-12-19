#pragma once

#define GRID_SIZE    7
#define TOWER_HEIGHT 3

#define SOLDIER1  'x'
#define SOLDIER2  'o'
#define OFFICER1  'X'
#define OFFICER2  'O'
#define NULL_PAWN ' '

typedef char Pawn;
typedef Pawn* Tower;
typedef Tower** PlayableBoard;

