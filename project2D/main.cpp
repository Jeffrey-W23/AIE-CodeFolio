#include "Application2D.h"
#include <crtdbg.h>
#include "Heap.h"
#include <iostream>
using namespace std;

int main() {
	
	// Memory leak check
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);


	Heap<int> heap;

	heap.Push(10);
	heap.Push(4);
	heap.Push(5);

	cout << heap.Pop() << endl;
	cout << heap.Pop() << endl;
	cout << heap.Pop() << endl;

	// allocation
	auto app = new Application2D();

	// initialise and loop
	app->run("AIE", 1280, 720, false);

	// deallocation
	delete app;

	return 0;
}