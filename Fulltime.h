#ifndef FULLTIME_H
#define FULLTIME_H

#include "Employee.h"

class Fulltime : public Employee
{
	private:
	public:
		Fulltime();
		Fulltime(const int &id, const string &name, const int &age, const string &telephone, const double &rating, TypeEmp type);
		
		double calculateSalary() const;
		void print(ostream &os) const;
		friend ostream& operator<<(ostream& os, const Fulltime &f);
	protected:
};

#endif

