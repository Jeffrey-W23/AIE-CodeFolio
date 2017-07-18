#include "Application2D.h"
#include <crtdbg.h>
#include "Heap.h"
#include <iostream>
#include "FunctionPointerTestClass.h"
using namespace std;

void Cat(float cat)
{
	cout << "Your number is: " << cat << endl;
}



int main() {

	FunctionPointerTestClass tc;
	tc.SetFunction(&Cat);
	tc.Callfunction();
	
	// Memory leak check
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	// allocation
	auto app = new Application2D();

	// initialise and loop
	app->run("AIE", 1280, 720, false);

	// deallocation
	delete app;

	return 0;
}