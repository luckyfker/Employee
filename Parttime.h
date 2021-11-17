#ifndef PARTTIME_H
#define PARTTIME_H

#include "Employee.h"

class Parttime : public Employee
{
	private:
	public:
		Parttime();
		Parttime(const int &id, const string &name, const int &age, const string &telephone, const double &rating, TypeEmp type);
		
		double calculateSalary() const;
		friend ostream& operator<<(ostream& os, const Parttime &p);
	protected:
};

#endif
