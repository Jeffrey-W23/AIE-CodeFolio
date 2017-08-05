// #includes, using, etc
#include "FunctionPointerExampleClass.h"

// Call the function pointer.
void FunctionPointerExampleClass::Callfunction()
{
	myFunc(5.0f);
}

// Set the function pointer.
void FunctionPointerExampleClass::SetFunction(MyFunction func)
{
	myFunc = func;
}