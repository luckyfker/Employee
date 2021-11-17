#include "Hourly.h"

Hourly::Hourly() : Employee(0, "No name", 0, "No telephone", 0.0, NONE)
{
	hour = 0.0;
	this->type = E_HOURLY;
}

Hourly::Hourly(const int &id, const string &name, const int &age, const string &telephone, const double &rating, double const &hour, TypeEmp type) : Employee(id, name, age, telephone, rating, NONE)
{
	this->hour = hour;
	this->type = E_HOURLY;
}

double Hourly::calculateSalary() const
{
	return BASIC_SALARY * rating * hour / 240;
}

ostream& operator<<(ostream& os, const Hourly &h)
{
	h.print(os);
	return os;
}
