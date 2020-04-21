// Pointers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include <iostream>

#include "PointerFunctions.h"
#include "FunctionHeader.h"

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

	int* memblock;
	int** memblockptr; // Pointer to a pointer
	memblock = (int*)malloc(2000000000*sizeof(int)); // This allocates like 7.5 GB of memory, you may need to make this smaller for your comptuer. Also it can take a while.

	*memblock = 5;
	printf("Value at the first integer of memblock: %d\n", *memblock);

	memblock[0] = 15;
	printf("Value at the first integer of memblock: %d\n", *memblock);

	memblock[10] = 1000;
	printf("Value at the tenth integer of memblock: %d\n", memblock[10]);

	memblock += 10;
	*memblock = 1500;
	memblock -= 10;
	printf("Value at the tenth integer of memblock: %d\n", memblock[10]);

	printf("Using memblockptr to set a value.\n");
	memblockptr = &memblock;
	(*memblockptr)[5000] = 7;
	printf("Value at the 50th integer of memblock: %d\n", memblock[5000]);

	// Release that memory back to the comptuer.
	free(memblock);


	// Using Header File Functions
	globalVal = 0;
	const int inc = 1;
	while (globalVal < 15)
	{
		ConstIncGlobalVars(&inc);
		printf("Value of globalVal is: %d\n", globalVal);
	}

	// Demo header file functions
	int Andy = 5;
	int returnVal = AddOne(Andy);
	printf("Value of Andy is %d\n", Andy);
	printf("Value of returnVal is %d\n", returnVal);

	return 0;
}

