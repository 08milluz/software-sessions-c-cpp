#pragma once

#define BSIZE 1000

namespace CppClass 
{
    const int arraySizeInfo = 5000;

    class MyClass
    {
    private:
        int a[5];
        int* b;
    public:
	    MyClass();
	    ~MyClass();
        static int myFunctionCppStatic();
        int myFunctionCpp();
        int GetAZero() { return a[0]; };
        int GetBFiveFortyTwo() {
            if (542 < arraySizeInfo) { return b[542]; }
            else { return 0; }
        };
    };
}
