#pragma once
#include <conio.h> // For function getch()
#include <cstdlib> // For several general-purpose functions
#include <fstream> // For file handling
#include <iomanip> // For formatted output
#include <iostream> // For cin, cout, and system
#include <string> // For string data type
#include <cmath> // Calculate using even functions
#include <vector>
using namespace std; // So "std::cout" may be abbreviated to "cout"

class object
{
public:
	void checkout();
	void returnbook();
	void setid(int);
	void setname(string);

protected:
	int id;
	string name;
	bool checkedin;
};

class book : public object
{
public:
	book();
	void setbook(int, string, string);
	void setauthor(string);
	string getauthor();
	string getTitle();
	friend ostream& operator<<(ostream& obj, const book& otherBook);
	bool operator==(const book& otherBook) const;

private:
	string Author_name;
};

class journal : public object
{
public:
	journal();
	void setjournal(int, string, int);
	void setvolume(int);
	string getTitle();
	friend ostream& operator<<(ostream& obj, const journal& otherJournal);
	bool operator==(const journal& otherJournal) const;

private:
	int Volume;
};

class magazine : public object
{
public:
	magazine();
	void setmagazine(int, string, int);
	void setissue(int);
	string getTitle();
	friend ostream& operator<<(ostream& obj, const magazine& otherMagazine);
	bool operator==(const magazine& otherMagazine) const;

private:
	int Issue_number;
};