#include <stdio.h>
#include <stdlib.h>

int sideSize = 7;

typedef struct {
	char content[3];
} Tower;

//Inizializzazione delle pedine..............
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
// void print(Tower towers[sideSize][sideSize]) {
// 	int row, col;

// 	for(row = 0; row < sideSize; row++)
// 		for(col = 0; col < sideSize; col++)
// 			if(towers[row][col].content[0] != '-')
// 				printf("(%d, %d) = %c \n", row, col, towers[row][col].content[0]);
// }

//Restituisce una pedina o la pedina che comanda la torre........
char getTop(Tower towers[sideSize][sideSize], int row, int col) {
	int i;
	char top = '-';

	for(i = 0; i < 3; i++)
		if(towers[row][col].content[i] != '-')
			top = towers[row][col].content[i];

	return top;
}

//Rimuove e restituisce una pedina o la pedina che comanda la torre...
char removeTop(Tower towers[sideSize][sideSize], int row, int col) {
	int i;
	char top = '-';
	int pos = -1;

	for(i = 0; i < 3; i++)
		if(towers[row][col].content[i] != '-'){
			top = towers[row][col].content[i];
			pos = i;
		}

	if(pos != -1)
		towers[row][col].content[i] = '-';

	return top;
}

//Controlla che le coordinate inserite esistano..............................
int coordinatesAreRight(int startRow, int startCol, int endRow, int endCol) {
	int rowsAreRight = (startRow >= 0 && startRow <= 6) && (endRow >= 0 && endRow <= 6);
	int colsAreRight = (startCol >= 0 && startCol <= 6) && (endCol >= 0 && endCol <= 6);

	if(rowsAreRight && colsAreRight)
		printf("Coordinates are right\n");
	else	
		printf("Coordinates are not right\n");

	return rowsAreRight && colsAreRight;
}

//Controlla se una pedina o la pedina che controlla la torre può andare verso il basso.................
int canMoveDown(Tower towers[sideSize][sideSize], int startRow, int startCol, int endRow, int endCol) {
	int movedDown = 0;
	int topIsRight = 0;

	if(coordinatesAreRight(startRow, startCol, endRow, endCol)) {
		movedDown = (startRow == (endRow - 1) && (startCol == (endCol + 1) || startCol == (endCol - 1)));
		topIsRight = ((getTop(towers, startRow, startCol) == 'a') || (getTop(towers, startRow, startCol) == 'B'));
	}

	if(movedDown && topIsRight)
		printf("It can move down\n\n");
	else	
		printf("It cant move down\n\n");

	return movedDown && topIsRight;
}

//Controlla se una pedina o la pedina che controlla la torre può andare verso l'alto.................
int canMoveUp(Tower towers[sideSize][sideSize], int startRow, int startCol, int endRow, int endCol) {
	int movedUp = 0;
	int topIsRight = 0;

	if(coordinatesAreRight(startRow, startCol, endRow, endCol)) {
		movedUp = (startRow == (endRow + 1) && (startCol == (endCol + 1) || startCol == (endCol - 1)));
		topIsRight = ((getTop(towers, startRow, startCol) == 'A') || (getTop(towers, startRow, startCol) == 'b'));
	}

	if(movedUp && topIsRight)
		printf("It can move up\n\n");
	else	
		printf("It cant move up\n\n");

	return movedUp && topIsRight;
}

//Conta quante pedine possono essere conquistate................
int counter(Tower towers[sideSize][sideSize], int row, int col) {
	int count = 0;
	int i;

	for(i = 0; i < 3; i++)
		if(towers[row][col].content[i] == '-')
			count++;

	return count;
}

//Shifta di una posizione verso l'alto le pedine, per conquistarne una
void shift(Tower towers[sideSize][sideSize], int row, int col) {
	int i;

	for(i = 1; i > 0; i--){
		if(towers[row][col].content[i] != '-')
			towers[row][col].content[i + 1] = towers[row][col].content[i];
			towers[row][col].content[i] = '-';
	}
}

