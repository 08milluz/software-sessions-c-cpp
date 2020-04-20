// HelloWorld.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <stdio.h>
#include <iostream>

unsigned int callCounter;

int printOnNewLine(unsigned int value);

int main()
{
	callCounter = 0;
	int returnedFromFrunction = 0;
    std::cout << "Hello World!\n"; 
	for (char i = 0; i < 5; i++)
	{
		returnedFromFrunction += printOnNewLine(i+7);
	}
	return returnedFromFrunction;
}

int printOnNewLine(unsigned int value)
{
	callCounter++;
	printf("This is on a differnt line! We have called this %d time!\n", value);
	return -1 * callCounter;
}
