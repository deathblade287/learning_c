



























#include <stdio.h>

// globally available struct
// When you do this, you’re making a new type. The full type name is struct car. (Not just car—that won’t work.)

struct car {
	char * name;
	float price;
	float zeroTo60;
};

// • If you have a struct, use dot (.).
// • If you have a pointer to a struct, use arrow (->).

void set_price(struct car *c, float new_price) { // accepting a pointer of type "struct car" hence the * at the end
	// (*c).price = new_price; // Works, but non-idiomatic :(
	
	// The line above is 100% equivalent to the one below:

	c->price = new_price; // That's the one!
}

int main() {

	// struct car porche_911;
	// porche_911.name = "Porche 911 Turbo S";
	// porche_911.price = 250000;
	// porche_911.zeroTo60 = 2.9;

	// OR
	
	// struct car porche_911 = {"Porche 911 Turbo S", 250000, 2.9}; // have to enter in the same order as the definition + no good way of communicating field name in code
	
	// OR

	struct car porche_911 = {.name = "Porche 911 Turbo S", .price = 250000, .zeroTo60 = 2.9}; // enter in any order

	return 0;
}




































