#include "FunctionPointerExampleClass.h"

void FunctionPointerExampleClass::Callfunction()
{
	myFunc(5.0f);
}

void FunctionPointerExampleClass::SetFunction(MyFunction func)
{
	myFunc = func;
}