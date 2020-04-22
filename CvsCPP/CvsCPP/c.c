#include "c.h"


int a[5];

int myFunction()
{
    a[0]++;
    a[1]++;
    a[2]++;
    a[3]--;
    a[4]--;

    return a[0];
}

int sendData(int value)
{
    a[4] += value;
    return a[4];
}
