/*
*
*	Author: Shelby Pace
*	Tic Tac Toe program
*/

#include <stdio.h>
#include "ticTacToe.h"

// the board
char gameBoard[3][3];
// state that determines whose play it is
int p1;
int turns, win;

int main(int argc, char* argv[])
{
	// create a test board to use to test the printBoard function
	/*	
	char myBoard[3][3] = {{'x', ' ', 'o'}, {'x', 'x', ' '}, {'o', 'x', 'o'}};
	char myBoard2[3][3] = {{'x', 'x', 'o'}, {'x', 'o', ' '}, {'o', ' ', 'o'}};
	printBoard(myBoard);
	printBoard(myBoard2);
	*/	

	/* for the console version, the game should run until the user chooses to quit
	* after the game ends, show the final result, and then start a new game
	*/
	while(playing())
		;

	printf("End game\n");
}

// official entrance into the game
// this will request a choice from the player
// either a spot on the board or the escape sequence to exit the game
int playing()
{
	int c;
	init();
	while((c = getchar()) != EOF)
	{
		if(c != '\n')
		{
			// if no winner, keep playing
			if(!win)
			{
				placeChoice(c);
			}
			// else, declare the winner
			else
			{
				if(p1)
				{
					printf("Player 1 wins!\n");
				}
				else
				{
					printf("Player 2 wins!\n");
				}
			}
		}
	}
	
	return 0;
}

// initial game state
void init()
{
	// player one goes first
	p1 = 1;
	turns, win = 0;
	printf("To enter a spot on the board, input the number (1-9) that corresponds to the space on the board\n");
	printf(" 1 | 2 | 3\n 4 | 5 | 6\n 7 | 8 | 9\n");
	putchar('\n');

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

void placeChoice(char choice)
{
	// get the numeric form of choice
	int play = choice - '0';
	int row, col = 0;

	// the board is a 2d array with 3 rows & 3 columns
	// the input for each column needs to be 0-2,
	// but the input asked for is 1-9
	// transform the play, check the current position, and either place on board or not
	if(play <= 9 && play > 0)
	{
		// first set the play to be within the range of 0-1
		play-=1;
		// then get corresponding row and column
		row = play / 3;
		col = play % 3;
		// printf("%d	%d  \n", row, col);
		// test for emptiness, place respective symbol if so
		if(p1 && gameBoard[row][col] == ' ')
		{
			gameBoard[row][col] = 'x';
			p1 = 0;
			turns++;
			printBoard(gameBoard);
		}
		else if(!(p1) && gameBoard[row][col] == ' ')
		{
			gameBoard[row][col] = 'o';
			p1 = 1;
			turns++;
			printBoard(gameBoard);
		}
		else
		{
			printBoard(gameBoard);
			printf("Selection not empty\n");
		}

		// five turns is the minimum for a win
		if(turns >= 5)
		{
			checkForWin();
		}

	}
	else
	{
		printf("Guess is not within bounds specified\n");
	}

}

int checkForWin()
{

}

void printBoard(char board[][3])
{
	// run through each index and print out each cell
	for(int i = 0; i < 3; i++)
	{
		putchar(' ');
		for(int j = 0; j < 3; j++)
		{
			if(j == 2)
			{
				printf("%c", board[i][j]);
			}
			else
			{
				printf("%c | ", board[i][j]);
			}
		}

		printf("\n");
	}

	printf("\n");

}
