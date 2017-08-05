// #includes, using, etc
#pragma once

// This is a class that is an example of how to use Function pointers.

// In the order written its typedef, the Return type, Function pointer name, the input parameter.
typedef void(*MyFunction)(float);

// Example class
class FunctionPointerExampleClass
{
public:

	// Call the function pointer.
	void Callfunction();

	// Set the function pointer.
	void SetFunction(MyFunction func);
	
	// assign MyFunction to the var myFunc and set to null.
	MyFunction myFunc = nullptr;
};