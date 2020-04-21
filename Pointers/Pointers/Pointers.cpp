// Pointers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include <iostream>

int main()
{
	// Pointer intro
	int a = 0; // variable with a value 0
	int* b = nullptr; // pointer to an int with a value of nullptr
	printf("Value of a %d, value of b %d\n", a, b);

	printf("Assing B to point to A\n");
	b = &a; // b = the address of the memory location for variable a
	printf("Value of a %d, value of b %d\n", a, b);
	printf("Address of a %d, value of b %d\n", &a, b);

	printf("Setting the value of a to 7\n");
	a = 7;
	printf("Value of a %d, value of b %d\n", a, b);
	printf("Value of a %d, value at address b %d\n", a, *b);

	printf("Set the value at address b to 8\n");
	*b = 8; // the value at the address provided by b is set to 8
	printf("Value of a %d, value of b %d\n", a, b);


	return 0;
}

