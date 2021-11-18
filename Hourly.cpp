#include "Hourly.h"

Hourly::Hourly() : Employee(0, "No name", 0, "No telephone", 0.0, NONE)
{
	hour = 0.0;
	this->type = E_HOURLY;
}

Hourly::Hourly(const int &id, const string &name, const int &age, const string &telephone, const double &rating, const double &hour, TypeEmp type) : Employee(id, name, age, telephone, rating, NONE)
{
	this->hour = hour;
	this->type = E_HOURLY;
}
void Hourly::setHour(double hour) {
	this->hour = hour;
}
double Hourly::calculateSalary() const
{
//	double hours;
//	cout << "Input hours employee: "; cin >> hours;
//	this->hour = hours;
	return BASIC_SALARY * rating * hour / 240;
}

ostream& operator<<(ostream& os, const Hourly &h)
{
	h.print(os);
	return os;
}

void Hourly::print(ostream &os) const
{
    os << "Type:" << type << ", ID:" << id << ", Name:" << name << ", Age:" << age << ", Telephone:" << telephone << ", Rating:" << rating << ", Hours:" << hour << ",H" << endl;
}
