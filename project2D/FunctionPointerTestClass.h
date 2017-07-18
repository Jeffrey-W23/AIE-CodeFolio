#pragma once

// Return/Type/Input
typedef void(*MyFunction)(float);

class FunctionPointerTestClass
{
public:
	void Callfunction();
	void SetFunction(MyFunction func);

	MyFunction myFunc = nullptr;
};