#include "Fulltime.h"

Fulltime::Fulltime() : Employee(0, "No name", 0, "No telephone", 0.0, NONE)
{
	this->type = E_FULLTIME;
}

Fulltime::Fulltime(const int &id, const string &name, const int &age, const string &telephone, const double &rating, TypeEmp type) : Employee(id, name, age, telephone, rating, NONE)
{
	this->type = E_FULLTIME;
	//exception
}

double Fulltime::calculateSalary() const
{
	double bonus = 0.0;
	if (rating >= 1.0 && rating <= 4.0) bonus = 50.0;
	else if (rating >= 4.0 && rating <= 7.0) bonus = 100.0;
	else if (rating >= 7.0 && rating <= 10.0) bonus = 200.0;
	else {}
	return BASIC_SALARY * rating + bonus;
}

ostream& operator<<(ostream& os, const Fulltime &f)
{
	f.print(os);
	return os;
}

void Fulltime::print(ostream &os) const
{
    os << "Type:" << type << ", ID:" << id << ", Name:" << name << ", Age:" << age << ", Telephone:" << telephone << ", Rating:" << rating << ",F" << endl;
}
