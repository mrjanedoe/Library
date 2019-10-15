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

template<class items>
void list(items A, int numof)
{
	cout << endl;
	for (int i = 0; i < numof; i++)
	{
		cout << A[i] << endl;
	}
}

int search(string name, book b[], journal j[], magazine m[], int numofb, int numofm, int numofj)
{
	try
	{
		bool itemfound = false;
		for (int i = 0; i <= numofb; i++)
		{
			if (b[i].getTitle() == name)
			{
				cout << "The item was found! Here is its information" << endl;
				cout << b[i] << endl;
				itemfound = true;
				return i;
			}
		}
		for (int i = 0; i <= numofj; i++)
		{
			if (j[i].getTitle() == name)
			{
				cout << "The item was found! Here is its information" << endl;
				cout << j[i] << endl;
				itemfound = true;
				return i;
			}
		}
		for (int i = 0; i <= numofm; i++)
		{
			if (m[i].getTitle() == name)
			{
				cout << "The item was found! Here is its information" << endl;
				cout << m[i] << endl;
				itemfound = true;
				return i;
			}
		}
		if (itemfound == false)
		{
			throw string("We don't carry this item.");
		}
	}
	catch (string s)
	{
		cout << s << endl;
		return 0;
	}
}

int booksearch(string Author, book b[], int numofb)
{
	bool itemfound = false;
	for (int i = 0; i < numofb; i++)
	{
		string a = b[i].getauthor();
		if (a == Author)
		{
			cout << "The book has been found! Here is its information!" << endl;
			cout << b[i] << endl;
			itemfound = true;
			return i;
		}
	}
	if (itemfound == false)
	{
		cout << "We do not carry any items by this author" << endl;
		return 0;
	}
}

int newbook(book b[], string title, string Author, int id, int numof)
{
	int i = 0;
	bool added = true;
	while (b[i].getauthor() != "")
	{
		i++;
	}
	b[i].setauthor(Author);
	b[i].setid(id);
	b[i].setname(title);
	b[i].returnbook();
	for (int a = 0; a < numof; a++)
	{
		if (b[i] == b[a])
		{
			cout << "That book already exists" << endl;
			b[i].setbook(0, "", "");
			added = false;
			return 0;
		}
	}
	for (int a = 0; a < numof; a++)
	{
		if (b[i].getauthor() == b[a].getauthor())
		{
			cout << "There is already a book by this author. You cannot add another one" << endl;
			b[i].setbook(0, "", "");
			added = false;
			return 0;
		}
	}
	if (added = true)
	{
		cout << "The book has been added!" << endl;
	}
}

int newjournal(journal j[], string title, int vol, int id, int numof)
{
	bool added = true;
	int i = 0;
	while (j[i].getTitle() != "")
	{
		i++;
	}
	j[i].setvolume(vol);
	j[i].setid(id);
	j[i].setname(title);
	j[i].returnbook();

	for (int a = 0; a < numof; a++)
	{
		if (j[i] == j[a])
		{
			cout << "That journal already exists" << endl;
			j[i].setjournal(0, "", 0);
			added = false;
			return 0;
		}
	}
	if (added = true)
	{
		cout << "The journal has been added!" << endl;
	}
}

int newmagazine(magazine m[], string title, int vol, int id, int numof)
{
	bool added = true;
	int i = 0;
	while (m[i].getTitle() != "")
	{
		i++;
	}
	m[i].setissue(vol);
	m[i].setid(id);
	m[i].setname(title);
	m[i].returnbook();

	for (int a = 0; a < numof; a++)
	{
		if (m[i] == m[a])
		{
			cout << "That magazine already exists" << endl;
			m[i].setmagazine(0, "", 0);
			added = false;
			return 0;
		}
	}
	if (added == true)
	{
		cout << "Your magazine has been added!" << endl;
	}
}

