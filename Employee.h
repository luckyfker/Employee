#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <iostream>
#include <string>

#define BASIC_SALARY 500

using namespace std;

enum TypeEmp
{
	NONE = 0,
	E_FULLTIME,
	E_PARTTIME,
	E_HOURLY
};

class Employee
{
	protected:
		int id;
		string name;
		int age;
		string telephone;
		double rating;
		TypeEmp type;
	public:
		Employee();
		Employee(const int &id, const string &name, const int &age, const string &telephone, const double &rating, TypeEmp type);
		
		friend ostream& operator<<(ostream& os, const Employee &e);
			
		virtual double calculateSalary() const = 0;
		virtual ~Employee();
		int getID() const;
		string getName() const;
		int getAge() const;
		string getTelephone() const;
		double getRating() const;
		void setName(string name);
		void setAge(int age);
		void setID(int id);
		void setTelephone(string telephone);
		void setRating(double rating);
	protected:
		void print(ostream &os) const;
		
};

#endif
