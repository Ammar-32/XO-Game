/*
 ============================================================================
 Project       : XO Game
 Author        : Ammar Moataz
 ============================================================================
 */

// Includes
#include <stdio.h>
#include <stdlib.h>

//Prototypes
void printBoard(void);
void player1Turn(void);
void player2Turn(void);
void checkWinner(void);


// Global Variables
char board[10] = {0 ,'1' , '2', '3', '4' ,'5', '6', '7', '8', '9'};
char winner = 0;
char moves = 0;


// Main Function
int main(void) {
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	// Print Board Initially and Start the game
	printf("XO Game Started\n\n");
	printBoard();

	// Game Start
	while(1){
		player1Turn();
		moves++;
		checkWinner();
		if(winner!=0 || moves==9)
			break;
		player2Turn();
		moves++;
		checkWinner();
		if(winner!=0 || moves==9)
			break;
	}

	// Announce Winner
	if(winner==0)
		printf("Game Tie !");
	else
		printf("\n Player %d wins !!!", winner);
	return 0;
}

// Functions

// Print the game board on the console
void printBoard(void){
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", board[1], board[2], board[3]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", board[4], board[5], board[6]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", board[7], board[8], board[9]);

    printf("     |     |     \n\n");
}


// Player 1 move
void player1Turn(void){
	printf("Player 1 Turn \n");
	int index;
	scanf("%d", &index);
	if(index>=1 && index<=9 && board[index]!='X' && board[index]!='O'){
		board[index] = 'X';
		printBoard();
	}else{
		printf("Enter a valid move!\n");
		printBoard();
		player1Turn();
	}
}


// Player 2 Move
void player2Turn(void){
	printf("Player 2 Turn \n");
	int index;
	scanf("%d", &index);
	if(index>=1 && index<=9 && board[index]!='X' && board[index]!='O'){
		board[index] = 'O';
		printBoard();
	}else{
		printf("Enter a valid move!\n");
		printBoard();
		player2Turn();
	}
}


// Check for win conditions
void checkWinner(void){
	// Horizontal win conditions
	if(board[1]=='X' && board[2]=='X' && board[3]=='X' )
		winner=1;
	if(board[1]=='O' && board[2]=='O' && board[3]=='O' )
		winner=2;
	if(board[4]=='X' && board[5]=='X' && board[6]=='X' )
		winner=1;
	if(board[4]=='O' && board[5]=='O' && board[6]=='O' )
		winner=2;
	if(board[7]=='X' && board[8]=='X' && board[9]=='X' )
		winner=1;
	if(board[7]=='O' && board[8]=='O' && board[9]=='O' )
		winner=2;

	// Vertical win conditions
	if(board[1]=='X' && board[4]=='X' && board[7]=='X' )
		winner=1;
	if(board[1]=='O' && board[4]=='O' && board[7]=='O' )
		winner=2;
	if(board[2]=='X' && board[5]=='X' && board[8]=='X' )
		winner=1;
	if(board[2]=='O' && board[5]=='O' && board[8]=='O' )
		winner=2;
	if(board[3]=='X' && board[6]=='X' && board[9]=='X' )
		winner=1;
	if(board[3]=='O' && board[6]=='O' && board[9]=='O' )
		winner=2;

	// Diagonal win conditions
	if(board[1]=='X' && board[5]=='X' && board[9]=='X' )
		winner=1;
	if(board[1]=='O' && board[5]=='O' && board[9]=='O' )
		winner=2;
	if(board[3]=='X' && board[5]=='X' && board[7]=='X' )
		winner=1;
	if(board[3]=='O' && board[5]=='O' && board[7]=='O' )
		winner=2;
}

