#include "Application2D.h"
#include <crtdbg.h>
#include <iostream>
#include "FunctionPointerExampleClass.h"
using namespace std;

// Function pointer example
	//void Cat(float cat)
	//{
	//	cout << "Your number is: " << cat << endl;
	//}

int main() {

	// Function pointer example
		/*FunctionPointerExampleClass tc;
		tc.SetFunction(&Cat);
		tc.Callfunction();*/
	
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