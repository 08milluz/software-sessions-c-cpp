#include "cpp.h"

#include <stdio.h>
#include <string.h>

using namespace CppClass;

MyClass::MyClass()
{
    a[0] = 400;
    b = new int[arraySizeInfo];
    for (int i = 0; i < arraySizeInfo; i++)
    {
        b[i] = 4;
    }
}


MyClass::~MyClass()
{
    delete[] b;
}

int CppClass::MyClass::myFunctionCppStatic()
{
    return 10;
}

int CppClass::MyClass::myFunctionCpp()
{
    b[542] = 17;
    a[0] += 9;
    return a[0];
}
