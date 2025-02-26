




















































#include <stdio.h>
#include <stdlib.h>

// malloc, calloc, realloc and free


int main() {

	int n;
	printf("Number Of Elements : ");
	scanf("%i", &n);

	int * ptr;

	ptr = (int *) malloc(n*sizeof(int));
	// ptr = (int *) calloc(n, sizeof(int));


	for (int i = 0; i < n; i++) {
		printf("Index %i", i);
		scanf("%i", &ptr[i]);
	}

	for (int i = 0; i < n; i++) {
		printf("Index %i : %i\n", i, ptr[i]);
	}

	// Reallocate The Same Memory Now

	printf("\nNumber Of Elements : ");
	scanf("%i", &n);
	
	ptr = (int *) realloc(ptr, n*sizeof(int));


	for (int i = 0; i < n; i++) {
		printf("Index %i", i);
		scanf("%i", &ptr[i]);
	}

	for (int i = 0; i < n; i++) {
		printf("Index %i : %i\n", i, ptr[i]);
	}

	// Free Memory
	
	free(ptr);

	return 0;
}






























