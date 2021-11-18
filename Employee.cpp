#include "Employee.h"
Employee::Employee()
{
	id = 0;
	name = "No name";
	age = 0;
	telephone = "No telephone";
	rating = 0.0;
	type = NONE;
}

Employee::Employee(const int &id, const string &name, const int &age, const string &telephone, const double &rating, TypeEmp type)
{
	this->id = id;
	this->name = name;
	this->age = age;
	this->telephone = telephone;
	this->rating = rating;
	this->type = NONE;
}

ostream& operator<<(ostream& os, const Employee &e) 
{
    e.print(os);
    return os;
}

TypeEmp Employee::getType() const
{
	return type;
}

int Employee::getID() const
{
	return id;
}

string Employee::getName() const
{
	return name;
}

int Employee::getAge() const
{
	return age;
}

string Employee::getTelephone() const
{
	return telephone;
}

double Employee::getRating() const
{
	return rating;
}

void Employee::setName(string name)
{
	this->name = name;
}

void Employee::setAge(int age)
{
	this->age = age;
}

void Employee::setID(int id)
{
	this->id = id;
}

void Employee::print(ostream &os) const
{
    os << "Type:" << type << ", ID:" << id << ", Name:" << name << ", Age:" << age << ", Telephone:" << telephone << ", Rating:" << rating << ",";
}

void Employee::setTelephone (string telephone)
{
	this->telephone = telephone;
}

void Employee::setRating(double rating)
{
	this->rating = rating;
}

Employee::~Employee()
{
	
}
