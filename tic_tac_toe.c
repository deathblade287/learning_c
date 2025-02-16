













































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


// todo : scale to 5x5 and nxn where n is odd type of grids in the end
// ask chatgpt how could could be more effecient especially the winning algo since the entire point of using c is speed

int printBoard(int ** board) {
	// figure out a way to "referesh" instead of print
	
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
	
	return 0;
}

int ** takeTurn(int ** board, int currentPlayer) {

	int row_inp;
	int col_inp;

	// implement error handling for input
	scanf("%i", &row_inp);
	scanf("%i", &col_inp);
	
	if (currentPlayer == 1) {
		board[row_inp-1][col_inp-1] = 1;
	}
	else {
		board[row_inp-1][col_inp-1] = 2;
	}

	
	return board;
}

int main() {


	int ** board; // why does it have to be * and [3] ? why cant it be [3][3]?

	int row[3] = {0, 0, 0};

	board[0] = row;
	board[1] = row;
	board[2] = row;

	bool halt = false;

	int currentPlayer = 1;

	while (halt == false) {
		printBoard(board);
		board = takeTurn(board, currentPlayer);

		if (currentPlayer == 1) {
			currentPlayer = 2;
		}
		else {
			currentPlayer = 1;
		}

		for (int i = 0; i < 3; i++) {
				if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && (board[i][0] + board[i][1] + board[i][2]) / 3 != 0) {
					halt = true;
				}
			}	
		
		for (int j = 0; j < 3; j++) {
			if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && (board[0][j] + board[1][j] + board[2][j]) / 3 != 0) {
				halt = true;
			}
		}

		if ((board[0][0] == board[1][1] && board[1][1] == board[2][2] && (board[0][0] + board[1][1] + board[2][2]) / 3 != 0) || (board[0][2] == board[1][1] && board[1][1] == board[2][0] && (board[0][2] + board[1][1] + board[2][0]) / 3 != 0)) {
			halt = true;
		}

	}

	// 1. define "consecutive" and then halt game at any 3 consecutive X or Os
	// 2. indvidually defifne vertical, horizontal and diagnol winning positions
	
	
	
	
	return 0;

}










































