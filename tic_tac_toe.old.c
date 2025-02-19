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
// optimal move algorithm (create a perfect both for first standard 3x3 and then nxn)
// ask chatgpt how could could be more effecient especially the winning algo since the entire point of using c is speed



/*

int printBoardDebug(int ** board) {
	for (int i = 0; i < 3; i++) {
		printf("\n----- ----- -----\n");
		for (int j = 0; j < 3; j++) {
			printf("|");
			printf(" ");
			printf("%i", board[i][j]);
			printf(" ");
			printf("|");
			printf(" ");
		}
	}
	return 0;
}

*/

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

	printf("%i", row_inp);
	printf("%i", col_inp);
	
	if (currentPlayer == 1) {
		board[row_inp-1][col_inp-1] = 1;
	}
	else {
		board[row_inp-1][col_inp-1] = 2;
	}

	printf("New Value In Row %i & Column %i : %i", row_inp-1, col_inp-1, board[row_inp-1][col_inp-1]);

	return board;
}

int main() {

	int ** board; // why does it have to be either ** or (* and [3]) ? why cant it be [3][3]?


	int row0[3] = {0, 0, 0};
	int row1[3] = {0, 0, 0};
	int row2[3] = {0, 0, 0};

	board[0] = row0;
	board[1] = row1;
	board[2] = row2;

	bool halt = false;

	int currentPlayer = 1;

	while (halt == false) {

		printBoard(board);
		printf("Player %i : ", currentPlayer);
		board = takeTurn(board, currentPlayer);

		if (currentPlayer == 1) {
			currentPlayer = 2;
		}
		else {
			currentPlayer = 1;
		} 
		
		/*
			
		for (int i = 0; i < 3; i++) {
				if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
					halt = true;
				}
			}	
		
		for (int j = 0; j < 3; j++) {
			if (board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
				halt = true;
			}
		}

		if ((board[0][0] == board[1][1] && board[1][1] == board[2][2]) || (board[0][2] == board[1][1] && board[1][1] == board[2][0])) {
			halt = true;
		}

		*/

	}

	// 1. define "consecutive" and then halt game at any 3 consecutive X or Os
	// 2. indvidually defifne vertical, horizontal and diagnol winning positions
	
	return 0;

}
