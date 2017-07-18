#include "FunctionPointerTestClass.h"

void FunctionPointerTestClass::Callfunction()
{
	myFunc(5.0f);
}

void FunctionPointerTestClass::SetFunction(MyFunction func)
{
	myFunc = func;
}