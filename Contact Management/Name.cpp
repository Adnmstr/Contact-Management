#include "Name.h"

Name::Name()
{
	this->fName = "";
	this->lName = "";
}

Name::Name(string fName, string lName)
{
	this->fName = fName;
	this->lName = lName;
}

void Name::setFName(string fName)
{
	this->fName = fName;
}

string Name::getFName()
{
	return this->fName;
}

void Name::setLName(string lName)
{
	this->lName = lName;
}

string Name::getLName()
{
	return this->lName;
}

ostream& operator<<(ostream& out, const Name& name)
{
	out << name.fName << endl;
	out << name.lName;
	return out;
}

istream& operator>>(istream& in, Name& name)
{
	getline(in, name.fName);
	getline(in, name.lName);
	return in;
}

