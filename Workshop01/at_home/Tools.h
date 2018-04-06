#ifndef WS1_TOOLS_H
#define WS1_TOOLS_H

#include <iostream>

using namespace std;

namespace ws1 {
	// Displays the user interface menu
	int menu();
	// Performs a fool-proof integer entry
	int getInt(int min, int max);
}

#endif // ! WS1_TOOLS_H
