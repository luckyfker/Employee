#include "DemoEmployee.h"
#include <limits>
#include <fstream>

DemoEmployee::DemoEmployee()
{
	find = NULL;
}

int DemoEmployee::getChoice()
{
	int choice;
	cout << "Enter your choice: ";
	cin >> choice;	
	
	while (cin.fail()) {
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "You have entered wrong input! Enter your choice again: ";
		cin >> choice;
	}
	
	return choice;
}

void DemoEmployee::run(Task task)
{
	bool quit = false;
	while (!quit) {
		printMenu(task);
		int choice = getChoice();
		doTask(choice, task);
		quit = choice == EXIT;
	}
}

void DemoEmployee::printMenu(Task task)
{
	switch (task) {
		case MAIN_MENU:
			cout << "************* Demo Employee *************" << endl;
			cout << "1. Add Employee" << endl;
			cout << "2. Edit Employee" << endl;
			cout << "3. Delete Employee" << endl;
			cout << "4. Print all" << endl;
			cout << "5. Search employee" << endl;
			cout << "0. Exit & Save to file" << endl;
			break;
		case ADDEMP_MENU:
			cout << "************* Add Employee *************" << endl;
			cout << "1. Add employee full time" << endl;
			cout << "2. Add employee part time" << endl;
			cout << "3. Add employee hourly" << endl;
			cout << "0. Exit" << endl;
			break;
		case EDIT_MENU:
			cout << "************* Edit information Employee *************" << endl;
			cout << "1. Edit name" << endl;
			cout << "2. Edit age" << endl;
			cout << "3. Edit telephone" << endl;
			cout << "4. Edit rating" << endl;
			cout << "0. Exit" << endl;
		default:
			showError();
			break;
	}
}

void DemoEmployee::doTask(int choice, Task task)
{
	if (task == MAIN_MENU) {
		switch (choice) {
			case ADDEMPLOYEE:
				addEmployee();
				break;
			case EDIT:
				editEmployee();
				break;
			case DELETE:
				deleteEmployee();
				break;
			case PRINT:
				printAll();
				break;
			case SEARCH:
				searchEmployee();
				break;
			case EXIT:
				exitAndSave();
				exitProgram();
				break;
			default:
				showError();
				break;
		}
	} else if (task == ADDEMP_MENU) {
		switch (choice) {
			case FULLTIME:
				addEmployFulltime();
				break;
			case PARTTIME:
				addEmployParttime();
				break;
			case HOURLY:
				addEmployHourly();
				break;
			case EXIT:
				break;
			default:
				showError();
				break;
		}
	} else if (task == EDIT_MENU) {
		switch (choice) {
			case NAME:
				editName();
				break;
			case AGE:
				editAge();
				break;
			case TELEPHONE:
				editTelephone();
				break;
			case RATING:
				editRating();
				break;
			case EXIT:
				break;
			default:
				showError();
				break;
		}
	} else {
		
	}
}

void DemoEmployee::addEmployee()
{
	run(ADDEMP_MENU);
}

void DemoEmployee::addEmployFulltime()
{
	int id;
	string name;
	int age;
	string telephone;
	double rating;
	cout << "Input id employee: "; cin >> id;
	cout << "Input name employee: "; cin.ignore(); getline(cin, name);
	cout << "Input age employee: "; cin >> age;
	cout << "Input telephone employee: "; cin >> telephone;
	cout << "Input rating employee: "; cin >> rating;
	
	Employee *e = new Fulltime(id, name, age, telephone, rating, E_FULLTIME);
	
	empList.insert(e);
}

void DemoEmployee::addEmployParttime()
{
	int id;
	string name;
	int age;
	string telephone;
	double rating;
	cout << "Input id employee: "; cin >> id;
	cout << "Input name employee: "; cin.ignore(); getline(cin, name);
	cout << "Input age employee: "; cin >> age;
	cout << "Input telephone employee: "; cin >> telephone;
	cout << "Input rating employee: "; cin >> rating;
	
	Employee *e = new Parttime(id, name, age, telephone, rating, E_PARTTIME);
	
	empList.insert(e);
}

