#ifndef CONT_H
#define CONT_H

#include "Address.h"
#include "Name.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Contact
{
private:
	Name name;
	Address address;
	string phone;
	int id;
	void setID();
public:
	static int totalCt;
	Contact();
	Contact(string, string, string, string, string, string);
	void setName(string, string);
	string getName();
	string getLName();
	string getAddress();
	string getPhone()const;
	int getID()const;
	friend ostream& operator<<(ostream& out, const Contact& contact);
	friend istream& operator>>(istream& in, Contact& contact);

};

#endif 