void main()
{
	int numofb = 5;
	int numofj = 5;
	int numofm = 5;
	book b[100];
	journal j[100];
	magazine m[100];
	b[0].setbook(892, "1984", "Orwell");
	b[1].setbook(292, "Brave New World", "Huxley");
	b[2].setbook(3931, "To Kill a Mockingbird", "Lee");
	b[3].setbook(93829, "Frankenstein", "Shelley");
	b[4].setbook(2314, "A Tale of Two Cities", "Dickens");

	j[0].setjournal(1287, "Economics", 2);
	j[1].setjournal(123, "Romanticism", 8);
	j[2].setjournal(82374, "Politics", 1);
	j[3].setjournal(1037, "Urban form", 4);
	j[4].setjournal(024, "Modernity", 17);

	m[0].setmagazine(33, "American girl", 6);
	m[1].setmagazine(31, "Seventeen", 56);
	m[2].setmagazine(0721, "Teen Nick", 16);
	m[3].setmagazine(321, "Sports illustrated", 23);
	m[4].setmagazine(37021, "Time", 51);


	int start = 0;
	string inpStr = "Improper input. The program will now close";
	string choice;
	string choice2;
	string choice3;
	string title;
	int addnum;
	string addtitle;
	string addauthor;
	int addvol;
	int addissue;
	cout << "LIBRARY MANAGEMENT PROGRAM" << endl;
	cout << "*_*_*_*_*_*_*_*_*_*_*_*_*_" << endl;
	cout << endl;
	cout << "GENERAL INFORMATION" << endl;
	cout << "--------------------------------------------------------------------------------------------------------- " << endl;
	cout << "-If the book is checked in the program will show a one next to it." << endl;
	cout << "-There are only one copy of each item and one item by each author" << endl;
	cout << "-If the item is not checked in you cannot check it out" << endl;
	cout << "-There are currently 5 of each type of item in the catalog" << endl;
	cout << "---------------------------------------------------------------------------------------------------------" << endl;
	cout << endl;

	try
	{
		while (start != 6)
		{
			cout << endl;
			cout << "MENU" << endl;
			cout << "----------------" << endl;
			cout << "1: Search Catalog" << endl;
			cout << "2: Check out" << endl;
			cout << "3: Return" << endl;
			cout << "4: Add a new item" << endl;
			cout << "5: Exit" << endl;
			cout << endl;
			cout << "Please input a number" << endl;
			cout << "If you don't input a proper number, you will continue to be prompted" << endl;
			cout << "If you input a nonnumber you will close the program" << endl;
			cin >> start;
			cout << endl;
			if (start == 1)
			{
				cout << "Would you like to see a list of a certain library item first?" << endl;
				cout << "Enter yes or no" << endl;
				cin >> choice;
				while (choice != "yes" && choice != "no")
				{
					cout << "Please enter a valid input" << endl;
					cin >> choice;
				}
				if (choice == "yes")
				{
					cout << "Which item type you you like to see? books, journals, or magazines" << endl;
					cin >> choice2;
					while (choice2 != "books" && choice2 != "journals" && choice2 != "magazines")
					{
						cout << "please enter a valid input" << endl;
						cin >> choice2;
					}
					if (choice2 == "books")
					{
						list(b, numofb);
					}
					else if (choice2 == "journals")
					{
						list(j, numofj);
					}
					else if (choice2 == "magazines")
					{
						list(m, numofm);
					}
				}

				else if (choice == "no")
				{
					cout << "If you are searching for a book, then you can search by using the author's name" << endl;
					cout << "Would you like to this? Enter yes or no" << endl;
					cin >> choice3;
					while (choice3 != "yes" && choice3 != "no")
					{
						cout << "Please enter a valid input" << endl;
						cin >> choice3;
					}
					if (choice3 == "yes")
					{
						string author;
						cout << "Enter the author" << endl;
						cin >> author;
						booksearch(author, b, numofb);
					}
					else if (choice3 == "no")
					{
						cout << "please enter the title of the item you are searching for" << endl;
						cin.ignore();
						getline(cin, title);
						search(title, b, j, m, numofb, numofm, numofj);
					}

				}
			}
			else if (start == 2)
			{
				string itemtype2;
				cout << "If you want to check out an item, you must search for it first" << endl;
				cout << "Please enter the title" << endl;
				cin.ignore();
				getline(cin, title);
				cout << "Please enter the item type" << endl;
				int a = search(title, b, j, m, numofb, numofm, numofj);
				cout << "Your item will now be checked out after you enter the type of item it is" << endl;
				cout << "Please enter book, magazine or journal" << endl;
				cin >> itemtype2;
				while (itemtype2 != "book" && itemtype2 != "magazine" && itemtype2 != "journal")
				{
					cout << "Please enter valid input" << endl;
				}
				cout << endl;
				if (itemtype2 == "book")
				{
					b[a].checkout();
					cout << b[a] << endl;
				}
				else if (itemtype2 == "magazine")
				{
					m[a].checkout();
					cout << m[a] << endl;
				}
				else if (itemtype2 == "journal")
				{
					j[a].checkout();
					cout << j[a] << endl;
				}
			}
			else if (start == 3)
			{
				string itemtype2;
				cout << "If you want to return an item, you must search for it first" << endl;
				cout << "Please enter the title" << endl;
				cin.ignore();
				getline(cin, title);
				cout << "Please enter the type of item: book, magazine or journal" << endl;
				cin >> itemtype2;
				while (itemtype2 != "book" && itemtype2 != "magazine" && itemtype2 != "journal")
				{
					cout << "Please enter valid input" << endl;
				}
				cout << endl;
				int a = search(title, b, j, m, numofb, numofm, numofj);
				cout << "Your item will now be returned. If the item does not need to be returned, the status will not change" << endl;
				if (itemtype2 == "book")
				{
					b[a].returnbook();
					cout << b[a] << endl;
				}
				else if (itemtype2 == "magazine")
				{
					m[a].returnbook();
					cout << m[a] << endl;
				}
				else if (itemtype2 == "journal")
				{
					j[a].returnbook();
					cout << j[a] << endl;
				}
			}
			else if (start == 4)
			{
				string itemtype;
				cout << "Which type of item would you like to add? Please enter book, journal or magazine" << endl;
				cin >> itemtype;
				while (itemtype != "book" && itemtype != "journal" && itemtype != "magazine")
				{
					cout << "Please enter a valid input" << endl;
					cin >> itemtype;
				}
				if (itemtype == "book")
				{
					cout << "Enter an id number" << endl;
					cin >> addnum;
					cout << "Enter the book title" << endl;
					cin.ignore();
					getline(cin, addtitle);
					cout << "Enter the last name of the book author" << endl;
					cin >> addauthor;
					newbook(b, addtitle, addauthor, addnum, numofb);
					numofb++;
				}
				else if (itemtype == "journal")
				{
					cout << "Enter an id number" << endl;
					cin >> addnum;
					cout << "Enter the journal title" << endl;
					cin.ignore();
					getline(cin, addtitle);
					cout << "Enter the journal volume" << endl;
					cin >> addvol;
					newjournal(j, addtitle, addvol, addnum, numofj);
					numofj++;
				}
				else if (itemtype == "magazine")
				{
					cout << "Enter an id number" << endl;
					cin >> addnum;
					cout << "Enter the magazine title" << endl;
					cin.ignore();
					getline(cin, addtitle);
					cout << "Enter the issue number" << endl;
					cin >> addissue;
					newmagazine(m, addtitle, addissue, addnum, numofm);
					numofm++;
				}
			}
			else if (start == 5)
			{
				cout << "You will now exit the program." << endl;
				start = 6;
			}
			else if (!cin)
			{
				throw inpStr;
			}
			
		}
		
	}
	catch (string x)
	{
		cout << x << endl;
	}
	system("pause");
}