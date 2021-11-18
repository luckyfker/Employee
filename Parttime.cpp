#include "Parttime.h"

Parttime::Parttime() : Employee(0, "No name", 0, "No telephone", 0.0, NONE)
{
	this->type = E_PARTTIME;
}

Parttime::Parttime(const int &id, const string &name, const int &age, const string &telephone, const double &rating, TypeEmp type) : Employee(id, name, age, telephone, rating, NONE)
{
	this->type = E_PARTTIME;
}

double Parttime::calculateSalary() const
{
	return 0.5 * BASIC_SALARY * rating;
}

ostream& operator<<(ostream& os, const Parttime &p)
{
	p.print(os);
	return os;
}

void Parttime::print(ostream &os) const
{
    os << "Type:" << type << ", ID:" << id << ", Name:" << name << ", Age:" << age << ", Telephone:" << telephone << ", Rating:" << rating << ",P" << endl;
}
