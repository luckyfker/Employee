#ifndef DEMOEMPLOYEE_H
#define DEMOEMPLOYEE_H

#include <sstream>
#include <fstream>
#include <vector>
#include "Fulltime.h"
#include "Parttime.h"
#include "Hourly.h"
#include "list.h"

#define EXIT 0
#define ADDEMPLOYEE 1
#define EDIT 2
#define DELETE 3
#define PRINT 4
#define SEARCH 5

#define FULLTIME 1
#define PARTTIME 2
#define HOURLY 3

#define NAME 1
#define AGE 2
#define TELEPHONE 3
#define RATING 4

enum Task
{
	MAIN_MENU,
	ADDEMP_MENU,
	EDIT_MENU
};

class DemoEmployee
{
	private:
		Node* find;
		LList empList;
	public:
		DemoEmployee();
		int getChoice();
		void run(Task task);
		void printMenu(Task task);
		void doTask(int choice, Task task);
		
		void editEmployee();
		void deleteEmployee();
		void printAll();
		void searchEmployee();
		void exitAndSave();
		void readFromFile();
		
		~DemoEmployee();
		
	private:
		void addEmployee();
		void addEmployFulltime();
		void addEmployParttime();
		void addEmployHourly();
		void showError();
        void exitProgram();
        
        void editName();
        void editAge();
        void editTelephone();
        void editRating();
};

#endif