//Aggiunge le pedine conquistate alla pedina o alla torre appena mossa....................................
void add(Tower towers[sideSize][sideSize], int startRow, int startCol, int endRow, int endCol, char top) {
	if(top != '-'){
		shift(towers, startRow, startCol);
		towers[startRow][startRow].content[0] = top;
	}
}

//Scambia la pedina o le torri scelte............................................................
void swap(Tower towers[sideSize][sideSize], int startRow, int startCol, int endRow, int endCol) {
	int i;

	for(i = 0; i < 3; i++) {
		towers[endRow][endCol].content[i] = towers[startRow][startCol].content[i];
		printf("%c swapped with %c\n", towers[endRow][endCol].content[i], towers[startRow][startCol].content[i]);
		towers[startRow][startCol].content[i] = '-';
	}
}

//Restituisce l'indice nella quale si trova la pedina che comanda....
int getTopIndex(Tower towers[sideSize][sideSize], int row, int col) {
	int i;
	int index = -1;

	for(i = 0; i < 3; i++) {
		if(towers[row][col].content[i] != '-')
			index = i;
	}

	return index;
}

//Cambia la pedina in una che puo tornare indietro............................
void changeTop(Tower towers[sideSize][sideSize], int row, int col, char top) {
	int index = getTopIndex(towers, row, col);
	
	if(top == 'a')
		towers[row][col].content[index] = 'A';

	if(top == 'b')
		towers[row][col].content[index] = 'B';
}

//Controlla se una pedina è arrivata alla fine, così che può tornare indietro
void checkEnd(Tower towers[sideSize][sideSize], int row, int col) {
	char top = getTop(towers, row, col);

	if((top == 'a') && (row == sideSize-1))
		changeTop(towers, row, col, top);

	if((top == 'b') && (row == 0))
		changeTop(towers, row, col, top);
}

//Muove la pedina................................................................................
void move(Tower towers[sideSize][sideSize], int startRow, int startCol, int endRow, int endCol) {
	char startTop = getTop(towers, startRow, startCol);
	char endTop = getTop(towers, endRow, endCol);

	printf("start: %c\n", startTop);
	printf("end: %c\n", endTop);

	int i;

	printf("Trying to go from (%d, %d) to (%d, %d)\n", startRow, startCol, endRow, endCol);
	
	if(endRow > startRow){
		if(canMoveDown(towers, startRow, startCol, endRow, endCol))
			if(startTop != endTop){
				int count = counter(towers, startRow, startCol);

				for(i = 0; i < count; i++){
					char top = removeTop(towers, endRow, endCol);
					add(towers, startRow, startCol, endRow, endCol, top);
				}

				
				swap(towers, startRow, startCol, endRow, endCol);
				checkEnd(towers, endRow, endCol);
			}
	}

	else {
		if(canMoveUp(towers, startRow, startCol, endRow, endCol))
			if(startTop != endTop){
				int count = counter(towers, startRow, startCol);

				for(i = 0; i < count; i++){
					char top = removeTop(towers, endRow, endCol);
					add(towers, startRow, startCol, endRow, endCol, top);
				}

				printf("start: %c\n", towers[startRow][startCol].content[0]);
				printf("end: %c\n", towers[endRow][endCol].content[0]);
				swap(towers, startRow, startCol, endRow, endCol);
				checkEnd(towers, endRow, endCol);
			}
	}
}

int main() {
	int gridSize = sideSize * sideSize;
	Tower towers[sideSize][sideSize];

	init(towers);
	
	printf("before: %c %c %c\n", towers[4][0].content[0], towers[4][0].content[1], towers[4][0].content[2]);
	move(towers, 4, 0, 3, 1);
	printf("after: %c %c %c\n", towers[3][1].content[0], towers[3][1].content[1], towers[3][1].content[2]);

	printf("before: %c %c %c\n", towers[2][2].content[0], towers[2][2].content[1], towers[2][2].content[2]);
	move(towers, 2, 2, 3, 1);
	printf("after: %c %c %c\n", towers[3][1].content[0], towers[3][1].content[1], towers[3][1].content[2]);
}