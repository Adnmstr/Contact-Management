#include "Contact.h"

int Contact::totalCt = -1;

Contact::Contact()
{
	this->name.setFName("Empty");
	this->name.setLName("");
	this->address.setStreetAddress("");
	this->address.setState("");
	this->address.setZip("");
	this->phone = "";
	setID();
}

Contact::Contact(string fName, string lName, string streetAddress, string state, string zip, string phone)
{
	this->name.setFName(fName);
	this->name.setLName(lName);
	this->address.setStreetAddress(streetAddress);
	this->address.setState(state);
	this->address.setZip(zip);
	this->phone = phone;
	setID();
}

void Contact::setName(string fName, string lName)
{
	this->name.setFName(fName);
	this->name.setLName(lName);
}

string Contact::getName()
{
	string a = name.getFName();
	a += " " + name.getLName();
	return a;
}

string Contact::getLName()
{
	string a = name.getLName();
	return a;
}

string Contact::getAddress()
{
	string a = "";
	a += address.getStreetAddress();
	a += " ";
	a += address.getState();
	a += " ";
	a += address.getZip();
	return a;
}

string Contact::getPhone() const
{
	return this->phone;
}

int Contact::getID() const
{
	return this->id;
}

void Contact::setID()
{
	totalCt++;
	this->id = totalCt;
}

ostream& operator<<(ostream& out, const Contact& contact)
{
	out << contact.name << endl << contact.address << endl << contact.phone << endl << contact.getID();
	return out;
}

istream& operator>>(istream& in, Contact& contact)
{
	in >> contact.name;
	in >> contact.address;
	getline(in, contact.phone);
	contact.setID();
	return in;
}
