// CvsCPP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// Header file for C code
extern "C"
{
#include "c.h"
}

// Header file for C++ code
#include "cpp.h"

#include <stdio.h>

// For the C++ class, include the namespace
using namespace CppClass;

int main()
{
    // C examples
    printf("C vs. C++ Example\n");
    printf("\n\nC examples\n\n");
    printf("Here is the return from my C function: %d\n", myFunction());

    // Example of a static function call. Note that no object is created here.
    printf("Here is the return from my C++ static class function: %d\n", MyClass::myFunctionCppStatic());

    printf("Here is data sent between things: %d\n", sendData(100));

    printf("Value of publicGlobal: %d\n", publicGlobal);
    publicGlobal = 200;
    printf("Value of publicGlobal after I set it: %d\n", publicGlobal);
    myFunction();
    printf("Value of publicGlobal after myFunction: %d\n", publicGlobal);

    printf("\n\nC++ examples\n\n");
    // C++ Examples
    MyClass a;
    printf("The starting value of A: %d\n", a.GetAZero());
    printf("Here is the return from my C++ class function: %d\n", a.myFunctionCpp());

    MyClass* aPtr = new MyClass();
    printf("The starting value of A: %d\n", aPtr->GetAZero());
    printf("Here is the return from my C++ class function: %d\n", aPtr->myFunctionCpp());
    printf("Here is the return from my C++ class function: %d\n", aPtr->myFunctionCpp());
    printf("Here is the return from my C++ class function: %d\n", aPtr->myFunctionCpp());

    // Clean up the class and make a new one
    delete aPtr;
    aPtr = new MyClass();
    printf("The starting value of b[542]: %d\n", aPtr->GetBFiveFortyTwo());
    aPtr->myFunctionCpp();
    printf("The new value of b[542]: %d\n", aPtr->GetBFiveFortyTwo());

    // Good form to delete the created class at the end of the function
    delete aPtr;
}

