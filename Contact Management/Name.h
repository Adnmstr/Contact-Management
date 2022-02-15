#ifndef NAME_H
#define NAME_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Name
{
private:
	string fName;
	string lName;
public:
	Name();
	Name(string, string);
	void setFName(string);
	string getFName();
	void setLName(string);
	string getLName();
	friend ostream& operator<<(ostream& out, const Name& name);
	friend istream& operator>>(istream& in, Name& name);
};


#endif
