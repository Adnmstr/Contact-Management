#ifndef ADDR_H
#define ADDR_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Address
{
private:
	string streetAddress, state, zip;
public:
	Address();
	Address(string, string, string);
	void setStreetAddress(string);
	string getStreetAddress();
	void setState(string);
	string getState();
	void setZip(string);
	string getZip();
	friend ostream& operator<<(ostream& out, const Address& address);
	friend istream& operator>>(istream& in, Address& address);
};

#endif