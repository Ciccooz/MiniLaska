#include "..\\Headers\\pawn.h"

char getTop(int from[], PlayableBoard board) {
	int row = from[0];
	int col = from[1] / 2;
	char top = NULL_PAWN;

	int i;

	for(i = 0; i < 3; i++)
		if(board[row][col][i] != NULL_PAWN)
			top = board[row][col][i];

	return top;
}

int getTopIndex(int from[], PlayableBoard board) {
	int row = from[0];
	int col = from[1] / 2;
	int index = -1;
	
	int i;
	
	for(i = 0; i < 3; i++) {
		if(board[row][col][i] != NULL_PAWN)
			index = i;
	}

	return index;
}

void changeTop(int from[], char top, PlayableBoard board) {
	int row = from[0];
	int col = from[1] / 2;
	int index = getTopIndex(from, board);
	
	if(top == SOLDIER1)
		board[row][col][index] = OFFICER1;

	if(top == SOLDIER2)
		board[row][col][index] = OFFICER2;
}

void move(int from[], int to[], PlayableBoard board){

}