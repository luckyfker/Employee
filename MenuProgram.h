#ifndef MENUPROGRAM_H
#define MENUPROGRAM_H

#include <iostream>
#include <string>
using namespace std;

#define EXIT 0

enum Task
{
	MAIN_MENU,
	ADDEMP_MENU
};

class MenuProgram
{
	public:
		virtual void run(Task task) = 0;
	public:
		virtual void printMenu(Task task) = 0;
		int getChoice();
		virtual void doTask(int choice, Task task) = 0;
		
		virtual ~MenuProgram();
};

#endif
