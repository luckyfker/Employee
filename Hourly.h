#ifndef HOURLY_H
#define HOURLY_H

#include "Employee.h"

class Hourly : public Employee
{
	private:
		double hour;
	public:
		Hourly();
		Hourly(const int &id, const string &name, const int &age, const string &telephone, const double &rating, const double &hour, TypeEmp type);
		
		void setHour(double hour);
		double calculateSalary() const;
		void print(ostream &os) const;
		friend ostream& operator<<(ostream& os, const Hourly &h);
	protected:
};

#endif
