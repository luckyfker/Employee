#include "DemoEmployee.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {

	
	DemoEmployee demo;
	demo.readFromFile();
	demo.run(MAIN_MENU);
	
	
	return 0;
}

