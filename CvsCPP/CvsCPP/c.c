#include "c.h"

// Publicl gloabl, declared extren in header file
int publicGlobal = 7;

// Private global, only accessible to this file
int a[5];

// Adds 500 to publicGlobal, function is private to this file
void addToGlobal()
{
    publicGlobal += 500;
}


// Public function to do some various differnt things
int myFunction()
{
    // Creates instance of a struct to store and use data
    struct position car;
    car.x = 5;
    car.y = 19;

    // Operates on private (local to this file) array
    a[0]++;
    a[1] += car.x;
    a[2]++;
    a[3]-= car.y;
    a[4]--;

    // Calls private (local to this file) function to operate on the public global variable
    addToGlobal();
    return a[0];
}


// Public function to operate on the private (local to this file) array and return one of its values
int sendData(int value)
{
    a[4] += value;
    return a[4];
}
