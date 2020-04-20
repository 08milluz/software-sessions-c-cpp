// HelloWorld.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// Include standard IO library
#include <stdio.h>
#include <iostream>

// Global Variables
unsigned int callCounter;

// Function Declarations
int printOnNewLine(unsigned int value, int myFavNumber);
void iQuit(int value);

// Main Function
int main()
{
	// Set global value to 0
	callCounter = 0;

	// Declare local variable and set it to 0
	int returnedFromFrunction = 0;

	// Print out to the user "Hello World!" and return a new line
    std::cout << "Hello World!\n"; 

	// Call function iQuit() with a value of 7
	iQuit(7);

	// Loop over iQuit() and printOnNewLine() 5 times
	// Store returned value from printOnNewLine() in returnedFromFrunction
	for (char i = 0; i < 5; i++)
	{
		returnedFromFrunction += printOnNewLine(i, 3);
		iQuit(returnedFromFrunction + 7);
	}

	// Return the value of returnedFromFrunction
	return returnedFromFrunction;
}
 
 // Prints text on a new line and increments callCounter based on myFavNumber
 // Returns the negitive value of callCounter
int printOnNewLine(unsigned int value, int myFavNumber)
{
	// If the passed in value is greater than myFavNumber, subtract myFavNumber from call Counter
	if (myFavNumber < value)
	{
		callCounter -= myFavNumber;
	}
	// Otherwise, add myFavNumber to callCounter
	else
	{
		callCounter += myFavNumber;
	}

	// Print to the user the value that is passed in with the text below
	printf("This is on a differnt line! We have called this %d time!\n", value);

	// Return the negitive value of callCounter
	return -1 * callCounter;
}

// Shows how to use an if, else if, else and also how to return in a void function
void iQuit(int value)
{
	// If value is 7, print a message and exit function
	if (value == 7)
	{
		printf("Value should not be 7!\n");
		return;
	}

	// If value is less than 0, add 2*value to the call counter
	if (value < 0)
	{
		callCounter += 2 * value;
	}
	// Otherwise, if value is greater than 10, increment callCounter
	else if(value > 10)
	{
		callCounter++;
	}
	// Finally, print a message if neither of the previous conditions are met
	else
	{
		printf("Here is the value of callCounter: %d\n", callCounter);
	}
}