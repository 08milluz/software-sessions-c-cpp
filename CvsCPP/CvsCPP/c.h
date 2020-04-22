#pragma once

// Publically accessible integer from anyone including this header
extern int publicGlobal;

// Example function
int myFunction();

// Public function to set and read a value from an array that is not publically accessible
int sendData(int value);

// Example struct to store X and Y position data
struct position
{
    int x;
    int y;
};