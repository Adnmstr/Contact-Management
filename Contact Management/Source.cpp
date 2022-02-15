// All work is my own, help with clearing the console after certin functions recieved from https://mathbits.com/MathBits/CompSci/Introduction/clear.htm
// Adonijah Farner

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "Contact.h"

using namespace std;
void search(vector<Contact> vec);
void addContact(vector<Contact>& vec, ofstream& hahaha, Contact contact);
void menu(vector<Contact>& vec, ofstream& hahaha, Contact contact, int& point);

int main()
{
	
	int point = 0;
	Contact contact;
	vector<Contact> vec;
	ifstream hehehe("data.txt");
	ofstream hahaha("output.txt");
	if (!hehehe)
	{
		cout << "file not found";
		exit(10);
	}
	string str;
	while (hehehe >> contact)
	{
		hahaha << contact << endl;
		vec.push_back(contact);
	}
	while (point == 0)
	{
		menu(vec, hahaha, contact, point);
	}
	return 0;
}
//---------------------------------------------------------------------------------------------------------------------------------
// Function to create a menu of options for the user
// Input vector<Contact>: vec, ofstream: hahaha, Contact: contact, int: point
// Output void
//---------------------------------------------------------------------------------------------------------------------------------
void menu(vector<Contact>& vec, ofstream& hahaha, Contact contact, int& point)
{
	int input;
	cout << "-------------" << endl << "  (1) Search" << endl << "  (2) Add Contact" << endl << "  (3) Exit Program" << endl << "-------------" << endl;
	cin >> input;
	if (input == 1)
	{
		system("CLS");
		search(vec);
	}
	if (input == 2)
	{
		system("CLS");
		addContact(vec, hahaha, contact);
	}
	if (input == 3)
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
		cout << "Please enter a last tname or an idetification number to search for contact, then press enter. When finished type EXIT." << endl;
		cin >> input;
		for (int i = 0; i < vec.size(); i++)
		{
			if (atoi(input.c_str()) == vec[i].getID())
			{
				cout << vec[i] << endl;
			}
			if (input != "EXIT" && input != "Exit" && input != "exit")
			{
				if (input == vec[i].getLName())
				{
					cout << vec[i] << endl;
				}
			}
			else if(input == "EXIT" && input == "Exit" && input == "exit")
			{
				point++;
			}
			else
			{
				cout << "impropper answer, try again.";
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
// Input vector<Contact>: vec, ofstream: hahaha, Contact: contact
// Output void
//---------------------------------------------------------------------------------------------------------------------------------
void addContact(vector<Contact>& vec, ofstream& hahaha, Contact contact)
{
	cout << "please enter a new contact." << endl << flush;
	cin >> contact;
	vec.push_back(contact);
	for (int i = 0; i < vec.size(); i++)
	{
		hahaha << vec[i] << endl;
	}
	system("CLS");
}
//---------------------------------------------------------------------------------------------------------------------------------
// End of addContact() function
//---------------------------------------------------------------------------------------------------------------------------------
