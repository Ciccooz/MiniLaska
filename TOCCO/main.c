#include <stdio.h>
#include <stdlib.h>

int sideSize = 7;

typedef struct {
	char content[3];
} Tower;

void init(Tower towers[sideSize][sideSize]) {
	int row, col;

	for(row = 0; row < sideSize; row++)
		for(col = 0; col < sideSize; col++) {
			if((row < 3) && ((row + col) % 2) == 0) {
				towers[row][col].content[0] = 'a';
				towers[row][col].content[1] = '-';
				towers[row][col].content[2] = '-';
			}

			else{
				if((row > 3) && ((row + col) % 2) == 0){
					towers[row][col].content[0] = 'b';
					towers[row][col].content[1] = '-';
					towers[row][col].content[2] = '-';
				}

				else{
					towers[row][col].content[0] = '-';
					towers[row][col].content[1] = '-';
					towers[row][col].content[2] = '-';
				}
			}
		}
}

//DA FARE MEGLIO..............................
void print(Tower towers[sideSize][sideSize]) {
	int row, col;

	for(row = 0; row < sideSize; row++)
		for(col = 0; col < sideSize; col++)
			if(towers[row][col].content[0] != '-')
				printf("(%d, %d) = %c \n", row, col, towers[row][col].content[0]);
}

char topTower(Tower towers[sideSize][sideSize], int startRow, int startCol) {
	int i;
	char top;

	for(i = 0; i < 3; i++)
		if(towers[startRow][startCol].content[i] != '-')
			top = towers[startRow][startCol].content[i];

	return top;
}

int coordinatesAreRight(int startRow, int startCol, int endRow, int endCol){
	int rowsAreRight = (startRow >= 0 && startRow <= 6) && (endRow >= 0 && endRow <= 6);
	int colsAreRight = (startCol >= 0 && startCol <= 6) && (endCol >= 0 && endCol <= 6);

	if(rowsAreRight && colsAreRight)
		printf("Coordinates are right\n");
	else	
		printf("Coordinates are not right\n");

	return rowsAreRight && colsAreRight;
}

int canMoveDown(Tower towers[sideSize][sideSize], int startRow, int startCol, int endRow, int endCol){
	int movedDown = 0;
	int topIsRight = 0;

	if(coordinatesAreRight(startRow, startCol, endRow, endCol)) {
		movedDown = (startRow == (endRow - 1) && (startCol == (endCol + 1) || startCol == (endCol - 1)));
		topIsRight = ((topTower(towers, startRow, startCol) == 'a') || (topTower(towers, startRow, startCol) == 'B'));
	}

	if(movedDown && topIsRight)
		printf("It can move down\n\n");
	else	
		printf("It cant move down\n\n");

	return movedDown && topIsRight;
}

int canMoveUp(Tower towers[sideSize][sideSize], int startRow, int startCol, int endRow, int endCol){
	int movedUp = 0;
	int topIsRight = 0;

	if(coordinatesAreRight(startRow, startCol, endRow, endCol)) {
		movedUp = (startRow == (endRow + 1) && (startCol == (endCol + 1) || startCol == (endCol - 1)));
		topIsRight = ((topTower(towers, startRow, startCol) == 'A') || (topTower(towers, startRow, startCol) == 'b'));
	}

	if(movedUp && topIsRight)
		printf("It can move up\n\n");
	else	
		printf("It cant move up\n\n");

	return movedUp && topIsRight;
}

void move(Tower towers[sideSize][sideSize], int startRow, int startCol, int endRow, int endCol) {
	printf("Trying to go from (%d, %d) to (%d, %d)\n", startRow, startCol, endRow, endCol);
	
	if(endRow > startRow){
		if(canMoveDown(towers, startRow, startCol, endRow, endCol))
			printf("");
	}

	else {
		if(canMoveUp(towers, startRow, startCol, endRow, endCol))
			printf("");
	}
}

int main() {
	int gridSize = sideSize * sideSize;
	Tower towers[sideSize][sideSize];

	init(towers);
	move(towers, 0, 0, 1, 1);
	move(towers, 6, 6, 5, 5);
	move(towers, 0, 0, 1, -1);
	move(towers, 6, 6, 5, 7);
	move(towers, 0, 0, 2, 2);
	move(towers, 6, 6, 4, 4);
}