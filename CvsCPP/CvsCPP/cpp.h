#pragma once

// Preprocessor definition of a value
#define BSIZE 1000

// Grouping of all classes and values for CppClass. A namespace is sort of like a logical storage bin
namespace CppClass 
{
    // Constant definition of a value, local to this namespace
    const int arraySizeInfo = 5000;

    // Object called My Class
    class MyClass
    {
        // Values and functions only accessible to the object
    private:

        // Example of a private statically declared array
        int a[5];

        // Example of a private, dynamically declared array
        int* b;

        // Function to add a value that can only be accessed by the object
        int addToSomething(int value);

        // Values and functions anyone can use
    public:

        // Constructor. Automatically runs when object is created. There is not return from a constructor.
	    MyClass();

        // Destructor. Automatically runs when object is deleted. There is no return from a destructor.
	    ~MyClass();

        // Function that does not require the object to be created to use, see exmaple in CvsCPP.cpp
        static int myFunctionCppStatic();

        // Function anyone can call on the object to do stuff
        int myFunctionCpp();

        // Function to return a specific value from a private member
        int GetAZero() { return a[0]; };

        // Function to return a specific value from a private member, with checks for size due to dynamic allocation
        int GetBFiveFortyTwo() {
            if (542 < arraySizeInfo) { return b[542]; }
            else { return 0; }
        };
    };
}
