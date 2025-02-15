













































#include <stdio.h>

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

int printBoard(int * board[3]) {
	// figure out a way to "referesh" instead of print
	
	for (int i = 0; i < 3; i++) {
		printf("\n----- ----- -----\n");
		for (int j = 0; j < 3; j++) {
			printf("|");
			printf(" ");
			if (board[i][j] == 0) {
				printf("O");
			}
			else {
				printf("X");
			}

			printf(" ");
			printf("|");
			printf(" ");
		}
	}

	printf("\n----- ----- -----\n");
	
	return 0;
}

int main() {


	int * board[3]; // why does it have to be * and [3] ? why cant it be [3][3]?

	int row[3] = {0, 0, 0};

	board[0] = row;
	board[1] = row;
	board[2] = row;
	
	printBoard(board);

	return 0;

}










































