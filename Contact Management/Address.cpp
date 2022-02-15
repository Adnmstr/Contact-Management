#include "Address.h"

Address::Address()
{
	this->streetAddress = "";
	this->state = "";
	this->zip = "";
}

Address::Address(string streetAddress, string state, string zip)
{
	this->streetAddress = streetAddress;
	this->state = state;
	this->zip = zip;
}

void Address::setStreetAddress(string streetAddress)
{
	this->streetAddress = streetAddress;
}

string Address::getStreetAddress()
{
	return this->streetAddress;
}

void Address::setState(string state)
{
	this->state = state;
}

string Address::getState()
{
	return this->state;
}

void Address::setZip(string zip)
{
	this->zip = zip;
}

string Address::getZip()
{
	return this->zip;
}

ostream& operator<<(ostream& out, const Address& address)
{
	out << address.streetAddress << endl << address.state << ", " << address.zip;
	return out;
}

istream& operator>>(istream& in, Address& address)
{
	getline(in, address.streetAddress);
	getline(in, address.state);
	getline(in, address.zip);
	return in;
}
