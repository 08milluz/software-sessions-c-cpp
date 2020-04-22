#include "cpp.h"

// Tell the complier we are using things defined in this namespace
using namespace CppClass;

// Declare the constructor. This should not be used for logic, only initializing memory and setting initial values
// Note that MyClass:: before the function name indicates it is part of the class
MyClass::MyClass()
{
    a[0] = 400;
    b = new int[arraySizeInfo];
    for (int i = 0; i < arraySizeInfo; i++)
    {
        b[i] = 4;
    }
}

// Destructor to clean up allocated memory
MyClass::~MyClass()
{
    // Use delete[] due to memory being declared as an array
    delete[] b;
}

// Static function that does not require the object to be created
// Note that a static function cannot operate on the object (since it may not be created when called)
int CppClass::MyClass::myFunctionCppStatic()
{
    return 10;
}

// Demo public function to do stuff
int MyClass::myFunctionCpp()
{
    // Calls private method to operate on data
    b[542] = addToSomething(17);
    a[0] += 9;
    return a[0];
}

// Private method to simply add 1024
int MyClass::addToSomething(int value)
{
    value += 1024;
    return value;
}