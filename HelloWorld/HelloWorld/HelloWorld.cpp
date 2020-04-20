// HelloWorld.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <stdio.h>
#include <iostream>

unsigned int callCounter;

void printOnNewLine();

int main()
{
	callCounter = 0;
    std::cout << "Hello World!\n"; 
	printOnNewLine();
	printOnNewLine();
	printOnNewLine();
	printOnNewLine();
	printOnNewLine();
	return 0;
}

void printOnNewLine()
{
	callCounter++;
	printf("This is on a differnt line! We have called this %d time!\n", callCounter);
}
