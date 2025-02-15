




















#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {

	int nrows = atoi(argv[1]);

	// checks if nrows is between 0 and 8 (incl. whether it is even an integer or not) and keeps asking if not after giving error msg 
	// have to learn catch and throw and also take in the input again as it's ann arguement, not a line of code
	
	for (int i = 1; i < nrows + 1; i++) {

		/*
		 
		space => nrows - i	
		hash 1 => i
		space => 1
		hash 2 => i
		\n

		*/

		
		for (int j = 0; j < nrows - i; j++) {
			printf(" ");
		}

		for (int j2 = 0; j2 < i; j2++) {
			printf("#");
		}

		printf(" ");

		for (int j3 = 0; j3 < i; j3++) {
			printf("#");
		}

		printf("\n");

		
	}

	return 0;
}
