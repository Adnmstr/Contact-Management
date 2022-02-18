// All work is my own, help with clearing the console after certin functions recieved from https://mathbits.com/MathBits/CompSci/Introduction/clear.htm
// Adonijah Farner

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "Contact.h"

using namespace std;
void search(vector<Contact> vec);
void addContact(vector<Contact>& vec, Contact contact);
void menu(vector<Contact>& vec, ofstream& out, Contact contact, int& point);
void save(vector<Contact>& vec, ofstream& out);
vector<Contact> createFile(ifstream& in, Contact contact);

int main()
{
	int point = 0;
	Contact contact;
	ifstream in("contact.txt");
	ofstream out("output.txt");
	vector<Contact> vec = createFile(in, contact);
	while (point == 0)
	{
		menu(vec, out, contact, point);
	}
	return 0;
}

//---------------------------------------------------------------------------------------------------------------------------------
// Function to create a menu of options for the user
// Input vector<Contact>&: vec, ofstream&: out, Contact: contact, int&: point
// Output void
//---------------------------------------------------------------------------------------------------------------------------------
void menu(vector<Contact>& vec, ofstream& out, Contact contact, int& point)
{
	int input;
	cout << "-------------" << endl << "  (1) Search" << endl << "  (2) Add Contact" << endl << "  (3) Save To File" << endl << "  (4) Exit Program" << endl << "-------------" << endl;
	cin >> input;
	if (input == 1)
	{
		system("CLS");
		search(vec);
	}
	if (input == 2)
	{
		system("CLS");
		addContact(vec, contact);
	}
	if (input == 3)
	{
		system("CLS");
		save(vec, out);
	}
	if (input == 4)
	{
		point = 1;
		system("CLS");
	}
}
//---------------------------------------------------------------------------------------------------------------------------------
// End of menu() function
//---------------------------------------------------------------------------------------------------------------------------------

//---------------------------------------------------------------------------------------------------------------------------------
// Function to search for a contact by either last name or identification number
// Input vector<Contact>: vec
// Output int
//---------------------------------------------------------------------------------------------------------------------------------
void search(vector<Contact> vec)
{
	int point = 0;
	string input;
	while (point == 0)
	{
		cout << "Please enter a last name or an idetification number to search for contact, then press enter. When finished type EXIT." << endl;
		cin >> input;
		for (int i = 0; i < vec.size(); i++)
		{
			if (atoi(input.c_str()) == vec[i].getID())
			{
				cout << vec[i] << endl;
			}
			else if (input != "EXIT" && input != "Exit" && input != "exit")
			{
				if (input == vec[i].getLName())
				{
					cout << vec[i] << endl;
				}
			}
			else if(input == "EXIT" || input == "Exit" || input == "exit")
			{
				point++;
			}
			else
			{
				cout << "Impropper answer, try again.";
			}
		}
	}
	system("CLS");
}
//---------------------------------------------------------------------------------------------------------------------------------
// End of search() function
//---------------------------------------------------------------------------------------------------------------------------------

//---------------------------------------------------------------------------------------------------------------------------------
// Function to add a new user imputted contact to the vector and file
// Input vector<Contact>&: vec, Contact: contact
// Output void
//---------------------------------------------------------------------------------------------------------------------------------
void addContact(vector<Contact>& vec, Contact contact)
{
	cout << "please enter a new contact." << endl << flush;
	cin >> contact;
	vec.push_back(contact);
	system("CLS");
}
//---------------------------------------------------------------------------------------------------------------------------------
// End of addContact() function
//---------------------------------------------------------------------------------------------------------------------------------

//---------------------------------------------------------------------------------------------------------------------------------
// Function to save the vactor to file
// Input vector<Contact>&: vec, ofstream&: out
// Output void
//---------------------------------------------------------------------------------------------------------------------------------
void save(vector<Contact>& vec, ofstream& out)
{
	for (int i = 0; i < vec.size(); i++)
	{
		out << vec[i];
	}
	cout << "Saved to file" << endl;
	system("PAUSE");
	system("CLS");
}
//---------------------------------------------------------------------------------------------------------------------------------
// End of save() function
//---------------------------------------------------------------------------------------------------------------------------------

//---------------------------------------------------------------------------------------------------------------------------------
// Function to add a new user imputted contact to the vector and file
// Input ofstream&: in, Contact: contact
// Output vector<Contact>
//---------------------------------------------------------------------------------------------------------------------------------
vector<Contact> createFile(ifstream& in, Contact contact)
{
	vector<Contact> vec;
	if (!in)
	{
		cout << "file not found";
		exit(10);
	}
	string str;
	while (in >> contact)
	{
		vec.push_back(contact);
	}
	return vec;
}
//---------------------------------------------------------------------------------------------------------------------------------
// End of createFile function
//---------------------------------------------------------------------------------------------------------------------------------