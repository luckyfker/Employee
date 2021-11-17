#include "DemoEmployee.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
//	
//	Employee *eFulltime = new Fulltime(1, "Thai", 20, "0981010894", 5.0);
//	//cout << "Salary: " << eFulltime->calculateSalary() << endl;
//	//cout << *eFulltime;
//	
//	Employee *eParttime = new Parttime(2, "Lam", 22, "0981010894", 2.0);
//	//cout << "Salary: " << eParttime->calculateSalary() << endl;
//	//cout << *eParttime;
//	
//	//Employee *eHourly = new Hourly(7, "Phuc", 23, "0981023564", 8.0, 120);
//	//cout << "Salary: " << eHourly->calculateSalary() << endl;
//	//cout << *eHourly;
//	
//	LList myList;
//	
//	myList.insert(eFulltime);
//	myList.insert(eParttime);
//	//myList.insert(eHourly);
//	try {
//		myList.remove(1);
//	} catch (const char* msg){
//		cerr << msg << endl;
//	}
	
//	try {
//		Node *find = myList.search(3);
//		cout << "Found! " << *find->emp << endl;
//		delete find;
//	} catch (const char* msg){
//		cerr << msg << endl;
//	}
//		
	//myList.print();
	
//	DemoEmployee demo;
//	demo.readFromFile();
//	demo.run(MAIN_MENU);

	//LList myList;
	
//	Employee *e = new Parttime();
//	cout << "HELLO WORLD" << endl;
//	cout << *e;
//	delete e;

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
	
	
	
	return 0;
}
