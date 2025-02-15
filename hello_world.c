




























// what is memory leak?
// what is garbage collector?
// %i vs %d


#include <stdio.h>

int add3(int a, int b, int c) {
	int result = a + b + c ;
	return result;
}


int main(void) {

	int y = 7;
	int *p = &y; // point to variable y

	int * pX = &x; // astrix is used to modify a type
	int y = *pX // astrix is used as "de-reference" - grabs value from the address given 
	
	// arrow used insttead of pointer - signifies "go to this address and then get ___ value"
	
	// adding or subtracting fdrom pointer values moves it by a multiple of the bits in order to skip the "block" of memory assigned to an x bit variable and onto the next

	// ig * for a string (array of charecters) exists so that you can "point" to the first charecter and then you just need to know the number of charecters in order to create a string
	
	if (x == 10) {
		printf("Equal");
	}

	else if (x < 10) {
		printf("Less Than");
	}

	int count = 10;
	count += 5;
	count ++;
	count --;
	

	while (counter < 10) {
		printf("Test");
		break;
	}

	do {
		printf("Test");
	} while (counter < 10) 

	
	for (int i = 0; i < 5; i++) { // (init; condition; instructions for next step)
		printf("Test");
	}
	
	y = x++; // y will become previous value of x and x will be incrimented
	y = ++x // x will be incremented and y will also take the final value

	*p = 10;
	
	struct person me; // why is "person" highlighted
	me.age = 15;

	int x[2];
	x = [1, 0]; // can you define arrays like this? how do u print arrays?
	
	// you can assign arrays but not other data types to pointers 

	int myNumber = 0;
	int hello;

	// printf("%i", hello); // prints the memory location instead
	printf("hello, world\n");
	printf("add3 = %i\n", add3(3, 32, 23));
}

































