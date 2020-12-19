#include "../Headers/input.h"

#include <ctype.h>

int getGameMode(){
	char newline;
	int gameMode;
	printf("Welcome to miniLaska\n\n");
	printf("1. Player vs Player\n");
	printf("2. Player vs CPU\n\n");
	printf("Select the game mode: ");
	scanf("%d%c", &gameMode, &newline);
	
	refreshTerminal();
	return gameMode;
}

Names getNames(int gameMode){
	int i;

	Names names = malloc(sizeof(char *) * 2);
	char player1[15];
	char player2[15];
	char cpu[] = "CPU";
	
	for(i = 0; i < 2; i++)
		names[i] = malloc(sizeof(char) * 15);
	
	if(gameMode == 1){
		printf("Insert Player 1 name: ");
		fgets(player1, 15, stdin);
		printf("\n\nInsert Player 2 name: ");
		fgets(player2, 15, stdin);
		
		player1[0] = toupper(player1[0]);
		player2[0] = toupper(player2[0]);
		
		player1[strlen(player1)-1] = 0;
		player2[strlen(player2)-1] = 0;
		
		strcpy(names[1], player2);
	}
	
	else{
		printf("Insert your name: ");
		fgets(player1, 15, stdin);
		strcpy(names[1], cpu);
	}
	
	strcpy(names[0], player1);
	refreshTerminal();
	
	return names;
}
