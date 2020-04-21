#include "PointerFunctions.h"

int globalVal;

void IncGlobalVars(int * valueToIncrement)
{
	globalVal += *valueToIncrement;
	// also double valueToIncrement
	*valueToIncrement *= 2; 
}

void ConstIncGlobalVars(const int * valueToIncrement)
{
	globalVal += *valueToIncrement;
	// also double valueToIncrement
	//*valueToIncrement *= 2; // can no longer execute due to const int
}
