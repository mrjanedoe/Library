#include <conio.h> // For function getch()
#include <cstdlib> // For several general-purpose functions
#include <fstream> // For file handling
#include <iomanip> // For formatted output
#include <iostream> // For cin, cout, and system
#include <string> // For string data type
#include <cmath> // Calculate using even functions
#include <vector>
#include "library.h"
using namespace std; // So "std::cout" may be abbreviated to "cout"

void object::checkout()
{
	checkedin = false;
}

void object::returnbook()
{
	checkedin = true;
}

void object::setid(int v)
{
	id = v;
}

void object::setname(string n)
{
	name = n;
}

book::book()
{
	id = 0;
	name = "";
	checkedin = true;
	Author_name = "";
}

void book::setbook(int a, string b, string c)
{
	id = a;
	name = b;
	Author_name = c;
	checkedin = true;
}

void book::setauthor(string a)
{
	Author_name = a;
}

string book::getauthor()
{
	return Author_name;
}

string book::getTitle()
{
	return name;
}

ostream& operator<<(ostream& obj, const book& otherBook)
{
	obj << "Title: " << otherBook.name << "\t Author: " << otherBook.Author_name << "\t ID: " << otherBook.id
		<< "\t Book Status: " << otherBook.checkedin << endl;
	return obj;
}

bool book::operator==(const book& otherBook) const
{
	return (Author_name == otherBook.Author_name && name == otherBook.name && id == otherBook.id);
}

journal::journal()
{
	id = 0;
	name = "";
	checkedin = true;
	Volume = 0;
}

void journal::setjournal(int a, string b, int c)
{
	id = a;
	name = b;
	checkedin = true;
	Volume = c;
}

void journal::setvolume(int v)
{
	Volume = v;
}

string journal::getTitle()
{
	return name;
}

ostream& operator<<(ostream& obj, const journal& otherJournal)
{
	obj << "Title: " << otherJournal.name << "\t Volume: " << otherJournal.Volume << "\t ID: " << otherJournal.id
		<< "\t Journal Status: " << otherJournal.checkedin << endl;
	return obj;
}

bool journal::operator==(const journal& otherJournal) const
{
	return (Volume == otherJournal.Volume && name == otherJournal.name && id == otherJournal.id);
}

magazine::magazine()
{
	id = 0;
	name = "";
	checkedin = true;
	Issue_number = 0;
}

void magazine::setmagazine(int a, string b, int c)
{
	id = a;
	name = b;
	checkedin = true;
	Issue_number = c;
}

void magazine::setissue(int i)
{
	Issue_number = i;
}

string magazine::getTitle()
{
	return name;
}

ostream& operator<<(ostream& obj, const magazine& otherMagazine)
{
	obj << "Title: " << otherMagazine.name << "\t Issue: " << otherMagazine.Issue_number<< "\t ID: " << otherMagazine.id
		<< "\t Magazine Status: " << otherMagazine.checkedin << endl;
	return obj;
}

bool magazine::operator==(const magazine& otherMagazine) const
{
	return (Issue_number == otherMagazine.Issue_number&& name == otherMagazine.name && id == otherMagazine.id);
}