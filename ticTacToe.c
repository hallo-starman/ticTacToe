/*
*
*	Author: Shelby Pace
*	Tic Tac Toe program
*/

#include <stdio.h>
#include "ticTacToe.h"

// the board
char gameBoard[3][3];

int main(int argc, char* argv[])
{
	// create a test board to use to test the printBoard function
	char myBoard[3][3] = {{'x', ' ', 'o'}, {'x', 'x', ' '}, {'o', 'x', 'o'}};
	char myBoard2[3][3] = {{'x', 'x', 'o'}, {'x', 'o', ' '}, {'o', ' ', 'o'}};
	printBoard(myBoard);
	printBoard(myBoard2);
	init();

}

void init()
{
	// initialize gameboard with empty spaces
	// then print the board
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			gameBoard[i][j] = ' ';
		}
	}

	printBoard(gameBoard);

}

void printBoard(char board[][3])
{
	// run through each index and print out each cell
	for(int i = 0; i < 3; i++)
	{
		printf("| ");

		for(int j = 0; j < 3; j++)
		{
			printf("%c | ", board[i][j]);
		}

		printf("\n");
	}

	printf("\n");


}
