#include <stdio.h>
#include <stdbool.h>

/*

how do you take in multiple user input ?? 

3x3 matrix as a representation of the tictactoe grid
 - with 0 having 0 and 1 having x

each "box" has a border like =>

-----
|   |
-----

board will likely look like this =>


----- ----- ----- 
|   | |   | |   |
----- ----- -----
----- ----- ----- 
|   | |   | |   |
----- ----- -----
----- ----- ----- 
|   | |   | |   |
----- ----- -----

*/


// TODO: Scale to NxN where N is odd type of grids in the end

// TODO: optimal move algorithm (create a perfect both for first standard 3x3 and then nxn)

// TODO: ask chatgpt how could could be more effecient especially the winning algo since the entire point of using c is speed


void printBoard(int board[3][3]) {
	// TODO: figure out a way to "referesh" instead of print
	
	for (int i = 0; i < 3; i++) {
		printf("\n----- ----- -----\n");
		for (int j = 0; j < 3; j++) {
			printf("|");
			printf(" ");
			if (board[i][j] == 0) {
				printf(" ");
			}
			else if (board[i][j] == 1){
				printf("X");
			}
			else {
				printf("O");
			}

			printf(" ");
			printf("|");
			printf(" ");
		}
	}

	printf("\n----- ----- -----\n");	
}

void takeTurn(int board[3][3], int currentPlayer) {

	int row_inp;
	int col_inp;

	// TODO: implement error handling for input
	
	// 1. [x] correct range (only 1, 2 and 3)
	// 2. no other formats and datatypes
	// 3. [x] not on the same square if it's already marked

	bool notReplacing = false;

	while (notReplacing == false) {

		bool inRange = false;
		
		while (inRange == false) {
			printf("Player %i (Row) : ", currentPlayer);
			scanf("%i", &row_inp);

			if (row_inp >= 1 && row_inp <= 3) {
				inRange = true;
			}
		}
		
		inRange = false;

		while (inRange == false) {
			printf("Player %i (Col) : ", currentPlayer);
			scanf("%i", &col_inp);

			if (col_inp >= 1 && col_inp <= 3) {
				inRange = true;
			}
		}

		if (board[row_inp-1][col_inp-1] == 0) {
			notReplacing = true;
		}

	}

	if (currentPlayer == 1) {
		board[row_inp-1][col_inp-1] = 1;
	}
	else {
		board[row_inp-1][col_inp-1] = 2;
	}
}

int main() {

	int board[3][3] = {0};
	

	bool halt = false;

	int currentPlayer = 1;

	while (halt == false) {

		printBoard(board);
		takeTurn(board, currentPlayer);

		if (currentPlayer == 1) {
			currentPlayer = 2;
		}
		else {
			currentPlayer = 1;
		} 
		
		// use a different strategy for halting - define "consecutive" and then halt game at any 3 consecutive X or Os
		
		for (int i = 0; i < 3; i++) {
				if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != 0) {
					halt = true;
				}
			}	
		
		for (int j = 0; j < 3; j++) {
			if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] != 0) {
				halt = true;
			}
		}

		if (((board[0][0] == board[1][1] && board[1][1] == board[2][2]) || (board[0][2] == board[1][1] && board[1][1] == board[2][0])) && board[1][1] != 0) {
			halt = true;
		}

	}

	printBoard(board);

	printf("\nPlayer %i Wins!\n", currentPlayer);
	
	return 0;

}