void DemoEmployee::addEmployHourly()
{
	int id;
	string name;
	int age;
	string telephone;
	double rating;
	double hours;
	cout << "Input id employee: "; cin >> id;
	cout << "Input name employee: "; cin.ignore(); getline(cin, name);
	cout << "Input age employee: "; cin >> age;
	cout << "Input telephone employee: "; cin >> telephone;
	cout << "Input rating employee: "; cin >> rating;
	cout << "Input hours employee: "; cin >> hours;
	
	Employee *e = new Hourly(id, name, age, telephone, rating, hours, E_HOURLY);
	
	empList.insert(e);
}

void DemoEmployee::editEmployee()
{
	int id;
	cout << "Enter ID employee want to edit information: "; cin >> id;
	try {
		find = empList.search(id);
	} catch (const char* msg) {
		cerr << msg << endl;
	}
	run(EDIT_MENU);
}

void DemoEmployee::editName()
{
	string name;
	cout << "Enter new name: "; cin.ignore(); getline(cin, name);
	find->emp->setName(name);
}

void DemoEmployee::editAge()
{
	int age;
	cout << "Enter new age: "; cin >> age;
	find->emp->setAge(age);
}

void DemoEmployee::editTelephone()
{
	string telephone;
	cout << "Enter new telephone: "; cin >> telephone;
	find->emp->setTelephone(telephone);
}

void DemoEmployee::editRating()
{
	double rating;
	cout << "Enter new rating: "; cin >> rating;
	find->emp->setRating(rating);
}

void DemoEmployee::deleteEmployee()
{
	int id;
	cout << "Enter ID employee want to delete: "; cin >> id;
	try {
		empList.remove(id);
	} catch (const char* msg) {
		cerr << msg << endl;
	}
}

void DemoEmployee::searchEmployee()
{
	string name;
	cout << "Enter name employee want to show information: "; cin.ignore(); getline(cin, name);
	try {
		find = empList.search(name);
		cout << *find->emp;
	} catch (const char* msg) {
		cerr << msg << endl;
	}
}

void DemoEmployee::showError()
{
	cout << "Invalid choice! Please try again!" << endl;
}

void DemoEmployee::exitProgram()
{
    cout << "Program quits. See you again!" << endl;
}

void DemoEmployee::printAll()
{
	// if empty, print []
    if (empList.isEmpty()) cout << "[]" << endl;
    else {
    	Node *n = empList.head;
    // TODO: print n->key, loop until n->next == NULL
	    while (n != NULL) {
	    	cout << *n->emp;
			n = n->next; 
		}
	}
}

void DemoEmployee::exitAndSave()
{
	ofstream out ("Employee.txt");
	if (out.is_open()) {
		if (empList.isEmpty()) {
			cout << "List is empty!" << endl;
			out.close();
			return;
		} else {
			cout << "Saving ..." << endl;
			Node *n = empList.head;
			while (n != NULL) {
				//out << *n->emp->getID() << " " << *n->emp->getName() << " " << *n->emp->getAge() << " " << *n->emp->getTelephone() << " " << *n->emp->getAge() << endl; 
				//out << *n->emp;
				out << *(n)->emp;
				n = n->next;
			}
		}
	} else {
		cout << "Unable to open file!" << endl;
	}
}

void DemoEmployee::readFromFile()
{
	ifstream infile("Employee.txt");
	string line;
	//Eg: ID:1, Name:Nguyen Thai, Age:23, Telephone:097432345, Rating:3, Salary:1550
	while (std::getline(infile, line))
	{
		//Get line by line
		cout << line << endl;
	    vector<string> v;

	    string colon = ",";
	    
	    size_t pos = 0;
	    string token;
	    //Split  => ID:1, Name:Nguyen Thai ... 
	    while ((pos = line.find(colon)) != std::string::npos) {
	        token = line.substr(0, pos);
	        v.push_back(token);
	        line.erase(0, pos + colon.length());
	    }
	    
	    //Split => 1, Nguyen Thai ...
	    for (int i = 0; i < v.size(); i++) {
	        stringstream test(v[i]);
		    string info;
		    vector<string> vInfo;
		    
		    while(std::getline(test, info, ':'))
		    {
		      vInfo.push_back(info);
		    }
	        cout << vInfo[1] << endl;
	    }
	    
	}
}

DemoEmployee::~DemoEmployee()
{
	
}
